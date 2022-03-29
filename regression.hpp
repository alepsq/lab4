#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <cassert>
#include <stdexcept>
struct result {
  double A{};
  double B{};
};

class regression {
  int N_{};
  double sum_x_{};
  double sum_y_{};
  double sum_x2_{};
  double sum_xy_{};

 public:
  void add(double x, double y);

  result fit() const;

  int size() const;
};

result fit(regression const &reg);

#endif