#include <Rcpp.h>
#include <math.h>
#include "day_6.h"
#include "day_6_shoal.h"

//' Model fish internal timers for a number of days for some initial fish state.
//'
//' @param fish Vector of fish internal timers
//' @param days The number of days to run
//' @return The final state of fish internal timers
//' @export
// [[Rcpp::export]]
std::vector<int> model_fish(std::vector<int> fish, int days) {
  for (std::size_t i = 1; i <= days; ++i) {
    fish = run_day(fish);
  }
  return fish;
}

//' Run a single day through fish timer.
//'
//' Take a vector of fish timers, reduce their values by 1 or if 0
//' reset timer to 6. If timer was reset, add a new fish to the end
//' with start timer of 8.
//'
//' @param fish Vector of fish internal timers
//' @return The final state of fish internal timers
//' @export
// [[Rcpp::export]]
std::vector<int> run_day(std::vector<int> fish) {
  std::size_t size = fish.size();
  for (std::size_t i = 0; i < size; ++i) {
    if (fish[i] == 0) {
      fish[i] = 6;
      fish.push_back(8);
    } else {
      fish[i] -= 1;
    }
  }
  return fish;
}

//' Count the number of fish after a number of days from some internal state
//'
//' @param fish Vector of fish internal timers
//' @param days The number of days to run
//' @return The final number of fish
//' @export
// [[Rcpp::export]]
int count_fish(std::vector<int> fish, int days) {
  std::vector<int> final_fish = model_fish(fish, days);
  return final_fish.size();
}

//' Count the number of fish after a number of days from some internal state
//'
//' @param fish Vector of fish internal timers
//' @param days The number of days to run
//' @return The final number of fish
//' @export
// [[Rcpp::export]]
long count_fish_class(std::vector<int> fish, int days) {
  Shoal shoal {fish};
  shoal.run_days(days);
  return shoal.count_fish();
}
