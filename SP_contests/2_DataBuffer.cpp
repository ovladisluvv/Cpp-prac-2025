struct Data
{
    int value;

    Data() { value = 42; }
    
    Data(int value_) { value = value_; }

    ~Data() { increment_counter(); }

    Data & operator=(const size_t value_) {
      value = value_;
      return *this;
    }

    friend std::ostream &
    operator<<(std::ostream &os, Data &data)
    {
        return os << data.value;
    }
};

class DataBuffer
{
    Data *buffer;
    size_t buffer_size;

  public:
    DataBuffer(size_t size = 1)
    {
        buffer_size = size;
        buffer = new Data[buffer_size];
    }

    ~DataBuffer() { delete[] buffer; }

    DataBuffer(DataBuffer &&other)
    {
        buffer = other.buffer;
        buffer_size = other.buffer_size;
        other.buffer = nullptr;
        other.buffer_size = 0;
    }

    DataBuffer &
    operator=(DataBuffer &&other)
    {
        if (this != &other) {
            delete[] buffer;
            buffer = other.buffer;
            buffer_size = other.buffer_size;
            other.buffer = nullptr;
            other.buffer_size = 0;
        }

        return *this;
    }

    Data &
    operator[](size_t index) const
    {
        return buffer[index];
    }

    size_t
    size() const
    {
        return buffer_size;
    }
};
