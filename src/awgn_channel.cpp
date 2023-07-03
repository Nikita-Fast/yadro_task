#include "awgn_channel.hpp"
#include <math.h>  
#include <random>
#include <iostream>


AWGN_CHANNEL::AWGN_CHANNEL(int information_bits_per_symbol) {
    this->information_bits_per_symbol = information_bits_per_symbol;
}

double AWGN_CHANNEL::calc_signal_power(const std::vector<std::complex<double>> &symbols) {
    // Рассчитываем мощность сигнала
    double sum = 0;
    for (std::complex<double> s : symbols) {
        sum += pow(std::abs(s), 2);
    }
    return sum / symbols.size();
}

double AWGN_CHANNEL::calc_noise_power(int ebn0_db, const std::vector<std::complex<double>> &symbols) {
    // Рассчитываем необходимую мощность шума для переданного массива символов и требуемого EB_N0_db.
    double Es_N0_dB = ebn0_db + 10 * log10(this->information_bits_per_symbol);
    double SNR_dB = Es_N0_dB;
    double SNR = pow(10, SNR_dB / 10);
    return calc_signal_power(symbols) / SNR;
}

void AWGN_CHANNEL::add_noise(std::vector<std::complex<double>> &symbols, int ebn0_db) {
    // p == N0
    // var(N) == p / 2 == N0 / 2
    double p = calc_noise_power(ebn0_db, symbols);
    std::cout << "noise_var=" << p << std::endl;

    int symbols_num = symbols.size();

    std::default_random_engine gen;
    std::normal_distribution<double> distribution(0.0, sqrt(p / 2));

    for (size_t i = 0; i < symbols.size(); i++) {
        std::complex<double> noise(distribution(gen), distribution(gen));
        symbols[i] += noise;
    }
}

void AWGN_CHANNEL::add_noise(std::vector<std::complex<double>> &symbols, double noise_var) {
    // p == N0
    // var(N) == p / 2 == N0 / 2
    // double p = calc_noise_power(ebn0_db, symbols);

    int symbols_num = symbols.size();

    std::default_random_engine gen;
    std::normal_distribution<double> distribution(0.0, sqrt(noise_var / 2));

    for (size_t i = 0; i < symbols.size(); i++) {
        std::complex<double> noise(distribution(gen), distribution(gen));
        symbols[i] += noise;
    }
}

double AWGN_CHANNEL::calc_ebn0_db(double noise_var, const std::vector<complex> &symbols) {
    double SNR = calc_signal_power(symbols) / noise_var;
    double SNR_dB = 10 * log10(SNR);
    double Es_N0_dB = SNR_dB;
    double ebn0_db = Es_N0_dB - 10 * log10(this->information_bits_per_symbol);

    return ebn0_db;
}
