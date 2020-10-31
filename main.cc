//  
// Created By Hikari Software
// 
// Y-Enterprise
// 
// 

#include <iostream>
#include "hart.h"
#include "gaussianhermite.h"
#include <vector>
#include <array>

// using namespace std;

int main(int argc, char *argv[])
{
    // for(double i=-10.0;i<10.0;i+=0.1) {
        // std::cout << i << " : " << hart_cdf(i) << std::endl;
    // }
    std::vector<std::array<int,2>> a(5,{1,2});
    std::cout << a.size() << std::endl;
    std::cout << a[3][1] << std::endl;
    auto sample_weight = gaussian_hermite(96);
    for(int i=0;i<96;++i) {
        std::cout << sample_weight[i][0] << " : " << sample_weight[i][1] << std::endl;
}
    return 0;
}


