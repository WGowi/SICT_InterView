//
// Created by 伍高巍 on 2023/2/18.
//

//已知单链表L是一个递增有序表，试写一高效算法，删除表中值大于min且小于max的结点（若表中又这样的结点），同时释放被删结点的空间，这里的min和max是两个给定的参数。请分析你的算法时间复杂度。

#include "../myLinkList.hpp"

void Delete_Between_min_and_max(LinkList<int> *L, int min, int max)
{
	LNode<int> *LH = L->getHead();
	while (LH != NULL)
	{
		if (LH->next != NULL && LH->next->data < max && LH->next->data > min)
		{
			LNode<int> *p = LH->next;
			LH->next = p->next;
			::free(p);
		}
		else
		{
			LH = LH->next;
		}
	}
}

int main()
{
	int min, max;
	::scanf("%d %d", &min, &max);
	LinkList<int> L = LinkList<int>("PreInsert");
	Delete_Between_min_and_max(&L, min, max);
	L.PrintLinkList();
	return 0;
}