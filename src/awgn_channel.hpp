#include <vector> 
#include <complex> 


#ifndef AWGN_CHANNEL_H
#define AWGN_CHANNEL_H

typedef std::complex<double> complex;

class AWGN_CHANNEL
{
  int information_bits_per_symbol;
  double calc_signal_power(const std::vector<complex> &symbols);
  double calc_noise_power(int ebn0_db, const std::vector<complex> &symbols);

public:
  AWGN_CHANNEL(int information_bits_per_symbol);
  void add_noise(std::vector<complex> &symbols, int ebn0_db);
  void add_noise(std::vector<complex> &symbols, double noise_var);
  double calc_ebn0_db(double noise_var, const std::vector<complex> &symbols);
  
};

#endif