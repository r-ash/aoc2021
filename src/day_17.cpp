#include <Rcpp.h>
#include <math.h>
#include "day_17.h"

struct Probe {
  int initial_x = 0;
  int initial_y = 0;
  int x = 0;
  int y = 0;
  int highest_y = 0;
  int velocity_x;
  int velocity_y;
  std::pair<int, int> x_limits;
  std::pair<int, int> y_limits;
  bool hit_target = false;
  bool overshot = false;
  Probe(int velocity_x, int velocity_y, std::pair<int, int> x_limits,
        std::pair<int, int> y_limits): velocity_x(velocity_x), velocity_y(velocity_y),
        x_limits(x_limits), y_limits(y_limits), initial_x(velocity_x), initial_y(velocity_y) {}
  void step() {
    if (hit_target || overshot) {
      return;
    }
    x += velocity_x;
    y += velocity_y;
    if (y > highest_y) {
      highest_y = y;
    }
    if (velocity_x > 0) {
      velocity_x--;
    } else if (velocity_x < 0) {
      velocity_x++;
    }
    velocity_y--;
    hit_target = in_target_zone();
    overshot = has_overshot();
  }
  bool in_target_zone() {
    return x >= x_limits.first && x <= x_limits.second &&
      y >= y_limits.first && y <= y_limits.second;
  }
  bool has_overshot() {
    return x > std::max(x_limits.first, x_limits.second) || y < std::min(y_limits.first, y_limits.second);
  }
};

std::vector<int> get_velocity_bounds(std::pair<int, int> x_lim, std::pair<int, int> y_lim) {
  int x_lower;
  int x_upper;
  int y_lower;
  int y_upper;
  // Assuming x region is +ve
  x_lower = 0;
  x_upper = x_lim.second;
  // Assuming y region is -ve
  // We should do this in a smarter way
  y_lower = y_lim.first;
  y_upper = 500;
  return {x_lower, x_upper, y_lower, y_upper};
}


//' Get the path which reaches the highest point and still lands in
//' target area
//'
//' @param limits Vector of size 4 containing x and y upper and lower limits
//' @return The highest point which lands in target area
//' @export
// [[Rcpp::export]]
int get_highest_path(std::vector<int> limits) {
  std::pair<int, int> x_lim;
  if (limits[0] < limits[1]) {
    x_lim = std::make_pair(limits[0], limits[1]);
  } else {
    x_lim = std::make_pair(limits[1], limits[0]);
  }
  std::pair<int, int> y_lim;
  if (limits[2] < limits[3]) {
    y_lim = std::make_pair(limits[2], limits[3]);
  } else {
    y_lim = std::make_pair(limits[3], limits[2]);
  }
  std::vector<int> bounds = get_velocity_bounds(x_lim, y_lim);
  std::vector<Probe> probes;
  for (int i = bounds[0]; i <= bounds[1]; i++) {
    for (int j = bounds[2]; j <= bounds[3]; j++) {
      probes.push_back(Probe(i, j, x_lim, y_lim));
    }
  }
  int highest_y = 0;
  for (auto& probe: probes) {
    while (!probe.hit_target && !probe.overshot) {
      probe.step();
    }
    if (probe.hit_target && probe.highest_y > highest_y) {
      highest_y = probe.highest_y;
    }
  }
  return highest_y;
}

//' Get the number of initial velocities which hit target area
//'
//' @param limits Vector of size 4 containing x and y upper and lower limits
//' @return The highest point which lands in target area
//' @export
// [[Rcpp::export]]
int get_no_initial_velocities(std::vector<int> limits) {
  std::pair<int, int> x_lim;
  if (limits[0] < limits[1]) {
    x_lim = std::make_pair(limits[0], limits[1]);
  } else {
    x_lim = std::make_pair(limits[1], limits[0]);
  }
  std::pair<int, int> y_lim;
  if (limits[2] < limits[3]) {
    y_lim = std::make_pair(limits[2], limits[3]);
  } else {
    y_lim = std::make_pair(limits[3], limits[2]);
  }
  std::vector<int> bounds = get_velocity_bounds(x_lim, y_lim);
  std::vector<Probe> probes;
  for (int i = bounds[0]; i <= bounds[1]; i++) {
    for (int j = bounds[2]; j <= bounds[3]; j++) {
      probes.push_back(Probe(i, j, x_lim, y_lim));
    }
  }
  int hit_target = 0;
  for (auto& probe: probes) {
    while (!probe.hit_target && !probe.overshot) {
      probe.step();
    }
    if (probe.hit_target) {
      hit_target++;
    }
  }
  return hit_target;
}
