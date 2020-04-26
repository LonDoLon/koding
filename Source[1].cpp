#include <iostream>

size_t find(int* arr, size_t size, int value) {
    if (size != 0) {
        int last = arr[size - 1];//�������� ������� ������� �������
        arr[size - 1] = value;//�����������, ��� value ���� � �������
        //���� �������� ����, ��� ������� ���� � �������, ������ ������ ����� �� ���������
        size_t i = 0;
        for (i = 0; arr[i] != value; ++i) {//���� ������� � �����
        }
        arr[size - 1] = last;//��������������� ��������� �������
        if (i != (size - 1) || value == last) {//�� ��������� � ������ ��� ��������� ������� ��� �������
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