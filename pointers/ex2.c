#include <stdio.h>
#include <stddef.h>
void swap_size_t(size_t *a, size_t *b)
{
    size_t temp = *a;
    *a = *b;
    *b = temp;
}
void swap_size_t_ptr(size_t **ptr_a, size_t **ptr_b)
{
    swap_size_t((size_t *)ptr_a, (size_t *)ptr_b);
}
int main()
{
    size_t x = 10, y = 20;
    size_t *p1 = &x;
    size_t *p2 = &y;
    printf("Before swap:\n p1 points to address %p (value %zu)\n p2 points to address %p (value %zu)\n",
           (void *)p1, *p1, (void *)p2, *p2);
    swap_size_t_ptr(&p1, &p2);
    printf("\nAfter swap:\n p1 points to address %p (value %zu)\n p2 points to address %p (value %zu)\n",
           (void *)p1, *p1, (void *)p2, *p2);

    size_t t = 10;
    size_t *pt = &t;
    size_t **tptr = &pt;
    printf("%p\n", (void *)**tptr);

    return 0;
}