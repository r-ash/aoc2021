#ifndef AOC_DAY_4_H
#define AOC_DAY_4_H

class Board {
public:
  std::vector<std::vector<int>> rows;
  std::vector<std::vector<int>> cols;
  bool has_won = false;
  int winning_number;

  Board(std::vector<std::vector<int>> numbers);
  void blob_number(int number);
  int get_score();
  void set_winning(int number);
};

class Game {
public:
  std::vector<Board> boards;
  std::vector<int> draws;

  Game(std::vector<int> _draws, std::vector<Board> _boards);
  int winning_score();
  int losing_score();
};

int winning_score(std::vector<std::vector<int>> input);
int losing_score(std::vector<std::vector<int>> input);

#endif //AOC_DAY_4_H
