#include <Rcpp.h>
#include <math.h>
#include "day_4.h"

Board::Board(std::vector<std::vector<int>> numbers) {
  rows = numbers;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cols[j][i]= rows[i][j];
    }
  }
}

void Board::blob_number(int number) {
  std::vector<std::vector<int>> new_rows = rows;
  std::vector<std::vector<int>> new_cols = cols;
  for (int i = 0; i < rows.size(); ++i) {
    std::vector<int> row = new_rows[i];
    remove(row.begin(), row.end(), number);
  }
  for (int j = 0; j < cols.size(); ++j) {
    std::vector<int> col = new_cols[j];
    remove(col.begin(), col.end(), number);
  }
  rows = new_rows;
  cols = new_cols;
}
