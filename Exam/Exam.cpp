#include <iostream>
#include <algorithm>

const int rows = 22;
const int cols = 2;

int main() {
    int array[rows][cols];

    // ���������� ������ ����������� ���������� (����� ������� �� �������� �����������)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100; // �������� �������� ����� �� 0 �� 99
        }
    }

    // ����������� ������ ������ �����, ���� �������� � ���� �����������
    int maxSum = INT_MIN;
    int maxSumRow1, maxSumRow2;

    for (int i = 0; i < rows - 1; ++i) {
        int currentSum = array[i][0] + array[i][1] + array[i + 1][0] + array[i + 1][1];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxSumRow1 = i;
            maxSumRow2 = i + 1;
        }
    }

    // ��������� ����������
    std::cout << "Numbers of rows with the maximum sum of elements: " << maxSumRow1 << " and " << maxSumRow2 << std::endl;

    // ���������� ������� ����� �� ���������
    for (int i = 0; i < rows; ++i) {
        std::sort(array[i], array[i] + cols, std::greater<int>());
    }

    // ��������� ������������� ������
    std::cout << "Sorted array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
