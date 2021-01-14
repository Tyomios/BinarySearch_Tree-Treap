#pragma once
#ifndef _H_BINARYTREE_C878
#define _H_BINARYTREE_C878

/// @brief Узел бинарного дерева
struct TreeNode 
{
	int Data;						//< Данные узла
	TreeNode* LeftNode	= nullptr;	//< Указатель на левый узел
	TreeNode* RightNode = nullptr;	//< Указатель на правый узел
};

/// @brief Бинарное дерево
struct BinaryTree
{
	TreeNode* Root;		//< Указатель на корневой узел дерева
};

/// @brief Функция инициализации бинарного дерева
///
/// @param binaryTree Инициализируемое дерево
void InitTree(BinaryTree* binaryTree);

/// @brief Функция удаления бинарного дерева
///
/// @param binarytree Узел дерева
void DeleteTree(TreeNode* binaryTreeNode);

/// @brief  Функция добавления элемента в дерево
///
/// @param binaryTreeNode	Узел дерева 
/// @param data				Значение
void AddElement(TreeNode*& binaryTreeNode, int data);

/// @brief Функция удаления бинарного дерева
///
/// @param binaryTreeNode	Узел дерева 
/// @param data				Значение
/// @param success			Статус удаления элемента
void RemoveElement(TreeNode*& binaryTreeNode, int data, bool& success);

/// @brief Функция поиска элемента в дереве
///
/// @param binaryTreeNode	Узел дерева 
/// @param data				Значение
///  
/// @return Адрес найденного элемента
TreeNode* FindElement(TreeNode* binaryTreeNode, int data);

/// @brief Функция поиска наибольшего значения в дереве
///
/// @param binaryTreeNode Узел дерева 
/// 
/// @return Адрес узла с наибольшим значением
TreeNode* FindBiggestElement(TreeNode* binaryTreeNode);

/// @brief Функция поиска наименьшего элемента в дереве
///
/// @param binaryTreeNode Узел дерева 
/// 
/// @return Адрес узла с наименьшим значением
TreeNode* FindSmallestElement(TreeNode* binaryTreeNode);
#endif