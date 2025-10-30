#include "Array.hpp"
#include <vector>
#include <iostream>

int main() {
    // Нормальный случай
    std::vector<int> data = {1, 2, 0, 4, 5, 0, 7, 8, 9, 10, 11, 12};
    try {
        Array arr(data);
        std::cout << "Оригинальный массив: ";
        arr.print();
        std::cout << "Индекс максимального элемента: " << arr.getMaxIndex() << std::endl;
        std::cout << "Произведение между нулями: " << arr.getProductBetweenZeros() << std::endl;
        arr.transform();
        std::cout << "После преобразования: ";
        arr.print();
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    // Неверный размер
    std::vector<int> badData = {1, 2, 3};
    try {
        Array arr2(badData);
    } catch (const std::exception& e) {
        std::cout << "Ошибка размера: " << e.what() << std::endl;
    }

    // Нет нулей
    std::vector<int> noZeroData(12, 1);
    try {
        Array arr3(noZeroData);
        arr3.getProductBetweenZeros();
    } catch (const std::exception& e) {
        std::cout << "Ошибка нулей: " << e.what() << std::endl;
    }

    return 0;
}