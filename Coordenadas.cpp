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

map<string, int> Ocorrencia_Arq (vector<string> palavras, vector<string>arquivos){
    map<string, int> freq_arq;
    for(int b = 0; b < palavras.size(); b++){
        int freq = 0;
        for(int c = 0; c < arquivos.size(); c++){
            vector<string> arquivo;
            arquivo = Arq(arquivos[c]);
            for(int d = 0; d < arquivo.size(); d++){
                if(palavras[b] == arquivo[d]){
                    freq++;
                    break;
                }
            }
        }
        freq_arq.insert(pair<string,int>(palavras[b], freq));
    }
    return freq_arq;
}

map<string, int> Freq_P_Arq (vector<string> palavras){
    map<string, int> tf;
    for (int i = 0; i < palavras.size(); i++){
        int freq = 1;
        for (int j = 1+i; j < palavras.size(); j++){
           if(palavras[i] == palavras[j]){
                freq++;
                palavras.erase(palavras.begin()+j);
                j--;
            }
        }
        tf.insert(pair<string, int>(palavras[i], freq));
    }
    return tf;
}

map<string, double> In_Freq (map<string, int> ocorrencia, int arquivos){
    map<string, double> inversefreq;
    double freq;
    for(map<string, int>::iterator it = ocorrencia.begin(); it != ocorrencia.end(); it++){
        double aux = arquivos/it -> second;
        freq = log(aux);
        inversefreq.insert(pair <string, double> (it-> first, freq));
    }
    return inversefreq;
}


map<string, map<string, double>> Coordenada_parq (vector<string> arquivo, int num_arq){
    map<string, map<string, double>> coordenada;
    for(int a = 0; a < arquivo.size(); a++){
        vector<string> v1;
        v1 = Arq(arquivo[a]);
        map<string, int> mapocorrencia;
        mapocorrencia = Ocorrencia_Arq(v1, arquivo);
        map<string, int> mapfrequencia;
        mapfrequencia = Freq_P_Arq(v1);
        map<string, double> map2;
        map2 = In_Freq(mapocorrencia, num_arq);
        map<string, double> mapaux;
        double d;
        for(int b = 0; b < v1.size(); b++){
            for(map<string, int>::iterator it = mapfrequencia.begin(); it != mapfrequencia.end(); it++){
                string s = it -> first;
                int x = it -> second;
                for(map<string, double>::iterator it = map2.begin(); it != map2.end(); it++){
                    if(s == it -> first){
                        d = x * it -> second;
                        break;
                    }
                }
                mapaux.insert(pair<string, double>(s, d));
            }
        }
        coordenada.insert(pair<string, map<string, double>>(arquivo[a], mapaux));
    }
    return coordenada;
}

map<string, vector<double>> Vetor_P_Doc(vector<string> palavras, vector<string> arquivos, int num_arq){
    map<string, set<string>> in;
    in = In_Invertido(palavras, arquivos);
    map<string, map<string, double>> coord;
    coord = Coordenada_parq(arquivos, num_arq);
    map<string, double> mpacoo;
    map<string, vector<double>> cparq;
    vector<double> v;
    set<string> doc;
    int j = 0;
       for(map<string, map<string, double>>::iterator it = coord.begin(); it != coord.end(); it++){
            string arqnome = it -> first;
            mpacoo = it -> second;
            for(map<string, set<string>>::iterator it = in.begin(); it != in.end(); it++){
                string palavra = it -> first;
                doc = it -> second;
                for(map<string, double>::iterator it = mpacoo.begin(); it != mpacoo.end(); it++){
                    if(palavra == it -> first){
                        v.push_back(it -> second);
                        j++;
                    }
                }
                if(j == 0){
                    v.push_back(0.0);
                }
                else if (j != 0){
                    j = 0;
                }
            }
            cparq.insert(pair<string, vector<double>>(arqnome, v));
            v.clear();
        }

    return cparq;
}

bool Existe (map<string, double> inversefreq, string busca){
    for(map<string, double>::iterator it = inversefreq.begin(); it != inversefreq.end(); it++){
        if(busca == it -> first){
            return true;
        }
    }
    return false;
}

double Coordenada_busca (map<string, double> inversefreq, string busca){
    double coordbus;
    if(Existe(inversefreq, busca) == true){
        for(map<string, double>::iterator it = inversefreq.begin(); it != inversefreq.end(); it++){
            if(busca == it -> first){
            coordbus = it -> second;
            return coordbus;
            }
        }
    }
    if(Existe(inversefreq, busca) == false){
    cout << "Nao existe";
    }
}

vector<double> V_Busca (map<string, set<string>> indice, map<string, double> coorbusca){
    vector<double> v;
    int j = 0;
    for(map<string, set<string>>::iterator it = indice.begin(); it != indice.end(); it++){
        string s = it -> first;
        for(map<string, double>::iterator it = coorbusca.begin(); it != coorbusca.end(); it++){
            string d = it -> first;
            if(s == d){
                v.push_back(it -> second);
                j++;
            }
        }
        if(j == 0){
            v.push_back(0.0);
        }
        else if(j != 0){
            j = 0;
        }
    }
    return v;
}