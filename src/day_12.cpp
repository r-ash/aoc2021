#include <Rcpp.h>
#include <math.h>
#include <cctype>
#include <ostream>
#include "day_12.h"

struct Cave {
  std::string name;
  Cave(const std::string name): name(name) {}
  bool operator == (const Cave& p) const {
    return name == p.name;
  }
  bool is_start() {
    return name == "start";
  }
  bool is_end() {
    return name == "end";
  }
  friend std::ostream &operator<<(std::ostream &os, const Cave &cave) {
    return os << cave.name;
  }
};

struct Connection {
  Cave cave1;
  Cave cave2;
  Connection(const Cave cave1, const Cave cave2): cave1(cave1), cave2(cave2) {}
  bool contains_cave(Cave cave) {
    return cave1 == cave || cave2 == cave;
  }
  Cave get_other_side(Cave cave) {
    if (cave == cave1) {
      return cave2;
    }
    return cave1;
  }
};

bool is_upper(std::string s) {
  for (auto& c: s) {
    if (!std::isupper(c)) {
      return false;
    }
  }
  return true;
}

struct Path {
  std::vector<Cave> visited;
  int small_caves;
  Cave last;
  bool dead_end = false;
  bool complete = false;
  Path(std::vector<Cave> _visited, Cave _last, int _small_caves):
    visited(_visited), last(_last), small_caves(_small_caves) {
    visited.push_back(last);
    if (last.is_end()) {
      complete = true;
    }
    if (!is_upper(last.name) && small_caves > 1) {
      int times_visited = std::count(visited.begin(), visited.end(), last);
      if (times_visited == 2) {
        // Once we've visited 1 small cave twice, can't do it again
        // this is a bit ugly but just want to get an answer
        small_caves = 1;
      }
    }
  }
  bool can_visit(Cave cave) {
    return is_upper(cave.name) ||
      (!cave.is_start() && std::count(visited.begin(), visited.end(), cave) < small_caves);
  }
  friend std::ostream &operator<<(std::ostream &os, const Path &path) {
    for (auto& cave: path.visited) {
      os << cave << ",";
    }
    return os;
  }
};

std::vector<Path> build_all(std::vector<Connection> connections, std::vector<Path> paths) {
  std::vector<Path> all_paths;
  for (auto& path: paths) {
    std::vector<Cave> possible_moves;
    for (Connection& con: connections) {
      if (con.contains_cave(path.last)) {
        Cave other = con.get_other_side(path.last);
        if (path.can_visit(other)) {
          possible_moves.push_back(other);
        }
      }
    }
    if (possible_moves.size() == 0) {
      path.dead_end = true;
    } else {
      for (auto& cave: possible_moves) {
        Path further_path = Path(path.visited, cave, path.small_caves);
        all_paths.push_back(further_path);
      }
    }
  }
  std::vector<Path> incomplete;
  std::vector<Path> complete;
  for (auto& path: all_paths) {
    if (!path.complete && !path.dead_end) {
      incomplete.push_back(path);
    } else {
      complete.push_back(path);
    }
  }
  if (complete.size() == all_paths.size()) {
    return complete;
  }
  std::vector<Path> finished = build_all(connections, incomplete);
  for (auto& path: finished) {
    complete.push_back(path);
  }
  return complete;
}

//' Get the number of complete paths through caves
//'
//' @param commands Vector of size 2 vectors, showing connections from caves
//' @param small_caves The number of times you can visit a small cave
//' @param verbose If TRUE print the completed paths
//' @return The total number of complete caves
//' @export
// [[Rcpp::export]]
int get_num_paths(std::vector<std::vector<std::string>> connections,
                  int small_caves, bool verbose) {
  std::vector<Connection> cons;
  for (auto& connection: connections) {
    cons.push_back(Connection(Cave(connection[0]), Cave(connection[1])));
  }
  Cave start = Cave("start");
  Path start_path = Path({}, start, small_caves);
  std::vector<Path> paths = {start_path};
  std::vector<Path> all = build_all(cons, paths);
  std::vector<Path> completed;
  for (auto& path: all) {
    if (verbose) {
      std::cout << "completed path " << path << "\n";
    }
    if (path.complete) {
      completed.push_back(path);
    }
  }
  return completed.size();
}
