#include "funktsioonid.h"

#include <random>


//genereerib suvalise numbri antud vahemikus
int suvaline_number(int a, int b) {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(generator);
}

//olenevalt sisestatud numbrist tagastab värvi, mis sellele numbrile vastab, rouletti reeglite järgi
std::string värv(int a) {
    if (a == 0 || a == 37) { // kas 0 või 00
        return "roheline";
    }

    //kui arv vahemiks 1-10 ja 19-28
    if (a < 11 || (a > 18 && a < 29)) {
        //paaris siis must
        if (a % 2 == 0) {
            return "must";
        //kui paaritu siis panane
        } else {
            return "punane";
        }
    //kui arv vahemiks 11-18 ja 29-36
    } else {
        //paaritu siis must
        if (a % 2 == 1) {
            return "must";
        //kui paaris siis panane
        } else {
            return "punane";
        }
    }
}

// vastavalt sellele kas mängija võidab või kaotab (bool väärtus) tehakse teha kontole vastavad muudatused
void väline_tulemus(bool väärtus, int panuse_kogus, int kordaja, int* konto) {
    if (väärtus) {
        *konto += kordaja * panuse_kogus;
        std::cout << "võitiste: " << kordaja * panuse_kogus << "!\n";
    } else {
        *konto -=  panuse_kogus;
        std::cout << "kaotasite.\n";
    }
}

void käsurealt_info(int argc, char* argv[], std::vector<int>& kasutaja_sisend) { //loeb käsurealt saadud info ja paneb vektrorisse
    for (int i = 0; i < argc; ++i) { //töötleb käsurea sisendit
        kasutaja_sisend.push_back(std::atoi(argv[i])); //sisend muudetakse int tüübiks ja lisatakse vektorisse
    }
}

void failist_raha(std::string failiNimi, int& summa) { //loeb failist kontol oleva raha summa
    std::ifstream fail(failiNimi); //avab faili
    std::string rida;
    std::getline(fail, rida); //loeb ainult esimese rea, sest failis on ainult 1 rida konto summa jaoks
    summa = std::stoi(rida); //annab summale failist saadud väärtuse
    fail.close();
}

void raha_faili(std::string failiNimi, int& summa) { //paneb konto summa faili
    std::ofstream fail(failiNimi); //avab faili
    fail << summa; //lisab summa faili
    fail.close();
}

//pks rouletti round, kasutaja panuse kogusega ja panuse stiiliga, nt: 100€ panus punasele värvile
void round(int panuse_kogus, int panuse_stiil, int* konto) { //22 võidu viisi

    //genereeritakse suvaline number ja sellele vastav värv
    int number = suvaline_number(0, 37);
    std::string round_värv = värv(number);

    //väljastadakse, tulemus
    std::cout << "Pall maandus: " << round_värv << " " << number << "\n";     

    //sisemised panused

    //roulettis olevad välised panused (https://en.wikipedia.org/wiki/Roulette) 
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

//vaatab kas kasutaja sisestatud sisend on õige
int valik(int mitu_valikut) {
    int sisend = -1;
    while (true)
    {
        std::cin >> sisend;
        if (0 < sisend && sisend <= mitu_valikut) {
            break;
        } else {
            std::cout << "Sellist valikut ei ole!\nValiku tegemiseks sisestage number: ";
        }
    }
    return sisend;
}

//selgitused erinevatele panustamis viisidele
void panuse_viisid() {
    std::cout << "**************\npanuse viisid\n**************\n\n";

    while (true) {
        std::cout << "1. must\n2. punane\n3. kõrge\n4. madal\n5. number\n6. paaritu\n7. paaris\n8. tosinad\n9. tulbad\n10. madu\n\n11. tagasi\n\nValiku tegemiseks sisestage number: ";
    
        int sisend = valik(11);

        switch(sisend) {
            case 1: 

            break;

            case 2: 
            
            break;

            case 3: 

            break;

            case 4: 
            
            break;

            case 5: 
            
            break;

            case 6: 
            
            break;

            case 7: 
            
            break;

            case 8: 
            
            break;

            case 9: 
            
            break;

            case 10: 
            
            break;

            case 11: 
                return;
            break;
        }
    }      
}

void mängima(int* konto) {
    std::cout << "**************\nmängimine\n**************\n\n";
    int panus;
    while (true) { 
        std::cout << "Sisestage panuse suurus: ";
        std::cin >> panus;
        if (panus <= *konto) {
            break;
        } else {
            std::cout << "Pole piisavalt raha panuse tegemiseks!\nTeil on kontol alles " << *konto << "\n";
        }
    }

    while (true) {
        std::cout << "\nValige panuse tüüp\n\n";
        std::cout << "1. must\n2. punane\n3. kõrge\n4. madal\n5. number\n6. paaritu\n7. paaris\n8. 1.tosin\n9. 2.tosin\n10. 3.tosin\n11. 1.tulp" <<
        "\n12. 2.tulp\n13. 3.tulp\n14. madu\n\n15. tagasi\n\nValiku tegemiseks sisestage number: ";
    
        int sisend = valik(15);

        switch(sisend) {
            case 1: //must
                std::cout << "\n=======================\n\n";
                round(panus, 19, konto);
                std::cout << "\n=======================\n\n";
            break;

            case 2: //punane
                std::cout << "\n=======================\n\n";
                round(panus, 18, konto);
                std::cout << "\n=======================\n\n";
            break;

            case 3: 

            break;

            case 4: 
            
            break;

            case 5: 
            
            break;

            case 6: 
            
            break;

            case 7: 
            
            break;

            case 8: 
            
            break;

            case 9: 
            
            break;

            case 10: 
            
            break;

            case 11: 
            
            break;

            case 12: 
            
            break;

            case 13: 
            
            break;

            case 14: 
            
            break;

            case 15: 
                return;
            break;
        }
        //peale panuse tegemist läheb peaekraanile tagasi
        return;
    }
}