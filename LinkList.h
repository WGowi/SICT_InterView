//
// Created by 伍高巍 on 2023/2/18.
//

#ifndef SICT_INTERVIEW_CODE_LINKLIST_H
#define SICT_INTERVIEW_CODE_LINKLIST_H

#endif //SICT_INTERVIEW_CODE_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

struct LNode
{
	struct LNode *next;
	int data;
};

typedef struct LNode LNode;
typedef struct LNode LinkList;

LinkList *CreatList_pre(LinkList *L)
{
	int a;
	LNode *p = L;
	while (scanf("%d", &a) && a != -1)
	{
		LNode *q = (LNode *) malloc(sizeof(LNode));
		q->data = a;
		p->next = q;
		q->next = NULL;
		p = p->next;
	}
	return L;
}

LinkList *CreatLinkList_post(LinkList *L)
{
	int a;
	LNode *p = L;
	while (scanf("%d", &a) && a != -1)
	{
		LNode *q = (LNode *) malloc(sizeof(LNode));
		q->data = a;
		q->next = p->next;
		p->next = q;
	}
	return L;
}

int IsEmpty(LinkList *L)
{
	if (L->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void print_LinkList(LinkList *L)
{
	if (IsEmpty(L))
	{
		printf("链表为空\n");
	}
	else
	{
		for (LNode *p = L->next; p != NULL; p = p->next)
		{
			printf("%d->", p->data);
		}
		printf("NULL\n");
	}
}
