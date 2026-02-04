
#include <stddef.h>
#ifndef MATRIX_H
#define MATRIX_H

typedef struct mat_t{
    size_t nrow;
    size_t ncol;
    double** matrix;  
} mat_t;

#define SUCCESS 0
#define FAILURE 1
#define DIMENSIONS_ERROR -1
#define NULL_PTR_ERROR 2

# define TRUE 1
# define FALSE 0

typedef struct mat_t mat_t;

// Creates a mat_t structure that holds a pointer to a matrix of dimensions "rows" and "cols".
// Requires that the number of rows and cols specified are each greater than 0.
// Returns a pointer to the structure if succesful; a NULL pointer otherwise.
mat_t* mat_create(size_t rows, size_t cols);

// Frees the memory used to hold the mat_t structure and its elements (including the matrix).
void mat_destroy(mat_t* matrix);

// Adds the values of two matrices and stores the output values in a results matrix. 
// Requires that the two matrices as well as the results matrix have equivalent dimensions.
// Returns a status code: SUCCESS or DIMENSIONS_ERROR (when the two matrices have different dimensions). 
int matrix_add(const mat_t* matrix_a, const mat_t* matrix_b, mat_t* result);

// Multiply the values (i,j) of two matrices and stores the output values in a results matrix.
// Requires that the results matrix has the appropriate dimensions to accomodate the result: if mat_a is m x n and mat_b is n x k than result requires m x k.
// Returns a status code: SUCCESS or DIMENSIONS_ERROR (when the results matrix has incorrect dimensions). 
int matrix_multiply(const mat_t* matrix_a, const mat_t* matrix_b, mat_t* result);

//returns a status int, multiplies the values of the elements of matrix mat with a scalar and puts the product in the result matrix.
//must be m x n for mat and result
//returns a status int: SUCCESS for success, DIMENSIONS_ERROR for dimentions error, NULL_PTR_ERROR for null ptr error
int matrix_scalar_multiply(const mat_t* mat, const double scalar, mat_t* result);

//returns 1 if the two matrixes are the same. 
//must be m x n for both mats
//returns status: 1 for TRUE, 0 for FALSE
int matrix_is_same(const mat_t* matrix_a, const mat_t* matrix_b);

//calculates the transpose of matrix mat and places it into result
// must be m x n for mat and n x m for result
//returns status: SUCCESS for success, DIMENSIONS_ERROR for dimentions error, NULL_PTR_ERROR for null ptr error
int matrix_transpose(const mat_t* matrix, mat_t* result);

//calculates the trace of a matrix and returns it as a double
//expact for a m x m matrix and not NULL
//updates status int for errors: SUCCESS for success, DIMENSIONS_ERROR for dimentions error, NULL_PTR_ERROR for null ptr error
double matrix_trace(const mat_t* matrix, int* status);

//calculates the determinant of the matrix and returns it 
//expacted for a m x m matrix and not NULL
//updates status int for errors: SUCCESS for success, DIMENSIONS_ERROR for dimentions error, NULL_PTR_ERROR for null ptr error
double matrix_determinant(const mat_t* matrix, int* status);

//find the sub matrix and places it in result
//result is the original mat without the given row and col
//returns result: TRUE if they are the same, FALSE if not
//status will be added into the given pointer: SUCCESS for seccess, DIMENSIONS_ERROR for dimentions error, NULL_PTR_ERROR for null ptr error
int matrix_get_submatrix(const mat_t* matrix, size_t row, size_t col, mat_t* result);

//calculates the forbenius norm and return it
//expact for a not NULL ptr.
double matrix_norm(const mat_t* matrix);

//calculate the inverse matrix of mat and place it in result 
// if mat is m x n , result must be n x m
//expact for a not NULL ptrs.
int matrix_inverse(const mat_t* matrix, mat_t* result);

//set the elements in the matrix
//if mat is m x n and size is bigger, will only set the first values.
//must be sizeof(elements) == size (the user must give a correct size for their array of elements)
//expact for a not NULL ptr.
int matrix_set(mat_t* matrix, double* elements, size_t size);

//get the number of rows of the matrix
//expact for a not NULL ptr.
size_t mat_get_num_of_rows(const mat_t* mat);

//get the number of columnns of the matrix
//expact for a not NULL ptr.
size_t mat_get_num_of_cols(const mat_t* mat);

//get the value stored in the row and column cordinates of the given matrix
//expact for a not NULL ptr.
double mat_get_val(mat_t* matrix, size_t row_idx, size_t col_idx);


///////help function
void print_matrix(mat_t* m);

#endif