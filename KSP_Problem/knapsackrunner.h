#ifndef KNAPSACKRUNNER_H
#define KNAPSACKRUNNER_H

#include <QObject>
#include "ksp_core.h"

class KnapsackRunner : public QObject
{
    Q_OBJECT

public:
    KnapsackRunner(Mochila *problemData);

public slots:
    void run();
signals:
    void resultReady(std::pair<int, double> result);

private:
    Mochila *problemData;
};

#endif // KNAPSACKRUNNER_H
