#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdint>

int
main()
{
    constexpr size_t OCTETS_MULTIPLICITY = 4, DATA_SIZE = 32;

    uint32_t offset;
    uint32_t hex_arr[OCTETS_MULTIPLICITY];

    while (std::cin >> std::hex >> offset) {
        for (size_t i = 0; i < OCTETS_MULTIPLICITY; ++i) {
            if (std::cin >> hex_arr[0] >> hex_arr[1] >> hex_arr[2] >> hex_arr[3]) {
                uint32_t dec_num = 0;
                for (size_t j = 0; j < OCTETS_MULTIPLICITY; ++j) {
                    dec_num += hex_arr[j] << (DATA_SIZE - (j + 1) * CHAR_BIT);
                }
                std::cout << dec_num << std::endl;
            }
        }
    }
}
