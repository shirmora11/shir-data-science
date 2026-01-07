#include "array.h"

void calculateRowSums(int rows, int cols, int (*matrix)[cols], int results[]) {
    for (int i = 0; i < rows; i++) {
        results[i] = 0;
        for (int j = 0; j < cols; j++) {
            results[i] += matrix[i][j];
        }
    }
}
int main() {
    return 0;
}
