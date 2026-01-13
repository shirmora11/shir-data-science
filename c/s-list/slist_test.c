#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "slist.h"
int main() {
    // Create list first
    sll_t* list = sll_create();

    sll_append(list, (void*)(uintptr_t)10);
    sll_append(list, (void*)(uintptr_t)20);
    sll_append(list, (void*)(uintptr_t)30);
    sll_append(list, (void*)(uintptr_t)40);
    
    printf("List after appending: ");
    sll_for_each(list, print_int);
    printf("\n");
    printf("Count: %zu\n", sll_get_count(list));

    node_t* head = sll_get_head(list);
    if (head != NULL) {
        printf("Current head value: %d\n", (int)(uintptr_t)sll_get_data(head));
    }

    sll_prepend(list, (void*)(uintptr_t)5);
    printf("After prepending 5 at head: ");
    sll_for_each(list, print_int);
    printf("\n");

    head = sll_get_head(list);
    if (head != NULL) {
        printf("New head value: %d\n", (int)(uintptr_t)sll_get_data(head));
    }
    
    node_t* found = sll_find(list, (void*)(uintptr_t)20, match_int);
    if (found != NULL) {
        printf("Found element: %d\n", (int)(uintptr_t)sll_get_data(found));
        
        sll_insert(list, found, (void*)(uintptr_t)25);
        printf("After inserting 25 after 20: ");
        sll_for_each(list, print_int);
        printf("\n");
    }
    
    void* popped = sll_pop(list);
    printf("Popped: %d\n", (int)(uintptr_t)popped);
    printf("After pop: ");
    sll_for_each(list, print_int);
    printf("\n");
    
    node_t* to_remove = sll_find(list, (void*)(uintptr_t)30, match_int);
    if (to_remove != NULL) {
        sll_remove(list, to_remove);
        printf("After removing 30: ");
        sll_for_each(list, print_int);
        printf("\n");
    }
    printf("Final count: %zu\n", sll_get_count(list));
    
    sll_destroy(list);
    printf("List destroyed.\n");
    
    return 0;
}