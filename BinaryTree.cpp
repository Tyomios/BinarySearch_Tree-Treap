#include "BinaryTree.h"


void InitTree(BinaryTree* binaryTree)
{
	binaryTree->Root = nullptr;
}


void DeleteTree(TreeNode* binaryTreeNode)
{
	if (!binaryTreeNode)
	{
		return;
	}

	DeleteTree(binaryTreeNode->LeftNode);
	DeleteTree(binaryTreeNode->RightNode);
	delete binaryTreeNode;
}


void AddElement(TreeNode*& binaryTreeNode, int data)
{
	if (!binaryTreeNode)
	{
		binaryTreeNode = new TreeNode;
		binaryTreeNode->Data = data;
		return;
	}

	if (binaryTreeNode && data > binaryTreeNode->Data)
	{
		AddElement(binaryTreeNode->RightNode, data);
		return;
	}

	AddElement(binaryTreeNode->LeftNode, data);
	return;
}


void RemoveElement(TreeNode*& binaryTreeNode, int data, bool& success)
{
	if (!binaryTreeNode)
	{
		success = false;
		return;
	}

	if (data > binaryTreeNode->Data)
	{
		RemoveElement(binaryTreeNode->RightNode, data, success);
	}
	else if (data < binaryTreeNode->Data)
	{
		RemoveElement(binaryTreeNode->LeftNode, data, success);
	}
	else if (binaryTreeNode->LeftNode && binaryTreeNode->RightNode)
	{
		binaryTreeNode->Data = FindSmallestElement(binaryTreeNode->RightNode)->Data;
		RemoveElement(binaryTreeNode->RightNode, binaryTreeNode->Data, success);
	}
	else
	{
		TreeNode* temp = nullptr;
		if (binaryTreeNode->RightNode)
		{
			temp = binaryTreeNode;
			binaryTreeNode = temp->RightNode;
			delete temp;
		}
		else if (binaryTreeNode->LeftNode)
		{
			temp = binaryTreeNode;
			binaryTreeNode = temp->LeftNode;
			delete temp;
		}
		else
		{
			delete binaryTreeNode;
			binaryTreeNode = nullptr;
		}
	}
}


TreeNode* FindElement(TreeNode* binaryTreeNode, int data)
{
	if (!binaryTreeNode)
	{
		return nullptr;
	}
	if (binaryTreeNode->Data == data)
	{
		return binaryTreeNode;
	}
	if (data > binaryTreeNode->Data)
	{
		return FindElement(binaryTreeNode->RightNode, data);
	}

	return FindElement(binaryTreeNode->LeftNode, data);
}


TreeNode* FindBiggestElement(TreeNode* binaryTreeNode)
{
	if (!binaryTreeNode)
	{
		return nullptr;
	}

	while (binaryTreeNode->RightNode)
	{
		binaryTreeNode = binaryTreeNode->RightNode;
	}

	return binaryTreeNode;
}


TreeNode* FindSmallestElement(TreeNode* binaryTreeNode)
{
	if (!binaryTreeNode)
	{
		return nullptr;
	}

	while (binaryTreeNode->LeftNode)
	{
		binaryTreeNode = binaryTreeNode->LeftNode;
	}

	return binaryTreeNode;
}