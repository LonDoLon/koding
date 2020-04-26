#include <iostream>

size_t find(int* arr, size_t size, int value)
{
	size_t i = 0, j = size - 1, m;
	while (i < j)
	{
		m = (i + j) / 2;
		if (value > arr[m])
			i = m + 1;
		else j = m;
	}
	if (arr[i] == value) return i;
	else return std::numeric_limits<size_t>::max();
}

const int size = 10;

int main() {
	int* arr = new int[size] { 1, 2, 5, 7, 8, 5, 2, 1235, 123, 423 };
	int ind = find(arr, size, 1235);

	std::cout << "found at " << ind << "\n";

	return 0;
}