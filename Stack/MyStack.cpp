//
//  MyStack.cpp
//  Stack
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "MyStack.hpp"
#include <iostream>
using namespace std;

//分配内存初始化栈空间，设定栈容量，栈顶
template <typename T>
MyStack<T>::MyStack(int size){
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;
}

//回收栈空间内存
template <typename T>
MyStack<T>::~MyStack(){
	m_iSize = 0;
	m_iTop = 0;
	delete [] m_pBuffer;
	m_pBuffer = NULL;
}

//判定栈是否为空，为空返回true，非空返回false
template <typename T>
bool MyStack<T>::stackEmpty(){
	if (0 == m_iTop) {
		return true;
	} else {
		return false;
	}
}

//判断栈是否已满，为满返回true，不满返回false
template <typename T>
bool MyStack<T>::stackFull(){
	if (m_iSize == m_iTop) {
		return true;
	} else {
		return false;
	}
}

//清空栈
template <typename T>
void MyStack<T>::clearStack(){
	m_iTop = 0;
}

//已有元素的个数
template <typename T>
int MyStack<T>::stackLength(){
	return m_iTop;
}

//元素入栈，栈顶上升
template <typename T>
bool MyStack<T>::push(T elem){
	if (stackFull()) {
		return false;
	}
	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}

//元素出栈，栈顶下降
template <typename T>
bool MyStack<T>::pop(T &elem){
	if (stackEmpty()) {
		return false;
	}
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}

//遍历栈中所有元素
template <typename T>
void MyStack<T>::stackTraverse(){
	for (int i = 0; i < m_iTop; i++) {
		cout << m_pBuffer[i];
	}
}
