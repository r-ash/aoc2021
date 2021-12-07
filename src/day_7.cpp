#include <Rcpp.h>
#include <math.h>
#include "day_2.h"

//' Get the cost of aligning crabs to a particular position
//'
//' @param positions Vector of crab positions
//' @param alignment_position Final crab positions
//' @return The fuel cost of aligning to that position
//' @export
// [[Rcpp::export]]
int position_cost(std::vector<int> positions, int alignment_position) {
  int total_cost = 0;
  std::vector<int>::iterator it;
  for (it = positions.begin(); it != positions.end(); it++) {
    total_cost += std::abs(*it - alignment_position);
  }
  return total_cost;
}

//' Get the lowest amount of fuel needed for all crabs to align.
//'
//' @param positions Vector of crab horizontal positions
//' @return The minimum fuel needed for the crabs to align
//' @export
// [[Rcpp::export]]
int optimal_position(std::vector<int> positions) {
  int min = *std::min_element(positions.begin(), positions.end());
  int max = *std::max_element(positions.begin(), positions.end());
  int optimal_position = min;
  int min_cost = position_cost(positions, min);
  for (int i = min + 1; i <= max; ++i) {
    int cost = position_cost(positions, i);
    if (cost < min_cost) {
      min_cost = cost;
      optimal_position = i;
    }
  }
  return min_cost;
}

int triangular_number(int n) {
  return n * (n + 1) / 2;
}

//' Get the cost of aligning crabs to a particular position
//'
//' @param positions Vector of crab positions
//' @param alignment_position Final crab positions
//' @return The fuel cost of aligning to that position
//' @export
// [[Rcpp::export]]
int position_cost_2(std::vector<int> positions, int alignment_position) {
  int total_cost = 0;
  std::vector<int>::iterator it;
  for (it = positions.begin(); it != positions.end(); it++) {
    total_cost += triangular_number(std::abs(*it - alignment_position));
  }
  return total_cost;
}

int binary_search(std::vector<int> positions, int start_min, int min_cost,
                  int start_max, int max_cost) {
  if (start_min == start_max - 1) {
    return std::min(min_cost, max_cost);
  }
  int mid = std::floor((start_min + start_max) / 2);
  int cost = position_cost_2(positions, mid);
  if (min_cost < max_cost) {
    cost = binary_search(positions, start_min, min_cost, mid, cost);
  } else if (min_cost > max_cost) {
    cost = binary_search(positions, mid, cost, start_max, max_cost);
  }
  return cost;
}

//' Get the lowest amount of fuel needed for all crabs to align puzzle 2.
//'
//' @param positions Vector of crab horizontal positions
//' @return The minimum fuel needed for the crabs to align
//' @export
// [[Rcpp::export]]
int optimal_position_2(std::vector<int> positions) {
  int min = *std::min_element(positions.begin(), positions.end());
  int max = *std::max_element(positions.begin(), positions.end());
  int min_cost = position_cost_2(positions, min);
  int max_cost = position_cost_2(positions, max);
  return binary_search(positions, min, min_cost, max, max_cost);
}
