#include <stdio.h>
#include <string.h>
int main() {
    const char *text = "Infinity Labs R&D";
    const char *find = "Labs";
    char *result;
    result = strstr(text, find);
    if (result) {
        printf("Substring found at: %s\n", result);
    } else {
        printf("Substring not found.\n");
    }
    return 0;
}