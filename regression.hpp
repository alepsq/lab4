#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <cassert>
#include <stdexcept>
#include <vector>
struct result {
  double A{};
  double B{};
};

class regression {
  struct Point {
    double x;
    double y;
  };

  std::vector<Point> points_{};

  
 public:
  void add(double x, double y);

  result fit() const;

  int size() const;
};

result fit(regression const &reg);

#endif