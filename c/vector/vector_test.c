#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
int main(){
    size_t capacity = 10;
    vector_t* my_vec = vec_create(capacity);
    int numbers[10]; 
    printf("--- Pushing numbers 1 to 10 ---\n");
    for (int i = 0; i < 10; i++) 
    {
        numbers[i] = i + 1; 
        vec_push(my_vec, &numbers[i]);
    }
    printf("--- Reading from vector ---\n");
    for (size_t i = 0; i < my_vec->len; i++) 
    {
        int* val = (int*)vec_get_element(my_vec, i);
        if (val) {
            printf("Element at index %zu: %d\n", i, *val);
        }
    }
    printf("--- Popping elements from vector ---\n");
    for (size_t i = 0; i < 5; i++) 
    {
        int* val = (int*)vec_pop(my_vec);
        if (val) {
            printf("Popped element: %d\n", *val);
        }
    }
    for (size_t i = 0; i < my_vec->len; i++) 
    {
        int* val = (int*)vec_get_element(my_vec, i);
        if (val) {
            printf("Element at index %zu: %d\n", i, *val);
        }
    }
    printf("--- Final vector state ---\n");
    printf("Vector size: %zu\n", vec_get_size(my_vec));
    printf("Vector capacity: %zu\n", vec_get_capacity(my_vec));
    vec_destroy(my_vec);
    printf("--- Vector test completed ");
    return 0;
}