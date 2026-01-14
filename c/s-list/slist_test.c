#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "slist.h"

// --- Helper Functions ---
int print_int(void* data) {
    printf("%d ", (int)(uintptr_t)data);
    return 0;
}

int match_int(void* data, void* param) {
    return ((int)(uintptr_t)data == (int)(uintptr_t)param);
}


int main(void) {
    sll_t* list = sll_create();
    printf("Check if List creation successful.\n");

    sll_append(list, (void*)(uintptr_t)10);
    sll_append(list, (void*)(uintptr_t)20);
    sll_append(list, (void*)(uintptr_t)30);
    assert(sll_get_count(list) == 3);
    printf("Check if Append 10, 20, 30. Count: %zu\n", sll_get_count(list));

    printf("Check if Printing list (should be 10 20 30): ");
    sll_for_each(list, print_int);

    node_t* head = sll_get_head(list);
    assert(head != NULL);
    assert((int)(uintptr_t)sll_get_data(head) == 10);
    printf("Check if Head data is 10.\n");

    node_t* second = sll_get_next(head);
    assert(second != NULL);
    assert((int)(uintptr_t)sll_get_data(second) == 20);
    printf("Check if Second node data is 20.\n");

    node_t* found = sll_find(list, (void*)(uintptr_t)20, match_int);
    assert(found == second);
    printf("Check if Found node with value 20.\n");

    sll_insert(list, found, (void*)(uintptr_t)25);
    assert(sll_get_count(list) == 4);
    printf("Check if Inserted 25 after 20. New list: ");
    sll_for_each(list, print_int);

    sll_set_data(head, (void*)(uintptr_t)5);
    assert((int)(uintptr_t)sll_get_data(head) == 5);
    printf("Check if Changed head value to 5.\n");

    void* popped = sll_pop(list);
    assert((int)(uintptr_t)popped == 5);
    assert(sll_get_count(list) == 3);
    printf("Check if Popped head (5). New head is 20.\n");

    node_t* to_rem = sll_find(list, (void*)(uintptr_t)25, match_int);
    int res = sll_remove(list, to_rem);
    assert(res == 0);
    assert(sll_get_count(list) == 2);
    printf("Check if Removed 25. List now: ");
    sll_for_each(list, print_int);

    sll_destroy(list);
    printf("Check if List destroyed. No memory leaks.\n");

    return 0;
}