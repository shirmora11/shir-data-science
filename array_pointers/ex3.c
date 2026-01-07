#include <stdio.h>
#include <stdbool.h>

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
