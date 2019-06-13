#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

#include "Leitura.h"

using namespace std;

vector<string> Arq (string nomeArquivo){
    ifstream arquivo;
    string Var;
    char delim = ' ';
    arquivo.open(nomeArquivo);
    vector<string> palavras;
    while(!arquivo.eof()){
        getline(arquivo, Var, delim);
        for(int r = 0; r < Var.length(); r++){
            if(Var[r] == '\n'){
                Var.erase(Var.begin()+r);
                r--;
            }
        }
        palavras.push_back(Var);
    }
    arquivo.close();
    vector<string> limpo;
    limpo = Limpeza(palavras);
    return limpo;
}

string Minuscula (string x){
    for(int i = 0; i < x.length(); i++){
        char a;
        char b;
        a = x[i];
        b = tolower(a);
        x[i] = b;
    }
    return x;
}

string Pontuacao(string x){
    for(int i = 0; i < x.length(); i++){
        if(!isalnum(x[i])){
           x.erase(x.begin()+i);
           i--;
        }
    }
    return x;
}

string Final(string x){
    string a, b;
    a = Minuscula(x);
    b = Pontuacao(a);
    return b;
}

vector<string> Limpeza (vector<string> v){
    for (int i = 0; i < v.size(); i++){
       string s;
       string x;
        s = v[i];
        x = Final(s);
        v[i] = x;
    }
    return v;
}