#ifndef ARRAY_H
#define ARRAY_H

// ONLY declarations here! End them with a semicolon ;
void calculateRowSums(int rows, int cols, int (*matrix)[cols], int results[]);
void josephus_n2();
int josephus(int n, int k);
int josephus_fast(int total_people);
int data_types();
void to_lowercase_manual(char *str);
char** clone_env_manual(int *count);
void print_and_free(char **buffer);

#endif