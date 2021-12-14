#include <Rcpp.h>
#include <math.h>
#include <string>
#include "day_11.h"

Octopus::Octopus(int _energy) {
  energy = _energy;
}

void Octopus::increase_energy() {
  energy++;
  if (energy > 9) {
    has_flashed = true;
  }
}

void Octopus::reset_energy() {
  energy = 0;
  has_flashed = false;
}

OctoGrid::OctoGrid(std::vector<std::string> octopuses) {
  for (int i = 0; i < width; i++) {
    std::vector<Octopus> row;
    for (int j = 0; j < height; j++) {
      Octopus oct {(int)(octopuses[i][j]) - 48};
      row.push_back(oct);
    }
    grid.push_back(row);
  }
}

void OctoGrid::increase_energy(int i, int j) {
  if (grid[i][j].has_flashed) {
    return;
  }
  grid[i][j].increase_energy();
  if (grid[i][j].has_flashed) {
    if (i > 0) {
      increase_energy(i - 1, j);
    }
    if (i < 9) {
      increase_energy(i + 1, j);
    }
    if (j > 0) {
      increase_energy(i, j - 1);
    }
    if (j < 9) {
      increase_energy(i, j + 1);
    }
    if (i > 0 && j > 0) {
      increase_energy(i - 1, j - 1);
    }
    if (i > 0 && j < 9) {
      increase_energy(i - 1, j + 1);
    }
    if (i < 9 && j > 0) {
      increase_energy(i + 1, j - 1);
    }
    if (i < 9 && j < 9) {
      increase_energy(i + 1, j + 1);
    }
  }
}

void OctoGrid::count_and_reset() {
  int day_flashed = 0;
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if (grid[i][j].has_flashed) {
        day_flashed++;
        total_flashed++;
        grid[i][j].reset_energy();
      }
    }
  }
  if (day_flashed == 100) {
    all_flashed.push_back(step);
  }
}

void OctoGrid::run_day() {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      increase_energy(i, j);
    }
  }
  step++;
  count_and_reset();
}


//' Count the number of times grid of octopuses flashed
//'
//' @param octopuses Grid of octopuses
//' @param steps The number of steps to run
//' @return The total number of times an octopus flashed
//' @export
// [[Rcpp::export]]
int get_flashes(std::vector<std::string> octopuses, int steps) {
  OctoGrid grid {octopuses};
  for (int i = 0; i < steps; i++) {
    grid.run_day();
  }
  return grid.total_flashed;
}

//' Get the first day all octopuses flash
//'
//' @param octopuses Grid of octopuses
//' @param steps The number of steps to run
//' @return The first day all octopuses flash
//' @export
// [[Rcpp::export]]
int get_first_all_flash(std::vector<std::string> octopuses, int steps) {
  // This shouldn't really need to take steps arg, we should run until we find
  // the answer, but in the interest of getting the answer quickly let's
  // just run this with a high number
  OctoGrid grid {octopuses};
  for (int i = 0; i < steps; i++) {
    grid.run_day();
  }
  int first = 0;
  if (grid.all_flashed.size() > 0) {
    first = grid.all_flashed[0];
  }
  return first;
}
