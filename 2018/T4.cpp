//
// Created by Gowi on 2023/2/19.
//

#include "../myTree.h"

#define N 6

void Swap_LR(BiNode<int> *T)
{
	if (T != NULL)
	{
		Swap_LR(T->LChild);
		Swap_LR(T->RChild);
		BiNode<int> *x = T->LChild;
		T->LChild = T->RChild;
		T->RChild = x;
	}
}

int main()
{
	int pre[N] = {1, 2, 4, 3, 6, 7}, in[N] = {2, 4, 1, 6, 7, 3}, l1 = 0, l2 = 0, r1 = N - 1, r2 = N - 1;
	BiTree<int> root = BiTree<int>(pre, in, l1, r1, l2, r2);
	Swap_LR(root.getRoot());
	root.getPreOrder1();
	cout << endl;
	root.getInOrder1();
	return 0;
}