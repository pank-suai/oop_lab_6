#pragma once

#include <vector>
#include "Exceptions.hpp"

class Array {
private:
    static const int SIZE = 12;
    int data[SIZE];
public:
    Array(const std::vector<int>& input);
    int getMaxIndex() const;
    long long getProductBetweenZeros() const;
    void print() const;
    void transform();
};