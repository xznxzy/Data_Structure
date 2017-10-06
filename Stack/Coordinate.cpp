//
//  Coordinate.cpp
//  Stack
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "Coordinate.hpp"
#include <iostream>
using namespace std;

Coordinate::Coordinate(int x, int y){
	m_iX = x;
	m_iY = y;
}

void Coordinate::printCoordinate(){
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
}

//ostream& Coordinate::operator<<(ostream & out, Coordinate & coor){
//	out << "(" << m_iX << "," << m_iY << ")" << endl;
//	return out;
//}
