template <typename Container, typename Predicate>
Container
myfilter(const Container &cont, Predicate pred)
{
    Container ans_cont;

    for (auto &elem : cont) {
        if (pred(elem)) {
            ans_cont.insert(ans_cont.end(), elem);
        }
    }

    return ans_cont;
}

class A {
    int *a;

public:
    A(A &&other) noexcept {
        a = other.a;
        other.a = nullptr;
    }
};