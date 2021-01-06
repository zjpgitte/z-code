#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#define true 1
#define false 0
typedef int bool ;
typedef struct {
	int *_data;//队列
	int _front;//队头
	int _tail;//队尾
	int _tag;//判断队列是满或空的辅助标志位
	int _size;//队列中元素的个数
} MyCircularQueue;
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *newQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	newQueue->_data = (int*)malloc(sizeof(int)*k);
	newQueue->_front = newQueue->_tail = 0;
	newQueue->_tag = 0;//初始时队列为空tag初始化为0；
	newQueue->_size = k;
	return newQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}//队列满不插入
	obj->_data[obj->_tail] = value;
	obj->_tail = (obj->_tail + 1) % obj->_size;
	obj->_tag = 1;//插入的时候tag置1
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}//队列空不删除
	obj->_front = (obj->_front + 1) % obj->_size;;
	obj->_tag = 0;//删除的时候tag置0
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->_data[(obj->_tail - 1 + obj->_size) % obj->_size];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if ((obj->_tag == 0) && (obj->_front == obj->_tail))
	{
		return true;
	}//tag为0且头尾相等队列为空
	else
	{
		return false;
	}
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->_tag == 1) && (obj->_front == obj->_tail))
	{
		return true;
	}//tag为1且头尾相等队列为满
	else
	{
		return false;
	}
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_data);
	free(obj);
}

int main()
{
	
	
	 MyCircularQueue* obj = myCircularQueueCreate(3);
	 myCircularQueueEnQueue(obj, 1);
	 myCircularQueueEnQueue(obj, 2);
	 myCircularQueueEnQueue(obj, 3);
	 myCircularQueueEnQueue(obj, 4);
	 printf("%d\n", myCircularQueueRear(obj));
	 if (myCircularQueueIsFull(obj))
	 {
		 printf("FULL\n");
	 }
	 myCircularQueueDeQueue(obj);
	 myCircularQueueEnQueue(obj, 4);
	 printf("%d\n", myCircularQueueRear(obj));

	 myCircularQueueFree(obj);
	 obj = NULL;
	system("pause");
	return 0;
}