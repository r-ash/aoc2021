#include <Rcpp.h>
#include <math.h>
#include <string>
#include <regex>
#include "day_5.h"

//' Get the coordinates x1, y1, x2, y2 from input string of vent
//'
//' Takes vector of strings of format "0,9 -> 5,9" and parses to vector
//' of arrays
//'
//' @param commands Vector of commands for the submarine,
//'   e.g. forward 2, down 3 or up 5
//' @return The distance traveled by the submarine, resultant depth * horizontal
//' @export
// [[Rcpp::export]]
std::vector<std::array<int, 4>> get_coordinates(std::vector<std::string> vents) {
  std::regex rgx("\\d+");
  std::smatch match;
  std::vector<std::string>::iterator it;
  std::vector<std::array<int, 4>> all_coords;
  for (it = vents.begin(); it != vents.end(); it++) {
    std::array<int, 4> coords;
    int array_length = 0;
    std::string::const_iterator start_search( (*it).cbegin() );
    while (regex_search(start_search, (*it).cend(), match, rgx) &&
           array_length < 4) {
      coords[array_length] = std::stoi(match[0]);
      array_length++;
      start_search = match.suffix().first;
    }
    all_coords.push_back(coords);
  }
  return all_coords;
}

Vent::Vent(std::vector<std::array<int, 4>> coordinates) {
  int max_x = coordinates[0][0];
  int max_y = coordinates[0][1];
  std::vector<std::array<int, 4>>::iterator it;
  for (it = coordinates.begin(); it != coordinates.end(); it++) {
    std::array<int, 4> coord = *it;
    if (coord[0] > max_x) {
      max_x = coord[0];
    }
    if (coord[2] > max_x) {
      max_x = coord[2];
    }
    if (coord[1] > max_y) {
      max_y = coord[1];
    }
    if (coord[3] > max_y) {
      max_y = coord[3];
    }
  }
  std::vector<std::vector<int>> new_sea(max_x + 1, std::vector<int>(max_y + 1));
  sea = new_sea;
}

void Vent::mark_dangerous(std::vector<std::array<int, 4>> coordinates, bool incl_diagonal) {
  std::vector<std::array<int, 4>>::iterator it;
  for (it = coordinates.begin(); it != coordinates.end(); it++) {
    std::array<int, 4> coord = *it;
    if (coord[0] == coord[2]) {
      for (int i = std::min(coord[1], coord[3]); i <= std::max(coord[1], coord[3]); i++) {
        sea[coord[0]][i]++;
      }
    } else if (coord[1] == coord[3]) {
      for (int i = std::min(coord[0], coord[2]); i <= std::max(coord[0], coord[2]); i++) {
        sea[i][coord[1]]++;
      }
    } else if (incl_diagonal) {
      int step_x;
      if (coord[0] < coord[2]) {
        step_x = 1;
      } else {
        step_x = -1;
      }
      int step_y;
      if (coord[1] < coord[3]) {
        step_y = 1;
      } else {
        step_y = -1;
      }
      int length = std::abs(coord[0] - coord[2]);
      for (int i = 0; i <= length; i++) {
        sea[coord[0] + i * step_x][coord[1] + i * step_y]++;
      }
    }
  }
}

int Vent::count_dangerous() {
  int dangerous = 0;
  std::vector<std::vector<int>>::iterator row_iter;
  for (row_iter = sea.begin(); row_iter != sea.end(); row_iter++) {
    std::vector<int> row = *row_iter;
    std::vector<int>::iterator col_iter;
    for (col_iter = row.begin(); col_iter != row.end(); col_iter++) {
      if (*col_iter >= 2) {
        dangerous++;
      }
    }
  }
  return dangerous;
}

//' Count dangerous areas from input string of vent paths
//'
//' @param vents Vent paths
//' @return The count of dangerous areas
//' @export
// [[Rcpp::export]]
int count_dangerous_areas(std::vector<std::string> vents) {
  std::vector<std::array<int, 4>> coordinates = get_coordinates(vents);
  Vent vent {coordinates};
  vent.mark_dangerous(coordinates, false);
  return vent.count_dangerous();
}

//' Count dangerous areas from input string of vent paths
//'
//' @param vents Vent paths
//' @return The count of dangerous areas
//' @export
// [[Rcpp::export]]
int count_dangerous_areas_2(std::vector<std::string> vents) {
  std::vector<std::array<int, 4>> coordinates = get_coordinates(vents);
  Vent vent {coordinates};
  vent.mark_dangerous(coordinates, true);
  return vent.count_dangerous();
}
