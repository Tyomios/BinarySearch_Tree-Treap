#pragma once
#ifndef _H_TREEP_B081
#define _H_TREEP_B081

#include <random>

/// @brief узел Декартового дерева
struct TreapNode
{
	int Key;							//< Значене узла
	int Priority		 = rand();		//< Приоритет узла
	TreapNode* LeftNode  = nullptr;		//< Указатель на левый узел
	TreapNode* RightNode = nullptr;		//< Указатель на правый узел
};

/// @brief Декартовое дерево
struct Treap
{
	TreapNode* Root;	//< Указатель на корневой узел дерева
};

/// @brief Инициализация декартового дерева 
///
/// @param treep Инициализируемое декартовое дерево
void InitTreap(Treap* treep);

/// @brief Удаление декартового дерева
///
/// @param node Узел дерева
void DeleteTreap(TreapNode* node);

/// @brief Поиск элемента в декартовом дереве
///
/// @param node Узел дерева
/// @param key  Искомое значение
///  
/// @return Адрес найденного значения
TreapNode* FindElement(TreapNode* node, int key);

/// @brief Разделение дерева на 2 дерева по значению
///
/// @param node  Узел дерева
/// @param key	 Критерий для разделения 
/// @param left	 Левое дерево
/// @param right Правое дерево
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// @brief Слияние 2 деревьев в одно
///
/// @param left  Левое дерево
/// @param right Правое дерево
///  
/// @return		 Единное дерево
TreapNode* Marge(TreapNode* left, TreapNode* right);	/// @todo ?

/// @brief Функция добавления узла в дерево 
///			Использующая неоптимизированный алгоритм
///
/// @param node Узел дерева
/// @param key  Значение
void AddNotOptimized(TreapNode*& node, int key);

/// @brief Функция доюавления узла в дерево
///			Использующая оптимизированный алгоритм
///
/// @param node Узел дерева
/// @param key  Значение
void AddOptimized(TreapNode*& node, int key);

/// @brief Функция удаления узла из дерева 
///			Использующая оптимизированный алгоритм
///
/// @param node		Узел дерева
/// @param key		Значение
/// @param success	Статус удаления элемента 
void RemoveOptimized(TreapNode*& node, int key, bool& success);

/// @brief Функция удаления узлов из дерева
///	С равным ключем, использует неоптимизированный алгоритм
///
/// @param node		Узел дерева
/// @param key		Значение
/// @param success	Статус удаления элемента
void RemoveNotOptimized(TreapNode*& node, int key, bool& success);
#endif
