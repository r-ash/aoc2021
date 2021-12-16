#include <Rcpp.h>
#include <math.h>
#include <cctype>
#include "day_12.h"

struct Cave {
  std::string name;
  Cave(const std::string name): name(name) {}
  bool operator == (const Cave& p) const {
    return name == p.name;
  }
  bool is_end() {
    return name == "end";
  }
};

struct Connection {
  Cave cave1;
  Cave cave2;
  Connection(const Cave cave1, const Cave cave2): cave1(cave1), cave2(cave2) {}
  bool is_start() {
    return contains_cave(Cave("start"));
  }
  bool contains_cave(Cave cave) {
    return cave1 == cave || cave2 == cave;
  }
  Cave get_other_side(Cave cave) {
    if (cave == cave1) {
      return cave2;
    }
    return cave1;
  }
  // bool operator == (const Point& p) const {
  //   return row == p.row && col == p.col;
  // }
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
  Cave last;
  bool dead_end = false;
  bool complete = false;
  Path(const std::vector<Cave> visited, const Cave current): visited(visited), last(current) {
    visited.push_back(last);
    if (last.is_end()) {
      complete = true;
    }
  }
  bool can_visit(Cave cave) {
    return is_upper(cave.name) || std::find(visited.begin(), visited.end(), cave) == visited.end();
  }
  void add_cave(Cave cave) {
    visited.push_back(cave);
    last = cave;
    if (last.is_end()) {
      complete = true;
    }
  }
};


int get_num_paths(std::vector<std::vector<std::string>> connections) {
  std::vector<std::vector<std::string>> paths;
  while () {

  }
}

std::vector<Path> build_all(std::vector<Connection> connections, std::vector<Path> paths) {
  std::vector<Path> incomplete;
  std::vector<Path> complete;
  for (auto& path: paths) {
    if (!path.complete && !path.dead_end) {
      incomplete.push_back(path);
    } else {
      complete.push_back(path);
    }
  }
  if (complete.size() == paths.size()) {
    return paths;
  }
  // Here we should for each compatible other side
  // create multiple paths
  // return all of them
  // use recursion to build up all of the paths
  for (auto& path: incomplete) {
    bool dead_end = true;
    std::vector<Cave> other_side;
    for (Connection& con: connections) {
      if (con.contains_cave(path.last)) {
        Cave other = con.get_other_side(path.last);
        if (path.can_visit(other)) {
          other_side.push_back(other);
          path.add_cave(other);
          dead_end = false;
        }
      }
    }
    if (dead_end) {
      path.dead_end = true;
    }
  }
  std::vector<Path> finished =
}
