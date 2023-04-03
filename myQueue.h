//
// Created by Gowi on 2023/2/18.
//

#ifndef SICT_INTERVIEW_CODE_MYQUEUE_H
#define SICT_INTERVIEW_CODE_MYQUEUE_H

#endif //SICT_INTERVIEW_CODE_MYQUEUE_H

#include <cstdio>

#define X 100

template<typename T>
class Queue
{
private:
	T data[X];
	int head, end, MaxLen;
public:
	Queue(int MaxLen)
	{
		this->head = 0;
		this->end = 0;
		this->MaxLen = MaxLen + 1;
	}

	bool IsEmpty()
	{
		if (head == end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		if ((end + 1) % MaxLen == 0 && end != head)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void EnQueue(T x)
	{
		if (!IsFull())
		{
			data[end] = x;
			end = (end + 1) % MaxLen;
		}
		else
		{
			printf("队列已满\n");
		}
	}

	T DeQueue()
	{
		if (!IsEmpty())
		{
			T x = data[head];
			head = (head + 1) % MaxLen;
			return x;
		}
		else
		{
			printf("队列已空\n");
		}
	}

};
