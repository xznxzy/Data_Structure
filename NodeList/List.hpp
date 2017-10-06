//
//  List.hpp
//  NodeList
//
//  Created by zhangying on 10/3/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "Node.hpp"

class List{
public:
	List();
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node* pNode);
	int LocateElem(Node* pNode);
	bool PriorElem(Node* pCurretNode, Node* pPreNode);
	bool NextElem(Node* pCurrentNode, Node* pNextNode);
	void ListTraverse();
	bool ListInsert(int i, Node* pNode);
	bool ListDelete(int i, Node* pNode);
	bool ListInsertHead(Node* pNode);
	bool ListInsertTail(Node* pNode);
private:
	Node* m_pList;
	int m_iLength;
};

#endif /* List_hpp */
