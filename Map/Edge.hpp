//
//  Edge.hpp
//  Map
//
//  Created by zhangying on 10/5/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>

class Edge{
public:
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);
	int m_iNodeIndexA;
	int m_iNodeIndexB;
	int m_iWeightValue;
	bool m_bSelected;
};

#endif /* Edge_hpp */
