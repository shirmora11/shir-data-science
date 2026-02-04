#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct GenericStack {
    StackNode *top;
    size_t element_size;
} GenericStack;

GenericStack* create_stack(size_t element_size) {
    GenericStack *stack = malloc(sizeof(GenericStack));
    if (!stack) {
        perror("Failed to allocate memory for stack");
        return NULL;
    }
    stack->top = NULL;
    stack->element_size = element_size;
    return stack;
}