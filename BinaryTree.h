#pragma once
#ifndef _H_BINARYTREE_C878
#define _H_BINARYTREE_C878

/// @brief ���� ��������� ������
struct TreeNode 
{
	int Data;						//< ������ ����
	TreeNode* LeftNode	= nullptr;	//< ��������� �� ����� ����
	TreeNode* RightNode = nullptr;	//< ��������� �� ������ ����
};

/// @brief �������� ������
struct BinaryTree
{
	TreeNode* Root;		//< ��������� �� �������� ���� ������
};

/// @brief ������� ������������� ��������� ������
///
/// @param binaryTree ���������������� ������
void InitTree(BinaryTree* binaryTree);

/// @brief ������� �������� ��������� ������
///
/// @param binarytree ���� ������
void DeleteTree(TreeNode* binaryTreeNode);

/// @brief  ������� ���������� �������� � ������
///
/// @param binaryTreeNode	���� ������ 
/// @param data				��������
void AddElement(TreeNode*& binaryTreeNode, int data);

/// @brief ������� �������� ��������� ������
///
/// @param binaryTreeNode	���� ������ 
/// @param data				��������
/// @param success			������ �������� ��������
void RemoveElement(TreeNode*& binaryTreeNode, int data, bool& success);

/// @brief ������� ������ �������� � ������
///
/// @param binaryTreeNode	���� ������ 
/// @param data				��������
///  
/// @return ����� ���������� ��������
TreeNode* FindElement(TreeNode* binaryTreeNode, int data);

/// @brief ������� ������ ����������� �������� � ������
///
/// @param binaryTreeNode ���� ������ 
/// 
/// @return ����� ���� � ���������� ���������
TreeNode* FindBiggestElement(TreeNode* binaryTreeNode);

/// @brief ������� ������ ����������� �������� � ������
///
/// @param binaryTreeNode ���� ������ 
/// 
/// @return ����� ���� � ���������� ���������
TreeNode* FindSmallestElement(TreeNode* binaryTreeNode);
#endif