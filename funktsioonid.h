#ifndef FUNKTSIOONID_H
#define FUBKTSIOONID_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

int suvaline_number(int a, int b);
std::string värv(int a);
void round(int panuse_kogus, int panuse_stiil, int* konto);
void väline_tulemus(bool väärtus, int panuse_kogus, int kordaja, int* konto);
void käsurealt_info(int argc, char* argv[], std::vector<int>& kasutaja_sisend);
void failist_raha(std::string failiNimi, int& summa);
void raha_faili(std::string failiNimi, int& summa);
int valik(int mitu_valikut);
void panuse_viisid();
void mängima(int* konto);


#endif