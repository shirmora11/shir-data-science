#include <stdio.h>
int main() {
    long long num;
    long long reversed = 0;
    long long remainder;
    printf("Enter a number to reverse: ");
    if (scanf("%lld", &num) != 1) {
        printf("Error: Please enter a valid whole number.\n");
        return 1;
    }
    long long originalNum = num;
    while (num != 0) {
        remainder = num % 10;          
        reversed = reversed * 10 + remainder; 
        num = num / 10;               
    }
    printf("The reverse of %lld is %lld\n", originalNum, reversed);
    return 0;
}