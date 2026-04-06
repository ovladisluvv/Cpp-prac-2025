#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <memory>

class FigureFactory
{
    FigureFactory()
    {
        creators["R"] = [](const std::string &params) { return std::unique_ptr<Figure>(Rectangle::make(params)); };

        creators["S"] = [](const std::string &params) { return std::unique_ptr<Figure>(Square::make(params)); };

        creators["C"] = [](const std::string &params) { return std::unique_ptr<Figure>(Circle::make(params)); };
    }

    FigureFactory(const FigureFactory &) = delete;
    FigureFactory &operator=(const FigureFactory &) = delete;

  public:
    std::map<std::string, std::function<std::unique_ptr<Figure>(const std::string &)>> creators;

    static FigureFactory &
    factory_instance()
    {
        static FigureFactory inst;
        return inst;
    }

    std::unique_ptr<Figure>
    make(const std::string &type, const std::string &params)
    {
        auto it = creators.find(type);
        if (it != creators.end()) {
            return it->second(params);
        }
        return nullptr;
    }
};

bool
compare(const std::unique_ptr<Figure> &a, const std::unique_ptr<Figure> &b)
{
    return a->get_square() < b->get_square();
}

int
main()
{
    std::vector<std::unique_ptr<Figure>> figs;
    std::string in_str;

    while (std::getline(std::cin, in_str)) {
        std::istringstream iss(in_str);
        std::string type;
        iss >> type;

        std::string params;
        std::getline(iss, params);

        auto &fact = FigureFactory::factory_instance();
        figs.push_back(fact.make(type, params));
    }

    std::stable_sort(figs.begin(), figs.end(), compare);

    for (const auto &fig : figs) {
        std::cout << fig->to_string() << std::endl;
    }
}
