typedef struct {
	Queue *pq1;
	Queue *pq2; //����������ʵ��ջ������ʵ�ֵ�ջ��ȡջ��Ԫ�صȲ���
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
	}//��xѹ��һ��������
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	//ջ�е�Ԫ��Ҫô���ڶ���1�У�Ҫô���ڶ���2��
	//��Ԫ���ڶ���1�У�Ҫʵ�ֵ�ջ���������ö���1�ж�βԪ�س���
	//ʵ�ֵķ�ʽ�����ö���1�еĶ�ͷԪ�س��ӣ��ٽ��뵽����2�С����һ��Ԫ�س��Ժ󲻽������2������������2�е�Ԫ�ؾͲ���������1�����һ��Ԫ�ء�������ʵ���˵�ջ����������2�е�Ԫ�ؾ���ջ�е�Ԫ�ء�
	if (!QueueEmpty(obj->pq1))//����1���ǿյ����
	{
		int x;
		while (!QueueEmpty(obj->pq1))
		{
			x = QueuePop(obj->pq1);
			if (!QueueEmpty(obj->pq1))
			{
				QueuePush(obj->pq2, x);
			}
		}//�ö���1��Ԫ�ص�ջ���ٽ������2�У�����1�����һ��Ԫ�ز��������2,�Ҹ�Ԫ���Ƕ���1�����һ��Ԫ�ؼ�ջ��.
		return x;
	}
	else//����2���ǿյ����
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
	//ȡջ��Ԫ�غ͵�ջ�������ƣ���ͬ����ǵ�ջ�����ж���1�����һ��
	//Ԫ�ز��������2��ȡջ��Ԫ�ز����ж���1�����һ��Ԫ��Ҳ���뵽
	//����2�С�
	if (!QueueEmpty(obj->pq1))
	{
		int x;
		while (!QueueEmpty(obj->pq1))
		{
			x = QueuePop(obj->pq1);
			QueuePush(obj->pq2, x);
		}//x��¼ÿ�γ�����1���Ǹ�Ԫ�أ���ÿ��x���������2�����һ�������Ԫ���ڶ���1���Ƕ�βҲ��ջ����
		return x;
	}
	else
	{
		int x;
		while (!QueueEmpty(obj->pq2))
		{
			x = QueuePop(obj->pq2);
			QueuePush(obj->pq1, x);
		}//x��¼ÿ�γ�����2���Ǹ�Ԫ�أ���ÿ��x���������1�����һ�������Ԫ���ڶ���2���Ƕ�βҲ��ջ����
		return x;
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(obj->pq1) && QueueEmpty(obj->pq2))
	{
		return true;
	}//ֻ�е��������ж��ǿյ�ʱ��ջ���ǿյ�
	else
	{
		return false;
	}
}

void myStackFree(MyStack* obj) {
	QueueDestroy(obj->pq1);
	QueueDestroy(obj->pq2);//����������
	free(obj->pq1);
	free(obj->pq2);
	free(obj);//���ٵ������Լ����ٵĿռ�
}