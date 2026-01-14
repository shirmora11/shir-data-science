#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

struct node_t {
    void* data;
    struct node_t* next;
};

struct sll_t {
    node_t* head;
    node_t* dummy; 
    size_t count;
};

sll_t* sll_create(void) {
    sll_t* list = malloc(sizeof(sll_t));
    if (!list) return NULL;
    list->dummy = malloc(sizeof(node_t));
    if (!list->dummy) { free(list); return NULL; }
    
    list->dummy->data = NULL;
    list->dummy->next = NULL;
    list->head = list->dummy;
    list->count = 0;
    return list;
}

node_t* sll_get_head(sll_t* list) {
    if (!list || list->head == list->dummy) return NULL;
    return list->head;
}

// O(1) Append using the dummy node swap
node_t* sll_append(sll_t* list, void* data) {
    if (!list) return NULL;
    node_t* new_dummy = malloc(sizeof(node_t));
    if (!new_dummy) return NULL;
    
    new_dummy->data = NULL;
    new_dummy->next = NULL;

    node_t* actual_node = list->dummy;
    actual_node->data = data;
    actual_node->next = new_dummy;
    
    if (list->head == list->dummy) list->head = actual_node;
    
    list->dummy = new_dummy;
    list->count++;
    return actual_node;
}

node_t* sll_insert(sll_t* list, node_t* where, void* data) {
    if (!list || !where) return NULL;
    node_t* new_node = malloc(sizeof(node_t));
    if (!new_node) return NULL;
    
    new_node->data = data;
    new_node->next = where->next;
    where->next = new_node;
    
    list->count++;
    return new_node;
}

int sll_remove(sll_t* list, node_t* to_remove) {
    if (!list || !to_remove || to_remove == list->dummy) return -1;

    node_t* next_node = to_remove->next;
    
    to_remove->data = next_node->data;
    to_remove->next = next_node->next;

    if (next_node == list->dummy) {
        list->dummy = to_remove;
    }

    free(next_node);
    list->count--;
    return 0;
}

node_t* sll_find(sll_t* list, void* param, match_func func) {
    if (!list || !func) return NULL;
    node_t* curr = list->head;
    while (curr != list->dummy) {
        if (func(curr->data, param)) return curr;
        curr = curr->next;
    }
    return NULL;
}

void* sll_pop(sll_t* list) {
    if (!list || list->head == list->dummy) return NULL;
    node_t* to_pop = list->head;
    void* data = to_pop->data;
    list->head = to_pop->next;
    free(to_pop);
    list->count--;
    return data;
}

node_t* sll_get_next(node_t* node) {
    if (!node || node->next == NULL || node->next->next == NULL) return NULL;
    return node->next;
}

void sll_set_data(node_t* node, void* data) { if (node) node->data = data; }
void* sll_get_data(node_t* node) { return node ? node->data : NULL; }
size_t sll_get_count(const sll_t* list) { return list ? list->count : 0; }

int sll_for_each(sll_t* list, for_each_func func) {
    if (!list || !func) return -1;
    node_t* curr = list->head;
    while (curr != list->dummy) {
        if (func(curr->data) != 0) return -1;
        curr = curr->next;
    }
    return 0;
}

void sll_destroy(sll_t* list) {
    if (!list) return;
    node_t* curr = list->head;
    while (curr != NULL) {
        node_t* next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}