#ifndef AOC_DAY_11_H
#define AOC_DAY_11_H

class Octopus {
public:
  int energy;
  bool has_flashed = false;

  Octopus(int energy);
  void increase_energy();
  void reset_energy();
};

class OctoGrid {
public:
  std::vector<std::vector<Octopus>> grid;
  int width = 10;
  int height = 10;
  int total_flashed = 0;
  int step = 0;
  std::vector<int> all_flashed;

  OctoGrid(std::vector<std::string> octopuses);
  void run_day();
  void increase_energy(int i, int j);
  void count_and_reset();
};


int total_flashes(std::vector<std::string> octopuses);
int get_first_all_flash(std::vector<std::string> octopuses, int steps);

#endif //AOC_DAY_11_H
