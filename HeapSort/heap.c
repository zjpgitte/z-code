#include "heap.h"

void PrintArray(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void Swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

//调整根为root的树为小堆，前提：root的左右子树已经是小堆
void AdjustDown(int *a, int n, int root)
{

    int parent = root;
    int child = 2*parent + 1;
    
    while(child < n)
    {
        //找左右孩子中较小的
        if(child + 1 < n && a[child+1] < a[child])
        {
            child++;
        }
        //比较孩子和创亲大小。若孩子比双亲小交换，否则跳出循环本次调整完成
        if(a[child] < a[parent])
        {
            Swap(&a[parent], &a[child]);
            parent = child;
            child = 2*parent + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *a, int n)
{
    //建堆
    for(int i = (n-1-1) / 2; i >= 0; --i)
    {
        AdjustDown(a, n, i);
    }

    //选最小元素，调整
    int end = n - 1;
    while(end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        end--; 
    }

}
