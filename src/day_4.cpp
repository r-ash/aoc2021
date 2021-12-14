#include <Rcpp.h>
#include <math.h>
#include "day_4.h"

Board::Board(std::vector<std::vector<int>> numbers) {
  rows = numbers;
  std::vector<std::vector<int>> trans(rows[0].size(), std::vector<int>(rows.size()));
  cols = trans;
  for (int i = 0; i < 5; ++i) {
    std::vector<int> col;
    for (int j = 0; j < 5; ++j) {
      cols[j][i] = rows[i][j];
    }
  }
}

std::vector<std::vector<int>> remove_num(std::vector<std::vector<int>> input, int number) {
  std::vector<std::vector<int>> out;
  for (int i = 0; i < input.size(); ++i) {
    std::vector<int> x = input[i];
    std::vector<int> new_x;
    for (int j = 0; j < x.size(); j++) {
      int val = x[j];
      if (val != number) {
        new_x.push_back(val);
      }
    }
    out.push_back(new_x);
  }
  return out;
}

void Board::blob_number(int number) {
  rows = remove_num(rows, number);
  cols = remove_num(cols, number);
  for (int i = 0; i < rows.size(); i++) {
    if (rows[i].size() == 0 || cols[i].size() == 0) {
      winning_number = number;
      has_won = true;
    }
  }
}

void Board::set_winning(int number) {
  winning_number = number;
}

int Board::get_score() {
  if (!has_won) {
    return 0;
  }
  int score = 0;
  for (auto& row: rows) {
    for (auto& i: row) {
      score += i;
    }
  }
  score *= winning_number;
  return score;
}

Game::Game(std::vector<int> _draws, std::vector<Board> _boards) {
  draws = _draws;
  boards = _boards;
}

int Game::winning_score() {
  for (auto& number: draws) {
    for (Board& board: boards) {
      board.blob_number(number);
      if (board.has_won) {
        return board.get_score();
      }
    }
  }
  return 0;
}

int Game::losing_score() {
  int last_score = 0;
  for (auto& number: draws) {
    for (Board& board: boards) {
      if (!board.has_won) {
        board.blob_number(number);
        if (board.has_won) {
          last_score = board.get_score();
        }
      }
    }
  }
  return last_score;
}

Game parse_game_input(std::vector<std::vector<int>> input) {
  std::vector<int> draws = input[0];
  // After stripping blank lines input has
  // draws
  // board 1
  // board 2
  // etc.
  // So we can use this to work out how may times we need to loop as each
  // board has 5 lines
  int num_boards = (input.size() - 1) / 5;
  std::vector<Board> boards;
  for (int i = 0; i < num_boards; i++) {
    std::vector<std::vector<int>>::const_iterator first = input.begin() + 1 + (i * 5);
    std::vector<std::vector<int>>::const_iterator last = input.begin() + 6 + (i * 5);
    std::vector<std::vector<int>> numbers(first, last);
    Board board(numbers);
    boards.push_back(board);
  }
  Game game(draws, boards);
  return game;
}

//' Print the winning bingo score
//'
//' @param input Puzzle input
//' @export
// [[Rcpp::export]]
int winning_score(std::vector<std::vector<int>> input) {
  Game game = parse_game_input(input);
  return game.winning_score();
}


//' Print the losing bingo score
//'
//' @param input Puzzle input
//' @export
// [[Rcpp::export]]
int losing_score(std::vector<std::vector<int>> input) {
  Game game = parse_game_input(input);
  return game.losing_score();
}
