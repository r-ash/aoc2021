#include <Rcpp.h>
#include <math.h>
#include <string>
#include <stack>
#include "day_10.h"

bool is_pair(char open, char close) {
  bool is_pair = false;
  if (open == '(') {
    is_pair = close == ')';
  } else if (open == '[') {
    is_pair = close == ']';
  } else if (open == '{') {
    is_pair = close == '}';
  } else {
    is_pair = close == '>';
  }
  return is_pair;
}

std::vector<char> get_corrupted(std::vector<std::string> nav_system) {
  std::vector<char> corrupted_characters;
  for (auto& line: nav_system) {
    std::stack<char> open;
    for (char i: line) {
      if (i == '(' || i == '[' || i == '{' || i == '<') {
        open.push(i);
      } else {
        // Is a closing bracket
        char last = open.top();
        if (!is_pair(last, i)) {
          corrupted_characters.push_back(i);
          break;
        }
        open.pop();
      }
    }
  }
  return corrupted_characters;
}

int score_errors(std::vector<char> characters) {
  int points= 0;
  for (auto& it: characters) {
    if (it == ')') {
      points += 3;
    } else if (it == ']') {
      points += 57;
    } else if (it == '}') {
      points += 1197;
    } else if (it == '>') {
      points += 25137;
    }
  }
  return points;
}

//' Get the error score from nav system.
//'
//' @param commands Vector of nav system entries
//' @return The syntax error score
//' @export
// [[Rcpp::export]]
int error_score(std::vector<std::string> nav_system) {
  std::vector<char> corrupted_chars = get_corrupted(nav_system);
  return score_errors(corrupted_chars);
}

std::vector<std::stack<char>> get_incomplete(std::vector<std::string> nav_system) {
  std::vector<std::stack<char>> incomplete;
  for (auto& line: nav_system) {
    std::stack<char> open;
    bool is_corrupt = false;
    for (char i: line) {
      if (i == '(' || i == '[' || i == '{' || i == '<') {
        open.push(i);
      } else {
        // Is a closing bracket
        char last = open.top();
        if (!is_pair(last, i)) {
          is_corrupt = true;
          break;
        }
        open.pop();
      }
    }
    if (!is_corrupt && open.size() > 0) {
      incomplete.push_back(open);
    }
  }
  return incomplete;
}

long median(std::vector<long> &v) {
  size_t n = v.size() / 2;
  nth_element(v.begin(), v.begin() + n, v.end());
  return v[n];
}

long score_autocomplete(std::vector<std::stack<char>> lines) {
  std::vector<long> all_points;
  for (std::stack<char> stack: lines) {
    long points = 0;
    while (!stack.empty()) {
      char character = stack.top();
      stack.pop();
      if (character == '(') {
        points = points * 5 + 1;
      } else if (character == '[') {
        points = points * 5 + 2;
      } else if (character == '{') {
        points = points * 5 + 3;
      } else if (character) {
        points = points * 5 + 4;
      }
    }
    all_points.push_back(points);
  }

  return median(all_points);
}

//' Get the autocomplete from nav system.
//'
//' @param commands Vector of nav system entries
//' @return The autocomplete score
//' @export
// [[Rcpp::export]]
long autocomplete_score(std::vector<std::string> nav_system) {
  std::vector<std::stack<char>> incomplete = get_incomplete(nav_system);
  return score_autocomplete(incomplete);
}
