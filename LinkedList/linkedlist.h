#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include<iostream>
using namespace std; 
struct NODE
{
	int key;
	NODE* next;
};

struct List{
	NODE *pHead = NULL;
	NODE *pTail = NULL;
};
List* createList();
NODE* createNode(int data);
bool addHead(List* &L, int Data);
bool addTail(List* &L, int Data);
void removeHead(List* &L);
void removeTail(List* &L);
void removeAll(List* &L);
void printList(List* L);
int countElements(List* L);

void list_Copy(List* src, List* &copy);
List* reverseList(List* L);
void removeDuplicate(List* &L);
bool removeElement(List* &L, int key);
#endif

