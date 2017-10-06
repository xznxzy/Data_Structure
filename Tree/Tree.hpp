//
//  Tree.hpp
//  Tree1
//
//  Created by zhangying on 10/4/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "Node.hpp"

class Tree{
public:
	Tree();
	~Tree();
	Node* SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex, int direction, Node* pNode);
	bool DeleteNode(int nodeIndex, Node* pNode);
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
//	int* SearchNode(int nodeIndex);
//	bool AddNode(int nodeIndex, int direction, int* pNode);
//	bool DeleteNode(int nodeIndex, int* pNode);
//	void TreeTraverse();
private:
	Node* m_pRoot;
};

#endif /* Tree_hpp */
