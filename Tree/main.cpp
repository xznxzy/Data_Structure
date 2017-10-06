//
//  main.cpp
//  Tree1
//
//  Created by zhangying on 10/3/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
#include "Tree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	
	Tree * tree = new Tree();
	
	Node * node1 = new Node();
	node1->index = 1;
	node1->data = 5;
	
	Node * node2 = new Node();
	node2->index = 2;
	node2->data = 8;
	
	Node * node3 = new Node();
	node3->index = 3;
	node3->data = 2;
	
	Node * node4 = new Node();
	node4->index = 4;
	node4->data =6;
	
	Node * node5 = new Node();
	node5->index = 5;
	node5->data = 9;
	
	Node * node6 = new Node();
	node6->index = 6;
	node6->data = 7;
	
	tree->AddNode(0, 0, node1);
	tree->AddNode(0, 1, node2);
	
	tree->AddNode(1, 0, node3);
	tree->AddNode(1, 1, node4);
	
	tree->AddNode(2, 0, node5);
	tree->AddNode(2, 1, node6);
	
	Node tmp;
	
	tree->DeleteNode(6, &tmp);
	tree->DeleteNode(2, &tmp);
	
	cout << "Delete node: " << tmp.data << endl;
	
	tree->PostorderTraversal();
	
	delete tree;
	
//	int root = 3;
//	Tree *pTree = new Tree(10, &root);
//	
//	int node1 = 5;
//	int node2 = 8;
//	pTree->AddNode(0, 0, &node1);
//	pTree->AddNode(0, 1, &node2);
//	
//	int node3 = 2;
//	int node4 = 6;
//	
//	pTree->AddNode(1, 0, &node3);
//	pTree->AddNode(1, 1, &node4);
//	
//	int node5 = 9;
//	int node6 = 7;
//	
//	pTree->AddNode(2, 0, &node5);
//	pTree->AddNode(2, 1, &node6);
//	
//	pTree->TreeTraverse();
//	
//	int* tmp;
//	tmp = pTree->SearchNode(2);
//	cout << "Search: " << *tmp << endl;
//	
//	pTree->DeleteNode(6, tmp);
//	cout << "Delete: " << *tmp << endl;
//	
//	pTree->TreeTraverse();
	
	return 0;
}
