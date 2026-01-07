#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void to_lowercase_manual(char *str) {
    if (!str) return;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        }
    }
}
extern char **environ;
char** clone_env_manual(int *count) {
    int n = 0;
    while (environ[n]) n++; 
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
void print_and_free(char **buffer) {
    if (!buffer) return;
    for (int i = 0; buffer[i] != NULL; i++) {
        printf("%s\n", buffer[i]);
        free(buffer[i]);
    }
    free(buffer); 
}
