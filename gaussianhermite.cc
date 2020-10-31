//  
// Created By Hikari Software
// 
// Y-Enterprise
// 
// 

#include "gaussianhermite.h"
#include <cmath>

SampleWeight gaussian_hermite(int32_t n) {
    int32_t m = (n+1) / 2;
    // (x0,w0),(x1,w1),...
    SampleWeight sample_weight(n, {0.0,0.0});
    double z = 0.0;
    for(int32_t i=1;i<=m;++i) {
        switch(i) {
            case 1:
                z = sqrt(static_cast<double>(2*n+1)) - 1.85575 * pow((2 * n + 1), (-0.16667));
                break;
            case 2:
                z = z - 1.14 * pow(n, 0.426) / z;
                break;
            case 3:
                z = 1.86 * z - 0.86 * sample_weight[0][0];
                break;
            case 4:
                z = 1.91 * z - 0.91 * sample_weight[1][0];
                break;
            default:
                z=2.0*z-sample_weight[i-3][0];
                break;
        }
        double pp = 0.0;
        for(int32_t k=1;k<=10;++k) {
            double p1=0.751125544464943;
            double p2=0.0;
            double p3=0.0;
            for(int32_t j=1;j<=n;++j) {
                p3=p2;
                p2=p1;
                p1=z * sqrt(2.0 / j) * p2 - sqrt((j - 1.0) / j) * p3;
            }
            pp=sqrt(2.0 * n) * p2;
            double z1=z;
            z=z1-p1/pp;
            if(abs(z-z1)<=0.00000000000003) {
                break;
            }
        }
        sample_weight[i - 1][0] = z;
        sample_weight[n - i][0] = -z;
        sample_weight[i - 1][1] = 2.0 / (pp*pp);
        sample_weight[n - i][1] = sample_weight[i-1][1];
    }
    return sample_weight;
}
