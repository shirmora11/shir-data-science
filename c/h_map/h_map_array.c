#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct pair_t {
    void *key;
    void *value;
} pair_t;

typedef struct sll_t {
    pair_t* kv; 
    struct sll_t *next; 
} sll;

typedef int (*hashfunction_pointer)(void*, int);
typedef struct hash_table {
    size_t size;      
    sll **buckets;  
    hashfunction_pointer hashfunc;
} hashmap_t;

static int inthash(void* key, int num_of_buckets){
    return (int)((uintptr_t)key % num_of_buckets);
}

hashmap_t* hm_create(size_t num_of_buckets){
    hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
    map->size = num_of_buckets;
    map->buckets = (sll**)malloc(sizeof(sll*) * num_of_buckets);
    for (size_t i = 0; i < num_of_buckets; ++i){
        map->buckets[i] = NULL;
    }
    map->hashfunc = inthash;
    return map;
}

int hm_insert(hashmap_t* hash, void* key) {
    pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
    newpair->key = key;  
    newpair->value = key;

    sll* newnode = (sll*)malloc(sizeof(sll));
    newnode->kv = newpair;  
    
    int bucket = hash->hashfunc(key, (int)hash->size);
    
    newnode->next = hash->buckets[bucket];
    hash->buckets[bucket] = newnode;
    return 0;
}

void hm_destroy(hashmap_t* hash){
    for (size_t i = 0; i < hash->size; ++i) {
        sll *current = hash->buckets[i];
        while (current != NULL) {
            sll *next = current->next;
            free(current->kv);
            free(current);
            current = next;
        }
    }
    free(hash->buckets);
    free(hash);
}

void* hm_find(const hashmap_t* hash, const void* key){
    unsigned int index = hash->hashfunc((void*)key, (int)hash->size);
    sll *current = hash->buckets[index];
    while (current != NULL) {
        if (current->kv->key == key){
            return current->kv->key;
        }
        current = current->next;
    }
    return NULL;
}

int hm_foreach(hashmap_t* hash) {
    for (int i = 0; i < (int)hash->size; ++i) {
        sll *current = hash->buckets[i];
        if (current == NULL) {
            printf("bucket %d: \t empty\n", i);
        } else {
            while (current != NULL) {
                printf("bucket %d:\t %d\n", i, (int)(uintptr_t)current->kv->key);
                current = current->next;
            }
        }   
    }
    return 0;
}
int is_sum_found (hashmap_t *hash, int *arr, int target, int size) {
    for (int i = 0; i < size; i++) {
        int complement = target - arr[i];
        
        if (hm_find(hash, (void*)(uintptr_t)complement) != NULL) {
            return complement;
        }
        hm_insert(hash, (void*)(uintptr_t)arr[i]);
    }
    return -1;
}

int main() {
    int arr[] = {4, 6, 8, 10, 15, 36, 37, 24, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 20; 
    
    hashmap_t* hash = hm_create(size);

    int result = is_sum_found(hash, arr, target, size);
    if (result != -1) {
        printf("Success! Found a pair. Numbers: %d and %d\n", result, target - result);
    } else {
        printf("No pair found for target %d\n", target);
    }
    hm_foreach(hash);

    hm_destroy(hash); 
    return 0;
}