#include <stdio.h>

void Two_Dim_Array(int arr[3][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int matrix() {
    int my_arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int result = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result += my_arr[i][j];
        }
    }
    printf("Sum of all elements: %d\n", result);
    Two_Dim_Array(my_arr, 3);
    return 0;
}