#include "matrix-operations.h"
#include <stdio.h>


int main()
{
    mat_t * mat = mat_create(3,3);
    mat_t * result = mat_create(3,3);
    mat_t * mat_b = mat_create(3,3);
    mat_t * mat_sub = mat_create(2,2);
    int status = SUCCESS;

    printf("number of column:%zu\n", mat_get_num_of_cols(mat));
    printf("number of rows:%zu\n",mat_get_num_of_rows(mat));
    matrix_is_same(mat, result);
    double arr[] = {1,-4,2,-2,1,3,2,6,8};
    double reset[] = {0,0,0,0,0,0,0,0,0};
    size_t size_arr = sizeof(arr)/sizeof(arr[0]);
    matrix_set(mat,arr,size_arr);
    print_matrix(mat);
    printf("\n");
    matrix_set(result ,reset ,size_arr);

    matrix_set(mat_b,arr,size_arr);
    matrix_add(mat,mat_b,result);
    print_matrix(result);
    printf("\n");
    matrix_set(result ,reset ,size_arr);

    matrix_multiply(mat,mat_b,result);
    print_matrix(result);
    printf("\n");
    matrix_set(result ,reset ,size_arr);

    matrix_get_submatrix(mat,1, 1, mat_sub);
    print_matrix(mat_sub);
    printf("\n");
    matrix_set(mat_sub ,reset ,size_arr);

    matrix_set(mat,arr,size_arr);
    matrix_scalar_multiply(mat, 4,result);
    print_matrix(result);
    printf("\n");
    matrix_set(result ,reset ,size_arr);

    matrix_set(mat,arr,size_arr);
    matrix_transpose(mat,result);
    print_matrix(result);
    printf("\n");
    matrix_set(result ,reset ,size_arr);

    matrix_set(mat,arr,size_arr);
    printf("trace of this is :%.2f\n",matrix_trace(mat,&status));

    matrix_set(mat,arr,size_arr);
    printf("determinant of this is :%.3f\n",matrix_determinant(mat,&status));

    printf("norm of this is :%.3f\n",matrix_norm(mat));
    
    printf("the value of the 2,2 is :%.2f\n",mat_get_val(mat,2,2));

    matrix_inverse(mat,result);
    print_matrix(result);

    mat_destroy(mat);
    mat_destroy(result);
    mat_destroy(mat_b);
    mat_destroy(mat_sub);
    return 0;
}