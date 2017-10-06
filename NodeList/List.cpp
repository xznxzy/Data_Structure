//
//  List.cpp
//  NodeList
//
//  Created by zhangying on 10/3/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "List.hpp"
#include <iostream>

using namespace std;

List::List(){
	m_iLength = 0;
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
}

List::~List(){
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::ListEmpty(){
	if (0 == m_iLength) {
		return true;
	} else {
		return false;
	}
}

int List::ListLength(){
	return m_iLength;
}

void List::ClearList(){
	Node* currentNode = m_pList->next;
	while (currentNode != NULL) {
		Node* tmp = currentNode->next;
		delete currentNode;
		currentNode = tmp;
	}
	m_iLength = 0;
	m_pList->next = NULL;
}

bool List::ListInsertHead(Node *pNode){
	Node* tmp = m_pList->next;
	Node* newNode = new Node;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = tmp;
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node *pNode){
	Node* currentNode = m_pList;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	Node* newNode = new Node;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListInsert(int i, Node *pNode){
	if (i < 0 || i > m_iLength) {
		return false;
	}
	Node* currentNode = m_pList;
	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}
	Node* newNode = new Node;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return true;
}

bool List::ListDelete(int i, Node *pNode){
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node* currentNode = m_pList;
	Node* preNode = NULL;
	for (int k = 0; k <= i; k++) {
		preNode = currentNode;
		currentNode = currentNode->next;
	}
	preNode->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::GetElem(int i, Node *pNode){
	if (i < 0 || i > m_iLength) {
		return false;
	}
	Node* currentNode = m_pList;
	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List::LocateElem(Node *pNode){
	Node* currentNode = m_pList;
	int count = 0;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data) {
			return count;
		}
		count++;
	}
	return -1;
}

void List::ListTraverse(){
	Node* currentNode = m_pList->next;
	while (currentNode != NULL) {
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}
















