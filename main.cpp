#include "funktsioonid.h"

#include <iostream>

//programmi jooksutamiseks tee "make roulette"

int main() {
    int konto = 1000;
    int* kontoptr = &konto;

    for (int i = 0; i < 10; i++) {
        round(100, 21, kontoptr);
    }

    std::cout << konto << "\n";

    return 0;
}