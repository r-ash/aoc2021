#ifndef AOC_DAY_7_H
#define AOC_DAY_7_H

int optimal_position(std::vector<int> positions);
int position_cost(std::vector<int> positions, int alignment_position);

int triangular_number(int n);
int binary_search(std::vector<int> positions, int start_min, int min_cost,
                  int start_max, int max_cost);
int optimal_position_2(std::vector<int> positions);
int position_cost_2(std::vector<int> positions, int alignment_position);

#endif //AOC_DAY_7_H
