#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cmath>
#include <set>
#include <map>

using namespace std;

map<string, double> Ranking_Cosseno (map<string, vector<double>> coorarquivos, vector<double> coorbusca){
    map<string, double> Ranking;
    double d = 0;
    double n = 0;
    double r = 0;
    double x = 0;
    double posicao;
    vector<double> v;
    for(map<string, vector<double>>::iterator it = coorarquivos.begin(); it != coorarquivos.end(); it++){
        string arq = it -> first;
        v = it -> second;
        for(int i = 0; i < v.size(); i++){
            d = d + (v[i] * coorbusca[i]);
            n = n + (v[i] * v[i]);
            r = r + (coorbusca[i] * coorbusca[i]);
        }
        x = sqrt(n) * sqrt(r);
        posicao = d/n;
        Ranking.insert(pair<string, double>(arq, posicao));
    }
    return Ranking;
}

map<double, vector<string>> Ranking_Organizado (map<string, double> Rank){
    map<double, vector<string>> org;
    vector <string> aux;
    for(map<string, double>::iterator it = Rank.begin(); it != Rank.end(); it++){
        if(org.find(it -> second) == org.end()){
            aux.push_back(it -> first);
            org.insert(pair<double, vector<string>>(it -> second, aux));
            aux.clear();
        } 
        else{
            org[it -> second].push_back(it -> first);
        }
    }
    return org;
}

