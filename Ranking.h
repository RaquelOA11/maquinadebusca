#ifndef RANKING_H
#define RANKING_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cmath>
#include <set>
#include <map>


using namespace std;

//Gera um mapa que relaciona o nome do arquivo e a importancia dele
map<string, double> Ranking_Cosseno (map<string, vector<double>> coorarquivos, vector<double> coorbusca);

//Mesma coisa que o Ranking_Cosseno so que organizado de acordo com o double
//Para ser acessado do maior para o menor e necessario utilizar reverse_iterator
map<double, vector<string>> Ranking_Organizado (map<string, double> Rank);

#endif