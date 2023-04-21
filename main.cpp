#include "funktsioonid.h"

#include <iostream>
#include <vector>

//programmi jooksutamiseks tee "make roulette"

int main(int argc, char* argv[]) {
    int konto = 1000;
    int* kontoptr = &konto;

   
    std::vector<int> kasutaja_sisend; //käsurea sisendi hoidmiseks

    for (int i = 0; i < argc; ++i) { //töötleb käsurea sisendit
        kasutaja_sisend.push_back(std::atoi(argv[i])); 
    }

    if (argc == 3) { //kui käsurealt on sisestatud 2 arvu, siis kasutab neid, et rouletti mängida
        round(kasutaja_sisend.at(1), kasutaja_sisend.at(2), kontoptr);
    }
    
    
    std::cout << konto << "\n";

    return 0;
}