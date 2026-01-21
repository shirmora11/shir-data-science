#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define DIMENSIONS_ERROR -1
#define NULL_PTR_ERROR 2
# define TRUE 1
# define FALSE 0

typedef struct mat_t{
    size_t nrow;
    size_t ncol;
    double** matrix;
} mat_t;


mat_t* mat_create(size_t rows, size_t cols)
{
    mat_t* matrix =(mat_t*)malloc(sizeof(mat_t));
    if (!matrix) {return NULL;}
    matrix->ncol= cols;
    matrix->nrow = rows;
    matrix->matrix = malloc(matrix->nrow * sizeof(double*));
    for (size_t i = 0 ; i < matrix->nrow; i++)
    {
        matrix->matrix[i] = malloc(matrix->ncol* sizeof(double*));
    }
    return matrix;
}

void mat_destroy(mat_t* matrix)
{
    if (!matrix){return;}
    for (size_t i = 0 ; i < matrix->nrow;i++)
    {
        free(matrix->matrix[i]);
    }
    free(matrix);
}


int matrix_add(const mat_t* matrix_a, const mat_t* matrix_b, mat_t* result)
{
    if (matrix_b->nrow != matrix_a->nrow || matrix_a->ncol!=matrix_b->ncol)
    {
        return FAILURE;
    }
    int sum = 0;
    for (size_t i =0; i < matrix_a->nrow; ++i)
    {
        for (size_t j = 0 ; j <matrix_b->ncol; ++j)
        {
            for (size_t k = 0; matrix_b->nrow ; ++k)
            {
                sum += matrix_a->matrix[i][k] + matrix_b->matrix[k][j];
            }
            result->matrix[i][j]= sum;
            sum = 0;
        }

    }
    return SUCCESS;
}





int matrix_multiply(const mat_t* matrix_a, const mat_t* matrix_b, mat_t* result)
{
    if (matrix_b->nrow != matrix_a->ncol)
    {
        return FAILURE;
    }
    int sum = 0;
    for (size_t i =0; i < matrix_a->nrow; ++i)
    {
        for (size_t j = 0 ; j <matrix_b->ncol; ++j)
        {
            for (size_t k = 0; matrix_b->nrow ; ++k)
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

    for (size_t i = 0; i < mat->nrow; ++i)
    {
        int sum = 0;
        for (size_t j = 0 ; j < mat->ncol; ++j)
        {
            sum = mat->matrix[i][j]*scalar;
            result->matrix[i][j] = sum;
        }
    }
    return SUCCESS;
}




int matrix_is_same(const mat_t* matrix_a, const mat_t* matrix_b)
{
    for (size_t i = 0 ;i < matrix_a->nrow; i++)
    {
        for (size_t j = 0 ;j < matrix_a->ncol; j++)
        {
            if (matrix_a->matrix[i][j] != matrix_b->matrix[i][j]){return FAILURE;}
        }
    }
    return SUCCESS;
}



/*int matrix_transpose(const mat_t* matrix, mat_t* result)
{
        for (size_t i = 0 ;i < matrix_a->nrow; i++)
    {
        for (size_t j = 0 ;j < matrix_a->ncol; j++)
        {
            
        }
    }
}*/

//double matrix_trace(const mat_t* matrix, int* status);


//double matrix_determinant(const mat_t* matrix, int* status);


//int matrix_get_submatrix(const mat_t* matrix, size_t row, size_t col, mat_t* result);


//double matrix_norm(const mat_t* matrix);


//int matrix_inverse(const mat_t* matrix, mat_t* result);


//int matrix_set(mat_t* matrix, double* elements, size_t size);


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

static void print_matrix(mat_t* m) {
    for (size_t i = 0; i < m->nrow; i++) {
        for (size_t j = 0; j < m->ncol; j++) {
            printf("%lu ", (size_t)mat_get_val(m, i, j));
        }
        printf("\n");
    }
}


int main()
{
    mat_t * mat = mat_create(3,3);
    print_matrix(mat);
    mat_destroy(mat);
    return 0;
}