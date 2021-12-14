#ifndef AOC_DAY_14_H
#define AOC_DAY_14_H

class Polymer {
public:
  std::string state;
  std::map<std::string, long> pair_counts;
  std::map<std::string, std::array<std::string, 2>> rules;

  Polymer(std::vector<std::string> input);
  void run_step(int times);
  long count_polymer();
};

long polymer_size(std::vector<std::string> input, int times);

#endif //AOC_DAY_14_H
