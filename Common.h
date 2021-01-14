#pragma once
#ifndef _H_COMMON_A543_
#define _H_COMMON_A543_

#include <iostream>

#include "BinaryTree.h"
#include "Treap.h"

/// @brief  ������� ��������� ����������� �������� ��� ����
///
/// @return ���������� ������������� ��������
int GetValue();

/// @brief ���� ��������� ������ 
///
/// @param binaryTree ��������� �� �������� ������
void BinaryTreeMenu(BinaryTree* binaryTree);

/// @brief ���� ����������� ������
///
/// @param node ��������� �� ���� ������
void TreapMenu(TreapNode* node);

/// @brief ������� ����������� ����������� ������
///			�� ������
/// 
/// @param node		���������� �� ���� ������
/// @param indent	������
void ShowTreap(TreapNode* node, int indent);

/// @brief  ������� ����������� ��������� ������
///
/// @param binaryTreeNode	��������� �� ���� ������
/// @param indent			������
void ShowBinaryTree(TreeNode* binaryTreeNode, int indent);
#endif
