//
// Created by Gowi on 2023/2/18.
//

//以二叉链表为存储结构，分别写出求二叉树高度算法及高度算法，所谓宽度是指二叉树的各层上，具有结点数最多的那一层上的结点总数。

#define N 6

#include <iostream>

#include "../myTree.h"

using namespace std;

int TreeHeight(BiNode<int> *T)
{
	int hl, hr;
	if (T)
	{
		if (T->LChild == NULL && T->RChild == NULL)
		{
			return 1;
		}
		else
		{
			hl = TreeHeight(T->LChild);
			hr = TreeHeight(T->RChild);
			if (hl >= hr)
			{
				return hl + 1;
			}
			else
			{
				return hr + 1;
			}
		}
	}
	else
	{
		return 0;
	}
}

int TreeWidth(BiNode<int> *T)
{
	int w = 0, h = 0, max_w = 0;
	Queue<BiNode<int> *> q1 = Queue<BiNode<int> *>(100);
	Queue<BiNode<int> *> q2 = Queue<BiNode<int> *>(100);
	q1.EnQueue(T);
	while (!q1.IsEmpty() || !q2.IsEmpty())
	{
		while (!q1.IsEmpty())
		{
			BiNode<int> *x = q1.DeQueue();
			if (x->LChild != NULL)
			{
				q2.EnQueue(x->LChild);
				w++;
			}
			if (x->RChild != NULL)
			{
				q2.EnQueue(x->RChild);
				w++;
			}
		}
		if (max_w < w)
		{
			max_w = w;
		}
		h++;
		w = 0;
		while (!q2.IsEmpty())
		{
			BiNode<int> *x = q2.DeQueue();
			if (x->LChild != NULL)
			{
				q1.EnQueue(x->LChild);
				w++;
			}
			if (x->RChild != NULL)
			{
				q1.EnQueue(x->RChild);
				w++;
			}
		}
		if (max_w < w)
		{

			max_w = w;
		}
		h++;
		w = 0;
	}
	return max_w;
}

int main()
{
	int pre[N] = {1, 2, 4, 3, 6, 7}, in[N] = {2, 4, 1, 6, 7, 3}, l1 = 0, l2 = 0, r1 = N - 1, r2 = N - 1;
	BiTree<int> root = BiTree<int>(pre, in, l1, r1, l2, r2);
	cout << TreeHeight(root.getRoot()) << endl;
	return 0;
}