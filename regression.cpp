#include "regression.hpp"

void regression::add(double x, double y) { points_.push_back({x, y}); }

result fit(regression const& reg) { return reg.fit(); }

result regression::fit() const {
  auto N_{points_.size()};
  if (N_ < 2) {
    throw std::runtime_error{"Not enough points to run a fit"};
  };

  double sum_x{};
  double sum_y{};
  double sum_xy{};
  double sum_x2{};

  for (auto const& p : points_) {
    sum_x += p.x;
    sum_y += p.y;
    sum_xy += p.x * p.y;
    sum_x2 += p.x * p.x;
  }

  double const d = N_ * sum_x2 - sum_x * sum_x;

  if (d == 0) {
    throw std::runtime_error{"Trying to build a vertical fit"};
  }

  double const a = (sum_y * sum_x2 - sum_x * sum_xy) / d;
  double const b = (N_ * sum_xy - sum_x * sum_y) / d;
  return {a, b};
}

int regression::size() const { return points_.size(); }
