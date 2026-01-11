#include <stdio.h>
#include "array.h"
int main() {
    //ex1 checking
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int results[3];
    calculateRowSums(3, 3, matrix, results);
    for (int i = 0; i < 3; i++) {
        printf("Sum of row %d: %d\n", i, results[i]);
    }

    //ex2 checking
    printf("Recursive (n=5, k=2): %d\n", josephus(5, 2));
    printf("Fast (n=100): %d\n", josephus_fast(100));

    //ex3 checking
    data_types();

    // ex4 checking
    int count = 0;
    char **cloned = clone_env_manual(&count);
    if (cloned) {
        printf("Successfully cloned %d environment variables (lowercase).\n", count);
        for (int i = 0; i < (count > 5 ? 5 : count); i++) {
            printf("%d: %s\n", i, cloned[i]);
        }
        printf("... (freeing memory)\n");
        print_and_free(cloned);
    }
    return 0;
}