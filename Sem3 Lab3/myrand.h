#pragma once
#include <random>
#include <iostream>
#include <string>
using namespace std;


double doublerand(double min, double max)
{
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}


float floatrand(float min, float max)
{
    float f = (float)rand() / RAND_MAX;
    return min + f * (max - min);
}

string GenRandomString(const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ "
        "abcdefghijklmnopqrstuvwxyz ";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int rand(int min, int max)
{
    return min + rand() % (max - min + 1);
}

long long rand(long long min, long long max)
{
    return min + (long long)rand() % (max - min + 1);
}