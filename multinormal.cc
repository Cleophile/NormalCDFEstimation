//  
// Created By Hikari Software
// 
// Y-Enterprise
// 
// 

#include "multinormal.h"
#include "hart.h"
#include "gaussianhermite.h"
#include <cmath>
#include <cassert>

double multivariate_normal_cdf(std::vector<double> x, std::vector<double> beta, int32_t precision) {
    const int32_t m = x.size();
    assert(m == beta.size());
    const auto sample_weight = gaussian_hermite(precision);
    double integrated = 0.0;
    for(const auto sw : sample_weight)  {
        double prod = 1.0;
        for(int32_t i=0;i<m;++i) {
            prod *= hart_cdf((x[i] - beta[i]*sw[0]*M_SQRT2) / sqrt(1 - beta[i]*beta[i]));
        }
        integrated += prod*sw[1];
    }
    return integrated * M_2_SQRTPI / 2;
}
