#include <vector>
#include <array>
#include <cstdint>

using SampleWeight = std::vector<std::array<double, 2>>;

SampleWeight gaussian_hermite(int32_t n);
