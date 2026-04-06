void
filter_sort(auto &cont, auto f1, auto f2, auto f3)
{
    std::erase_if(cont, [&f1](auto val) { return !(f1(val)); });

    auto my_cmp{[&f2, &f3](auto val1, auto val2) {
        if (!f2(val1, val2) && !f2(val2, val1)) {
            return f3(val1, val2);
        } else {
            return f2(val1, val2);
        }
    }};

    std::stable_sort(cont.begin(), cont.end(), my_cmp);
}

int
main()
{
  return 0;
}