#ifndef AOC_DAY_13_H
#define AOC_DAY_13_H

class Paper {
public:
  std::set<std::array<int, 2>> points;
  std::vector<std::string> orientation;
  std::vector<int> fold_lines;

  Paper(std::vector<std::string> input);
  void fold(int times);
};

std::set<std::array<int, 2>> input_to_points(std::vector<std::string> input);
int total_dots(std::vector<std::string> input);

#endif //AOC_DAY_13_H
