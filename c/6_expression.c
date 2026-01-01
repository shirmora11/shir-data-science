#include <stdio.h>
int main() {
    long num;
    long sec_num;
    long temp;
    printf("Enter a the first number to swap: ");
    if (scanf("%ld", &num) != 1) {
        printf("Error: Please enter a valid whole number.\n");
        return 1;
    }
    printf("Enter a the second number to swap: ");
    if (scanf("%ld", &sec_num) != 1) {
        printf("Error: Please enter a valid whole number.\n");
        return 1;
    }
    temp = num;
    num = sec_num;
    sec_num = temp;
    printf("now %ld is first and %ld is second\n", num , sec_num);
    return 0;
}