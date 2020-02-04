//
// Created by vibhatha on 2/4/20.
//

#ifndef SRC_UTIL_H
#define SRC_UTIL_H


#include <iostream>
#include <vector>

using namespace std;

class Util {
public:
    Util();
    void print1DMatrix(double* x, int features);
    void summary(string logfile, int world_size, int message_size, double time);
    string getTimestamp();
};


#endif //SRC_UTIL_H
