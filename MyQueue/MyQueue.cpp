//
//  MyQueue.cpp
//  DataStructure
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//
#include <iostream>
#include "MyQueue.hpp"
using namespace std;

//创建队列
MyQueue::MyQueue(int queueCapacity){
	m_iQueueCapacity = queueCapacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	m_pQueue = new Customer[m_iQueueCapacity];
}

//销毁队列
MyQueue::~MyQueue(){
	delete [] m_pQueue;
	m_pQueue = NULL;
}

//清空队列
void MyQueue::ClearQueue(){
	m_iQueueLen = 0;
	m_iHead = 0;
	m_iTail = 0;
}

//判空队列
bool MyQueue::QueueEmpty() const{
	if (m_iQueueLen == 0) {
		return true;
	} else {
		return false;
	}
//	return m_iQueueLen == 0 ? true : false;
}

//判满队列
bool MyQueue::QueueFull() const{
	if (m_iQueueLen == m_iQueueCapacity) {
		return true;
	} else {
		return false;
	}
}

//队列长度
int MyQueue::QueueLength() const{
	return m_iQueueLen;
}

//新元素入队
bool MyQueue::EnQueue(Customer element){
	if (QueueFull()) {
		return false;
	}
	m_pQueue[m_iTail] = element;
	m_iQueueLen++;
	m_iTail++;
	m_iTail = m_iTail % m_iQueueCapacity;
	return true;
}

//首元素出队
bool MyQueue::DeQueue(Customer &element){
	if (QueueEmpty()) {
		return false;
	}
	element = m_pQueue[m_iHead];
	m_iHead++;
	m_iHead = m_iHead % m_iQueueCapacity;
	m_iQueueLen--;
	return true;
}

//遍历队列
void MyQueue::QueueTraverse(){
	for (int i = m_iHead; i < m_iHead + m_iQueueLen; i++) {
		m_pQueue[i % m_iQueueCapacity].printInfo();
	}
}









