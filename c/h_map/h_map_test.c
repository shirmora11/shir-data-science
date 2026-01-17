int main() {
    size_t buckets = 11;
    hashmap_t* hash = hm_create(buckets);

    hm_insert(hash, "waldo");
    hm_insert(hash, "dr.house");
    hm_insert(hash, "jeff besos");
    hm_insert(hash, "micheal jordan");
    print_keyValues(hash);

    size_t size = hm_size(hash);
    hm_is_empty(hash);
    printf("Size of the hash table: %zu\n", size);
    void* find_waldo = hm_find(hash,"waldo");
    printf("found waldo at: %p\n",find_waldo);
    hm_remove(hash,"waldo");
    hm_foreach(hash);
    hm_destroy(hash);
    return 0;
}