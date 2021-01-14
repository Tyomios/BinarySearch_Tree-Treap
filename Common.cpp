#include <iomanip>

#include "Common.h"


int GetValue()
{
	int value;
	std::cout << " Enter value:" << std::endl;
	std::cin >> value;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Error. You need to enter digits (like 1 or -6).\n";
		return GetValue();
	}

	return value;
}


void BinaryTreeMenu(BinaryTree* binaryTree)
{
	enum class Menu
	{
		Exit = 0,
		Add = 1,
		Remove = 2,
		FindElement = 3,
		FindMaxElement = 4,
		FindMinElement = 5,
	};

	int userChoose;
	bool endProgramm = false;
	int data;

	while (!endProgramm)
	{
		std::cout << "Here is Binary Tree\n" << std::endl;
		ShowBinaryTree(binaryTree->Root, 3);

		std::cout	<< "\n 1 - Add in tree \n"
					<< " 2 - Remove form tree\n"
					<< " 3 - Find element\n"
					<< " 4 - Find maximum value \n"
					<< " 5 - Find minimum value \n"
					<< " 0 <- Back (You will lose tour data)\n"
					<< std::endl;
		
		int userChoose = GetValue();

		switch (static_cast<Menu>(userChoose))
		{
			case Menu::Add:
			{
				data = GetValue();

				AddElement(binaryTree->Root, data);
				break;
			}
			case Menu::Remove:
			{
				data = GetValue();
				bool success = true;

				RemoveElement(binaryTree->Root, data, success);
				if (!success)
				{
					std::cout	<< "Unsucessful removing. " 
								<< "Element doesn't exist"
								<< std::endl;

					system("pause");
				}
				break;
			}
			case Menu::FindElement:
			{
				data = GetValue();

				if (!FindElement(binaryTree->Root, data))
				{
					std::cout << "Not found(" << std::endl;
					system("pause");
					break;
				}

				std::cout	<< " Element in memory: " 
							<< FindElement(binaryTree->Root, data) << std::endl;

				system("pause");
				break;
			}
			case Menu::FindMaxElement:
			{
				if (!FindBiggestElement(binaryTree->Root))
				{
					std::cout << "Empty tree!" << std::endl;
					system("pause");
					break;
				}

				std::cout	<< " The biggest data has address memory: "
							<< FindBiggestElement(binaryTree->Root) 
							<< "( DATA: " << FindBiggestElement(binaryTree->Root)->Data
							<< " )" << std::endl;
							

				system("pause");
				break;
			}
			case Menu::FindMinElement:
			{
				if (!FindSmallestElement(binaryTree->Root))
				{
					std::cout << "Empty tree!" << std::endl;
					system("pause");
					break;
				}

				std::cout	<< " The smallest data has address memory: "
							<< FindSmallestElement(binaryTree->Root) 
							<< "( DATA: " << FindSmallestElement(binaryTree->Root)->Data
							<< " )" << std::endl;

				system("pause");
				break;
			}
			case Menu::Exit:
			{
				endProgramm = true;
				break;
			}
			default:
			{
				std::cout << "Unknown command. Use one from over the list." << std::endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}
}


void TreapMenu(TreapNode* node)
{
	enum class TreapMenu
	{
		Exit				= 0,
		AddNotOptimized		= 1,
		Add					= 2,
		RemoveNotOptimized	= 3,
		Remove				= 4,
		Find				= 5
	};

	int userInput;
	bool endProgramm = false;

	while (!endProgramm)
	{
		std::cout << "Here is TREAP\n" << std::endl;
		ShowTreap(node, 3);

		std::cout	<< "\n1 - Add (not optimized)\n"
					<< "2 - Add \n"
					<< "3 - Remove (not optimized)\n"
					<< "4 - Remove\n"
					<< "5 - Find element\n"
					<< "0 <- Back (You will lose your data)\n" << std::endl;

		userInput = GetValue();

		switch (static_cast<TreapMenu>(userInput))
		{
			case TreapMenu::AddNotOptimized:
			{
				int key = GetValue();

				AddNotOptimized(node, key);
				break;
			}
			case TreapMenu::Add:
			{
				int key = GetValue();

				AddOptimized(node, key);
				break;
			}
			case TreapMenu::RemoveNotOptimized:
			{
				int key = GetValue();
				bool success = true;

				RemoveNotOptimized(node, key, success);
				if (!success)
				{
					std::cout << "Unsucessful removing. "
						<< "Element doesn't exist"
						<< std::endl;

					system("pause");
				}
				break;
			}
			case TreapMenu::Remove:
			{
				int key = GetValue();
				bool success = true;

				RemoveOptimized(node, key, success);

				if (!success)
				{
					std::cout << "Unsucessful removing. "
						<< "Element doesn't exist"
						<< std::endl;

					system("pause");
				}
				break;
			}
			case TreapMenu::Find:
			{
				int key = GetValue();

				if (!FindElement(node, key))
				{
					std::cout << "Element not found" << std::endl;
					system("pause");
					break;
				}

				std::cout	<<"Element (key = "<< key 
							<< " ) has address in memory:"
							<< FindElement(node, key) << std::endl;

				system("pause");
				break;
			}
			case TreapMenu::Exit:
			{
				endProgramm = true;
				break;
			}
			default:
			{
				std::cout << "Unknown command. Use one from over the list." << std::endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}
}


void ShowTreap(TreapNode* node, int indent)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->RightNode)
	{
		ShowTreap(node->RightNode, indent + 4);
	}
	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (node->RightNode)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << node->Key << "(" << node->Priority << ")" << "\n ";
	if (node->LeftNode)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		ShowTreap(node->LeftNode, indent + 4);
	}
}


void ShowBinaryTree(TreeNode* binaryTreeNode, int indent)
{
	if (binaryTreeNode == nullptr)
	{
		return;
	}
	if (binaryTreeNode->RightNode)
	{
		ShowBinaryTree(binaryTreeNode->RightNode, indent + 4);
	}
	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (binaryTreeNode->RightNode)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << binaryTreeNode->Data << "\n ";

	if (binaryTreeNode->LeftNode)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		ShowBinaryTree(binaryTreeNode->LeftNode, indent + 4);
	}
}