//Heloisa Silva Rosa -> TF2
//Mateus Gaonçalves Moreira -> TF2
//Raquel Oliveira Azevedo -> TF2

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cmath>
#include <set>
#include <map>

#include "Leitura.h"
#include "Indice.h"
#include "Coordenadas.h"
#include "Ranking.h"

using namespace std;

int main(){


    cout << "Digite os arquivos que serao utilizados na busca\n";
    cout << "Coloque .txt apos o nome\n";
    cout << "Digite 'fimdosarquivos' ao adicionar todos os arquivos que serao utilizados\n";
    

    string nomeArquivo;
    cin >> nomeArquivo;
    vector<string> todosArquivos;
    int numeroArquivos = 1;
    while (nomeArquivo != "fimdosarquivos"){
        todosArquivos.push_back(nomeArquivo);
        cin >> nomeArquivo;
        numeroArquivos++;
    }
    

    vector<string> todasPalavras;
    for(int i = 0; i < todosArquivos.size(); i++){
        vector<string> p_arquivo;
        p_arquivo = Arq(todosArquivos[i]);
        for (int j = 0; j < p_arquivo.size(); j++){
            todasPalavras.push_back(p_arquivo[j]);
        }
    }
    cout << endl;

    cout << "Digite a palavra buscada\n";
    cout << "Apenas minusculas, uma palavra por linha\n";
    cout << "Digite 'iniciarbusca' ao adicionar todas as palavras\n";
    cout << "Caso a palavras não exita o programa avisara. Digite enter\n";

    string busca;
    cin >> busca;
    map<string, int> aux;
    aux = Ocorrencia_Arq(todasPalavras, todosArquivos);
    map<string, double> frequencia;
    frequencia = In_Freq(aux, numeroArquivos);
    double coordBusca;
    map<string, double> coordenadas;
    while(busca != "iniciarbusca"){
        coordBusca = Coordenada_busca(frequencia, busca);
        coordenadas.insert(pair<string, double>(busca, coordBusca));
        cin >> busca;
    }

    cout << endl;

    vector<double> var;
    var = V_Busca (In_Invertido(todasPalavras, todosArquivos), coordenadas);
    
    map<string, vector<double>> m;
    m = Vetor_P_Doc(todasPalavras, todosArquivos, numeroArquivos);
    
    map<string, double> Rank;
    Rank = Ranking_Cosseno(m, var);
   
    map<double, vector<string>> fi;
    fi = Ranking_Organizado(Rank);

    cout << "Os arquivos por ordem de importancia sao:\n";

    for(map<double, vector<string>>::reverse_iterator it = fi.rbegin(); it != fi.rend(); it++){
        vector<string> docs = it -> second;
        for(int k = 0; k < docs.size(); k++){
        cout << docs[k] << " ";
        }
       cout << endl;
    }

}