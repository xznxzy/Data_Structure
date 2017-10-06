//
//  main.cpp
//  Stack
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <iostream>
#include "MyStack.hpp"
#include "Coordinate.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
	
	MyStack<Coordinate> * pStack = new MyStack<Coordinate>(5);
	
	if(pStack->stackEmpty()){
		cout << "pStack->stackEmpty(): true" << endl;
	}

	Coordinate c1(10,20);
	Coordinate c2(5,15);
	Coordinate c3(6,13);
	Coordinate c4(50,4);
	Coordinate c5(24,9);
	pStack->push(c1);
	
	if(pStack->stackEmpty()){
		cout << "pStack->stackEmpty(): true" << endl;
	}
	
	Coordinate elem;
	
	pStack->push(c2);
	pStack->push(c3);
	pStack->push(c4);
	pStack->push(c5);
	
	pStack->pop(elem);
	
	elem.printCoordinate();
	
	pStack->stackTraverse();
	
	if (pStack->stackFull()) {
		cout << "pStack->stackFull(): true" << endl;
	}
	
	pStack->clearStack();
	
	if(pStack->stackEmpty()){
		cout << "pStack->stackEmpty(): true" << endl;
	}

	
	cout << "pStack->stackLength(): " << pStack->stackLength() << endl;
	
	delete pStack;
	pStack = NULL;
	
	return 0;
}
