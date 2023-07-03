#include <iostream>
#include "qam_modulator.hpp"
#include "awgn_channel.hpp"
#include "qam_demodulator.hpp"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


template<class T>
void print_vector(std::vector<T> &vector, std::string comment = "") {
    std::cout << comment << ": ";
    for (T element : vector) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

void generate_random_bits(std::vector<int> &bits) {
    int random_number = std::rand();
    int i = 0;
    while (i < bits.size()) {
        for (int j = 0; j < 32; j++) {
            if (i >= bits.size()) {
                break;
            }
            int bit = (random_number >> j) & 1;
            bits[i++] = bit;
        }
    }
}

double calc_ber(std::vector<int> &bits, std::vector<int> &demodulated_bits) {
    if (bits.size() != demodulated_bits.size()) {
        throw std::invalid_argument("can't compare vectors of different size");
    }
    int count = 0;
    for (size_t i = 0; i < bits.size(); i++) {
        if (bits[i] != demodulated_bits[i]) {
            count++;
        }
    }
    return (double)count / bits.size();
}

int main() {
    int bits_per_symbol = 4;

    QAM_Modulator qam_modulator(bits_per_symbol);
    AWGN_CHANNEL awgnc(bits_per_symbol);
    QAM_DEMODULATOR qam_demodulator(bits_per_symbol);

    const int bits_number = 3000000;
    std::vector<int> generated_bits(bits_number);
    generate_random_bits(generated_bits);
    std::vector<complex> symbols(bits_number / bits_per_symbol);
    std::vector<int> demodulated_bits(bits_number);

    std::vector<double> noise_var_list = {2.5, 1.98, 1.57, 1.25, 1, 0.8, 0.62, 0.5, 0.4, 0.32, 0.25, 0.2, 0.16, 0.12, 0.1, 0.08};
    std::vector<double> ber_list(0);
    std::vector<double> calculated_ebn0_db_list(0);

    for (double noise_var : noise_var_list) {
        std::vector<int> bits(generated_bits);

        qam_modulator.modulate(bits, symbols);

        awgnc.add_noise(symbols, noise_var);
        double calculated_ebn0_db = awgnc.calc_ebn0_db(noise_var, symbols);
        calculated_ebn0_db_list.push_back(calculated_ebn0_db);

        qam_demodulator.demodulate(symbols, demodulated_bits);

        double ber = calc_ber(bits, demodulated_bits);
        ber_list.push_back(ber);
        std::cout << "calculated ebn0_db=" << calculated_ebn0_db << ", noise_var=" << noise_var << ", ber=" << ber << std::endl;
    }
    
    plt::plot();
    plt::semilogy(noise_var_list, ber_list, "-o");
    plt::show();

    plt::plot();
    plt::semilogy(calculated_ebn0_db_list, ber_list, "-o");
    plt::show();

    return 0;
}