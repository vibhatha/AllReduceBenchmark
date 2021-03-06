//
// Created by vibhatha on 2/4/20.
//

#include "Util.h"
#include <iostream>
#include <fstream>

using namespace std;

Util::Util() {

}


void Util::print1DMatrix(double* x, int features) {
    for (int i = 0; i < features; ++i) {
        cout  << x[i] << " ";
    }
    cout << "\n";
}


void Util::summary(string logfile, int world_size, int message_size, double time) {
    ofstream myfile(logfile, ios::out | ios::app);
    string timestamp = getTimestamp();
    if (myfile.is_open()) {

        myfile << world_size << "," << message_size << "," << time << "," << timestamp << "\n";

        myfile.close();
    }
}

string Util::getTimestamp() {
    string string1;
    time_t t = time(0);   // get time now
    tm *now = localtime(&t);
    string datestring;
    datestring.append(to_string(now->tm_year + 1900)).append("-").append(to_string((now->tm_mon + 1))).append(
            "-").append(to_string(now->tm_mday));
    string timestring;
    timestring.append(to_string(now->tm_hour)).append(":").append(to_string(now->tm_min)).append(":").append(
            to_string(now->tm_sec));
    string1.append(datestring).append("__").append(timestring);
    return string1;
}