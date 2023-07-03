#include "qam_demodulator.hpp"
#include <math.h>
#include <iostream>


QAM_DEMODULATOR::QAM_DEMODULATOR(int bits_per_symbol) {
    switch (bits_per_symbol) {
        case 2:
            this->bits_per_symbol = 2;
            // 00, 01, 10, 11
            constellation = std::vector<complex>{
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
            };
            break;
        default:
            throw std::invalid_argument( "bits_per_symbol must be 2, 4 or 6" );
    }
}

void QAM_DEMODULATOR::demodulate(std::vector<complex> &symbols, std::vector<int> &bits) {
    // наивный метод
    for (size_t symbol_num = 0; symbol_num < symbols.size(); symbol_num++) {
        complex symbol = symbols[symbol_num];
        // выбираем ближайшую точку созвездия
        double min_dist = std::abs(constellation[0] - symbol);
        int index = 0;
        for (size_t i = 1; i < constellation.size(); i++) {
            double dist = std::abs(constellation[i] - symbol);
            if (dist < min_dist) {
                min_dist = dist;
                index = i;
            }
        }
        // int --> bits
        for (size_t i = 0; i < bits_per_symbol; i++) {
            int shift = bits_per_symbol - 1 - i;
            int mask = 1 << shift;
            int bit = (index & mask) >> shift;
            bits[symbol_num * bits_per_symbol + i] = bit;
        }
    }
}
