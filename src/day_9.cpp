#include <Rcpp.h>
#include <math.h>
#include <string>
#include "day_9.h"

std::vector<std::vector<int>> parse_height(std::vector<std::string> map) {
  std::vector<std::string>::iterator it;
  std::vector<std::vector<int>> parsed;
  for (it = map.begin(); it != map.end(); it++) {
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

//' Get the low points from heightmap
//'
//' @param commands map Heightmap
//' @return The low points in the heightmap
//' @export
// [[Rcpp::export]]
std::vector<int> get_low_points(std::vector<std::string> map) {
  std::vector<std::vector<int>> parsed = parse_height(map);
  std::vector<int> low_points;
  int no_rows = parsed.size();
  int no_cols = parsed[0].size();
  for (int i = 0; i < no_rows; i++) {
    for (int j = 0; j < no_cols; j++) {
      int val = parsed[i][j];
      bool low_point = true;
      // Compare left
      if (j > 0) {
        low_point = low_point && val < parsed[i][j - 1];
      }
      // Compare right
      if (j < (no_cols - 1)) {
        low_point = low_point && val < parsed[i][j + 1];
      }
      // Compare above
      if (i > 0) {
        low_point = low_point && val < parsed[i - 1][j];
      }
      // Compare below
      if (i < (no_rows - 1)) {
        low_point = low_point && val < parsed[i + 1][j];
      }
      if (low_point) {
        low_points.push_back(val);
      }
    }
  }
  return low_points;
}

//' Get the risk level from heightmap
//'
//' @param commands map Heightmap
//' @return The risk level
//' @export
// [[Rcpp::export]]
int risk_level(std::vector<std::string> map) {
  std::vector<int> low_points = get_low_points(map);
  int risk = 0;
  std::for_each(low_points.begin(), low_points.end(), [&] (int n) {
    risk += n + 1;
  });
  return risk;
}
