#ifndef SLIST_H
#define SLIST_H
#include <stddef.h>
sll_t* sll_create(void);
node_t* sll_get_head(sll_t* list);
node_t* sll_append(sll_t* list, void* data); // returns NULL for failure
node_t* sll_insert(sll_t* list, node_t* where, void* data); // returns NULL for failure
void* sll_get_data(node_t* node);
void sll_set_data(node_t* node, void* data);
void* sll_pop(sll_t* list); //pop head
node_t* sll_get_next(node_t* node);
void sll_destroy(sll_t* list);
size_t sll_get_count(const sll_t* list); // what does this do?
int sll_remove(sll_t* list, node_t* to_remove);
int sll_for_each(sll_t* list, for_each_func func);
node_t* sll_find(sll_t* list, void* param, match_func func); // returns NULL for failure

#endif