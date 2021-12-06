#ifndef AOC_DAY_6_SHOAL_H
#define AOC_DAY_6_SHOAL_H

class Shoal {
public:
  // Reserve space for 9 items, each one represents fish internal counter
  // 0 to 9. Values are number of fish with that counter
  std::vector<long> fish_counts = std::vector<long>(9, 0);

  Shoal(std::vector<int> fish);
  long count_fish();
  void run_days(int days);

private:
  void run_day();
};

#endif //AOC_DAY_6_SHOAL_H
