#pragma once
#include <string>
#include <vector>
using namespace std;

/// --------------------------- CONSTANTES
const int LIMIT_SR = 100;
const int LIMIT_SR2 = 50;

/// --------------------------- Classe Mochila
class Mochila {
public:
    // Construtores
    Mochila() : capacidade(0), n_itens(0) {}
    Mochila(int cap, int n) : capacidade(cap), n_itens(n), pesos(n), utilidades(n) {}

    // Métodos
    vector<int> strToArray(const string& str);
    string arrToString(const vector<int>& v);
    void lerArquivo(const string& nomeArquivo);
    int gerRandNum(int plimit);
    vector<int> gerRandPesoUtil(int tam, int lim);
    //int solveKSP();
    pair<int, double> solveKSP();
    pair<int, vector<int>> solveKSP_2();
    pair<int, double> knapsack();

    // Getters
    int getCapacidade() const { return capacidade; }
    int getNItens() const { return n_itens; }
    vector<int> getPesos() const { return pesos; }
    vector<int> getUtilidades() const { return utilidades; }

    // Setters
    void setCapacidade(int cap) { capacidade = cap; }
    void setNItens(int n) { n_itens = n; pesos.resize(n); utilidades.resize(n); }
    void setPesos(const vector<int>& p) { pesos = p; }
    void setUtilidades(const vector<int>& u) { utilidades = u; }

private:
    int capacidade; // ---- Capacidade da mochila
    int n_itens; // ---- Quantidade de itens a serem escolhidos
    vector<int> pesos; // ---- Pesos de cada item
    vector<int> utilidades; // ---- Utilidade de cada item
};

// !KSP_CORE_H
