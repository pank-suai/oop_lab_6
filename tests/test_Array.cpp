#include "../src/Array.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

// Тесты для класса Array

// Вспомогательная функция для захвата вывода print
std::string capturePrint(const Array& arr) {
    std::ostringstream oss;
    auto old_cout = std::cout.rdbuf(oss.rdbuf());
    arr.print();
    std::cout.rdbuf(old_cout);
    return oss.str();
}

// Тест нормальной работы
void testNormalOperation() {
    std::vector<int> data = {1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 10};
    Array arr(data);

    // Тест getMaxIndex
    if (arr.getMaxIndex() != 11) throw std::runtime_error("getMaxIndex failed");

    // Тест getProductBetweenZeros
    long long product = arr.getProductBetweenZeros();
    if (product != 4LL * 5 * 6) throw std::runtime_error("getProductBetweenZeros failed");

    // Тест transform
    arr.transform();
    // После трансформации: нечетные индексы сначала, четные потом
    // Оригинал: 1,2,3,0,4,5,6,0,7,8,9,10
    // Нечет: 2,0,5,0,8,10
    // Чет: 1,3,4,6,7,9
    // Итог: 2,0,5,0,8,10,1,3,4,6,7,9
    std::string expected = "2 0 5 0 8 10 1 3 4 6 7 9 \n";
    if (capturePrint(arr) != expected) throw std::runtime_error("transform failed");
}

// Тест исключений
void testExceptions() {
    // Неверный размер
    try {
        std::vector<int> data(11, 1);
        Array arr(data);
        throw std::runtime_error("InvalidSizeException not thrown");
    } catch (const InvalidSizeException&) {
        // OK
    }

    // Нет двух нулей
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Array arr(data);
    try {
        arr.getProductBetweenZeros();
        throw std::runtime_error("NoZerosException not thrown for no zeros");
    } catch (const NoZerosException&) {
        // OK
    }

    // Только один ноль
    data[5] = 0;
    Array arr2(data);
    try {
        arr2.getProductBetweenZeros();
        throw std::runtime_error("NoZerosException not thrown for one zero");
    } catch (const NoZerosException&) {
        // OK
    }
}

// Тест крайних случаев
void testEdgeCases() {
    // Нули на границах
    std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
    Array arr(data);
    long long product = arr.getProductBetweenZeros();
    long long expected_prod = 1LL;
    for (int i = 1; i <= 10; ++i) expected_prod *= i;
    if (product != expected_prod) throw std::runtime_error("boundary zeros product failed");

    // Множественные нули
    data = {0, 1, 0, 2, 0, 3, 4, 5, 6, 7, 8, 9};
    Array arr2(data);
    product = arr2.getProductBetweenZeros();
    if (product != 1) throw std::runtime_error("multiple zeros product failed");

    // Все нули
    data = std::vector<int>(12, 0);
    Array arr3(data);
    product = arr3.getProductBetweenZeros();
    if (product != 1) throw std::runtime_error("all zeros product failed");

    // Отрицательные числа
    data = {0, -1, -2, -3, 0, 4, 5, 6, 7, 8, 9, 10};
    Array arr4(data);
    product = arr4.getProductBetweenZeros();
    if (product != (-1) * (-2) * (-3)) throw std::runtime_error("negative numbers product failed");

    // Большие числа (без проверки на переполнение)
    data = {0, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 0, 1, 2, 3, 4, 5};
    Array arr5(data);
    // Вычисление произведения без обработки переполнения
    long long largeProduct = arr5.getProductBetweenZeros();
    // Проверяем, что функция вернула значение (даже если переполнено)
    if (largeProduct == 0) throw std::runtime_error("large product calculation failed");
}

int main() {
    try {
        testNormalOperation();
        std::cout << "Normal operation tests: PASSED\n";

        testExceptions();
        std::cout << "Exception tests: PASSED\n";

        testEdgeCases();
        std::cout << "Edge cases tests: PASSED\n";

        std::cout << "All tests passed!\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cout << "Test failed: unknown error\n";
        return 1;
    }
    return 0;
}