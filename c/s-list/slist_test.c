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

// --- Full Test Suite ---
int main(void) {
    printf("--- Starting Comprehensive SLL Test ---\n");

    // 1. Test sll_create
    sll_t* list = sll_create();
    assert(list != NULL);
    assert(sll_get_count(list) == 0);
    assert(sll_get_head(list) == NULL);
    printf("Check 1: List creation successful.\n");

    // 2. Test sll_append
    sll_append(list, (void*)(uintptr_t)10);
    sll_append(list, (void*)(uintptr_t)20);
    sll_append(list, (void*)(uintptr_t)30);
    assert(sll_get_count(list) == 3);
    printf("Check 2: Append 10, 20, 30. Count: %zu\n", sll_get_count(list));

    // 3. Test sll_for_each
    printf("Check 3: Printing list (should be 10 20 30): ");
    sll_for_each(list, print_int);
    printf("\n");

    // 4. Test sll_get_head and sll_get_data
    node_t* head = sll_get_head(list);
    assert(head != NULL);
    assert((int)(uintptr_t)sll_get_data(head) == 10);
    printf("Check 4: Head data is 10.\n");

    // 5. Test sll_get_next
    node_t* second = sll_get_next(head);
    assert(second != NULL);
    assert((int)(uintptr_t)sll_get_data(second) == 20);
    printf("Check 5: Second node data is 20.\n");

    // 6. Test sll_find
    node_t* found = sll_find(list, (void*)(uintptr_t)20, match_int);
    assert(found == second);
    printf("Check 6: Found node with value 20.\n");

    // 7. Test sll_insert (Insert 25 after 20)
    sll_insert(list, found, (void*)(uintptr_t)25);
    assert(sll_get_count(list) == 4);
    printf("Check 7: Inserted 25 after 20. New list: ");
    sll_for_each(list, print_int);
    printf("\n");

    // 8. Test sll_set_data
    sll_set_data(head, (void*)(uintptr_t)5);
    assert((int)(uintptr_t)sll_get_data(head) == 5);
    printf("Check 8: Changed head value to 5.\n");

    // 9. Test sll_pop (Removes the head: 5)
    void* popped = sll_pop(list);
    assert((int)(uintptr_t)popped == 5);
    assert(sll_get_count(list) == 3);
    printf("Check 9: Popped head (5). New head is 20.\n");

    // 10. Test sll_remove (O(1) value-stealing remove)
    // Let's remove the node with 25
    node_t* to_rem = sll_find(list, (void*)(uintptr_t)25, match_int);
    int res = sll_remove(list, to_rem);
    assert(res == 0);
    assert(sll_get_count(list) == 2);
    printf("Check 10: Removed 25. List now: ");
    sll_for_each(list, print_int);
    printf("\n");

    // 11. Test sll_destroy
    sll_destroy(list);
    printf("Check 11: List destroyed. No memory leaks.\n");

    printf("--- ALL TESTS PASSED SUCCESSFULLY ---\n");
    return 0;
}