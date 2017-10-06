//
//  LinkList.c
//  List
//
//  Created by zhangying on 10/1/17.
//  Copyright © 2017 zhangying. All rights reserved.
//

#include "LinkList.h"
#include <string.h>
#include <mm_malloc.h>

typedef struct _tag_LinkList{
	LinkListNode header;
	int length;
}TLinkList;

LinkList* LinkList_Create(){
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
	if (ret == NULL) {
		return NULL;
	}
	memset(ret, 0, sizeof(TLinkList));
	ret->header.next = NULL;
	ret->length = 0;
	return ret;
}

void LinkList_Destroy(LinkList* list){
	if (list == NULL) {
		return;
	}
	free(list);
}

void LinkList_Clear(LinkList* list){
	TLinkList* tList = (TLinkList*)list;
	if (tList == NULL) {
		return;
	}
	tList->length = 0;
	tList->header.next = NULL;
}

int LinkList_Length(LinkList* list){
	TLinkList* tList = (TLinkList*)list;
	if (tList == NULL) {
		return -1;
	}
	return tList->length;
	return 0;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos){
	TLinkList* tList = (TLinkList*)list;
	LinkListNode* current = &tList->header;
	int i = 0;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tList->length++;
	return 0;
}

LinkListNode* LinkList_Get(LinkList* list, int pos){
	TLinkList* tList = (TLinkList*)list;
	LinkListNode* current = &tList->header;
	if (list == NULL || pos < 0 || pos > tList->length) {
		return NULL;
	}
	int i = 0;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	return current->next;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos){
	TLinkList* tList = (TLinkList*)list;
	LinkListNode* current = &tList->header;
	LinkListNode* ret = NULL;
	if (list == NULL || pos < 0 || pos >= tList->length) {
		return NULL;
	}
	int i = 0;
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	tList->length--;
	free(ret);
	return ret;
}
