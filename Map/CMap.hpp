//
//  CMap.hpp
//  Map
//
//  Created by zhangying on 10/4/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef CMap_hpp
#define CMap_hpp

#include <stdio.h>
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

class CMap{
public:
	CMap(int capacity);
	~CMap();
	//向图中加入顶点（结点）
	bool addNode(Node* pNode);
	//重置顶点
	void resetNode();
	
	//为有向图设置邻接矩阵
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
	//为无向图设置邻接矩阵
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);
	
	//打印邻接矩阵
	void printMatrix();
	
	//深度优先遍历
	void depthFirstTraverse(int nodeIndex);
	//广度优先遍历
	void breadthFirstTraverse(int nodeIndex);
	
	//普里姆生成树算法
	void primTree(int nodeIndex);
	
	//克鲁斯卡尔生成树算法
	void kruskalTree();
	
	
private:
	//从矩阵中获取权值
	bool getValueFromMatrix(int row, int col, int &val);
	//广度优先遍历实现函数
	void breadthFirstTraverseImpl(vector<int> preVec);
	
	int getMinEdge(vector<Edge> edgeVec);
	
	//判断顶点是否在点集合中
	bool isInSet(vector<int> nodeSet, int target);
	//合并两个顶点集合
	void mergeNodeSet(vector<int> &nodeSetA, vector<int> nodeSetB);
	
private:
	//图中最多可以容纳的顶点数
	int m_iCapacity;
	//已经添加的顶点（结点）个数
	int m_iNodeCount;
	//用来存放顶点数组
	Node * m_pNodeArray;
	//用来存放邻接矩阵
	int * m_pMatrix;
	
	//保存最小边
	Edge * m_pEdge;
};

#endif /* CMap_hpp */
