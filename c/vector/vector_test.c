
#include "vector.h"
int main(){
    size_t capacity = 10;
    vector_t* my_vec = vec_create(capacity);
    int numbers[10]; 
    for (int i = 0; i < 10; i++) /// Pushing elements into the vector
    {
        numbers[i] = i + 1; 
        vec_push(my_vec, &numbers[i]);
        printf("Pushed: %d\n", numbers[i]);
    }
    for (size_t i = 0; i < 5; i++) /// Popping elements from the vector
    {
        int* val = (int*)vec_pop(my_vec);
        if (val) {
            printf("Popped: %d\n", *val);
        }
    }
    for (size_t i = 0; i < my_vec->len; i++) // Accessing remaining elements
    {
        int* val = (int*)vec_get_element(my_vec, i);
        if (val) {
            printf("Element at index %zu: %d\n", i, *val);
        }
    }
    vec_set_element(my_vec, 0, &numbers[1]);// Setting an element in the vector
    printf("After setting, element at index 0: %d\n", *(int*)vec_get_element(my_vec, 0));

    vec_get_size(my_vec);// Getting size of the vector
    printf("Vector size: %zu\n", vec_get_size(my_vec));
    vec_get_capacity(my_vec);// Getting capacity of the vector
    printf("Vector capacity: %zu\n", vec_get_capacity(my_vec));
    vec_destroy(my_vec);// Destroying the vector
    return 0;
}