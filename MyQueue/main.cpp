//
//  main.cpp
//  DataStructure
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
#include "MyQueue.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	MyQueue * p = new MyQueue(4);
	
	Customer c1("name1", 20);
	Customer c2("name2", 30);
	Customer c3("name3", 40);
//	Customer c4("name4", 24);
	
	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);
	
	p->QueueTraverse();
	
	Customer c4("",0);
	p->DeQueue(c4);
	c4.printInfo();
	p->QueueTraverse();
	
//	MyQueue * p = new MyQueue(4);
//	
//	p->EnQueue(10);
//	p->EnQueue(12);
//	p->EnQueue(16);
//	p->EnQueue(18);
//	p->EnQueue(20);
//
//	p->QueueTraverse();
//	
//	int e = 0;
//	p->DeQueue(e);
//	cout << "e = " << e << endl;
//	p->DeQueue(e);
//	cout << "e = " << e << endl;
//	
//	p->QueueTraverse();
//	p->ClearQueue();
//	p->QueueTraverse();
//	p->EnQueue(20);
//	p->EnQueue(30);
//	p->QueueTraverse();
//	
//	delete p;
	
	return 0;
}
