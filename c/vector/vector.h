#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>
typedef struct vector_t {
    size_t allocation;   
    size_t len;          
    void **data;         
} vector_t;
vector_t* vec_create(const size_t capacity);                                                       
void* vec_get_element(const vector_t* vec, const size_t idx);                           
void vec_push(vector_t* vec, void* new_element);                                  
void* vec_pop(vector_t* vec);                                                     
void vec_set_element(vector_t* vec, const size_t idx, void* element);                   
size_t vec_get_size(const vector_t* vec);                                         
size_t vec_get_capacity(const vector_t* vec);                                     
void vec_destroy(vector_t* vec);                                                  

#endif