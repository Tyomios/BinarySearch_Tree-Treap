#pragma once
#ifndef _H_TREEP_B081
#define _H_TREEP_B081

#include <random>

/// @brief ���� ����������� ������
struct TreapNode
{
	int Key;							//< ������� ����
	int Priority		 = rand();		//< ��������� ����
	TreapNode* LeftNode  = nullptr;		//< ��������� �� ����� ����
	TreapNode* RightNode = nullptr;		//< ��������� �� ������ ����
};

/// @brief ���������� ������
struct Treap
{
	TreapNode* Root;	//< ��������� �� �������� ���� ������
};

/// @brief ������������� ����������� ������ 
///
/// @param treep ���������������� ���������� ������
void InitTreap(Treap* treep);

/// @brief �������� ����������� ������
///
/// @param node ���� ������
void DeleteTreap(TreapNode* node);

/// @brief ����� �������� � ���������� ������
///
/// @param node ���� ������
/// @param key  ������� ��������
///  
/// @return ����� ���������� ��������
TreapNode* FindElement(TreapNode* node, int key);

/// @brief ���������� ������ �� 2 ������ �� ��������
///
/// @param node  ���� ������
/// @param key	 �������� ��� ���������� 
/// @param left	 ����� ������
/// @param right ������ ������
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// @brief ������� 2 �������� � ����
///
/// @param left  ����� ������
/// @param right ������ ������
///  
/// @return		 ������� ������
TreapNode* Marge(TreapNode* left, TreapNode* right);	/// @todo ?

/// @brief ������� ���������� ���� � ������ 
///			������������ ������������������ ��������
///
/// @param node ���� ������
/// @param key  ��������
void AddNotOptimized(TreapNode*& node, int key);

/// @brief ������� ���������� ���� � ������
///			������������ ���������������� ��������
///
/// @param node ���� ������
/// @param key  ��������
void AddOptimized(TreapNode*& node, int key);

/// @brief ������� �������� ���� �� ������ 
///			������������ ���������������� ��������
///
/// @param node		���� ������
/// @param key		��������
/// @param success	������ �������� �������� 
void RemoveOptimized(TreapNode*& node, int key, bool& success);

/// @brief ������� �������� ����� �� ������
///	� ������ ������, ���������� ������������������ ��������
///
/// @param node		���� ������
/// @param key		��������
/// @param success	������ �������� ��������
void RemoveNotOptimized(TreapNode*& node, int key, bool& success);
#endif
