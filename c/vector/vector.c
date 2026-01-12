#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
typedef struct vector_t {
    size_t allocation;   
    size_t len;          
    void **data;         
} vector_t;
vector_t* vec_create(size_t capacity)
{
    if (capacity == 0) capacity = 1;
    vector_t* vec = malloc(sizeof(vector_t));
    if (!vec) return NULL;
    
    vec->data = malloc(sizeof(void*) * capacity);
    if (!vec->data) {
        free(vec);
        return NULL;
    }

    vec->allocation = capacity;
    vec->len = 0;
    return vec;
}
static void vec_resize(vector_t* vec, size_t new_capacity)
{
    if (!vec || new_capacity == 0) return;
    void **new_data = realloc(vec->data, new_capacity * sizeof(void*));
    if (!new_data) return;
    vec->data = new_data;
    vec->allocation = new_capacity;
}

void vec_destroy(vector_t* vec)
{
    if (!vec) return;
    free(vec->data);
    free(vec);       
}
size_t vec_get_size(const vector_t* vec)
{
    return vec ? vec->len : 0;
}

size_t vec_get_capacity(const vector_t* vec)
{
    return vec ? vec->allocation : 0;
}

void* vec_get_element(const vector_t* vec, size_t idx)
{
    if (!vec || idx >= vec->len) return NULL;
    return vec->data[idx];
}

void vec_set_element(vector_t* vec, size_t idx, void* element)
{
    if (!vec || idx >= vec->len) return;
    vec->data[idx] = element;
}

void vec_push(vector_t* vec, void* new_element)
{
    if (!vec) return;
    if (vec->len >= vec->allocation) {
        vec_resize(vec, vec->allocation * 2);
        if (vec->len >= vec->allocation) return; 
    }

    vec->data[vec->len++] = new_element;
}
void* vec_pop(vector_t* vec)
{
    if (!vec || vec->len == 0) return NULL;
    return vec->data[--vec->len];
}