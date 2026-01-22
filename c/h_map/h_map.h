#ifndef H_MAP_H
#define H_MAP_H
#include <stddef.h>
#include <stdbool.h>
#define MAX_WORD_LEN 256
typedef struct pair_t {
    void *key;
    void *value;
} pair_t;

typedef struct sll_t {
    pair_t* kv; 
    size_t count;
    struct sll_t *next; 
} sll;

typedef int (*hashfunction_pointer)(void*, int);

typedef struct hash_table {
    size_t size;      
    sll **buckets;  
    hashfunction_pointer hashfunc;
} hashmap_t;
/// create the map if failed need more space
hashmap_t* hm_create(size_t num_of_buckets);
//will need to insert noraml values and charactersfor it to work anything else will cause an error
int hm_insert(hashmap_t* hash, pair_t* key_value);

//basic free memory cant fail
void hm_destroy(hashmap_t* hash);

//getting the size of the hash if hash not exist will cause an error
size_t hm_size(const hashmap_t* hash);

//checks if empty
int hm_is_empty(const hashmap_t* hash);

//return value that was asked
void* hm_find(const hashmap_t* hash, const void* key);

//find the requsted value if asking for NULL or non exesting stuff will return NULL
void* hm_find(const hashmap_t* hash, const void* key);

// wil remove the wanted key if its the wrong key or bad one will return NULL
void* hm_remove(hashmap_t* hash, const void* key);
/// for each of the hash i decided to print it all and give a good represintation of what its looking like
int hm_foreach(hashmap_t* hash);
//uploading the dic
int hm_upload_dict(hashmap_t* hash);


#endif