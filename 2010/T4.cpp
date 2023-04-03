//
// Created by Gowi on 2023/2/19.
//

#include "../myLinkList.hpp"

int main()
{
	LinkList<int> L = LinkList<int>("PreInsert");
	L.Delete_X(5);
	L.PrintLinkList();
}
