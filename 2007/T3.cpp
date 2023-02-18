//
// Created by 伍高巍 on 2023/2/18.
//

//已知单链表L是一个递增有序表，试写一高效算法，删除表中值大于min且小于max的结点（若表中又这样的结点），同时释放被删结点的空间，这里的min和max是两个给定的参数。请分析你的算法时间复杂度。

#include "../LinkList.hpp"

#include <stdio.h>
#include <stdlib.h>

LinkList *Delete_Between_Min_And_Max(LinkList *L, int min, int max)
{
	for (LNode *p = L; p != NULL;)
	{
		if (p->next != NULL && p->next->data < max && p->next->data > min)
		{
			LNode *q = p->next;
			p->next = p->next->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}
	return L;
}

int main()
{
	int min, max;
	LinkList *L = (LinkList *) malloc(sizeof(LNode));
	L = CreatList_pre(L);
	scanf("%d %d", &min, &max);
	Delete_Between_Min_And_Max(L, min, max);
	print_LinkList(L);
	return 0;
}