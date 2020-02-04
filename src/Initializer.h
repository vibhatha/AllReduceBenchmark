//
// Created by vibhatha on 2/4/20.
//

#ifndef SRC_INITIALIZER_H
#define SRC_INITIALIZER_H


class Initializer {
private:
    double *wInit;

public:
    double *initialWeights(int features);

    void initialWeights(int features, double *w);

    double *zeroWeights(int features);

    double *initializeWeightsWithArray(int features, double a[]);

    double **initalizeMatrix(int rows, int columns, double **b);
};


#endif //SRC_INITIALIZER_H
