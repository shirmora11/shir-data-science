#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include <math.h>
#include <stdbool.h> 

// ex1: Function to calculate the sum of each row in a 2D array
void calculateRowSums(int rows, int cols, int (*matrix)[cols], int results[]) {
    for (int i = 0; i < rows; i++) {
        results[i] = 0;
        for (int j = 0; j < cols; j++) {
            results[i] += matrix[i][j];
        }
    }
}

// ex2: Function to calculate the last soldier standing using n2 approach
void josephus_n2() {
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

    // This part was duplicated and broken outside the function
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            printf("\nTHE ABSOLUTE LAST SURVIVOR IS: %d (at index %d)\n", arr[i], i);
        }
    }
}

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int josephus_fast(int total_people) {
    int highest_power_of_2 = 1;
    while (highest_power_of_2 <= total_people) {
        highest_power_of_2 *= 2;
    }
    highest_power_of_2 /= 2; 
    int rem_people = total_people - highest_power_of_2;
    int survivor_pos = (2 * rem_people) + 1;
    return survivor_pos;
}

// ex3: Function to print sizes of standard C data types
int data_types() {
    printf("--- Standard C Data Type Sizes ---\n");
    printf("Type               Size (bytes)\n");
    printf("-------------------------------\n");
    printf("char:              %zu\n", sizeof(char));
    printf("short:             %zu\n", sizeof(short));
    printf("int:               %zu\n", sizeof(int));
    printf("long:              %zu\n", sizeof(long));
    printf("long long:         %zu\n", sizeof(long long));
    printf("float:             %zu\n", sizeof(float));
    printf("double:            %zu\n", sizeof(double));
    printf("long double:       %zu\n", sizeof(long double));
    printf("bool:              %zu\n", sizeof(bool));
    printf("void pointer (*):  %zu\n", sizeof(void*));
    printf("-------------------------------\n");
    return 0;
}

// ex4: Function to convert a string to lowercase manually
void to_lowercase_manual(char *str) {
    if (!str) return;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        }
    }
}

// Function to clone environment variables manually
extern char **environ;
char** clone_env_manual(int *count) {
    int n = 0;
    while (environ && environ[n]) n++; 
    *count = n;

    char **new_env = malloc((n + 1) * sizeof(char *));
    if (!new_env) return NULL;

    for (int i = 0; i < n; i++) {
        new_env[i] = strdup(environ[i]);
        if (new_env[i]) {
            to_lowercase_manual(new_env[i]); 
        }
    }
    new_env[n] = NULL;
    return new_env;
}

// Function to print and free cloned environment variables
void print_and_free(char **buffer) {
    if (!buffer) return;
    for (int i = 0; buffer[i] != NULL; i++) {
        printf("%s\n", buffer[i]);
        free(buffer[i]);
    }
    free(buffer); 
}