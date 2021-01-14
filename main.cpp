#include <iostream>

#include "BinaryTree.h"
#include "Common.h"


enum class StartMenu
{
	Exit		= 0,
	BinaryTree	= 1,
	Treap		= 2
};


int main()
{
	int numberOfStruct;
	
	while (true)
	{
		std::cout	<< "1 - Binary tree \n"
					<< "2 - Treap\n"
					<< "0 - Exit\n" 
					<< "Choose struct to start:" << std::endl;

		numberOfStruct = GetValue();

		switch (static_cast<StartMenu>(numberOfStruct))
		{
			case StartMenu::BinaryTree:
			{
				BinaryTree* binaryTree = new BinaryTree;
				InitTree(binaryTree);
				BinaryTreeMenu(binaryTree);
				DeleteTree(binaryTree->Root);
				break;
			}
			case StartMenu::Treap:
			{
				Treap* treap = new Treap;
				InitTreap(treap);
				TreapMenu(treap->Root);
				DeleteTreap(treap->Root);
				break;
			}
			case StartMenu::Exit:
			{
				return 0;
			}
			default:
			{
				std::cout << "Unknown command! Try again" << std::endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}
	return 0;
}