#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include <math.h>
#include <assert.h>

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
    if (matrix_b->nrow != matrix_a->nrow || matrix_a->ncol != matrix_b->ncol)
    {
        return DIMENSIONS_ERROR;
    }
    int sum = 0;
    for (size_t i =0; i < matrix_a->nrow; ++i)
    {
        for (size_t j = 0 ; j < matrix_b->ncol; ++j)
        {
            sum += matrix_a->matrix[i][j] + matrix_b->matrix[i][j];
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
    if (!scalar) {return FAILURE;}
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


int matrix_transpose(const mat_t* matrix, mat_t* result)
{    
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
    if (matrix->ncol != matrix->nrow)
    {
    *status = DIMENSIONS_ERROR; 
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
    if(row > matrix->nrow || col > matrix->ncol)
    {
        return DIMENSIONS_ERROR;
    }
    int rows = matrix->nrow;
    int cols = matrix->ncol;
    int res_i= 0;
    for(int i = 0; i < rows; i++)
        {
        if (i == row)continue;
        int res_j= 0;
        for(int j = 0; j < cols; j++)
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
    if (matrix->ncol != matrix->nrow)
    {
        return DIMENSIONS_ERROR;
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
//int matrix_inverse(const mat_t* matrix, mat_t* result){}


int matrix_set(mat_t* matrix, double* elements, size_t size)
{
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

static void print_matrix(mat_t* m) {
    for (size_t i = 0; i < m->nrow; i++) {
        for (size_t j = 0; j < m->ncol; j++) {
            printf("%lu\t ", (size_t)mat_get_val(m, i, j));
        }
        printf("\n\n");
    }
}

int main()
{
    mat_t * mat = mat_create(3,3);
    mat_t * result = mat_create(3,3);
    mat_t * mat_b = mat_create(3,3);
    mat_t * mat_sub = mat_create(2,2);
    int status = SUCCESS;

    printf("number of column:%zu\n", mat_get_num_of_cols(mat));
    printf("number of rows:%zu\n",mat_get_num_of_rows(mat));
    size_t size_mat = sizeof(mat->matrix);
    matrix_is_same(mat, result);
    double arr[] = {1,2,3,4,5,6,7,8,9};
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

    matrix_get_submatrix(mat,1, 1,mat_sub);
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
    printf("trace of this is :%.2f",matrix_trace(mat,&status));
    printf("\n");

    matrix_set(mat,arr,size_arr);
    printf("determinant of this is :%.3f",matrix_determinant(mat,&status));
    printf("\n");

    printf("norm of this is :%.3f\n",matrix_norm(mat));
    
    printf("the value of the 2,2 is :%.2f\n",mat_get_val(mat,2,2));


    

    mat_destroy(mat);
    mat_destroy(result);
    mat_destroy(mat_b);
    mat_destroy(mat_sub);
    return 0;
}