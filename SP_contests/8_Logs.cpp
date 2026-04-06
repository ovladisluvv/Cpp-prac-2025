std::optional<LogMessage>
parse_log_message(const std::string &line)
{
    static const std::regex log_form(R"(\[(\d*):(\d*)\] \[(INFO|WARNING|ERROR)\] (.*))");

    std::smatch parsed_line;
    if (std::regex_match(line, parsed_line, log_form)) {
        Type type;
        std::string type_str = parsed_line[3];
        if (type_str == "INFO") {
            type = Type::Info;
        } else if (type_str == "WARNING") {
            type = Type::Warning;
        } else if (type_str == "ERROR") {
            type = Type::Error;
        } else {
            return std::nullopt;
        }

        int h = std::stoi(parsed_line[1]);
        int m = std::stoi(parsed_line[2]);
        std::string msg = parsed_line[4];

        return LogMessage(type, Time(h, m), msg);
    }

    return std::nullopt;
}

std::optional<LogMessage>
find_first_message(const std::vector<LogMessage> &messages, Type type, Time after = Time(0, 0))
{
    for (const auto &msg : messages) {
        if (msg.type == type) {
            if ((msg.time.hour > after.hour) || (msg.time.hour == after.hour && msg.time.minute >= after.minute)) {
                return msg;
            }
        }
    }

    return std::nullopt;
}

std::optional<std::string>
find_last_client_name(const std::vector<LogMessage> &messages, Time before = Time(24, 0))
{
    static const std::regex client_form(R"(Client \"(.*)\" connected)");

    std::optional<std::string> last_name;
    for (const auto &msg : messages) {
        if (msg.type == Type::Info) {
            if ((msg.time.hour < before.hour) || (msg.time.hour == before.hour && msg.time.minute <= before.minute)) {
                std::smatch parsed_msg;
                if (std::regex_match(msg.message, parsed_msg, client_form)) {
                    last_name = parsed_msg[1];
                }
            }
        }
    }

    return last_name;
}
