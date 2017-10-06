//
//  CMap.cpp
//  Map
//
//  Created by zhangying on 10/4/17.
//  Copyright © 2017 zhangying. All rights reserved.
//
#include <iostream>
#include "CMap.hpp"

using namespace std;

CMap::CMap(int capacity){
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));
	m_pEdge = new Edge[m_iCapacity-1];
}

CMap::~CMap(){
	delete [] m_pNodeArray;
	delete [] m_pMatrix;
	delete [] m_pEdge;
}

bool CMap::addNode(Node *pNode){
	if (pNode == NULL) {
		return false;
	}
	if (m_iNodeCount >= m_iCapacity) {
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	m_iNodeCount++;
	return true;
}

void CMap::resetNode(){
	for (int i = 0; i < m_iNodeCount; i++) {
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val){
	if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity) {
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val){
	if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity) {
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

bool CMap::getValueFromMatrix(int row, int col, int &val){
	if (row < 0 || row >= m_iCapacity || col < 0 || col >= m_iCapacity) {
		return false;
	}
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

void CMap::printMatrix(){
	for (int i = 0; i < m_iCapacity; i++) {
		for (int k = 0; k < m_iCapacity; k++) {
			cout << m_pMatrix[i * m_iCapacity + k] << " ";
		}
		cout << endl;
	}
}

void CMap::depthFirstTraverse(int nodeIndex){
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	for (int i = 0; i < m_iCapacity; i++) {
		getValueFromMatrix(nodeIndex, i, value);
		if (value != 0) {
			if (m_pNodeArray[i].m_bIsVisited) {
				continue;
			} else {
				depthFirstTraverse(i);
			}
		} else {
			continue;
		}
	}
}

void CMap::breadthFirstTraverse(int nodeIndex){
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	
	vector<int> curVec;
	curVec.push_back(nodeIndex);
	breadthFirstTraverseImpl(curVec);
}

void CMap::breadthFirstTraverseImpl(vector<int> preVec){
	int value = 0;
	vector<int> curVec;
	
	for (int j = 0; j < (int)preVec.size(); j++) {
		for (int i = 0; i < m_iCapacity; i++) {
			getValueFromMatrix(preVec[j], i, value);
			if (value != 0) {
				if (m_pNodeArray[i].m_bIsVisited) {
					continue;
				} else {
					cout << m_pNodeArray[i].m_cData << " ";
					m_pNodeArray[i].m_bIsVisited = true;
					curVec.push_back(i);
				}
			}
		}
	}
	if (curVec.size() == 0) {
		return;
	} else {
		breadthFirstTraverseImpl(curVec);
	}
}

void CMap::primTree(int nodeIndex){
	int value = 0;
	int edgeCount = 0;
	vector<int> nodeVec;
	vector<Edge> edgeVec;
	
	cout << m_pNodeArray[nodeIndex].m_cData << endl;
	
	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	
	//算法结束条件
	while (edgeCount < m_iCapacity-1) {
		int tmp = nodeVec.back();
		for (int i = 0; i < m_iCapacity; i++) {
			getValueFromMatrix(tmp, i, value);
			if (value != 0) {
				if (m_pNodeArray[i].m_bIsVisited) {
					continue;
				} else {
					Edge edge(tmp, i, value);
					edgeVec.push_back(edge);
				}
			}
		}
		//从待选边集合中选取权值最小的边
		/////////////////////////////
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;
		
		cout << edgeVec[edgeIndex].m_iNodeIndexA << "-->" << edgeVec[edgeIndex].m_iNodeIndexB;
		cout << ": " << edgeVec[edgeIndex].m_iWeightValue;
		
		//将找到的边放入已选边集合
		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		edgeCount++;
		
		
		//找到与已选边相连的点
		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		cout << " Node: " << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec){
	int minWeight = 0;
	int edgeIndex = 0;
	int i = 0;
	for (i = 0; i < edgeVec.size(); i++) {
		if (!edgeVec[i].m_bSelected) {
			minWeight = edgeVec[i].m_iWeightValue;
			edgeIndex = i;
			break;
		}
	}
	////////////////////////////////
	if (minWeight == 0) {
		return -1;
	}
	
	for (; i < edgeVec.size(); i++) {
		if (edgeVec[i].m_bSelected) {
			continue;
		} else {
			if (minWeight > edgeVec[i].m_iWeightValue) {
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}
	}
	
	return edgeIndex;
}

void CMap::kruskalTree(){
	int value = 0;
	int edgeCount = 0;
	
	//定义存放结点集合的数组
	vector<vector<int>> nodeSets;
	
	//第一步：取出所有边
	vector<Edge> edgeVec;
	for (int i = 0; i < m_iCapacity; i++) {
		for (int k = i + 1; k < m_iCapacity; k++) {
			getValueFromMatrix(i, k, value);
			if (value != 0) {
				Edge edge(i, k, value);
				edgeVec.push_back(edge);
			}
		}
	}
	
	//第二步：从所有边中取出组成最小生成树的边
	//	1.找到算法结束条件
	while (edgeCount < m_iCapacity - 1) {
		//	2.从边集合中找到最小边
		int minEdgeIndex = getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected = true;
		
		//	3.找出最小边连接的点
		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;
		
		//	4.找出点所在的点集合
		bool nodeAIsInSet = false;
		bool nodeBIsInSet = false;
		
		int nodeAInSetLabel = -1;
		int nodeBInSetLabel = -1;
		
		for (int i = 0; i < nodeSets.size(); i++) {
			nodeAIsInSet = isInSet(nodeSets[i], nodeAIndex);
			if (nodeAIsInSet) {
				nodeAInSetLabel = i;
			}
		}
		
		for (int i = 0; i < nodeSets.size(); i++) {
			nodeBIsInSet = isInSet(nodeSets[i], nodeBIndex);
			if (nodeBIsInSet) {
				nodeBInSetLabel = i;
			}
		}
		
		//	5.根据点所在集合的不同做出不同的处理
		if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1) {
			vector<int> vec;
			vec.push_back(nodeAIndex);
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);
		} else if(nodeAInSetLabel == -1 && nodeBInSetLabel != -1){
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
		} else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1){
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
		} else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1
				  && nodeAInSetLabel != nodeBInSetLabel){
			mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);
			for (int k = nodeBInSetLabel; k < (int)nodeSets.size()-1; k++) {
				nodeSets[k] = nodeSets[k+1];
			}
		} else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel){
			continue;
		}
		m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
		edgeCount++;
		
		cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "-->";
		cout << edgeVec[minEdgeIndex].m_iNodeIndexB << ": ";
		cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

bool CMap::isInSet(vector<int> nodeSet, int target){
	for (int i = 0; i < nodeSet.size(); i++) {
		if (nodeSet[i] == target) {
			return true;
		}
	}
	return false;
}

void CMap::mergeNodeSet(vector<int> &nodeSetA, vector<int> nodeSetB){
	for (int i = 0; i < nodeSetB.size(); i++) {
		nodeSetA.push_back(nodeSetB[i]);
	}
}


















