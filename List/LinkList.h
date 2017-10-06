//
//  LinkList.h
//  List
//
//  Created by zhangying on 10/1/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>

#endif /* LinkList_h */
typedef void LinkList;

typedef struct _tag_LinkListNode{
	struct _tag_LinkListNode* next;
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);
