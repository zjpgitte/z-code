#include "qsort.h"
#include "Stack.h"

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

int GetMidValIndex(int *a, int left, int right)
{
    int mid = (left + right) / 2;
    if(a[mid] < a[left])
    {
        if(a[mid] < a[right])
        {
            if(a[left] < a[right])
            {
                return left;
            }
            else 
            {
                return right;
            }
        }
        else 
        {
            return mid;
        }
    }
    else 
    {
        if(a[mid] > a[right])
        {
            if(a[left] > a[right])
            {
                return left;
            }
            else 
            {
                return right;
            }
        }
        else 
        {
            return mid;
        }
    }
}

//单趟排序目的是找到待排序数组中一个元素的位置,这个位置是它最终排好序应该在的位置。需要注意的是只能找到一个元素的位置。
//单趟排序的最坏时间复杂度是O((right-left)/2);
int PartSort1(int *a, int left, int right)
{
    //三数取中，将中间大的那个交换到right位置处.
    //防止最大的数或最小的数在最后一个位置，避免出现的O(N)的时间复杂度
    int midValIndex = GetMidValIndex(a, left, right);
    Swap(&a[midValIndex], &a[right]);

    //假设 key 是待排序元素
    int keyIndex = right;//keyIndex是key在数组中的下标
    while(left < right)
    {
        //从左往右走找比key大的
        while(left < right && a[left] <= a[keyIndex])
        {
            left++;
        }
        //从右往左走找比key小的
        while(left < right && a[right] >= a[keyIndex])
        {
            right--;
        }

        //交换两个元素的位置
        Swap(&a[left], &a[right]);
    }

    //把key换到相应的位置
    Swap(&a[keyIndex], &a[left]);
    return left;
}

//挖坑法
int PartSort2(int *a, int left, int right)
{
    //三数取中
    int midValIndex = GetMidValIndex(a, left, right);
    Swap(&a[midValIndex], &a[right]);
    
    //把right位置处的元素保存在key中，这样right位置就可以被其它元素覆盖可将其看成是坑
    int key = a[right];

    while(left < right)
    {
        //从左往右找比key大的元素，保存到right位置处，这样left位置的元素就可以看成是坑,可以被覆盖
        while(left < right && a[left] <= key)
        {
            left++;
        }
        a[right] = a[left];

        //从右往左找比key小的元素，保存到left位置处,这样right位置又可以看成是坑，可以被覆盖
        while(left < right && a[right] >= key)
        {
            right--;
        }
        a[left] = a[right];
    }
    
    //最后的那个坑就是left和right相遇的位置,也是key的位置,将key保存在left和right位置处
    a[left] = key;
    return left;
}

//前后指针法
int PartSort3(int *a, int left, int right)
{
    int midValIndex = GetMidValIndex(a, left, right);
    Swap(&a[midValIndex], &a[right]);
    
    //找key的位置
    int keyIndex = right;//keyIndex是key的下标
    int prev = left - 1;
    int cur = left;
    
    while(cur < right)
    {
        //prev始终是比key小的最后一个元素下标,cur从左往右走找比key小的值，然后交换到prev的后面
        if(a[cur] < a[keyIndex] && ++prev != cur)
        {
            Swap(&a[cur], &a[prev]);
        }
        cur++;
    }
    
    Swap(&a[++prev], &a[keyIndex]);
    return prev;
    
}
void _Qsort(int *a, int left, int right)
{
    //当[left, right]的区间不存在或区间只有一个元素时，不进行排序
    if(left >= right)
    {
        return ;
    }

    //将[left,right]的元素单趟排序
    int mid = PartSort3(a, left, right);
    
    //[left,mid-1]区间的元素单趟排序
    _Qsort(a, left, mid-1);
    //[mid+1, right]区间的元素单趟排序
    _Qsort(a, mid+1, right);

}

void Qsort(int *a, int n)
{
    _Qsort(a, 0, n-1);  
}

void QsortNonR(int *a, int n)
{
    Stack st;
    StackInit(&st);
    int left = 0;
    int right = n - 1;
    StackPush(&st, right);
    StackPush(&st, left);
    
    //只要left < right 就入栈 ，那么就可以保证栈中的区间是合理的
    //对栈中的合理区间的元素进行排序
    while(!StackEmpty(&st))
    {
        left = StackTop(&st);
        StackPop(&st);
        right = StackTop(&st);
        StackPop(&st);
        //对[left,right]进行单趟排序
        int mid = PartSort1(a, left, right);
        
        //right > mid 区间合理可以入栈
        //当right < mid 时区间不存在，当right = mid 时区间只有一个元素不对它进行排序。这两种情况认为区间不合理不入栈
        if(right > mid)
        {
            StackPush(&st, right);
            StackPush(&st, mid+1);
        }
        //left <= mid 的区间不合理因此不如栈.
        if(left < mid)
        {
            StackPush(&st, mid-1);
            StackPush(&st, left);
        }
    }
}
