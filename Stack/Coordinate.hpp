//
//  Coordinate.hpp
//  Stack
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <stdio.h>
#include_next <ostream>
using namespace std;
class Coordinate{
public:
	friend ostream& operator<<(ostream & out, Coordinate & coor);
public:
	Coordinate(int x = 0, int y = 0);
	void printCoordinate();
private:
	int m_iX;
	int m_iY;
};

#endif /* Coordinate_hpp */
