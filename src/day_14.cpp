#include <Rcpp.h>
#include <math.h>
#include <string>
#include "day_14.h"

Polymer::Polymer(std::vector<std::string> input) {
  std::vector<std::string>::iterator it;
  bool passed_delim = false;
  for (it = input.begin(); it != input.end(); it++) {
    if (!passed_delim) {
      if ((*it) == "") {
        passed_delim = true;
        continue;
      }
      state = (*it);
    } else {
      std::stringstream row((*it));
      std::string segment;
      std::vector<std::string> seglist;
      while(std::getline(row, segment, ' ')) {
        seglist.push_back(segment);
      }
      std::string input_pair = seglist[0];
      std::string out_pair_1 = input_pair[0] + seglist[2];
      std::string out_pair_2 = seglist[2] + input_pair[1];
      rules[seglist[0]] = {out_pair_1, out_pair_2};
    }
  }

  std::map<std::string, std::array<std::string, 2>>::iterator rules_it;
  for (rules_it = rules.begin(); rules_it != rules.end(); rules_it++) {
    pair_counts[rules_it -> first] = 0;
  }

  for (int j = 0; j < state.size() - 1; j++) {
    std::string pair = state.substr(j, 2);
    if (rules.count(pair)) {
      if (pair_counts.count(pair)) {
        pair_counts[pair]++;
      } else {
        pair_counts[pair] = 1;
      }
    }
  }
}

void Polymer::run_step(int times) {
  for (int i = 0; i < times; i++) {
    std::map<std::string, long> updated_counts;
    std::map<std::string, std::array<std::string, 2>>::iterator rules_it;
    for (rules_it = rules.begin(); rules_it != rules.end(); rules_it++) {
      std::string in_pair = rules_it -> first;
      std::string out_pair_1 = (rules_it -> second)[0];
      std::string out_pair_2 = (rules_it -> second)[1];
      if (updated_counts.count(out_pair_1)) {
        updated_counts[out_pair_1] += pair_counts[in_pair];
      } else {
        updated_counts[out_pair_1] = pair_counts[in_pair];
      }
      if (updated_counts.count(out_pair_2)) {
        updated_counts[out_pair_2] += pair_counts[in_pair];
      } else {
        updated_counts[out_pair_2] = pair_counts[in_pair];
      }
    }
    pair_counts = updated_counts;
  }
}

long Polymer::count_polymer() {
  std::map<char, long> counts;
  std::map<std::string, long>::iterator it;
  for (it = pair_counts.begin(); it != pair_counts.end(); it++) {
    std::string pair = it -> first;
    long value = it -> second;
    if (counts.count(pair[0])) {
      counts[pair[0]] += value;
    } else {
      counts[pair[0]] = value;
    }
  }
  // Count only first from each pair, then have to add the last value in
  // sequence (which is same as initial state)
  counts[state[state.size() - 1]]++;
  long max = 0;
  long min = std::numeric_limits<long>::max();
  for (auto& value: counts) {
    long val = value.second;
    if (val < min) {
      min = val;
    }
    if (val > max) {
      max = val;
    }
  }
  return max - min;
}

//' Print the diff in size between most and least common element
//'
//' @param input Puzzle input
//' @export
// [[Rcpp::export]]
long polymer_size(std::vector<std::string> input, int times) {
  Polymer polymer(input);
  polymer.run_step(times);
  return polymer.count_polymer();
}
