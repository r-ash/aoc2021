#ifndef AOC_DAY_8_H
#define AOC_DAY_8_H

class Display {
public:
  std::vector<std::array<std::string, 10>> inputs;
  std::vector<std::array<std::string, 4>> outputs;
  std::vector<std::map<std::string, int>> display_map;
  std::vector<std::string> one;
  std::vector<std::string> four;

  Display(std::vector<std::string> entries);

  int count_digits();
  int sum_output();

private:
  void build_display();
};

int count_digits(std::vector<std::string> entries);
int sum_readings(std::vector<std::string> entries);

#endif //AOC_DAY_8_H
