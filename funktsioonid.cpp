#include "funktsioonid.h"

#include <random>


int suvaline_number(int a, int b) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(generator);
}

std::string värv(int a) {
    if (a == 0 || a == 37) { // kas 0 või 00
        return "roheline";
    }
    if (a < 11 || (a > 18 && a < 29)) {
        if (a % 2 == 0) {
            return "must";
        } else {
            return "punane";
        }
    } else {
        if (a % 2 == 1) {
            return "must";
        } else {
            return "punane";
        }
    }
}