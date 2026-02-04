#include <stdio.h>
#include <math.h>
#include "array.h"
int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        /* The position returned by josephus(n - 1, k) is
           adjusted because the recursive call josephus(n -
           1, k) considers the original position
           k%n + 1 as position 1 */
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
