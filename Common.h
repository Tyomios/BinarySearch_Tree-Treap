#pragma once
#ifndef _H_COMMON_A543_
#define _H_COMMON_A543_

#include <iostream>

#include "BinaryTree.h"
#include "Treap.h"

/// @brief  Функция получения корректного значения для узла
///
/// @return Корректное целочисленное значение
int GetValue();

/// @brief Меню бинарного дерева 
///
/// @param binaryTree Указатель на бинарное дерево
void BinaryTreeMenu(BinaryTree* binaryTree);

/// @brief Меню Декартового дерева
///
/// @param node Указатель на узел дерева
void TreapMenu(TreapNode* node);

/// @brief Функция отображения Декартового дерева
///			на экране
/// 
/// @param node		Указатиель на узел дерева
/// @param indent	Отступ
void ShowTreap(TreapNode* node, int indent);

/// @brief  Функция отображения бинарного дерева
///
/// @param binaryTreeNode	Указатель на узел дерева
/// @param indent			Отступ
void ShowBinaryTree(TreeNode* binaryTreeNode, int indent);
#endif
