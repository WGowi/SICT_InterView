//
// Created by 伍高巍 on 2023/2/21.
//

#include "../myStack.h"
#include "../myQueue.h"

int main()
{
	Queue<int> q = Queue<int>(10);
	Stack<int> s = Stack<int>(10);
	while (!q.IsFull())
	{
		int x;
		scanf("%d", &x);
		q.EnQueue(x);
	}
	while (!q.IsEmpty())
	{
		s.push(q.DeQueue());
	}
	while (!s.IsEmpty())
	{
		printf("%d,", s.pop());
	}
	return 0;
}