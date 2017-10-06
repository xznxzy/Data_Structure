//
//  MyQueue.hpp
//  DataStructure
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef MyQueue_hpp
#define MyQueue_hpp

#include <stdio.h>
#include "Customer.hpp"

class MyQueue{
public:
	MyQueue(int queueCapacity);	//创建队列
	virtual ~MyQueue();			//销毁队列
	void ClearQueue();			//清空队列
	bool QueueEmpty() const;	//判空队列
	bool QueueFull() const;		//判满队列
	int QueueLength() const;	//队列长度
	bool EnQueue(Customer element);	//新元素入队
	bool DeQueue(Customer &element);	//首元素出队
	void QueueTraverse();		//遍历队列
private:
	Customer * m_pQueue;		//队列数组指针
	int m_iQueueLen;			//队列元素个数
	int m_iQueueCapacity;		//队列数组容量
	int m_iHead;				//队头
	int m_iTail;				//队尾
};

#endif /* MyQueue_hpp */
