#include "funktsioonid.h"

#include <iostream>

//programmi jooksutamiseks tee "make roulette"

int main() {
    for (int i = 0; i < 10; i++) {
        int number = suvaline_number(0, 37);
        std::cout << värv(number) << " " << number << "\n";
    }

    return 0;
}