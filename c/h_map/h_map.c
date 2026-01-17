#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MAX_WORD_LEN 256
typedef struct pair_t {
    void *key;
    void *value;
} pair_t;

typedef struct sll_t {
    pair_t* kv; //key/values pair
    size_t count;
    struct sll_t *next; 
} sll;

typedef int (*hashfunction_pointer)(void*, int);
typedef struct hash_table {
    size_t size;      
    sll **buckets;  
    hashfunction_pointer hashfunc;
} hashmap_t;



static int stringhash(void* key, int num_of_buckets){
    const char *str = (const char*)key;
    unsigned long hash = 531;
    int c;
    while ((c = (unsigned char)*str++)) {
        hash = ((hash << 7) + hash) + c;  
    }
    return (int)(hash % num_of_buckets);
}

hashmap_t* hm_create(size_t num_of_buckets){
    hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
    map->size = num_of_buckets;
    map->buckets = (sll**)malloc(sizeof(sll*) * num_of_buckets);
    for (size_t i = 0; i < num_of_buckets; ++i){
        map->buckets[i] = NULL;
    }
    map->hashfunc = stringhash;
    return map;
}

int hm_insert(hashmap_t* hash, void* value) {
    pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
    newpair->key = malloc(strlen((char*)value) + 1);
    strcpy((char*)newpair->key, (char*)value);
    newpair->value = value;

    sll* newnode = (sll*)malloc(sizeof(sll));
    newnode->kv = newpair;  
    
    int bucket = hash->hashfunc(value, (int)hash->size);
    
    newnode->next = hash->buckets[bucket];
    hash->buckets[bucket] = newnode;
    return 0;
}

void hm_destroy(hashmap_t* hash){
    for (size_t i = 0; i < hash->size; ++i) {
        sll *current = hash->buckets[i];
        while (current != NULL) {
            sll *next = current->next;
            free(current->kv->key);
            free(current->kv);
            free(current);
            current = next;
        }
    }
    free(hash->buckets);
    free(hash);
}

size_t hm_size(const hashmap_t* hash) {
    if (hash == NULL) return 0;
    
    size_t total_items = 0;
    for (int i = 0; i < (int)hash->size; ++i) {
        sll *current = hash->buckets[i];
        while (current != NULL) {
            total_items++;
            current = current->next;
        }
    }
    return total_items;
}

int hm_is_empty(const hashmap_t* hash){
    if (hash==NULL){
        printf(" is empty: 0\n");
    }else {
        printf("have something ask get size\n");
    }
    return 0;
}


void* hm_find(const hashmap_t* hash, const void* key){
    void* found_it = NULL;
    unsigned int index = hash->hashfunc((void*)key,(int)hash->size);
    sll *current = hash->buckets[index];
    while (current != NULL) {
        if (strcmp((char*)current->kv->key,(char*)key)==0){
            found_it = current->kv->key;
            break;
        }
        current = current->next;
    }
    return found_it;
}


void* hm_remove(hashmap_t* hash, const void* key){
    unsigned int index = hash->hashfunc((void*)key, (int)hash->size);
    sll *current = hash->buckets[index];
    sll *prev = NULL;
    while (current != NULL) {
        if (strncmp((const char*)current->kv->key, (const char*)key, MAX_WORD_LEN) == 0) {
            if (prev == NULL) {
                hash->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            void* value = current->kv;
            free(current->kv);
            free(current);
            return value;
        }
        prev = current;
        current = current->next;
    }
    
    return NULL;
}

int hm_foreach(hashmap_t* hash){
    for (int i = 0; i<(int)hash->size;++i){
        sll *current = hash->buckets[i];
        if (current == NULL){
            printf("bucket%d: \t empty\n",i);
        }else {
            while(current != NULL){
                printf("bucket%d: \t %s\n",i, (char*)current->kv->key);
                current = current->next;
            }
        }   
    }
    return 0;
}
int hm_upload_dict(hashmap_t* hash){
    FILE* file = fopen("/usr/share/dict/words", "r");
    if (!file) {
        perror("Failed to open dictionary");
        return -1;
    }
    char buffer[MAX_WORD_LEN];
    while (fgets(buffer, MAX_WORD_LEN, file)) {

        buffer[strcspn(buffer, "\n")] = 0;
        char* word = strdup(buffer);
    
        hm_insert(hash, word);
    }

    fclose(file);
    return 0;
}
///void is_sum_found(hash_table * hash){
    
////}


int main() {
    size_t buckets = 50000;
    hashmap_t* hash = hm_create(buckets);
    size_t size = hm_size(hash);
    hm_is_empty(hash);
    hm_upload_dict(hash);
    printf("Size of the hash table: %zu\n", size);
    void* find_zebra = hm_find(hash,"zebra");
    printf("found zebra at: %d\n",find_zebra);
    hm_remove(hash,"zebra");
    hm_foreach(hash);

    hm_destroy(hash);
    return 0;
}
