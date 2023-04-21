#ifndef FUNKTSIOONID_H
#define FUBKTSIOONID_H

#include <string>
#include <vector>

int suvaline_number(int a, int b);
std::string värv(int a);
void round(int panuse_kogus, int panuse_stiil, int* konto);
void väline_tulemus(bool väärtus, int panuse_kogus, int kordaja, int* konto);
void käsurealt_info(int argc, char* argv[], std::vector<int>& kasutaja_sisend);

#endif