#ifndef INDICE_H
#define INDICE_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cmath>
#include <set>
#include <map>

using namespace std;

//Gera um mapa que relaciona uma palavra com os arquivos em que ela existe
map<string, set<string>> In_Invertido(vector<string> palavras, vector<string> arquivos);

#endif
