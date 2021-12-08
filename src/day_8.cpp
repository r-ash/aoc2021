#include <Rcpp.h>
#include <math.h>
#include <string>
#include <regex>
#include <algorithm>
#include <initializer_list>
#include "day_8.h"

Display::Display(std::vector<std::string> entries) {
  std::vector<std::string>::iterator it;
  std::regex rgx("\\w+");
  std::smatch match;
  for (it = entries.begin(); it != entries.end(); it++) {
    std::array<std::string, 10> input;
    std::array<std::string, 4> output;
    int index = 0;
    std::string::const_iterator start_search( (*it).cbegin() );
    while (regex_search(start_search, (*it).cend(), match, rgx) && index < 14) {
      if (index <= 9) {
        input[index] = match[0];
      } else {
        output[index - 10] = match[0];
      }
      index++;
      start_search = match.suffix().first;
    }
    inputs.push_back(input);
    outputs.push_back(output);
  }
  build_display();
}

//' Check if string b is in a, in any order.
//'
//' @param a superstring
//' @param b substring to test.
//' @return true if all characters in b are in a
//' @export
// [[Rcpp::export]]
bool str_in(std::string a, std::string b) {
  bool contains = true;
  std::string::size_type i = 0;
  while (contains && i < b.size()) {
    contains = contains && a.find(b[i]) != std::string::npos;
    i++;
  }
  return contains;
}

//' Remove characters of b from a.
//'
//' @param a string to remove from
//' @param b the string to remove
//' @return String a with characters from b removed
//' @export
// [[Rcpp::export]]
std::string str_diff(std::string a, std::string b) {
  for (char& c : b) {
    a.erase(std::remove(a.begin(), a.end(), c), a.end());
  }
 return a;
}

void Display::build_display() {
  std::vector<std::array<std::string, 10>>::iterator it;
  int i = 0;
  for (it = inputs.begin(); it != inputs.end(); it++) {
    std::map<std::string, int> display;
    std::array<std::string, 10> input = (*it);
    std::array<std::string, 10>::iterator str_it;
    // We can read out 1, 7, 4 and 8 on first pass
    for (str_it = input.begin(); str_it != input.end(); str_it++) {
      std::string str = (*str_it);
      int len = str.length();
      if (len == 2) {
        display[str] = 1;
        one.push_back(str);
      } else if (len == 3) {
        display[str] = 7;
      } else if (len == 4) {
        display[str] = 4;
        four.push_back(str);
      } else if (len == 7) {
        display[str] = 8;
      }
    }

    // Get remaining characters
    for (str_it = input.begin(); str_it != input.end(); str_it++) {
      std::string str = (*str_it);
      int len = str.length();
      if (len == 6) {
        // Either 9, 6 or 0
        // 9 display is superset of 4 display 6 & 0 are not
        // 0 display is superset of 1 display 9 & 6 are not
        // 6 is left over
        if (str_in(str, four[i])) {
          display[str] = 9;
        } else if (str_in(str, one[i])) {
          display[str] = 0;
        } else {
          display[str] = 6;
        }
      } else if (len == 5) {
        // either 2, 3 or 5
        // 3 is superset of 1 display 2 & 1 are not
        // set diff of 4, 1 gives b & d wires
        // b & d are in 5, not in 2
        std::string b_d = str_diff(four[i], one[i]);
        if (str_in(str, one[i])) {
          display[str] = 3;
        } else if (str_in(str, b_d)) {
          display[str] = 5;
        } else {
          display[str] = 2;
        }
      }
    }
    i++;
    display_map.push_back(display);
  }
}

// A map is probably not the best data structure to use here, but
// have spent too long on this to go refactor
int get_from_map(std::map<std::string, int> map, std::string x) {
  std::map<std::string, int>::iterator it = map.begin();
  int out;
  bool found = false;
  while (!found && it != map.end()) {
    std::string key = it->first;
    if (str_in(key, x) && str_in(x, key)) {
      out = it->second;
      found = true;
    }
    it++;
  }
  return out;
}

int Display::sum_output() {
  int total_value = 0;
  for (std::size_t i = 0; i < outputs.size(); i++) {
    std::array<std::string, 4> output = outputs[i];
    int value = get_from_map(display_map[i], output[0]) * 1000 +
      get_from_map(display_map[i], output[1]) * 100 +
      get_from_map(display_map[i], output[2]) * 10 +
      get_from_map(display_map[i], output[3]);
    total_value += value;
  }
  return total_value;
}

int Display::count_digits() {
  std::vector<std::array<std::string, 4>>::iterator it;
  int total_digits = 0;
  for (it = outputs.begin(); it != outputs.end(); it++) {
    std::array<std::string, 4>::iterator str_it;
    for (str_it = (*it).begin(); str_it != (*it).end(); str_it++) {
      int len = (*str_it).length();
      if (len == 2 || len == 3 || len == 4 || len == 7) {
        total_digits++;
      }
    }
  }
  return total_digits;
}

//' Count the number of times 1, 4, 7 or 8 appear in log entries
//'
//' @param entries Log entries of form 10 signal patterns | delimitter and
//'   4 output values
//' @return The number of times 1, 4, 7 or 8 appear
//' @export
// [[Rcpp::export]]
int count_digits(std::vector<std::string> entries) {
  Display display {entries};
  return display.count_digits();
}

//' Count the number of times 1, 4, 7 or 8 appear in log entries
//'
//' @param entries Log entries of form 10 signal patterns | delimitter and
//'   4 output values
//' @return The number of times 1, 4, 7 or 8 appear
//' @export
// [[Rcpp::export]]
int sum_readings(std::vector<std::string> entries) {
  Display display {entries};
  return display.sum_output();
}
