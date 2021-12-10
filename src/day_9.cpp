#include <Rcpp.h>
#include <math.h>
#include <string>
#include <stack>
#include <array>
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
//' @param map Heightmap
//' @return The low points in the heightmap
//' @export
// [[Rcpp::export]]
std::vector<std::array<int, 2>> get_low_points(std::vector<std::vector<int>> parsed) {
  std::vector<std::array<int, 2>> low_points;
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
        std::array<int, 2> low {i, j};
        low_points.push_back(low);
      }
    }
  }
  return low_points;
}

//' Get the risk level from heightmap
//'
//' @param map Heightmap
//' @return The risk level
//' @export
// [[Rcpp::export]]
int risk_level(std::vector<std::string> map) {
  std::vector<std::vector<int>> parsed = parse_height(map);
  std::vector<std::array<int, 2>> low_points = get_low_points(parsed);
  int risk = 0;
  std::for_each(low_points.begin(), low_points.end(), [&] (std::array<int, 2> point) {
    risk += parsed[point[0]][point[1]] + 1;
  });
  return risk;
}

int get_value(std::vector<std::vector<int>> map, std::array<int, 2> point) {
  return map[point[0]][point[1]];
}

bool in_basin(std::vector<std::array<int, 2>> basin, std::array<int, 2> point) {
  for (std::vector<std::array<int, 2>>::iterator it = basin.begin(); it != basin.end(); it++) {
    if ((*it)[0] == point[0] && (*it)[1] == point[1]) {
      return true;
    }
  }
  return false;
}

std::vector<std::array<int, 2>> fill_basin(std::vector<std::vector<int>> map, std::array<int, 2> point) {
  std::stack<std::array<int, 2>> stack;
  int no_rows = map.size();
  int no_cols = map[0].size();
  std::vector<std::array<int, 2>> basin;
  stack.push(point);
  std::array<int, 2> poi;
  while (!stack.empty()) {
    poi = stack.top();
    stack.pop();
    if (in_basin(basin, poi)) {
      // This is not nice, ideally we make point a type which we can
      // mark with some property to say it has been seen
      // Checking if every point exists in the basin will be slow
      continue;
    }
    int val = get_value(map, poi);
    if (val < 9) {
      basin.push_back(poi);
    }
    int i = poi[0];
    int j = poi[1];
    // Go left
    if (j > 0 && val < 9) {
      stack.push(std::array<int, 2> {i, j - 1});
    }
    // Go right
    if (j < (no_cols - 1) && val < 9) {
      stack.push(std::array<int, 2> {i, j + 1});
    }
    // Go up
    if (i > 0 && val < 9) {
      stack.push(std::array<int, 2> {i - 1, j});
    }
    // Go down
    if (i < (no_rows - 1) && val < 9) {
      stack.push(std::array<int, 2> {i + 1, j});
    }
  }
  return basin;
}

std::vector<std::vector<std::array<int, 2>>> locate_basins(
    std::vector<std::vector<int>> map, std::vector<std::array<int, 2>> low_points) {

  std::vector<std::vector<std::array<int, 2>>> basins;
  std::for_each(low_points.begin(), low_points.end(), [&] (std::array<int, 2> point) {
    std::vector<std::array<int, 2>> basin = fill_basin(map, point);
    basins.push_back(basin);
  });
  return basins;
}

//' Get the value of largest 3 basins multiplied together
//'
//' @param map height map
//' @return The size of 3 largest basins multiplied together
//' @export
// [[Rcpp::export]]
int basin_sizes(std::vector<std::string> map) {
  std::vector<std::vector<int>> parsed = parse_height(map);
  std::vector<std::array<int, 2>> low_points = get_low_points(parsed);
  std::vector<std::vector<std::array<int, 2>>> basins =
    locate_basins(parsed, low_points);
  int first = 0;
  int second = 0;
  int third = 0;
  std::for_each(basins.begin(), basins.end(), [&] (std::vector<std::array<int, 2>> basin) {
    int size = basin.size();
    if (size > first) {
      third = second;
      second = first;
      first = size;
    } else if (size > second) {
      third = second;
      second = size;
    } else if (size > third) {
      third = size;
    }
  });
  return first * second * third;
}
