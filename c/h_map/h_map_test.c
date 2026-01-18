#include "h_map.h"
#include <stdio.h>

int main() {
    printf("--- Initializing Hashmap Test ---\n");
    hashmap_t* hash = hm_create(1000);

    printf("Uploading dictionary...\n");
    hm_upload_dict(hash);

    printf("Inserting 'waldo'...\n");
    hm_insert(hash, "waldo");

    size_t count = hm_size(hash);
    printf("Current Size: %zu\n", count);

    if (hm_find(hash, "waldo")) {
        printf("Found 'waldo' in map!\n");
    }

    hm_is_empty(hash);

    printf("Removing 'waldo'...\n");
    hm_remove(hash, "waldo");

    if (hm_find(hash, "waldo") == NULL) {
        printf("'waldo' successfully removed.\n");
    }

    hm_foreach(hash);

    printf("Cleaning up...\n");
    hm_destroy(hash);

    printf("Test completed successfully.\n");
    return 0;
}