#include "funktsioonid.h"

//programmi jooksutamiseks tee "make roulette"
//mängimiseks ./roulette <panus> <panuse tüüp>


int main(int argc, char* argv[]) {
    int konto;
    failist_raha("raha.txt", konto); //loeb failist kontol oleva raha summa
    int* kontoptr = &konto;

    //kui programmi lõpetamiseks
    bool töötab = true;

    std::cout << "=======================\n\nTere tulemast rouletti!\n\n=======================\n\n";

    //seni kuni programm töötab
    while (töötab) {
        std::cout << "**************\nvalige tegevus\n**************\n\n";
        std::cout << "1. panustamise viisid\n2. mängima\n3. välju\n\nValiku tegemiseks sisestage number: ";
        
        int sisend = valik(3);

        switch(sisend) {
            case 1: // panustamise viisid
                panuse_viisid();
            break;

            case 2: // mängima
                mängima(kontoptr);
            break;

            case 3: // mängima
                std::cout << "järgmise korrani!\n";
                töötab = false;
            break;
        }
    }
    

    std::vector<int> kasutaja_sisend; //käsurea sisendi hoidmiseks
    käsurealt_info(argc, argv, kasutaja_sisend); //lisab käsurealt saadu kasutaja_sisend vektorisse

    if (argc == 3) { //kui käsurealt on sisestatud 2 arvu, siis kasutab neid, et rouletti mängida
        round(kasutaja_sisend.at(1), kasutaja_sisend.at(2), kontoptr);
    }
    
    std::cout << "Raha alles: " << konto << "\n";
    raha_faili("raha.txt", konto); //paneb konto summa faili
    
    return 0;
}