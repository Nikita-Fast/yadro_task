#include <vector> 
#include <complex> 


#ifndef QAM_Modulator_H
#define QAM_Modulator_H

typedef std::complex<double> complex;

class QAM_Modulator
{
  int bits_per_symbol;
  std::vector<complex> constellation;

  int bits_to_int(const int *ptr);

public:
  QAM_Modulator(int bits_per_symbol);
  void modulate(const std::vector<int> &bits, std::vector<complex> &symbols);

};

#endif