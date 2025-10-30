#pragma once

#include <exception>

class NoZerosException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Массив не содержит двух нулей для вычисления произведения.";
    }
};

class InvalidSizeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Неверный размер массива.";
    }
};

