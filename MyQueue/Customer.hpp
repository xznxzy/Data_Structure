//
//  Customer.hpp
//  DataStructure
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Customer{
public:
	Customer(string name = "", int age = 0);
	void printInfo() const;
private:
	string m_strName;
	int m_iAge;
};

#endif /* Customer_hpp */
