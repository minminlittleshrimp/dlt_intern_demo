#include <stdlib.h>
#include <stdio.h>

int main() {
    //int arr[4] = {0};
    //arr[4] = 1;
    //for (int i = 0; i<4; i++)
    //    printf("Element number %d: %d\n", i, arr[i]);
    int* ptr;
    ptr = (int*)malloc(sizeof(int));
    *ptr = 100;
    printf("Number %d\n", *ptr);

    //free(ptr);
    return 0;
}
