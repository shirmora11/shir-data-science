#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include <math.h>
#include <assert.h>
#include "matrix-operations.h"

#define SUCCESS 0
#define FAILURE 1
#define DIMENSIONS_ERROR -1
#define NULL_PTR_ERROR 2
# define TRUE 1
# define FALSE 0


mat_t* mat_create(size_t rows, size_t cols)
{
    if (rows < 1 || cols < 1) return NULL;

    mat_t* matrix = malloc(sizeof(mat_t));
    if (!matrix) return NULL;

    matrix->nrow = rows;
    matrix->ncol = cols;
    matrix->matrix = malloc(rows * sizeof(double*));
    
    if (!matrix->matrix) 
    {
        free(matrix);
        return NULL;
    }

    for (size_t i = 0; i < rows; i++) 
    {
        matrix->matrix[i] = malloc(cols * sizeof(double)); 
        if (!matrix->matrix[i]) 
        {
            for (size_t j = 0; j < i; j++)
            {
                free(matrix->matrix[j]);
            }
            free(matrix->matrix);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void mat_destroy(mat_t* matrix)
{
    if (matrix == NULL) return;
    for (size_t i = 0; i < matrix->nrow; i++)
    {
        free(matrix->matrix[i]);
        matrix->matrix[i] = NULL;
    }
    free(matrix->matrix);
    matrix->matrix = NULL; 
    free(matrix);
}


int matrix_add(const mat_t* matrix_a, const mat_t* matrix_b, mat_t* result)
{
    if (!matrix_a || !matrix_b) {return FAILURE;}
    if (matrix_b->nrow != matrix_a->nrow || matrix_a->ncol != matrix_b->ncol )
    {
        return DIMENSIONS_ERROR;
    }
    for (size_t i =0; i < matrix_a->nrow; ++i)
    {
        for (size_t j = 0 ; j < matrix_b->ncol; ++j)
        {
            result->matrix[i][j] = matrix_a->matrix[i][j] + matrix_b->matrix[i][j];
        }
    }
    return SUCCESS;
}



int matrix_multiply(const mat_t* matrix_a, const mat_t* matrix_b, mat_t* result)
{
    if (!matrix_a || !matrix_b){return FAILURE;}
    if (matrix_b->nrow != matrix_a->ncol)
    {
        return DIMENSIONS_ERROR;
    }
    double sum = 0;
    for (size_t i =0; i < matrix_a->nrow; ++i)
    {
        for (size_t j = 0 ; j <matrix_b->ncol; ++j)
        {
            for (size_t k = 0; k < matrix_b->nrow ; ++k)
            {
                sum += matrix_a->matrix[i][k] * matrix_b->matrix[k][j];
            }
            result->matrix[i][j] = sum;
            sum = 0;
        }
    }
    return SUCCESS;
}


int matrix_scalar_multiply(const mat_t* mat, const double scalar, mat_t* result)
{
    if (!mat){return FAILURE;}
    for (size_t i = 0; i < mat->nrow; ++i)
    {
        for (size_t j = 0 ; j < mat->ncol; ++j)
        {
            result->matrix[i][j] = mat->matrix[i][j]*scalar;
        }
    }
    return SUCCESS;
}



int matrix_is_same(const mat_t* matrix_a, const mat_t* matrix_b)
{
    if (!matrix_a || !matrix_b){return FAILURE;}
    for (size_t i = 0 ;i < matrix_a->nrow; i++)
    {
        for (size_t j = 0 ;j < matrix_a->ncol; j++)
        {
            if (matrix_a->matrix[i][j] != matrix_b->matrix[i][j]){return FAILURE;}
        }
    }
    return TRUE;
}


int matrix_transpose(const mat_t* matrix, mat_t* result)
{    
    if (!matrix){return FAILURE;}
    for (size_t i = 0 ;i < matrix->nrow; i++)
    {
        for (size_t j = 0 ;j < matrix->ncol; j++)
        {
            result->matrix[j][i] = matrix->matrix[i][j];
        }
    }
    return SUCCESS;
}

double matrix_trace(const mat_t* matrix, int* status)
{
    if (!matrix){return FAILURE;}
    if (matrix->ncol != matrix->nrow)
    {
    *status = DIMENSIONS_ERROR;
    return FAILURE; 
    }    
    double sum =0;
    for(size_t i = 0 ; i < matrix->nrow ; i++)
    {
        sum += matrix->matrix[i][i];
    }
    return sum;
}



int matrix_get_submatrix(const mat_t* matrix, size_t row, size_t col, mat_t* result)
{
    if (!matrix){return FAILURE;}
    if(row >= matrix->nrow || col > matrix->ncol)
    {
        return DIMENSIONS_ERROR;
    }
    size_t rows = matrix->nrow;
    size_t cols = matrix->ncol;
    int res_i= 0;
    for(size_t i = 0; i < rows; i++)
        {
        if (i == row)continue;
        int res_j= 0;
        for(size_t j = 0; j < cols; j++)
        {
            if (j ==  col )continue;
            result->matrix[res_i][res_j] = matrix->matrix[i][j];
            res_j++;

        }
        res_i++;
    }
    return SUCCESS;
}



double matrix_determinant(const mat_t* matrix, int* status)
{
    if (!matrix){return FAILURE;}
    if (matrix->ncol != matrix->nrow)
    {
        *status = DIMENSIONS_ERROR;
        return FAILURE;
    }
    int cols = matrix->ncol;
    int rows = matrix->nrow;
    if (rows == 1) {
        return matrix->matrix[0][0];
    }
    if (rows == 2) {
        return matrix->matrix[0][0] * matrix->matrix[1][1] - 
               matrix->matrix[0][1] * matrix->matrix[1][0];
    }
   double total_deter = 0;
    int sign = 1;
    mat_t* sub = mat_create(rows - 1, cols - 1);
    if (!sub) {
        if (status) *status = FAILURE;
        return 0;
    }
    for (size_t j = 0; j < matrix->nrow; j++) {
        matrix_get_submatrix(matrix, 0, j, sub);
        
        total_deter += sign * matrix->matrix[0][j] * matrix_determinant(sub, status);
        sign = -sign; 
    }
    mat_destroy(sub);

    if (status) *status = SUCCESS;
    return total_deter;
}

double matrix_norm(const mat_t* matrix)
{
    if (!matrix){return FAILURE;}
    double sum = 0;
    for (size_t i = 0; i < matrix->nrow; i++) 
    {
        for (size_t j = 0; j < matrix->ncol; j++)
        {
            sum += matrix->matrix[i][j]* matrix->matrix[i][j];
        }
    }
    return sqrt(sum);
}


int matrix_set(mat_t* matrix, double* elements, size_t size)
{
    if (!matrix){return FAILURE;}
    if(size > (matrix->ncol * matrix->nrow)) {return FAILURE;}
    size_t cols = matrix->ncol;
    size_t rows = matrix->nrow;
    int t=0;
    for(size_t i = 0; i < rows ; ++i)
    {
        for (size_t j = 0 ; j < cols ; j++)
        {
            matrix->matrix[i][j] = elements[t];
            t++;
        }
    }
    return SUCCESS;
}


size_t mat_get_num_of_rows(const mat_t* mat)
{
    return mat->nrow;
}


size_t mat_get_num_of_cols(const mat_t* mat)
{
    return mat->ncol;
}


double mat_get_val(mat_t* matrix, size_t row_idx, const size_t col_idx)
{
    return matrix->matrix[row_idx][col_idx];
}

void print_matrix(mat_t* m)
{
    for (size_t i = 0; i < m->nrow; i++)
    {
        for (size_t j = 0; j < m->ncol; j++) 
        {
            printf("%.3f\t ",mat_get_val(m, i, j));
        }
        printf("\n\n");
    }
}
int matrix_inverse(const mat_t* matrix, mat_t* result)
{
    if (!matrix){return FAILURE;}
    int status = SUCCESS;
    if (matrix->nrow != matrix->ncol) {return FAILURE;}
    mat_t * sub_temp = mat_create(matrix->nrow-1, matrix->ncol-1);
    mat_t * temp_1 = mat_create(matrix->nrow, matrix->ncol);
    mat_t * temp_2 = mat_create(matrix->nrow, matrix->ncol);
    if (!sub_temp || !temp_1 || !temp_2){return FAILURE;}
    mat_destroy(sub_temp);
    mat_destroy(temp_1);
    mat_destroy(temp_2);
    for (size_t i = 0; i < matrix->nrow; i++) {
        for (size_t j = 0; j < matrix->ncol; j++) {
            if (matrix_get_submatrix(matrix, i, j, sub_temp) == SUCCESS) {
                int sign = ((i + j) % 2 == 0) ? 1 : -1;
                temp_1->matrix[i][j] = sign * matrix_determinant(sub_temp,&status);
            }
        }
    }
    matrix_transpose(temp_1, temp_2);
    double inv_det = 1.0 / matrix_determinant(matrix,&status);
    if (inv_det == 0) {
        mat_destroy(sub_temp); mat_destroy(temp_1); mat_destroy(temp_2);
        return FAILURE; 
    }
    matrix_scalar_multiply(temp_2, inv_det, result);

    mat_destroy(sub_temp);
    mat_destroy(temp_1);
    mat_destroy(temp_2);

    return SUCCESS;
}
