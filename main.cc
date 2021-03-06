//  
// Created By Hikari Software
// 
// Y-Enterprise
// 
// 

#include <iostream>
#include "hart.h"
#include "gaussianhermite.h"
#include "multinormal.h"
#include <vector>
#include <array>

// using namespace std;

int main(int argc, char *argv[])
{
    // for(double i=-10.0;i<10.0;i+=0.1) {
        // std::cout << i << " : " << hart_cdf(i) << std::endl;
    // }
    // std::vector<std::array<int,2>> a(5,{1,2});
    // std::cout << a.size() << std::endl;
    // std::cout << a[3][1] << std::endl;
    // auto sample_weight = gaussian_hermite(96);
    // for(int i=0;i<96;++i) {
        // std::cout << sample_weight[i][0] << " : " << sample_weight[i][1] << std::endl;
    // }
    std::vector<double> x{0.0,0.0};
    // std::vector<double> beta{0.6,5.0 / 6.0};
    std::vector<double> beta{0.0, 1.0};
    std::cout << multivariate_normal_cdf(x, beta, 128) << std::endl;
    return 0;
}


