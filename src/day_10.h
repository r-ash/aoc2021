#ifndef AOC_DAY_10_H
#define AOC_DAY_10_H

bool is_pair(char open, char close);
int score_errors(std::vector<char> characters);
std::vector<char> get_corrupted(std::vector<std::string> nav_system);
int error_score(std::vector<std::string> nav_system);
std::vector<std::stack<char>> get_incomplete(std::vector<std::string> nav_system);
long score_autocomplete(std::vector<std::stack<char>> lines);
long autocomplete_score(std::vector<std::string> nav_system);

#endif //AOC_DAY_10_H
