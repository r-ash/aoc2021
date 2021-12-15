#include <Rcpp.h>
#include <math.h>
#include "day_15.h"


int min(std::vector<int> list) {
  int min = std::numeric_limits<double>::infinity();
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

// std::pair<int, int> get_min_dist(std::vector<std::pair<int, int>> vertices, std::map<std::pair<int, int>, int> distance) {
//   std::pair<int, int> min_v = vertices[0];
//   int min_d = std::numeric_limits<double>::infinity();
//   for (auto& v: vertices) {
//     if (distance[v] < min_d) {
//       min_d = distance[v];
//       min_v = v;
//     }
//   }
//   return min_v;
// }

// int djisktra(std::vector<std::vector<int>> graph) {
//   std::map<std::pair<int, int>, int> distance;
//   std::vector<std::pair<int, int>> vertices;
//   for (size_t i = 0; i < graph.size(); i++) {
//     for (size_t j = 0; j < graph[0].size(); j++) {
//       std::pair<int, int> vertex = std::make_pair(i, j);
//       distance[vertex] = std::numeric_limits<double>::infinity();
//       vertices.push_back(vertex);
//     }
//   }
//
//   std::pair<int, int> source = std::make_pair(0, 0);
//   distance[source] = 0;
//
//   while (!vertices.empty()) {
//     std::pair<int, int> u = get_min_dist(vertices, distance);
//     vertices
//   }
//   // function Dijkstra(Graph, source):
//   //   2
//   // 3      create vertex set Q
//   //   4
//   // 5      for each vertex v in Graph:
//   //   6          dist[v] ← INFINITY
//   //   7          prev[v] ← UNDEFINED
//   //   8          add v to Q
//   //   9      dist[source] ← 0
//   // 10
//   // 11      while Q is not empty:
//   //   12          u ← vertex in Q with min dist[u]
//   // 13
//   // 14          remove u from Q
//   //   15
//   // 16          for each neighbor v of u still in Q:
//   //   17              alt ← dist[u] + length(u, v)
//   //   18              if alt < dist[v]:
//   //     19                  dist[v] ← alt
//   //     20                  prev[v] ← u
//   //     21
//   //   22      return dist[], prev[]
// }

// Let the node at which we are starting at be called the initial node. Let the distance of node Y be the distance from the
// initial node to Y. Dijkstra's algorithm will initially start with infinite distances and will try to improve them step by step.
//
// Mark all nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.
// Assign to every node a tentative distance value: set it to zero for our initial node and to infinity
// for all other nodes. The tentative distance of a node v is the length of the shortest path discovered so far between
// the node v and the starting node. Since initially no path is known to any other vertex than the source itself (which
// is a path of length zero), all other tentative distances are initially set to infinity. Set the initial node as current.[15]

// For the current node, consider all of its unvisited neighbors and calculate their tentative distances
// through the current node. Compare the newly calculated tentative distance to the current assigned value and
// assign the smaller one. For example, if the current node A is marked with a distance of 6, and the edge
// connecting it with a neighbor B has length 2, then the distance to B through A will be 6 + 2 = 8. If B
// was previously marked with a distance greater than 8 then change it to 8. Otherwise, the current value will be kept.

// When we are done considering all of the unvisited neighbors of the current node, mark the current node as
// visited and remove it from the unvisited set. A visited node will never be checked again.

// If the destination node has been marked visited (when planning a route between two specific nodes)
// or if the smallest tentative distance among the nodes in the unvisited set is infinity (when planning a
// complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.
// Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new current node, and go back to step 3.

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
  std::vector<std::vector<int>> cumulative = get_cumulative_risk(full_risk);
  int min = cumulative[cumulative.size() - 1][cumulative[0].size() - 1];
  int i= 0;
  while(i < 100) {
    cumulative = get_cumulative_risk(cumulative);
    int val = cumulative[cumulative.size() - 1][cumulative[0].size() - 1];
    if (val < min) {
      min = val;
    }
    i++;
  }
  return min;
}
