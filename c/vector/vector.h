#include "vector.c"
#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>
vector_t* vec_create(const size_t capacity);                           /// Creates a new vector with the specified initial capacity    

void* vec_get_element(const vector_t* vec, const size_t idx);          /// Retrieves the element at the specified index         

void vec_push(vector_t* vec, void* new_element);                       /// Adds a new element to the end of the vector if value not NULL  

void* vec_pop(vector_t* vec);                                          /// Removes and returns the last element of the vector if not empty 

void vec_set_element(vector_t* vec, const size_t idx, void* element);  /// Sets the element at the specified index if index is valid   

size_t vec_get_size(const vector_t* vec);                              /// Returns the current number of elements in the vector   

size_t vec_get_capacity(const vector_t* vec);                          /// Returns the current capacity of the vector   
       
void vec_destroy(vector_t* vec);                                       /// Destroys the vector and frees associated memory           
#endif