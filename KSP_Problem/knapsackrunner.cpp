#include "knapsackrunner.h"

KnapsackRunner::KnapsackRunner(Mochila *problemData)
    : problemData(problemData) {}

void KnapsackRunner::run() {
    auto result = problemData->knapsack();
    emit resultReady(result);
}
