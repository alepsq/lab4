#include "regression.hpp"

void regression::add(double x, double y) { points_.push_back({x, y}); }

result fit(regression const &reg) { return reg.fit(); }

result regression::fit() const {
  assert(N_ == points_.size());
  if (N_ < 2) {
    throw std::runtime_error{"Not enough points to run a fit"};
  };

  double const d = N_ * sum_x2_ - sum_x_ * sum_x_;

  if (d == 0) {
    throw std::runtime_error{"Trying to build a vertical fit"};
  }

  double const a = (sum_y_ * sum_x2_ - sum_x_ * sum_xy_) / d;
  double const b = (N_ * sum_xy_ - sum_x_ * sum_y_) / d;
  return {a, b};
}

int regression::size() const {
  assert(N_ == points_.size());
  return N_;
}
