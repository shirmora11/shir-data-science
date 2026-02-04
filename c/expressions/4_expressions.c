#include <stdio.h>
int main() {
    int n;
    long long result = 1; 
    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1) {
        printf("Please enter a valid number.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        result = result * 10;
    }
    printf("10^%d is: %lld\n", n, result);
    return 0;
}