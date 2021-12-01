#include <Rcpp.h>
#include <math.h>
#include "day_1.h"

//' Count number of times a sequence of numbers increases.
//'
//' @param values Vector of integers
//' @return The number of times subsequent value increases
//' @export
// [[Rcpp::export]]
int count_increases(std::vector<int> values) {
  int increases = 0;
  for (std::size_t i = 1; i < values.size(); ++i) {
    if (values[i] > values[i - 1]) {
      increases += 1;
    }
  }
  return increases;
}

//' Count number of times a three-measurement sliding window increases in value.
//'
//' @param values Vector of integers
//' @return The number of times three measurement sliding window increases.
//' @export
// [[Rcpp::export]]
int window_increases(std::vector<int> values) {
  // We could do this in 1 loop but let's reuse count_increases func
  std::vector<int> window = get_window(values);
  return count_increases(window);
}

std::vector<int> get_window(std::vector<int> values) {
  auto length = values.size();
  std::vector<int> window(length - 2);
  for (std::size_t i = 0; i < length - 2; ++i) {
    window[i] = values[i] + values[i + 1] + values[i + 2];
  }
  return window;
}
