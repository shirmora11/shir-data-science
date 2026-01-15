#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct pair_t {
    void *key;
    void *value;
} pair_t;

typedef struct sll_t {
    pair_t* kv;//key/value pair
    size_t count;
    struct node_t *next;
} sll;

int stringhash(void* key, int num_of_buckets){
    const char *str = (const char*)key;

    unsigned long hash = 5381;
    int c;
    while ((c = (unsigned char)*str++)) {
        hash = ((hash << 5) + hash) + c;  
    }
    return (int)hash % num_of_buckets;
}

typedef int (*hashfunction_pointer)(void*, int);


typedef struct hash_table {
    size_t size;      
    sll **buckets;  
    hashfunction_pointer hashfunc;

} hashmap_t;


hashmap_t* hm_create(size_t num_of_buckets/*, hash_func hfunc, compare_func cfunc*/){
    hashmap_t* map =(hashmap_t*)malloc(sizeof(hashmap_t));
    map->size = num_of_buckets;

    map->buckets = (sll**)malloc(sizeof(sll*)*num_of_buckets);
    for (int i=0;i<num_of_buckets;++i){
        map->buckets[i]=NULL;
    }
    map->hashfunc=stringhash;
    return map;
}










int hm_insert(hashmap_t* hash, pair_t* key_value){
    pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
    newpair->key= (void*)malloc(strlen(key_value->key)*sizeof(void*)+1);
    newpair->value = key_value->value;
    strcpy(newpair->key, (char*)key_value->key);

    sll* newnode = (sll*)malloc(sizeof(sll));
    newnode->kv = newpair;  
    newnode->next = NULL;

    unsigned int bucket = hash->hashfunc(key_value->key, hash->size);
    if (hash->buckets[bucket]==NULL){
        hash->buckets[bucket]= newnode;

    }else{
        newnode->next = hash->buckets[bucket];
        hash->buckets[bucket]=newnode;
    }

}









static void print_keyValues(hashmap_t *hash) {
    if (hash == NULL) return;

    for (int i = 0; i < (int)hash->size; ++i) {
        printf("Bucket %d:", i);
        
        // In your code, the nodes are type 'sll'
        sll *current = hash->buckets[i];
        
        if (current == NULL) {
            printf("\t---\n");
        } else {
            while (current != NULL) {
                // Access key via the 'kv' pointer in the 'sll' struct
                printf(" -> [%s]", (char*)current->kv->key);
                current = (sll*)current->next; // Cast next to sll*
            }
            printf("\n");
        }
    }
}






/*int hm_insert(map* hash, const void* key, void* value){
    for ()
}*/

typedef int(*for_each_func)(void*, void*); 
typedef size_t(*hash_func)(void*);
typedef int(*compare_func)(void*, void*);

/*void hm_destroy(hash_map_t* hash);
void* hm_remove(hash_map_t* hash, const void* key);// insert of the same key twice caus the value to be update  
size_t hm_size(const hash_map_t* hash);
int hm_is_empty(const) hash_map_t* hash);
void* hm_find(const hash_map_t* hash, const void* key);
int hm_foreach(hash_map_t* hash, for_each_func func, void* params);*/

int main() {
    size_t buckets = 8;
    hashmap_t* hash = hm_create(buckets);
    
    // hm_insert expects a pair_t*, so we wrap the strings:
    hm_insert(hash, create_pair("mike", NULL));
    hm_insert(hash, create_pair("dr. house", NULL));
    hm_insert(hash, create_pair("jeff besos", NULL));
    hm_insert(hash, create_pair("micheal jordan", NULL));

    print_keyValues(hash);
    
    // Note: You should ideally free the pairs and the map here
    return 0;
}