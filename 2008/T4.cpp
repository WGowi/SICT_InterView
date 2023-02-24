//
// Created by 伍高巍 on 2023/2/19.
//


//请写出二叉树的中序非递归遍历的基本思想，然后写出算法，实现对二叉树的中序非递归遍历。

#include "../myTree.h"

#define N 6

int main()
{
	int pre[N] = {1, 2, 4, 3, 6, 7}, in[N] = {2, 4, 1, 6, 7, 3}, l1 = 0, l2 = 0, r1 = N - 1, r2 = N - 1;
	BiTree<int> root = BiTree<int>(pre, in, l1, r1, l2, r2);
	root.getInOrder2();
	return 0;
}