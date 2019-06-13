#ifndef COORDENADAS_H
#define COORDENADAS_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cmath>
#include <set>
#include <map>

#include "Leitura.h"
#include "Indice.h"

using namespace std;

//Gera um mapa que relaciona uma palavra com o numero de arquivos no qual ela aparece (TP -> n(t))
map<string, int> Ocorrencia_Arq (vector<string> palavras, vector<string>arquivos);

//Gera um mapa que relaciona uma palavra a quantas vezes ela aparece em um arquivo (TP -> tf)
map<string, int> Freq_P_Arq (vector<string> palavras);

//Gera um mapa que relaciona uma palavra a frequencia inversa dele (TP -> itf)
map<string, double> In_Freq (map<string, int> freqpalarq, int arquivos);

//Mostra as coordenadas de cada palavra dentro de cada arquivo
map<string, map<string, double>> Coordenada_parq (vector<string> arquivos, int num_arq);

//Gera um mapa que relaciona o nome do arquivo com o vetor de coordenadas das palavras
map<string, vector<double>> Vetor_P_Doc(vector<string> palavras, vector<string> arquivos, int num_arq);

//Determina se a palavra existe no indice
bool Existe (map<string, double> inversefreq, string busca);

//Determina a coordenada da busca
double Coordenada_busca (map<string, double> inversefreq, string busca);

//Gera um vetor com as coordenadas da busca em comparação ao indice
vector<double> V_Busca (map<string, set<string>> indice, map<string, double> coorbusca);

#endif