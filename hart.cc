//  
// Created By Hikari Software
// 
// Y-Enterprise
// 
// 

#include "hart.h"
#include <cmath>

double hart_cdf(const double x) {
    double x_abs = x;
    if(x < 0) {
        x_abs = -x;
    }
    double cum_norm = 0;
    if(x_abs > 37) {
        if(x < -37) {
            return 0;
        }
        return 1;
    }
    double expo_x = exp(-x_abs*x_abs / 2);
    if(x_abs < 7.07106781186547) {
        double build = 3.52624965998911E-02 * x_abs + 0.700383064443688;

        build = build * x_abs + 6.37396220353165;
        build = build * x_abs + 33.912866078383;
        build = build * x_abs + 112.079291497871;
        build = build * x_abs + 221.213596169931;
        build = build * x_abs + 220.206867912376;

        cum_norm = expo_x * build;

        build = 8.83883476483184E-02 * x_abs + 1.75566716318264;
        build = build * x_abs + 16.064177579207;
        build = build * x_abs + 86.7807322029461;
        build = build * x_abs + 296.564248779674;
        build = build * x_abs + 637.333633378831;
        build = build * x_abs + 793.826512519948;
        build = build * x_abs + 440.413735824752;
        cum_norm /= build;
    }
    else {
        double build = x_abs + 0.65;
        build = x_abs + 4 / build;
        build = x_abs + 3 / build;
        build = x_abs + 2 / build;
        build = x_abs + 1 / build;
        cum_norm = expo_x / build / 2.506628274631;
    }
    if(x < 0) {
        return cum_norm;
    }
    return 1.0 - cum_norm;
}
