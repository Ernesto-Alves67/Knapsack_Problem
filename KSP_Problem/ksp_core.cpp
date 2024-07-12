#include "ksp_core.h"
#include <fstream>
#include <sstream>
#include <random>
#include <iostream>
#include <chrono>

/**
   *  @brief Esta função converte uma stringd e numeros
   *  @ingroup sorting_algorithms
   *  @param  str_  A string a ser convertida.
   *  @return Um array de inteiros.
  */
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

string Mochila::arrToString(const vector<int>& v) {
    stringstream ss;
    for (int i : v) {
        ss << i << " ";
    }
    string result = ss.str();
    result.pop_back(); // Remove o último espaço
    return result;
}

void Mochila::lerArquivo(const string& nomeArquivo) {
    ifstream file(nomeArquivo);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    file >> capacidade >> n_itens;
    pesos.resize(n_itens);
    utilidades.resize(n_itens);
    for (int i = 0; i < n_itens; ++i) {
        file >> pesos[i] >> utilidades[i];
    }
    file.close();
}

int Mochila::gerRandNum(int plimit) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, plimit);
    return dis(gen);
}

vector<int> Mochila::gerRandPesoUtil(int tam, int lim) {
    vector<int> result(tam);
    for (int& val : result) {
        val = gerRandNum(lim);
    }
    return result;
}
/**
   * Resolve o problema da mochila utilizando Programação dinâmica
   * @return A capacidade maxiima para a mochila de capacidade X, com os itens Y
   * com peso P e utilidade U.
*/
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

int Mochila::knapsack(){
    vector<int> K(capacidade + 1, 0);

    for (int i = 0; i < n_itens; ++i) {
        for (int w = capacidade; w >= pesos[i]; --w) {
            K[w] = max(K[w], K[w - pesos[i]] + utilidades[i]);
        }
    }

    return K[capacidade];
}
