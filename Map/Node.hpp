//
//  Node.hpp
//  Map
//
//  Created by zhangying on 10/4/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node{
public:
	Node(char data = 0);
	char m_cData;
	bool m_bIsVisited;
};

#endif /* Node_hpp */
