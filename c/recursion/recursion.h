#ifndef RECURSION_H
#define RECURSION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

int fibonaci_int(int num);//the normal way any wrong number (float , minus) will result in a error
int fibonachi_rec(int num);//the recursive way same as the normal
int rec_strlen(const char *str); //finds string lenght wrong input (float , minus) will result in a error
int rec_strcmp(const char *str1, const char *str2);//string compare wrong input (float , minus) will result in a error
void permutation(char *str, int left, int right);//finds the permutation of a string , wrong input (float , minus) will result in a error
Node* list();//linked list creator
Node* flip_list(Node* head);//linked list flipper
void foreach(Node* head);//print each node for visualization
unsigned multy(unsigned n, unsigned *arr, int size);//if a big number is a mulptiply

#endif
