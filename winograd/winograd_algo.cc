#include "winograd.h"

// Функция для умножения двух матриц
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int n = matrix1.size();
    int m = matrix2[0].size();
    int mid = matrix2.size();

    std::vector<std::vector<int>> result(n, std::vector<int>(m, 0));
    std::vector<int> row_factor(n, 0);
    std::vector<int> col_factor(m, 0);

    // Вычисление row_factor
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mid / 2; j++) {
            row_factor[i] += matrix1[i][2 * j] * matrix1[i][2 * j + 1];
        }
    }

    // Вычисление col_factor
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < mid / 2; j++) {
            col_factor[i] += matrix2[2 * j][i] * matrix2[2 * j + 1][i];
        }
    }

    // Умножение матриц
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = -row_factor[i] - col_factor[j];
            for (int k = 0; k < mid / 2; k++) {
                result[i][j] += (matrix1[i][2 * k] + matrix2[2 * k + 1][j]) * (matrix1[i][2 * k + 1] + matrix2[2 * k][j]);
            }
        }
    }

    // Добавление дополнительных элементов для нечетного mid
    if (mid % 2 != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] += matrix1[i][mid - 1] * matrix2[mid - 1][j];
            }
        }
    }

    return result;
}
