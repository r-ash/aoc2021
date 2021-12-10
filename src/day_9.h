#ifndef AOC_DAY_9_H
#define AOC_DAY_9_H

std::vector<std::vector<int>> parse_height(std::vector<std::string> map);
std::vector<std::array<int, 2>> get_low_points(std::vector<std::vector<int>> parsed);
int risk_level(std::vector<std::string> map);
std::vector<std::array<int, 2>> fill_basin(std::vector<std::vector<int>> map, std::array<int, 2> point);
std::vector<std::vector<std::array<int, 2>>> locate_basins(
    std::vector<std::vector<int>> map, std::vector<std::array<int, 2>> low_points);
int basin_sizes(std::vector<std::string> map);

#endif //AOC_DAY_9_H
