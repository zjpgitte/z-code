typedef struct {
	Queue *pq1;
	Queue *pq2; //用两个队列实现栈，可以实现弹栈、取栈顶元素等操作
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *newStack = (MyStack*)malloc(sizeof(MyStack));
	newStack->pq1 = (Queue*)malloc(sizeof(Queue));
	newStack->pq2 = (Queue*)malloc(sizeof(Queue));
	QueueInit(newStack->pq1);
	QueueInit(newStack->pq2);
	return newStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(obj->pq1))
	{
		QueuePush(obj->pq1, x);
	}
	else
	{
		QueuePush(obj->pq2, x);
	}//将x压入一个队列中
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	//栈中的元素要么是在队列1中，要么是在队列2中
	//若元素在队列1中，要实现弹栈操作就是让队列1中队尾元素出队
	//实现的方式就是让队列1中的队头元素出队，再进入到队列2中。最后一个元素出对后不进入队列2。那这样队列2中的元素就不包括队列1的最后一个元素。这样就实现了弹栈操作，队列2中的元素就是栈中的元素。
	if (!QueueEmpty(obj->pq1))//队列1不是空的情况
	{
		int x;
		while (!QueueEmpty(obj->pq1))
		{
			x = QueuePop(obj->pq1);
			if (!QueueEmpty(obj->pq1))
			{
				QueuePush(obj->pq2, x);
			}
		}//让队列1的元素弹栈，再进入队列2中，队列1的最后一个元素不进入队列2,且该元素是队列1的最后一个元素即栈顶.
		return x;
	}
	else//队列2不是空的情况
	{
		int x;
		while (!QueueEmpty(obj->pq2))
		{
			x = QueuePop(obj->pq2);
			if (!QueueEmpty(obj->pq2))
			{
				QueuePush(obj->pq1, x);
			}
		}
		return x;
	}
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	//取栈顶元素和弹栈操作类似，不同点就是弹栈操作中队列1的最后一个
	//元素不进入队列2而取栈顶元素操作中队列1的最后一个元素也进入到
	//对列2中。
	if (!QueueEmpty(obj->pq1))
	{
		int x;
		while (!QueueEmpty(obj->pq1))
		{
			x = QueuePop(obj->pq1);
			QueuePush(obj->pq2, x);
		}//x记录每次出队列1的那个元素，让每个x都进入队列2。最后一个进入的元素在队列1中是队尾也是栈顶。
		return x;
	}
	else
	{
		int x;
		while (!QueueEmpty(obj->pq2))
		{
			x = QueuePop(obj->pq2);
			QueuePush(obj->pq1, x);
		}//x记录每次出队列2的那个元素，让每个x都进入队列1。最后一个进入的元素在队列2中是队尾也是栈顶。
		return x;
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(obj->pq1) && QueueEmpty(obj->pq2))
	{
		return true;
	}//只有当两个队列都是空的时候栈才是空的
	else
	{
		return false;
	}
}

void myStackFree(MyStack* obj) {
	QueueDestroy(obj->pq1);
	QueueDestroy(obj->pq2);//将队列销毁
	free(obj->pq1);
	free(obj->pq2);
	free(obj);//销毁掉我们自己开辟的空间
}