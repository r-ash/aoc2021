#include <Rcpp.h>
#include <math.h>
#include <queue>
#include "day_15.h"


int min(std::vector<int> list) {
  int min = std::numeric_limits<int>::infinity();
  for (auto elem: list) {
    if (elem < min) {
      min = elem;
    }
  }
  return min;
}

std::vector<std::vector<int>> get_cumulative_risk(std::vector<std::vector<int>> risk) {
  std::vector<int> v(risk[0].size(), 1000000);
  std::vector<std::vector<int>> cumulative(risk.size(), v);
  cumulative[0][0] = 0;
  // Going straight down, cumulative risk adds
  for (size_t i = 1; i < risk.size(); i++) {
    cumulative[i][0] = cumulative[i - 1][0] + risk[i][0];
  }

  // Going along column, cumulative risk adds
  for (size_t j = 1; j < risk[0].size(); j++) {
    cumulative[0][j] = cumulative[0][j - 1] + risk[0][j];
  }
  return get_cumulative_risk(risk, cumulative);
}

std::vector<std::vector<int>> get_cumulative_risk(std::vector<std::vector<int>> risk, std::vector<std::vector<int>> cumulative) {
  for (size_t i = 1; i < risk.size(); i++) {
    for (size_t j = 1; j < risk[0].size(); j++) {
      std::vector<int> compare;
      compare.push_back(cumulative[i - 1][j] + risk[i][j]);
      compare.push_back(cumulative[i][j - 1] + risk[i][j]);
      cumulative[i][j] = min(compare);
    }
  }
  return cumulative;
}

//' Get the min risk of traversing risk grid
//'
//' @param risk Vector of vector of ints of risk of moving to a space
//' @return The minimum total risk
//' @export
// [[Rcpp::export]]
int get_min_risk(std::vector<std::vector<int>> risk) {
  std::vector<std::vector<int>> cumulative = get_cumulative_risk(risk);
  return cumulative[risk.size() - 1][risk[0].size() - 1];
}

int get_risk_level(int input_risk, int repeat) {
  int value = input_risk + repeat;
  if (value > 9) {
    value = value - 9;
  }
  return value;
}

struct Point {
  int row, col;
  Point(const int row, const int col): row(row), col(col) {}
  bool operator == (const Point& p) const {
    return row == p.row && col == p.col;
  }
};

struct compare {
  bool operator () (const std::pair<Point, int>& p1, const std::pair<Point, int>& p2) const {
    return p1.second > p2.second;
  }
};

std::vector<Point> get_neighbours(Point p, int width, int height) {
  std::vector<Point> points;
  if (p.row > 0) {
    points.push_back(Point(p.row - 1, p.col));
  }
  if (p.col > 0) {
    points.push_back(Point(p.row, p.col - 1));
  }
  if (p.row < height - 1) {
    points.push_back(Point(p.row + 1, p.col));
  }
  if (p.col < width - 1) {
    points.push_back(Point(p.row, p.col + 1));
  }
  return points;
}

int djikstra(std::vector<std::vector<int>> graph) {
  int width = graph.size();
  int height = graph[0].size();
  std::map<Point, int> distance;
  Point point = Point(0, 0);
  std::priority_queue<std::pair<Point, int>, std::vector<std::pair<Point, int>>, compare> q;
  std::vector<Point> seen;
  q.emplace(point, 0);

  while (!q.empty()) {
    std::pair<Point, int> top = q.top();
    Point point = top.first;
    int cost = top.second;
    q.pop();
    if(point == Point(width - 1, height - 1)) {
      // We're at the end, return the cost of getting here
      return cost;
    }
    for (Point& neighbour: get_neighbours(point, width, height)) {
      int x = graph[neighbour.row][neighbour.col] + cost;
      if (std::find(seen.begin(), seen.end(), neighbour) == seen.end()) {
        q.emplace(neighbour, x);
        seen.push_back(neighbour);
      }
    }
  }
  return 0;
}

// function Dijkstra(Graph, source):
//   2      dist[source] ← 0                           // Initialization
// 3
// 4      create vertex priority queue Q
//   5
// 6      for each vertex v in Graph:
//   7          if v ≠ source
//     8              dist[v] ← INFINITY                 // Unknown distance from source to v
//     10
//   11         Q.add_with_priority(v, dist[v])
//     12
//   13
//   14     while Q is not empty:                      // The main loop
//     15         u ← Q.extract_min()                    // Remove and return best vertex
//     16         for each neighbor v of u:              // only v that are still in Q
//       17             alt ← dist[u] + length(u, v)
//       18             if alt < dist[v]
//       19                 dist[v] ← alt
//         21                 Q.decrease_priority(v, alt)
//         22
//       23     return dist, prev

std::vector<std::vector<int>> construct_full_map(std::vector<std::vector<int>> risk) {
  std::vector<int> v(risk[0].size() * 5, 0);
  std::vector<std::vector<int>> full_risk(risk.size() * 5, v);
  // Repeat right
  for (size_t repeat = 0; repeat < 5; repeat++) {
    for (size_t i = 0; i < risk.size(); i++) {
      for (size_t j = 0; j < risk[0].size(); j++) {
        int risk_level = get_risk_level(risk[i][j], repeat);
        full_risk[repeat * risk.size() + i][j] = risk_level;
      }
    }
  }
  // Copy down
  for (size_t repeat = 0; repeat < 5; repeat++) {
    for (size_t i = 0; i < full_risk.size(); i++) {
      for (size_t j = 0; j < risk[0].size(); j++) {
        int risk_level = get_risk_level(full_risk[i][j], repeat);
        full_risk[i][repeat * risk[0].size() + j] = risk_level;
      }
    }
  }
  return full_risk;
}

//' Get the min risk of traversing full risk grid
//'
//' @param risk Vector of vector of ints of risk of moving to a space
//' @return The minimum total risk
//' @export
// [[Rcpp::export]]
int get_min_total_risk(std::vector<std::vector<int>> risk) {
  std::vector<std::vector<int>> full_risk = construct_full_map(risk);
  return djikstra(full_risk);
}
