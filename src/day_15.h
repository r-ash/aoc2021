#ifndef AOC_DAY_15_H
#define AOC_DAY_15_H

int min(std::vector<int> list);
std::vector<std::vector<int>> get_cumulative_risk(std::vector<std::vector<int>> risk);
std::vector<std::vector<int>> get_cumulative_risk(std::vector<std::vector<int>> risk, std::vector<std::vector<int>> cumulative);
int get_min_risk(std::vector<std::vector<int>> risk);

int get_risk_level(int input_risk, int repeat);
std::vector<std::vector<int>> construct_full_map(std::vector<std::vector<int>> risk);
int get_min_risk(std::vector<std::vector<int>> risk);

#endif //AOC_DAY_15_H
