//
//  main.cpp
//  NodeList
//
//  Created by zhangying on 10/3/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
#include "List.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
	List* pList = new List();
	
	Node node1;
	node1.data = 2;
	Node node2;
	node2.data = 3;
	Node node3;
	node3.data = 4;
	Node node4;
	node4.data = 5;
	Node node5;
	node5.data = 7;
	Node tmp;
	
	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);
	
	pList->ListInsert(0, &node5);
	pList->GetElem(1, &tmp);
	cout << "1tmp.data: " << tmp.data << endl;
	
	pList->ListDelete(0, &tmp);
	
	cout << "2tmp.data: " << tmp.data << endl;
	
	pList->ListTraverse();


	
	
	delete pList;
	pList = NULL;
	
	return 0;
}
