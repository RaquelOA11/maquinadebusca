#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cmath>
#include <set>
#include <map>

#include "Leitura.h"

using namespace std;

map<string, set<string>> In_Invertido(vector<string> palavras, vector<string> arquivos){
    set<string> docs;
    map<string, set<string>> in_invertido;
    for(int b = 0; b < palavras.size(); b++){
        for(int c = 0; c < arquivos.size(); c++){
            vector<string> arquivo;
            arquivo = Arq(arquivos[c]);
            for(int d = 0; d < arquivo.size(); d++){
                if(palavras[b] == arquivo[d]){
                    docs.insert(arquivos[c]);
                    break;
                }
            }
        }
        in_invertido.insert(pair<string,set<string>>(palavras[b], docs));
        docs.clear();
    }
    return in_invertido;
}
