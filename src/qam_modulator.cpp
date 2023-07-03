#include "qam_modulator.hpp"
#include <stdexcept>
#include <iostream>

QAM_Modulator::QAM_Modulator(int bits_per_symbol) {
    switch (bits_per_symbol) {
        case 2:
            this->bits_per_symbol = 2;
            // 00, 01, 10, 11
            this->constellation = std::vector<complex>{
                complex(-1, 1),
                complex(1, 1),
                complex(-1, -1),
                complex(1, -1),
            };
            break;
        case 4:
            this->bits_per_symbol = 4;
            // 0 4 12 8 
            // 1 5 13 9 
            // 3 7 15 11 
            // 2 6 14 10
            constellation = std::vector<complex>{
                complex(-3, 3),
                complex(-3, 1),
                complex(-3, -3),
                complex(-3, -1),
                complex(-1, 3),
                complex(-1, 1),
                complex(-1, -3),
                complex(-1, -1),
                complex(3, 3),
                complex(3, 1),
                complex(3, -3),
                complex(3, -1),
                complex(1, 3),
                complex(1, 1),
                complex(1, -3),
                complex(1, -1)
            };
            break;
        case 6:
            this->bits_per_symbol = 6;
            
            constellation = std::vector<complex>{
                // 000000
                complex(-7, -7),
                complex(-7, -5),
                complex(-7, -1),
                complex(-7, -3),

                complex(-7, 7),
                complex(-7, 5),
                complex(-7, 1),
                complex(-7, 3),

                // 001000
                complex(-5, -7),
                complex(-5, -5),
                complex(-5, -1),
                complex(-5, 7),

                complex(-5, 7),
                complex(-5, 5),
                complex(-5, 1),
                complex(-5, 3),

                // 010000
                complex(-1, -7),
                complex(-1, -5),
                complex(-1, -1),
                complex(-1, -3),

                complex(-1, 7),
                complex(-1, 5),
                complex(-1, 1),
                complex(-1, 3),

                // 011000
                complex(-3, -7),
                complex(-3, -5),
                complex(-3, -1),
                complex(-3, -3),

                complex(-3, 7),
                complex(-3, 5),
                complex(-3, 1),
                complex(-3, 3),

                // 100000
                complex(7, -7),
                complex(7, -5),
                complex(7, -1),
                complex(7, -3),

                complex(7, 7),
                complex(7, 5),
                complex(7, 1),
                complex(7, 3),

                // 101000
                complex(5, -7),
                complex(5, -5),
                complex(5, -1),
                complex(5, -3),

                complex(5, 7),
                complex(5, 5),
                complex(5, 1),
                complex(5, 3),

                // 110000
                complex(1, -7),
                complex(1, -5),
                complex(1, -1),
                complex(1, -3),

                complex(1, 7),
                complex(1, 5),
                complex(1, 1),
                complex(1, 3),

                // 111000
                complex(3, -7),
                complex(3, -5),
                complex(3, -1),
                complex(3, -3),

                complex(3, 7),
                complex(3, 5),
                complex(3, 1),
                complex(3, 3),

                // complex(-7 , 7), complex(-5 , 7), complex(-3 , 7), complex(-1 , 7), 
                // complex(1 , 7), complex(3 , 7), complex(5 , 7), complex(7 , 7), 
                // complex(-7 , 5), complex(-5 , 5), complex(-3 , 5), complex(-1 , 5), 
                // complex(1 , 5), complex(3 , 5), complex(5 , 5), complex(7 , 5), 
                // complex(-7 , 3), complex(-5 , 3), complex(-3 , 3), complex(-1 , 3), 
                // complex(1 , 3), complex(3 , 3), complex(5 , 3), complex(7 , 3), 
                // complex(-7 , 1), complex(-5 , 1), complex(-3 , 1), complex(-1 , 1), 
                // complex(1 , 1), complex(3 , 1), complex(5 , 1), complex(7 , 1), 
                // complex(-7, 1), complex(-5, 1), complex(-3, 1), complex(-1, 1),
                // complex(1, 1), complex(3, 1), complex(5, 1), complex(7, 1), 
                // complex(-7, 3), complex(-5, 3), complex(-3, 3), complex(-1, 3), 
                // complex(1, 3), complex(3, 3), complex(5, 3), complex(7, 3), 
                // complex(-7, 5), complex(-5, 5), complex(-3, 5), complex(-1, 5), 
                // complex(1, 5), complex(3, 5), complex(5, 5), complex(7, 5), 
                // complex(-7, 7), complex(-5, 7), complex(-3, 7), complex(-1, 7), 
                // complex(1, 7), complex(3, 7), complex(5, 7), complex(7, 7)

            };
            break;
        default:
            throw std::invalid_argument( "bits_per_symbol must be 2, 4 or 6" );
    }
}

int QAM_Modulator::bits_to_int(const int *ptr) {
    int sum = 0;
    int shift = 0;
    for (int i = this->bits_per_symbol - 1; i >= 0; i--) {
        sum += (*(ptr + shift)) << i;
        shift++;
    }
    return sum;
}

void QAM_Modulator::modulate(const std::vector<int> &bits, std::vector<std::complex<double>> &symbols) {
    if (bits.size() % this->bits_per_symbol != 0) {
        throw std::invalid_argument( "size of bits vector must be multiple of this.bits_per_symbol" );
    }
    
    int j = 0;
    for (int i = 0; i < bits.size(); i += this->bits_per_symbol) {
        int index = bits_to_int(bits.data() + i);
        symbols[j++] = this->constellation[index];
    }
}