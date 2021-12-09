#include <Rcpp.h>
#include <math.h>
#include <bitset>
#include "day_3.h"

std::vector<std::bitset<12>> parse(std::vector<std::string> numbers) {
  std::vector<std::string>::iterator it;
  std::vector<std::bitset<12>> bits;
  for (it = numbers.begin(); it != numbers.end(); it++) {
    std::bitset<12> bit{(*it)};
    bits.push_back(bit);
  }
  return bits;
}

//' Get the power consumption from set of bytes
//'
//' @param numbers Vector of binary numbers
//' @return The power consumption
//' @export
// [[Rcpp::export]]
int power_consumption(std::vector<std::string> numbers) {
  std::vector<std::bitset<12>> bits = parse(numbers);
  std::vector<std::bitset<12>>::iterator it;
  std::array<int, 12> counts = {};;
  for (it = bits.begin(); it != bits.end(); it++) {
    std::bitset<12> number = (*it);
    for (int i = 0; i < 12; i++) {
      if (number[i]) {
        counts[i]++;
      }
    }
  }
  std::bitset<12> gamma;
  int len = bits.size();
  for (int i = 0; i < 12; i++) {
    if (counts[i] >= len / 2) {
      gamma[i] = 1;
    } else {
      gamma[i] = 0;
    }
  }
  std::bitset<12> epsilon = gamma;
  epsilon.flip();
  int g = (int)(gamma.to_ulong());
  int e = (int)(epsilon.to_ulong());
  int consumption = e * g;
  return consumption;
}

