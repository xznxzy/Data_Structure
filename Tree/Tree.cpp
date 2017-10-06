
//
//  Tree.cpp
//  Tree1
//
//  Created by zhangying on 10/4/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "Tree.hpp"
#include <iostream>

using namespace std;

Tree::Tree(){
	m_pRoot = new Node();
}

Tree::~Tree(){
	//m_pRoot->DeleteNode();
	DeleteNode(0, NULL);
}

Node* Tree::SearchNode(int nodeIndex){
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode){
	Node* tmp = SearchNode(nodeIndex);
	if (tmp == NULL) {
		return false;
	}
	Node* node = new Node();
	if (node == NULL) {
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = tmp;
	if (direction == 0) {
		tmp->pLChild = node;
	}
	if (direction == 1) {
		tmp->pRChild = node;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode){
	Node* tmp = SearchNode(nodeIndex);
	if (tmp == NULL) {
		return false;
	}
	if (pNode != NULL) {
		pNode->data = tmp->data;
	}
	tmp->DeleteNode();
	return true;
}

void Tree::PreorderTraversal(){
	m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal(){
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal(){
	m_pRoot->PostorderTraversal();
}

//Tree::Tree(int size, int * pRoot){
//	m_pTree = new int[size];
//	m_iSize = size;
//	for (int i = 0; i < size; i++) {
//		m_pTree[i] = 0;
//	}
//	m_pTree[0] = *pRoot;
//}
//
//Tree::~Tree(){
//	delete [] m_pTree;
//	m_pTree = NULL;
//}
//
//int* Tree::SearchNode(int nodeIndex){
//	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
//		return NULL;
//	}
//	if (m_pTree[nodeIndex] == 0) {
//		return NULL;
//	}
//	return &m_pTree[nodeIndex];
//}
//
//bool Tree::AddNode(int nodeIndex, int direction, int *pNode){
//	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
//		return false;
//	}
//	if (m_pTree[nodeIndex] == 0) {
//		return false;
//	}
//	if (direction == 0) {
//		if (nodeIndex*2+1 >= m_iSize) {
//			return false;
//		}
//		if (m_pTree[nodeIndex*2+1] != 0) {
//			return false;
//		}
//		m_pTree[nodeIndex*2+1] = *pNode;
//	}
//	if(direction == 1) {
//		if (nodeIndex*2+2 >= m_iSize) {
//			return false;
//		}
//		if (m_pTree[nodeIndex*2+2] != 0) {
//			return false;
//		}
//		m_pTree[nodeIndex*2+2] = *pNode;
//	}
//	return true;
//}
//
//bool Tree::DeleteNode(int nodeIndex, int *pNode){
//	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
//		return false;
//	}
//	if (m_pTree[nodeIndex] == 0) {
//		return false;
//	}
//	*pNode = m_pTree[nodeIndex];
//	m_pTree[nodeIndex] = 0;
//	return true;
//}
//
//void Tree::TreeTraverse(){
//	for (int i = 0; i < m_iSize; i++) {
//		cout << m_pTree[i] << ", ";
//	}
//	cout << endl;
//}
