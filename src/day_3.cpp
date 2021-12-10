#include <Rcpp.h>
#include <math.h>
#include <sstream>
#include "day_3.h"

std::vector<std::vector<int>> parse(std::vector<std::string> numbers) {
  std::vector<std::string>::iterator it;
  std::vector<std::vector<int>> parsed;
  for (it = numbers.begin(); it != numbers.end(); it++) {
    std::vector<int> parsed_row;
    std::string::iterator row_it;
    std::string row = (*it);
    for (row_it = row.begin(); row_it != row.end(); row_it++) {
      // -48 as (int) converts char to ASCII value, which of 0 is 48
      parsed_row.push_back((int)(*row_it) - 48);
    }
    parsed.push_back(parsed_row);
  }
  return parsed;
}

int most_common(std::vector<std::vector<int>> numbers, int index) {
  std::vector<std::vector<int>>::iterator it;
  int count_0 = 0;
  int count_1 = 0;
  for (it = numbers.begin(); it != numbers.end(); it++) {
    std::vector<int> numbers = (*it);
    if (numbers[index] == 0) {
      count_0++;
    } else {
      count_1++;
    }
  }
  int most_common;
  if (count_0 > count_1) {
    most_common = 0;
  } else {
    most_common = 1;
  }
  return most_common;
}

int convert_to_int(std::vector<int> bits) {
  int total = 0;
  int multiplier = 1;
  reverse(bits.begin(), bits.end());
  for (auto& it: bits) {
    total += it * multiplier;
    multiplier *= 2;
  }
  return total;
}

//' Get the power consumption from set of bytes
//'
//' @param numbers Vector of binary numbers
//' @return The power consumption
//' @export
// [[Rcpp::export]]
int power_consumption(std::vector<std::string> numbers) {
  std::vector<std::vector<int>> bits = parse(numbers);
  std::vector<std::vector<int>>::iterator it;
  std::vector<int> counts;
  int width = bits[0].size();
  for (int i = 0; i < width; i++) {
    int count = 0;
    for (it = bits.begin(); it != bits.end(); it++) {
      std::vector<int> numbers = (*it);
      if (numbers[i]) {
        count++;
      }
    }
    counts.push_back(count);
  }
  std::vector<int> gamma;
  std::vector<int> epsilon;
  int len = bits.size();
  for (int i = 0; i < counts.size(); i++) {
    if (counts[i] >= len / 2) {
      gamma.push_back(1);
      epsilon.push_back(0);
    } else {
      gamma.push_back(0);
      epsilon.push_back(1);
    }
  }
  return convert_to_int(epsilon) * convert_to_int(gamma);
}

std::string vec_to_str(std::vector<int> v) {
  std::stringstream ss;
  for(size_t i = 0; i < v.size(); ++i)
  {
    if(i != 0)
      ss << ",";
    ss << v[i];
  }
  std::string s = ss.str();
  return s;
}

std::vector<std::vector<int>> filter_bits(std::vector<std::vector<int>> bits,
                                          int val, int index) {
  std::vector<std::vector<int>>::iterator it;
  std::vector<std::vector<int>> keep;
  for (it = bits.begin(); it != bits.end(); it++) {
    std::vector<int> numbers = (*it);
    if (numbers[index] == val) {
      keep.push_back(numbers);
    }
  }
  return keep;
}

//' Get the life support rating from set of bytes
//'
//' @param numbers Vector of binary numbers
//' @return The life support rating
//' @export
// [[Rcpp::export]]
int life_support_rating(std::vector<std::string> numbers) {
  std::vector<std::vector<int>> bits = parse(numbers);
  int width = bits[0].size();
  int common;
  int least_common;
  std::vector<std::vector<int>> oxygen_generator = bits;
  std::vector<std::vector<int>> scrubber = bits;
  for (int i = 0; i < width; i++) {
    if (oxygen_generator.size() > 1) {
      common = most_common(oxygen_generator, i);
      oxygen_generator = filter_bits(oxygen_generator, common, i);
    }
    if (scrubber.size() > 1) {
      least_common = !most_common(scrubber, i);
      scrubber = filter_bits(scrubber, least_common, i);
    }
  }

  std::vector<int> oxy = oxygen_generator[0];
  std::vector<int> scrub = scrubber[0];
  for (int i = 0; i < oxy.size(); i++) {
  }
  return convert_to_int(oxy) * convert_to_int(scrub);
}
