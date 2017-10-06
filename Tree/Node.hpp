//
//  Node.hpp
//  Tree1
//
//  Created by zhangying on 10/4/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node{
public:
	Node();
	Node* SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
	int index;
	int data;
	Node* pLChild;
	Node* pRChild;
	Node* pParent;
};

#endif /* Node_hpp */
