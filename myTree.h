//
// Created by 伍高巍 on 2023/2/18.
//

#ifndef SICT_INTERVIEW_CODE_MYTREE_H
#define SICT_INTERVIEW_CODE_MYTREE_H

#endif //SICT_INTERVIEW_CODE_MYTREE_H

#include "myQueue.h"

#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
struct BiNode
{
	T data;
	BiNode<T> *LChild;
	BiNode<T> *RChild;
};

template<typename T>
class BiTree
{
private:
	BiNode<T> *root;
	int n;
protected:
	BiNode<int> *CreatBiTree_Pre_In(T pre[], T in[], int l1, int r1, int l2, int r2)
	{
		int r_pos = l2, l_len, r_len;
		BiNode<T> *r = (BiNode<T> *) malloc(sizeof(BiNode<T>));
		n++;
		r->data = pre[l1];
		for (int i = l2; i <= r2; ++i)
		{
			if (in[i] == pre[l1])
			{
				r_pos = i;
				break;
			}
		}
		l_len = r_pos - l2;
		r_len = r2 - r_pos;
		if (l_len > 0)
		{
			r->LChild = CreatBiTree_Pre_In(pre, in, l1 + 1, l1 + l_len, l2, r_pos - 1);
		}
		else
		{
			r->LChild = NULL;
		}
		if (r_len > 0)
		{
			r->RChild = CreatBiTree_Pre_In(pre, in, l1 + l_len + 1, r1, r_pos + 1, r2);
		}
		else
		{
			r->RChild = NULL;
		}
		return r;
	}

	void PreOrder(BiNode<T> *r)
	{
		if (r)
		{
			cout << r->data << ",";
			PreOrder(r->LChild);
			PreOrder(r->RChild);
		}
	}

	void InOrder(BiNode<T> *r)
	{
		if (r)
		{
			InOrder(r->LChild);
			cout << r->data << ",";
			InOrder(r->RChild);
		}
	}

	void PostOrder(BiNode<T> *r)
	{
		if (r)
		{
			PostOrder(r->LChild);
			PostOrder(r->RChild);
			cout << r->data << ",";
		}
	}

	void LevelOrder(BiNode<T> *r)
	{
		Queue<BiNode<T> *> q = Queue<BiNode<T> *>(n);
		q.EnQueue(r);
		while (!q.IsEmpty())
		{
			BiNode<T> *x = q.DeQueue();
			cout << x->data << ",";
			if (x->LChild != NULL)
			{
				q.EnQueue(x->LChild);
			}
			if (x->RChild != NULL)
			{
				q.EnQueue(x->RChild);
			}
		}
	}


public:
	BiTree(T pre[], T in[], int l1, int r1, int l2, int r2)
	{
		n = 0;
		this->root = CreatBiTree_Pre_In(pre, in, l1, r1, l2, r2);
	}

	void getPreOder()
	{
		PreOrder(root);
	}

	void getInOrder()
	{
		InOrder(root);
	}

	void getPostOrder()
	{
		PostOrder(root);
	}

	void getLevelOrder()
	{
		LevelOrder(root);
	}

	BiNode<T> *getRoot() const
	{
		return root;
	}

};


