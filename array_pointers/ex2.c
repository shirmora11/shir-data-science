#include <stdio.h>
int main() {
    int arr[100];
    int size = 100;
    int count = size;
    int current_pos = 0;
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    printf("Starting the 'Every Second One' elimination...\n");
    int skip_counter = 0;
    while (count > 1) {
        int index = current_pos % size;
        if (arr[index] != 0) { 
            skip_counter++;   
            if (skip_counter % 2 == 0) {
                printf("Eliminating: %d\n", arr[index]);
                arr[index] = 0;
                count--;
                skip_counter = 0;
            }
        }
        current_pos++; 
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            printf("\n THE ABSOLUTE LAST SURVIVOR IS: %d (at index %d)\n", arr[i], i);
        }
    }
    return 0;
}