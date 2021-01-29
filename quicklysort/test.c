#include "qsort.h"

int main()
{
    int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(a) / sizeof(a[0]);
    PrintArray(a, size);
    QsortNonR(a, size);
    PrintArray(a, size);

}
