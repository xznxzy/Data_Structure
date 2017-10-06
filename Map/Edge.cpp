//
//  Edge.cpp
//  Map
//
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "Edge.hpp"

Edge::Edge(int nodeIndexA, int nodeIndexB, int weightValue){
	m_iNodeIndexA = nodeIndexA;
	m_iNodeIndexB = nodeIndexB;
	m_iWeightValue = weightValue;
	m_bSelected = false;
}
