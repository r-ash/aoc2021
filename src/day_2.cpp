#include <Rcpp.h>
#include <math.h>
#include <string>
#include "day_2.h"

//' Get the distance traveled from a set of commands.
//'
//' This is the result horizontal * result depth.
//'
//' @param commands Vector of commands for the submarine,
//'   e.g. forward 2, down 3 or up 5
//' @return The distance traveled by the submarine, resultant depth * horizontal
//' @export
// [[Rcpp::export]]
int total_distance(std::vector<std::string> commands) {
  int horizontal = 0;
  int depth = 0;
  std::vector<std::string>::iterator it;
  for (it = commands.begin(); it != commands.end(); it++) {
    std::string cmd = *it;
    std::string command = cmd.substr(0, cmd.find(' '));
    int distance = std::stoi(cmd.substr(cmd.find(' ') + 1, cmd.length() - 1));
    if (command == "forward") {
      horizontal += distance;
    } else if (command == "up") {
      depth -= distance;
    } else {
      depth += distance;
    }
  }
  return horizontal * depth;
}

//' Get the distance traveled from a set of commands for puzzle 2.
//'
//' This is the result horizontal * result depth.
//'
//' @param commands Vector of commands for the submarine,
//'   e.g. forward 2, down 3 or up 5
//' @return The distance traveled by the submarine, resultant depth * horizontal
//' @export
// [[Rcpp::export]]
int total_distance_2(std::vector<std::string> commands) {
  int horizontal = 0;
  int depth = 0;
  int aim = 0;
  std::vector<std::string>::iterator it;
  for (it = commands.begin(); it != commands.end(); it++) {
    std::string cmd = *it;
    std::string command = cmd.substr(0, cmd.find(' '));
    int distance = std::stoi(cmd.substr(cmd.find(' ') + 1, cmd.length() - 1));
    if (command == "forward") {
      horizontal += distance;
      depth += aim * distance;
    } else if (command == "up") {
      aim -= distance;
    } else {
      aim += distance;
    }
  }
  return horizontal * depth;
}
