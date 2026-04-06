class BlackHole
{
    size_t mass;

  public:
    BlackHole(size_t mass_) : mass(mass_){};

    size_t
    get_mass() const
    {
        return mass;
    }

    template <typename T>
    void
    consume(T arg)
    {
        throw std::runtime_error("Black hole has tried to consume non-pointer");
    }

    template <typename T>
    void
    consume(T *arg)
    {
        if constexpr (std::is_void_v<T>) {
            throw std::runtime_error("Black hole has tried to consume void");
        } else if (arg == nullptr) {
            std::cout << "There is nothing to consume" << std::endl;
        } else {
            size_t cons_mass;

            if constexpr (std::is_same_v<T, BlackHole>) {
                if (arg == this) {
                    throw std::runtime_error("Black hole has tried to consume itself");
                }
                cons_mass = arg->get_mass();
            } else {
                cons_mass = sizeof(T);
            }

            std::cout << "Black hole consumed " << cons_mass
                      << (std::is_const_v<T> ? " const" : " non-const") << " bytes" << std::endl;
            mass += cons_mass;
            delete arg;
        }
    }
};
