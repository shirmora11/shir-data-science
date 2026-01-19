#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
}node;
typedef struct node Node;

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


unsigned multy(unsigned n, unsigned *arr){
    int i = i +1;
        if ((n % arr[i])==0){
            printf("diveded by %d\n",arr[i]);
        }
        else {return 0;}
    return multy(n,(unsigned int*)arr[i]+1);
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

Node* list(node * node){
    Node *prev = malloc(sizeof(Node));
    assert(prev!=0);
    Node * curr = malloc(sizeof(Node));
    assert(curr!=0);
    Node *next_node= malloc(sizeof(Node));
    assert(next_node!=0);
    Node *temp= malloc(sizeof(Node));
    assert(temp !=0);
    prev->next = curr;
    curr->next = next_node;
    next_node->next = temp;
    temp->next = NULL;
    prev->data =1;
    curr->data=2;
    next_node->data=3;
    temp->data = 4;
    return prev;
}
Node* flip_list(node* node){
    prev->

    return prev;
}
int main (){
    int num = 6;
    int six = fibonaci_int(num);
    printf("the six number is %d\n",six);
    fibonachi_rec(num);
    ///linked list build from here
    Node *my_list = create_list();
    my_list = flip_list(my_list);
    *int i = 1;
    while (i < num){
        fibonachi_rec(num-1) + fibonachi_rec(num -2);
        printf("%d\n",fibonachi_rec(i));
        ++i;
    }*/
    char str[] = "shir";
    rec_strlen(str);
    const char str2[] = "adi";
    rec_strcmp(str,str2);
    unsigned arr[] = {5,7,9,13,17};
    unsigned n = 125;
    //multy(n,arr);
    int len = strlen(str);
    node * node= list(node);

    permutation(str,0,len-1);
    return 0;
}