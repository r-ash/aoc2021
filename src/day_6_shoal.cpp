#include <bits/stdc++.h>
#include "day_6_shoal.h"

// [[Rcpp::plugins("cpp11")]]
Shoal::Shoal(std::vector<int> fish) {
  for (std::vector<int>::iterator it = fish.begin(); it != fish.end(); ++it) {
    fish_counts[*it]++;
  }
}

long Shoal::count_fish() {
  long total_fish = 0;
  for (std::vector<long>::iterator it = fish_counts.begin(); it != fish_counts.end(); ++it) {
    total_fish += *it;
  }
  return total_fish;
}

void Shoal::run_days(int days) {
  for (std::size_t i = 0; i < days; ++i) {
    run_day();
  }
}

void Shoal::run_day() {
  std::vector<long> next_generation(9, 0);
  for (std::size_t i = 0; i <= 7; ++i) {
    next_generation[i] = fish_counts[i + 1];
  }
  next_generation[8] = fish_counts[0];
  next_generation[6] += fish_counts[0];
  fish_counts = next_generation;
}
