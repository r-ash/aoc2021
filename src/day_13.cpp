#include <Rcpp.h>
#include <math.h>
#include <string>
#include <sstream>
#include "day_13.h"

Paper::Paper(std::vector<std::string> input) {
  std::vector<std::string>::iterator it;
  bool passed_delim = false;
  for (it = input.begin(); it != input.end(); it++) {
    if (!passed_delim) {
      if ((*it) == "") {
        passed_delim = true;
        continue;
      }
      std::istringstream row((*it));
      int number;
      std::array<int, 2> point;
      std::string number_str;
      int i = 0;
      while ( std::getline( row, number_str, ',' ) // separate at comma
                && std::istringstream( number_str ) >> number ) {
        point[i] = number;
        i++;
      }
      points.insert(point);
    } else {
      std::stringstream row((*it));
      std::string segment;
      std::vector<std::string> seglist;
      while(std::getline(row, segment, '=')) {
        seglist.push_back(segment);
      }
      orientation.push_back(seglist[0]);
      fold_lines.push_back(std::stoi(seglist[1]));
    }
  }
}

void Paper::fold(int times) {
  for (int i = 0; i < times; i++) {
    bool horizontal_fold = orientation[i] == "fold along y";
    std::set<std::array<int, 2>> after_fold;
    for (std::array<int, 2> point: points) {
      if (horizontal_fold) {
        if (point[1] > fold_lines[i]) {
          point[1] = (2 * fold_lines[i]) - point[1];
        }
      } else {
        if (point[0] > fold_lines[i]) {
          point[0] = (2 * fold_lines[i]) - point[0];
        }
      }
      after_fold.insert(point);
    }
    points = after_fold;
  }
}

//' Get the total number of marked dots after folding
//'
//' @param input Puzzle input
//' @return Number of marked dots
//' @export
// [[Rcpp::export]]
int total_dots(std::vector<std::string> input) {
  Paper paper(input);
  paper.fold(1);
  return paper.points.size();
}

//' Print the text output from folding
//'
//' @param input Puzzle input
//' @export
// [[Rcpp::export]]
void print_output(std::vector<std::string> input) {
  Paper paper(input);
  paper.fold(paper.orientation.size());
  int max_x = 0;
  int max_y = 0;
  for (std::set<std::array<int, 2>>::iterator it = paper.points.begin(); it != paper.points.end(); it++) {
    if ((*it)[0] > max_x) {
      max_x = (*it)[0];
    }
    if ((*it)[1] > max_y) {
      max_y = (*it)[1];
    }
  }
  for (int j = 0; j <= max_y; j++) {
    for (int i = 0; i <= max_x; i++) {
      char symbol = ' ';
      std::array<int, 2> a = {i, j};
      bool is_in = paper.points.find(a) != paper.points.end();
      if (is_in) {
        symbol = '#';
      }
      std::cout << symbol;
    }
    std::cout << "\n";
  }
}
