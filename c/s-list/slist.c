#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// Structure definitions
typedef struct sll_t sll_t;
typedef struct node_t node_t;
typedef int(*for_each_func)(void*);
typedef int(*match_func)(void*, void*);
struct node_t {
    void* data;
    struct node_t* next;
};
//dummy node
struct sll_t {
    node_t* dummy;  
    node_t* tail;   
    size_t count;
};

sll_t* sll_create(void) {
    sll_t* list = malloc(sizeof(sll_t));
    if (list == NULL) return NULL;
    
    list->dummy = malloc(sizeof(node_t));
    if (list->dummy == NULL) {
        free(list);
        return NULL;
    }

    list->dummy->data = NULL;
    list->dummy->next = NULL;
    list->tail = list->dummy;  
    list->count = 0;
    
    return list;
}

// Get the head node (first real node after dummy)
node_t* sll_get_head(sll_t* list) {
    if (list == NULL || list->dummy == NULL) return NULL;
    return list->dummy->next;
}


node_t* sll_append(sll_t* list, void* data) {
    if (list == NULL) return NULL;
    
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) return NULL;
    
    new_node->data = data;
    new_node->next = NULL;

    list->tail->next = new_node;
    list->tail = new_node;
    list->count++;
    
    return new_node;
}

node_t* sll_prepend(sll_t* list, void* data) {
    if (list == NULL) return NULL;
    
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) return NULL;
    
    new_node->data = data;
    new_node->next = list->dummy->next;
    list->dummy->next = new_node;
    
    // If list was empty, update tail
    if (list->tail == list->dummy) {
        list->tail = new_node;
    }
    
    list->count++;
    return new_node;
}

node_t* sll_insert(sll_t* list, node_t* where, void* data) {
    if (list == NULL) return NULL;
    
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) return NULL;
    
    new_node->data = data;
    

    if (where == NULL) {
        new_node->next = list->dummy->next;
        list->dummy->next = new_node;
        
        if (list->tail == list->dummy) {
            list->tail = new_node;
        }
    } 
    else {
        new_node->next = where->next;
        where->next = new_node;
        if (where == list->tail) {
            list->tail = new_node;
        }
    }
    list->count++;
    return new_node;
}

void* sll_get_data(node_t* node) {
    return (node == NULL) ? NULL : node->data;
}

void sll_set_data(node_t* node, void* data) 
{
    node->data;
}

void* sll_pop(sll_t* list) {
    if (list == NULL || list->dummy->next == NULL) return NULL;
    
    node_t* to_pop = list->dummy->next;
    void* data = to_pop->data;
    
    list->dummy->next = to_pop->next;
    
    if (list->tail == to_pop) {
        list->tail = list->dummy;
    }
    free(to_pop);
    list->count--;
    return data;
}

node_t* sll_get_next(node_t* node) {
    return (node == NULL) ? NULL : node->next;
}

void sll_destroy(sll_t* list) {
    if (list == NULL) return;
    node_t* current = list->dummy;
    node_t* next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
}

size_t sll_get_count(const sll_t* list) {
    return (list == NULL) ? 0 : list->count;
}

int sll_remove(sll_t* list, node_t* to_remove) {
    if (list == NULL || to_remove == NULL) return -1;

    node_t* current = list->dummy;
    while (current != NULL && current->next != to_remove) {
        current = current->next;
    }
    if (current == NULL || current->next != to_remove) return -1;
    
    current->next = to_remove->next;

    if (list->tail == to_remove) {
        list->tail = current;
    }
    free(to_remove);
    list->count--;
    
    return 0;
}

int sll_for_each(sll_t* list, for_each_func func) {
    if (list == NULL || func == NULL) return -1;
    
    node_t* current = list->dummy->next;
    while (current != NULL) {
        int result = func(current->data);
        if (result != 0) {
            return -1;  
        }
        current = current->next;
    }
    
    return 0;
}

node_t* sll_find(sll_t* list, void* param, match_func func) {
    if (list == NULL || func == NULL) return NULL;
    
    node_t* current = list->dummy->next;
    while (current != NULL) {
        if (func(current->data, param) != 0) {
            return current;  
        }
        current = current->next;
    }
    return NULL; 
}

int print_int(void* data) 
{
    printf("%d ", (int)(uintptr_t)data);
    return 0;
}

int match_int(void* data, void* param) 
{
    return ((int)(uintptr_t)data == (int)(uintptr_t)param);
}