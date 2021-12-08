#ifndef AOC_DAY_5_H
#define AOC_DAY_5_H

std::vector<std::array<int, 4>> get_coordinates(std::vector<std::string> vents);

class Vent {
public:
  std::vector<std::vector<int>> sea;

  Vent(std::vector<std::array<int, 4>> coordinates);

  void mark_dangerous(std::vector<std::array<int, 4>> coordinates,
                      bool incl_diagonal);
  int count_dangerous();
};

int count_dangerous_areas(std::vector<std::string> vents);
int count_dangerous_areas_2(std::vector<std::string> vents);

#endif //AOC_DAY_5_H
