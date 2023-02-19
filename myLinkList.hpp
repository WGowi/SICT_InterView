//
// Created by 伍高巍 on 2023/2/18.
//

#ifndef SICT_INTERVIEW_CODE_LINKLIST_H
#define SICT_INTERVIEW_CODE_LINKLIST_H

#endif //SICT_INTERVIEW_CODE_LINKLIST_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

template<typename T>

struct LNode
{
	T data;
	struct LNode<T> *next;
};

template<typename T>
class LinkList
{
private:
	LNode<int> *head;

	void PreCreatLinkList()
	{
		T x;
		LNode<T> *p = head;
		while (cin >> x && x != -1)
		{
			LNode<T> *q = new LNode<T>();
			q->data = x;
			q->next = NULL;
			p->next = q;
			p = p->next;
		}
	}

	void PostCreatLinkList()
	{
		T x;
		LNode<T> *p = head;
		p->next = NULL;
		while (cin >> x && x != -1)
		{
			LNode<T> *q = new LNode<T>();
			q->data = x;
			q->next = p->next;
			p->next = q;
		}
	}

public:
	LinkList(string mode = "PreInsert")
	{
		head = new LNode<T>;
		if (mode == "PreInsert")
		{
			PreCreatLinkList();
		}
		if (mode == "PostInsert")
		{
			PostCreatLinkList();
		}
	}

	void PrintLinkList()
	{
		for (LNode<T> *p = this->head->next; p != NULL; p = p->next)
		{
			cout << p->data << "->";
		}
		cout << "NULL" << endl;
	}

	LNode<T> *getHead()
	{
		return head;
	}

	void Delete_X(T x)
	{
		LNode<T> *p = head;
		while (p != NULL)
		{
			if (p->next != NULL && p->next->data == x)
			{
				LNode<T> *q = p->next;
				p->next = q->next;
				::free(q);
			}
			else
			{
				p = p->next;
			}
		}
	}

};