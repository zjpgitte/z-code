#include "heap.h"

int main()
{
    int a[] = { 1,2,3,4,5,6,6,7,7,0};
    int size = sizeof(a) / sizeof(a[0]);
    PrintArray(a, size);
    HeapSort(a, size);
    PrintArray(a, size);
    
    return 0;

}
