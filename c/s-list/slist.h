#ifndef SLIST_H
#define SLIST_H
#include <stddef.h>
 // for each function that help the sll_for each i did it to just print all
typedef int(*for_each_func)(void*);
// match function that ask what do you want to match with
typedef int(*match_func)(void*, void*); 
//the struct decloration
typedef struct sll_t sll_t; 
//dummy node for the head
typedef struct node_t node_t; 

//creating the linked list returns null if gone wrong
sll_t* sll_create(void);

//get the head so we can see the first in line
node_t* sll_get_head(sll_t* list);

//add to the end if cant add return null
node_t* sll_append(sll_t* list, void* data);

//insert the data where you want it on the node
node_t* sll_insert(sll_t* list, node_t* where, void* data);

//asking the data if data not avalible return null
void* sll_get_data(node_t* node); 

// set the data in the wanted node if node not exist return null
void sll_set_data(node_t* node, void* data); 

//poping the head form the list if no head then null
void* sll_pop(sll_t* list);

//asking the whats the next in line if thats the tail return null
node_t* sll_get_next(node_t* node);

//destory the list
void sll_destroy(sll_t* list);

//getting how many elements we have left
size_t sll_get_count(const sll_t* list);

// remove the element asking for if node dont exist return null
int sll_remove(sll_t* list, node_t* to_remove);
//for each function i did it to print all helped with testing
int sll_for_each(sll_t* list, for_each_func func);

// match function asked what paraneter you want to match if none are matching return null
node_t* sll_find(sll_t* list, void* param, match_func func);

#endif