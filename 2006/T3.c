//
// Created by 伍高巍 on 2023/2/17.
//

// 一棵n个结点的完全二叉树以向量作为存储结构，试写一非递归算法实现对该树的前序遍历。


//主要思路采用数组下标来模拟栈的操作，其中因为数组是从0开始的，所以i的左子树为2*i+1右子树为2*(i+1),即当i为左子树(i为奇数)时i/2为其父节点，i为右子树(i为偶数)时i/2-1为i的父节点
#include <stdio.h>

#define Num 18

int main()
{
	int BiTree[Num], visited[Num] = {0}, n = Num, i = 0, k = 0;
	for (int i = 0; i < n; ++i)
	{
		BiTree[i] = i;
	}
	while (k < n)//当n个节点全部访问完成退出循环
	{
		if (i < n && visited[i] != 1)
		{
			printf("%d,", BiTree[i]);//访问节点
			visited[i] = 1;
			k++;
			i = i * 2 + 1; //寻找左子树
		}
		else // 如果左子树为空，则寻找其右子树
		{
			i = i / 2; //节点i（i其实不存在二叉树中，i已经超过来二叉树的节点范围）
			if (i % 2) //寻找i的父节点，即上次被访问的节点
			{
				i = i / 2; //i若为左子树时,i/2为i的父节点
			}
			else
			{
				i = i / 2 - 1;//若i为左子树时，i/2-1为i的父节点
			}
			while (1)//不断往上寻找有为被访问的左子树后者右子树，相对于递归的回退部分
			{
				if (visited[2 * i + 1] == 0)//若i的左子树为被访问
				{
					i = 2 * i + 1;//i为i的左子树
					break;
				}
				if (visited[2 * (i + 1)] == 0)//i的右子树
				{
					i = 2 * (i + 1);//i为i的右子树
					break;
				}
				if (i % 2)//寻找其父节点
				{
					i = i / 2;
				}
				else
				{
					i = i / 2 - 1;
				}
			}
		}
	}
	return 0;
}


//#include<stdio.h>
//
//#define ARRAY_MAX 12
//
//int main()
//{
//	int tree[ARRAY_MAX];
//	for (int i = 0; i < ARRAY_MAX; i++)
//	{
//		tree[i] = i + 1;
//	}
//	int flag = 0;//记录当前叶子的遍历位置,0 刚遍历到这个叶子,1 已经遍历完成该叶子的左儿子,2 已经遍   //历完成该叶子的右儿子
//	int count = 1;//假设tree不为空
//	while (!(count == 1 && flag == 2))
//	{
//		if (flag == 0)
//		{
//			printf("%d ", tree[count - 1]);
//			if (count * 2 > ARRAY_MAX)
//			{
//				flag = 1;
//			}
//			else
//			{
//				count = count * 2;
//			}
//		}
//		else if (flag == 1)
//		{
//			if (count * 2 + 1 > ARRAY_MAX)
//			{
//				flag = 2;
//			}
//			else
//			{
//				count = count * 2 + 1;
//				flag = 0;
//			}
//		}
//		else if (flag == 2)
//		{
//			if (count % 2 == 0)
//			{
//				flag = 1;
//			}
//			else
//			{
//				flag = 2;
//			}
//			count = count / 2;
//		}
//	}
//	getchar();
//	return 0;
//}
