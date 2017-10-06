//
//  main.c
//  List
//
//  Created by zhangying on 10/1/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h"

typedef struct _Teacher{
	LinkListNode node;
	char name[64];
	int age;
}Teacher;

int main(int argc, const char * argv[]) {
	
	Teacher t1, t2, t3;
	int i = 0;
	int length = 0;
	LinkList* list = NULL;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	
	list = LinkList_Create();
	
	length = LinkList_Length(list);
	
	LinkList_Insert(list, (LinkListNode*)&t1, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&t2, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&t3, LinkList_Length(list));
	
	for (i=0; i<LinkList_Length(list); i++) {
		Teacher * tmp = (Teacher*)LinkList_Get(list, i);
		if(tmp != NULL){
			printf("age = %d \n", tmp->age);
		}
	}
	while(LinkList_Length(list) > 0){
		Teacher * tmp = (Teacher*)LinkList_Delete(list, i);
		if(tmp != NULL){
			printf("age = %d \n", tmp->age);
		}
	}
	LinkList_Destroy(list);
	
	/*
	LinkList* LinkList_Create();
	
	void LinkList_Destroy(LinkList* list);
	
	void LinkList_Clear(LinkList* list);
	
	int LinkList_Length(LinkList* list);
	
	int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
	
	LinkListNode* LinkList_Get(LinkList* list, int pos);
	
	LinkListNode* LinkList_Delete(LinkList* list, int pos);
	*/
	 
	return 0;
}
