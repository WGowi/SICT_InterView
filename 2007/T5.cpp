//
// Created by Gowi on 2023/2/19.
//

//以二叉链表为存储结构，对二叉树进行层次遍历(层次遍历的定义见6.13).提示：应使用队列来保存各层的结点。

#define N 6

#include "../myTree.h"

int main()
{
	int pre[N] = {1, 2, 4, 3, 6, 7}, in[N] = {2, 4, 1, 6, 7, 3}, l1 = 0, l2 = 0, r1 = N - 1, r2 = N - 1;
	BiTree<int> root = BiTree<int>(pre, in, l1, r1, l2, r2);
	root.getLevelOrder();
	return 0;
}
