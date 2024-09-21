#include "ksp_core.h"
#include <fstream>
#include <sstream>
#include <random>
#include <iostream>
#include <chrono>
#include <nlohmann/json.hpp> // usada para tratar o .JSON
#include <locale>
using json = nlohmann::json;

///  Converte string de um lineEdit
///  Em um vetor de inteiros se possivel.
vector<int> Mochila::strToArray(const string& str_)
{
    stringstream ss(str_);
    vector<int> result;
    string temp;
    while (ss >> temp) {
        result.push_back(stoi(temp));
    }
    return result;
}

///  Converte vetor de inteiros
///  Em uma string.
string Mochila::arrToString(const vector<int>& v) {
    stringstream ss;
    ss << "[" ;

    for (size_t i = 0; i < v.size(); ++i) {
        ss << v[i];
        if (i != v.size() - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    string result = ss.str();
    return result;
}

///  Realiza a leitura de um arquivo.json contendo as especificaç~eos do problema
///  Define os parametros de acordo com a definição do arquivo
void Mochila::lerArquivo(const string& nomeArquivo) {
    ifstream file(nomeArquivo);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    json j;
    file >> j;

    try {
        capacidade = j.at("capacidade").get<int>();
        n_itens = j.at("n_itens").get<int>();
        pesos = j.at("pesos").get<vector<int>>();
        utilidades = j.at("utilidades").get<vector<int>>();

        /*cout << "Capacidade: " << capacidade << endl;
        cout << "Número de itens: " << n_itens << endl;
        for (int i = 0; i < n_itens; ++i) {
            cout << "Peso do item " << i << ": " << pesos[i] << ", Utilidade do item " << i << ": " << utilidades[i] << endl;
        }*/
    } catch (json::exception& e) {
        cerr << "Erro ao processar JSON: " << e.what() << endl;
    }

    file.close();
    //cout << "Arquivo fechado com sucesso." << endl;
}

///  Realiza a leitura de um arquivo.bin contendo os dados de um array muito grande
///  Instancia o array de acordo com os dados do arquivo.bin
void Mochila::readBinArch(const string &nomeArquivo, vector<int>& array){
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    // Abrindo o arquivo binário para leitura
    std::ifstream inputFile(nomeArquivo, std::ios::in | std::ios::binary);

    if (inputFile.is_open()) {
        // Lendo o conteúdo do arquivo binário para o array
        inputFile.read(reinterpret_cast<char*>(&array[0]), array.size() * sizeof(int));
        inputFile.close();

        std::cout << "Array carregado com sucesso do arquivo " << nomeArquivo << "!" << std::endl;

    } else {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << "!" << std::endl;
    }
}

/// Gera numeros aleatorios usando uma distribuição uniforme
/// Variando de 1 a plimit
/// @param limite superior da geração aleatoria do número
/// @return um(1) número aleatorio
int Mochila::gerRandNum(int plimit) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, plimit);
    return dis(gen);
}

/// Gera um vetor contendo numeros aleatorios
/// @param int tam : Tamanho do vetor a ser criado
/// @param int lim : Limite do range da geração dos nuemros
/// @return o vetor
vector<int> Mochila::gerRandPesoUtil(int tam, int lim) {
    vector<int> result(tam);
    for (int& val : result) {
        val = gerRandNum(lim);
    }
    return result;
}

/// Resolve o problema da mochila utilizando Programação dinâmica
/// @return A capacidade maxiima para a mochila de capacidade X, com os itens Y
/// com peso P e utilidade U.
/// @author Ernesto:: Esse metodo é ineficiente para numeros muito grandes
pair<int, double> Mochila::solveKSP()
{
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> K(n_itens + 1, vector<int>(capacidade + 1, 0));
    for (int i = 0; i <= n_itens; ++i) {
        for (int w = 0; w <= capacidade; ++w) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (pesos[i - 1] <= w) {
                K[i][w] = max(utilidades[i - 1] + K[i - 1][w - pesos[i - 1]], K[i - 1][w]);
            }
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();  // Captura o tempo de término
    chrono::duration<double> duration_in_seconds = end - start;
    //chrono::seconds duracao = chrono::duration_cast<chrono::seconds>(end - start);
    //chrono::nanoseconds duracaoN = chrono::duration_cast<chrono::nanoseconds>(end - start);
    return make_pair(K[n_itens][capacidade], duration_in_seconds.count());
    //return K[n_itens][capacidade]; /// Retorno da capacidade maxima para os parametros passados
}

/// Resolve o problema da mochila utilizanod Programação dinâmica
/// @returns Par<int max_utilidade, vetor<itens escolhidos>
pair<int, vector<int>> Mochila::solveKSP_2() {
    vector<vector<int>> K(n_itens + 1, vector<int>(capacidade + 1, 0));
    vector<vector<bool>> keep(n_itens + 1, vector<bool>(capacidade + 1, false));

    for (int i = 0; i <= n_itens; ++i) {
        for (int w = 0; w <= capacidade; ++w) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (pesos[i - 1] <= w) {
                int includeItem = utilidades[i - 1] + K[i - 1][w - pesos[i - 1]];
                int excludeItem = K[i - 1][w];
                if (includeItem > excludeItem) {
                    K[i][w] = includeItem;
                    keep[i][w] = true;
                } else {
                    K[i][w] = excludeItem;
                }
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    int maxUtility = K[n_itens][capacidade];
    vector<int> itemsSelected;

    // Backtrack to find which items were selected
    int w = capacidade;
    for (int i = n_itens; i > 0 && w > 0; --i) {
        if (keep[i][w]) {
            itemsSelected.push_back(i - 1); // Item indices are zero-based
            w -= pesos[i - 1];
        }
    }

    return make_pair(maxUtility, itemsSelected);
}

/// Algoritmo Dinamico para resolução do problema da mochila.
/// Complexidade O(nW) pseudo-polinomial
/// \return par<max_utilidade, tempo_exec> o resultado problema e o tempo gasto para encontrar a solução.
pair<int, double> Mochila::knapsack(){
    auto start = chrono::high_resolution_clock::now();
    vector<int> M(capacidade + 1, 0);

    for (int i = 0; i < n_itens; ++i) {
        for (int w = capacidade; w >= pesos[i]; --w) {
            M[w] = max(M[w], M[w - pesos[i]] + utilidades[i]);
        }
    }
    auto end = chrono::high_resolution_clock::now();  // Captura o tempo de término
    chrono::duration<double> duration_in_seconds = end - start;

    return make_pair(M[capacidade], duration_in_seconds.count());
}
