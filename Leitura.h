#ifndef LEITURA_H
#define LEITURA_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

using namespace std;

//Le o arquivo e armazena as palavras num vetor.
//Necessario colocar .txt no final da string
vector<string> Arq (string nomeArquivo);

//Transforma as letras maiusculas de uma string em minusculas
string Minuscula (string x);

//Retira a pontuação de uma string
string Pontuacao(string x);

//Retorna uma string ja tratada por Minuscula() e Pontuacao()
string Final(string x);

//Cria um vetor sem pontuação, espaços letras e letras maiusculas
vector<string> Limpeza (vector<string> v);

#endif