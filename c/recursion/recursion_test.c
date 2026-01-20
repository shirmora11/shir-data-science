#include "recursion.h"

int main (){
    int num = 6;
    printf("the six number is %d\n", fibonaci_int(num));
    fibonachi_rec(num);

    char str[] = "shir";
    rec_strlen(str);
    const char str2[] = "adi";
    rec_strcmp(str, str2);

    int len = strlen(str);
    permutation(str, 0, len - 1);
    
    Node *head = list();
    printf("original list:\n");
    foreach(head);

    head = flip_list(head);
    printf("lipped list:\n");
    foreach(head);

    // Free memory
    Node *curr = head;
    while (curr != NULL) {
        Node *next = curr->next; 
        free(curr);        
        curr = next;       
    }
    unsigned arr[] = {5, 7, 9, 13, 17};
    unsigned bignum = 10710;
    int size = sizeof(arr) / sizeof(arr[0]);
    multy(bignum, arr, size);

    return 0;
}