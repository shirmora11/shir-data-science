#include <stdio.h>
#include "vector.h"

int main(){
    size_t capacity = 10;
    vector_t* my_vec = vec_create(capacity);
    int numbers[10]; 

    // 1. Pushing
    for (int i = 0; i < 10; i++) {
        numbers[i] = i + 1; 
        vec_push(my_vec, &numbers[i]);
        printf("Pushed: %d\n", numbers[i]);
    }

    // 2. Popping
    for (size_t i = 0; i < 5; i++) {
        int* val = (int*)vec_pop(my_vec);
        if (val) {
            printf("Popped: %d\n", *val); // This should now work!
        }
    }

    // 3. Remaining Elements
    printf("Remaining elements:\n");
    for (size_t i = 0; i < vec_get_size(my_vec); i++) {
        int* element = (int*)vec_get_element(my_vec, i);
        printf("Element %zu: %d\n", i, *element); 
    }

    // 4. Set/Get Check
    vec_set_element(my_vec, 0, &numbers[1]);
    printf("After setting index 0 to value 2: %d\n", *(int*)vec_get_element(my_vec, 0));

    printf("Vector size: %zu\n", vec_get_size(my_vec));
    printf("Vector capacity: %zu\n", vec_get_capacity(my_vec));

    vec_destroy(my_vec);
    return 0;
}