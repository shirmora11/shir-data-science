#include <stdio.h>
#include<string.h>
int maxSubarraySum(int arr[], int size) {
    int maxSum = arr[0];
    for (int i = 0; i < size; i++) {
        int currSum = 0;
        for (int j = i; j < size; j++) {
            currSum = currSum + arr[j];
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}

int Bursa(int list[] , int size){
    int *left = &list[0];
    int *right = &list[1];
    int current_sum = 0;
    int max_sum = 0;
    int index_buy,index_sell;
    for (int i = 0 ; i <size-1 ; i++){
        if (*right > *left){
            current_sum = *right - *left;
        }
        else{
            left = right;
        }
        if (current_sum > max_sum){
            max_sum = current_sum;
            index_buy = left - list;
            index_sell = right -list;
        }
        right++;
    }
    printf("the index to buy is %d, and the index to sell is %d, the profit is %d\n",index_buy,index_sell,max_sum);
    return max_sum;
}

int airplane(int *landing, int *taking_off, int lansize,int takesize){
    int stayed = 0;
    for(int i = 0; i < lansize ; i++){
        stayed += landing[i];
        if (i < takesize){
        stayed -= taking_off[i];
        }
    }
    printf("this is what stayed: %d\n",stayed);
    return stayed;
}
int is_rotation(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 0; i < len1; i++) {
        int j;
        for (j = 0; j < len1; j++) {
            if (s1[(i + j) % len1] != s2[j]) {
                break; 
            }
        }
        if (j == len1) {
        return 1;
        }
    }
    return 0;
}

int main() {
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxSubarraySum(arr, size));
    int list[] = {7, 1, 5, 3, 6, 4};
    int sizel = sizeof(list)/ sizeof(list[0]);
    Bursa(list,sizel);
    int landing[] ={1234,9876,4567};
    int taking_off[] = {9876 , 4567};
    int lansize = sizeof(landing)/sizeof(landing[0]);

    int takesize = sizeof(taking_off)/sizeof(taking_off[0]);
    airplane(landing,taking_off,lansize,takesize);
    if (is_rotation("shir","rshi")) {
        printf("True\n");
    } else {
        printf("False\n");
    }



    return 0;
}