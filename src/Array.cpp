#include "Array.hpp"
#include <iostream>

Array::Array(const std::vector<int>& input) {
    if (input.size() != SIZE) {
        throw InvalidSizeException();
    }
    for (int i = 0; i < SIZE; ++i) {
        data[i] = input[i];
    }
}

int Array::getMaxIndex() const {
    int maxIdx = 0;
    for (int i = 1; i < SIZE; ++i) {
        if (data[i] > data[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

long long Array::getProductBetweenZeros() const {
    int firstZero = -1;
    int secondZero = -1;
    for (int i = 0; i < SIZE; ++i) {
        if (data[i] == 0) {
            if (firstZero == -1) {
                firstZero = i;
            } else {
                secondZero = i;
                break;
            }
        }
    }
    if (firstZero == -1 || secondZero == -1) {
        throw NoZerosException();
    }
    long long product = 1;
    for (int i = firstZero + 1; i < secondZero; ++i) {
        product *= data[i];
    }
    return product;
}

void Array::print() const {
    for (int i = 0; i < SIZE; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void Array::transform() {
    int odd[6];
    int even[6];
    int oddIdx = 0, evenIdx = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (i % 2 == 1) {
            odd[oddIdx++] = data[i];
        } else {
            even[evenIdx++] = data[i];
        }
    }
    for (int i = 0; i < 6; ++i) {
        data[i] = odd[i];
        data[i + 6] = even[i];
    }
}