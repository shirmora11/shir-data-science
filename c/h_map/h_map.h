#include <stddef.h>

typedef struct pair_t{
    const void* key;
    void* value;
} pair_t;

hash_map_t* hm_create(size_t num_of_buckets, hash_func hfunc, compare_func cfunc);


int hm_insert(hash_map_t* hash, pair_t* key_value);




void hm_destroy(hash_map_t* hash);
void* hm_remove(hash_map_t* hash, const void* key);// insert of the same key twice caus the value to be update  
int hm_insert(hash_map_t* hash, pair_t* key_value);
size_t hm_size(const hash_map_t* hash);
int hm_is_empty(const hash_map_t* hash);
void* hm_find(const hash_map_t* hash, const void* key);//return value
int hm_foreach(hash_map_t* hash, hm_for_each_func func, void* params);


