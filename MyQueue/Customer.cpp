//
//  Customer.cpp
//  DataStructure
//
//  Created by zhangying on 10/2/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "Customer.hpp"
#include <iostream>
using namespace std;

Customer::Customer(string name, int age){
	m_strName = name;
	m_iAge = age;
}

void Customer::printInfo() const{
	cout << "Name: " << m_strName << endl;
	cout << "Age: " << m_iAge << endl;
}
