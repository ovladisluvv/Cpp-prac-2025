#include <iostream>
#include <new>


namespace numbers
{
class complex_stack
{
    complex *stack = nullptr;
    size_t cur_size = 0, max_size = 128;

  public:
    complex_stack()
    {
        stack = new complex[max_size];
    }

    complex_stack(const complex_stack &other)
    {
        cur_size = other.cur_size;
        max_size = other.max_size;

        if (stack != nullptr) {
            delete [] stack;
        }

        stack = new complex[max_size];

        for (size_t i = 0; i < cur_size; ++i) {
            new (stack + i) complex(other.stack[i]);
        }
    }

    ~complex_stack()
    {
        delete[] stack;
    }

    size_t
    size() const
    {
        return cur_size;
    }

    const complex &
    operator[](int index) const
    {
        return stack[index];
    }

    friend complex_stack
    operator<<(const complex_stack &stack, const complex &new_elem)
    {
        complex_stack new_stack = stack;

        if (new_stack.cur_size == new_stack.max_size) {
            new_stack.max_size *= 2;
            ++new_stack.max_size;

            complex *tmp_stack = new complex[new_stack.max_size];
            for (size_t i = 0; i < cur_size; ++i) {
                new (tmp_stack.stack + i) complex(new_stack[i]);
            }

            delete[] new_stack.stack;
            new_stack.stack = tmp_stack;
        }
        new (new_stack.stack + cur_size) complex(new_elem);

        return new_stack;
    }

    friend complex_stack
    operator~(const complex_stack &stack)
    {
        complex_stack new_stack = stack;
        --new_stack.cur_size;

        return new_stack;
    }
};

complex
operator+(complex_stack stack)
{
    return stack[stack.size() - 1];
}

} // namespace numbers
