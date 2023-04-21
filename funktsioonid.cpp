#include "funktsioonid.h"

#include <random>
#include <iostream>


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

void väline_tulemus(bool väärtus, int panuse_kogus, int kordaja, int* konto) {
    if (väärtus) {
        *konto += kordaja * panuse_kogus;
        std::cout << "võitiste: " << kordaja * panuse_kogus << "!\n";
    } else {
        *konto -=  panuse_kogus;
        std::cout << "kaotasite.\n";
    }
}

void käsurealt_info(int argc, char* argv[], std::vector<int>& kasutaja_sisend) {
    for (int i = 0; i < argc; ++i) { //töötleb käsurea sisendit
        kasutaja_sisend.push_back(std::atoi(argv[i])); 
    }
}

void round(int panuse_kogus, int panuse_stiil, int* konto) { //22 võidu viisi
    int number = suvaline_number(0, 37);
    std::string round_värv = värv(number);

    std::cout << "Pall maandus: " << round_värv << " " << number << "\n";     

    //sisemised panused

    //välised panused
    switch(panuse_stiil) {
        case 10: // 1 tulp
            väline_tulemus((number % 3 == 1 && number != 37), panuse_kogus, 2, konto);
        break;

        case 11: // 2 tulp
            väline_tulemus((number % 3 == 2), panuse_kogus, 2, konto);
        break;

        case 12: // 3 tulp
            väline_tulemus((number % 3 == 0 && number != 0), panuse_kogus, 2, konto);
        break;

        case 13: // 1 tosin
            väline_tulemus((0 < number && number < 13), panuse_kogus, 2, konto);
        break;

        case 14: // 2 tosin
            väline_tulemus((12 < number && number < 25), panuse_kogus, 2, konto);
        break;

        case 15: // 3 tosin
            väline_tulemus((24 < number && number < 37), panuse_kogus, 2, konto);
        break;

        case 16: // paaritu
            väline_tulemus((number % 2 == 1 && number != 37), panuse_kogus, 1, konto);
        break;

        case 17: // paaris
            väline_tulemus((number % 2 == 0 && number != 0), panuse_kogus, 1, konto);
        break;

        case 18: // punane
            väline_tulemus((round_värv == "punane"), panuse_kogus, 1, konto);
        break;

        case 19: // must
            väline_tulemus((round_värv == "must"), panuse_kogus, 1, konto);
        break;

        case 20: // 1-18 aka low
            väline_tulemus((number < 19 && number != 0), panuse_kogus, 1, konto);
        break;

        case 21: // 19-36 aka high
            väline_tulemus((number > 18), panuse_kogus, 1, konto);
        break;

        case 22: // snake
            väline_tulemus((number == 1 || number == 5 || number == 9 || number == 12 || number == 14 || 
            number == 16 || number == 19 || number == 23 || number == 27 || number == 39 || number == 32 || number == 34), panuse_kogus, 2, konto);
        break;
    }

}