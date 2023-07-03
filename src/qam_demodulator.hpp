#include <vector> 
#include <complex> 


#ifndef QAM_DEMODULATOR_H
#define QAM_DEMODULATOR_H

typedef std::complex<double> complex;

class QAM_DEMODULATOR
{
  int bits_per_symbol;
  std::vector<complex> constellation;

public:
  QAM_DEMODULATOR(int bits_per_symbol);
  void demodulate(std::vector<complex> &symbols, std::vector<int> &bits);  
};

#endif