//
// Created by 伍高巍 on 2023/2/19.
//

#ifndef SICT_INTERVIEW_CODE_MYSTACK_H
#define SICT_INTERVIEW_CODE_MYSTACK_H

#endif //SICT_INTERVIEW_CODE_MYSTACK_H

#include <iostream>

#define N 100

template<typename T>
class Stack
{
private:
	T A[N];
	int MaxLen;
	int top;
public:
	Stack(int len)
	{
		this->MaxLen = len;
		this->top = 0;
	}

	bool IsEmpty()
	{
		if (top == 0)
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
		if (top == MaxLen - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T getTop()
	{
		return A[top];
	}

	void push(T x)
	{
		if (!IsFull())
		{
			a[top] = x;
		}
		else
		{
			std::cout << "栈已满!" << std::endl;
		}
	}

	T pop()
	{
		if (IsEmpty())
		{
			std::cout << "栈已空!" << std::endl;
		}
		else
		{
			return A[top--];
		}
	}

};
