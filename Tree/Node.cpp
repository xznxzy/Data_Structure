//
//  Node.cpp
//  Tree1
//
//  Created by zhangying on 10/4/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "Node.hpp"
#include <iostream>

using namespace std;

Node::Node(){
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}

Node* Node::SearchNode(int nodeIndex){
	if (this->index == nodeIndex) {
		return this;
	}
	Node * tmp = NULL;
	if (this->pLChild != NULL) {
		if (this->pLChild->index == nodeIndex) {
			return this->pLChild;
		} else {
			tmp = this->pLChild->SearchNode(nodeIndex);
			if (tmp != NULL) {
				return tmp;
			}
		}
	}
	if (this->pRChild != NULL) {
		if (this->pRChild->index == nodeIndex) {
			return this->pRChild;
		} else {
			tmp = this->pRChild->SearchNode(nodeIndex);
			return tmp;
		}
	}
	return NULL;
}

void Node::DeleteNode(){
	if (this->pLChild != NULL) {
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL) {
		this->pRChild->DeleteNode();
	}
	if (this->pParent != NULL) {
		if (this->pParent->pLChild == this) {
			this->pParent->pLChild = NULL;
		}
		if (this->pParent->pRChild == this) {
			this->pParent->pRChild = NULL;
		}
	}
	delete this;
}

void Node::PreorderTraversal(){
	
	cout << this->index << "------" << this->data << endl;
	
	if (this->pLChild != NULL) {
		this->pLChild->PreorderTraversal();
	}
	
	if (this->pRChild != NULL) {
		this->pRChild->PreorderTraversal();
	}
}

void Node::InorderTraversal(){
	
	if (this->pLChild != NULL) {
		this->pLChild->InorderTraversal();
	}
	
	cout << this->index << "------" << this->data << endl;
	
	if (this->pRChild != NULL) {
		this->pRChild->InorderTraversal();
	}
}

void Node::PostorderTraversal(){
	
	if (this->pLChild != NULL) {
		this->pLChild->PostorderTraversal();
	}
	
	if (this->pRChild != NULL) {
		this->pRChild->PostorderTraversal();
	}
	
	cout << this->index << "------" << this->data << endl;
}











