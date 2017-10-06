//
//  MyStack.hpp
//  Stack
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef MyStack_hpp
#define MyStack_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
template <typename T>
class MyStack{
public:
	//分配内存初始化栈空间，设定栈容量，栈顶
	MyStack(int size);
	//回收栈空间内存
	~MyStack();
	//判定栈是否为空，为空返回true，非空返回false
	bool stackEmpty();
	//判断栈是否已满，为满返回true，不满返回false
	bool stackFull();
	//清空栈
	void clearStack();
	//已有元素的个数
	int stackLength();
	//元素入栈，栈顶上升
	bool push(T elem);
	//元素出栈，栈顶下降
	bool pop(T &elem);
	//遍历栈中所有元素
	void stackTraverse();
private:
	T * m_pBuffer;	//栈空间指针
	int m_iSize;		//栈容量
	int m_iTop;			//栈顶，栈中元素个数
};


#endif /* MyStack_hpp */
