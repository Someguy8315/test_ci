#include <stdio.h>
#include "func.h"

int main()
{
    int arr[3];
    arr[3] = 5;

    int value = getValue();
    printf("value = %d\n", value);

    puts("finished execution...");
    return 0;
}
