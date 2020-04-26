#include <iostream>

size_t find(int* arr, size_t size, int value) {
    if (size != 0) {
        int last = arr[size - 1];//Сохраним прежний элемент массива
        arr[size - 1] = value;//Гарантируем, что value есть в массиве
        //Есть гарантия того, что элемент есть в массиве, значит индекс можно не проверять
        size_t i = 0;
        for (i = 0; arr[i] != value; ++i) {//Одно условие в цикле
        }
        arr[size - 1] = last;//Восстанавливаем последний элемент
        if (i != (size - 1) || value == last) {//Не уткнулись в барьер или последний элемент был искомым
            return i;
        }
    }
    return std::numeric_limits<size_t>::max();
}

const int size = 10;

int main() {
    int* arr = new int[size] { 1, 2, 5, 7, 8, 5, 2, 1235, 123, 423 };
    int ind = find(arr, 11, 1235);

    std::cout << "found at " << ind << "\n";

    return 0;
}