#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include "recursion.h"

int fibonaci_int(int num){
    int first = 0;
    int second = 1;
    int third = 1;
    if (num == 1){return first;}
    if (num == 2 || num == 3){return second;}
    for (int i = 2;i<=num;++i){
        int temp = first;
        first = second;
        second = second + temp;
        third = first +temp;
    }
    return third;
}
int fibonachi_rec(int num){
    if (num == 1){return num;}
    else if(num == 2 ){return 1;}
    else {
        return (fibonachi_rec(num-1)+fibonachi_rec(num-2));
    }
}


int rec_strlen(const char *str){
    if (*str == '\0'){return 0;}
    return (1 + rec_strlen(str+1));
}
int rec_strcmp(const char *str1, const char *str2){
    if (*str1 && *str2 == '\0'){return 0;}
    if (*str1 == '\0' || *str2 == '\0'){return (*str1-*str2);}
    if (*str1 != *str2){return (*str1-*str2);}
    return rec_strcmp(str1+1 , str2+1);
}

static void swap(char *s , char *h){
    char temp;
    temp = *s;
    *s= *h;
    *h = temp;
}
void permutation(char *str , int left , int right){
    int i;
    if (left == right){
        printf("%s\n",str);
    }else{
        for (i = left ; i  <= right ; ++i){
            swap((str+left),(str+i));
            permutation(str,left+1,right);
            swap((str+left),(str+i));
        }
    }
}

Node* list(){
    Node *head = malloc(sizeof(Node));
    assert(head!=0);
    Node * curr = malloc(sizeof(Node));
    assert(curr!=0);
    Node *next_node= malloc(sizeof(Node));
    assert(next_node!=0);
    Node *temp= malloc(sizeof(Node));
    assert(temp !=0);
    head->next = curr;
    curr->next = next_node;
    next_node->next = temp;
    temp->next = NULL;
    head->data =1;
    curr->data=2;
    next_node->data=3;
    temp->data = 4;
    return head;
}

Node* flip_list(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node * head_reverse = flip_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return head_reverse;
}
void foreach(Node* head){
    Node *curr =head;
    while (curr != NULL){
        printf("%d\n",curr->data);
        curr= curr->next;
    }
}

unsigned multy(unsigned bignum, unsigned *arr, int size) {
    if (size <= 0 || bignum <= 1) {
        return bignum;
    }
    if (arr[0] <= 1) {
        return multy(bignum, arr + 1, size - 1);
    }
    if ((bignum % arr[0]) == 0) {
        printf("%u is a factor\n", arr[0]);
        return multy(bignum / arr[0], arr + 1, size - 1);
    } 
    else {
        printf("%u is NOT a factor\n", arr[0]);
        return multy(bignum, arr + 1, size - 1);
    }
}