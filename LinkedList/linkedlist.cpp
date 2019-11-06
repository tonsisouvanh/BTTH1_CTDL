#include"linkedlist.h"
List* createList(){
	List* l = new List();
	l->pHead = l->pTail = NULL;
	return l;
}
NODE* createNode(int data){
	NODE *p = new NODE;
	p->key = data;
	p->next = NULL;
	return p;
}
bool addHead(List* &L, int Data){
	NODE *p = createNode(Data);
	if (L->pHead == NULL){
		L->pHead = L->pTail = p;
		return true;
	}
	else{
		p->next = L->pHead;
		L->pHead = p;
		return true;
	}
	return false;
}
bool addTail(List* &L, int Data){
	NODE *p = createNode(Data);
	if (L->pHead == NULL){
		L->pHead = L->pTail = p;
		return true;
	}
	else{
		L->pTail->next = p;
		L->pTail = p;
		return true;
	}
	return false;
}
void removeHead(List* &L){
	if (L->pHead == NULL) return;
	else if (L->pHead->next != NULL){
		NODE *p = L->pHead;
		L->pHead = L->pHead->next;
		p->next = NULL;
	}
	else
		L->pHead = L->pTail = NULL;
}
void removeTail(List* &L){
	NODE *p = L->pHead;
	if (L->pHead->next == NULL && L->pTail->next == NULL){
		L->pHead = L->pTail = NULL;
	}
	else{
		while (p != NULL){
			if (p->next == L->pTail){
				L->pTail = p;
				p->next = NULL;
				break;
			}
			p = p->next;
		}
	}
}
void removeAll(List* &L){
	L->pHead = L->pTail = NULL;
}
void printList(List* L){
	for (NODE *p = L->pHead; p != NULL; p = p->next){
		printf("%d\t", p->key);
	}
	cout << endl;
}
int countElements(List* L){
	NODE *p = L->pHead;
	int dem = 0;
	while (p != NULL){
		dem++;
		p = p->next;
	}
	return dem;
}

void list_Copy(List* src, List* &copy)
{
	NODE *p = src->pHead;
	while (p != NULL){
		addTail(copy, p->key);
		p = p->next;
	}
}
List* reverseList(List* L){
	List* copy = createList();
	list_Copy(L, copy);
	NODE* current = copy->pHead;
	NODE *prev = NULL, *next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	copy->pHead = prev;
	return copy;
}
void removeDuplicate(List* &L){
	NODE *ptr1, *ptr2, *dup;
	ptr1 = L->pHead;

	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;

		while (ptr2->next != NULL)
		{
			if (ptr1->key == ptr2->next->key)
			{
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete(dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}
bool removeElement(List* &L, int key){
	NODE *p = L->pHead;
	NODE *prev = NULL;

	if (p->key == key){
		removeHead(L);
		return 1;
	}
	else{
		while (p != NULL){
			if (p->key == key){
				if (p->next == NULL){
					L->pTail = prev;
					prev->next = NULL;
				}
				else{
					prev->next = p->next;
					p->next = NULL;
				}
				return 1;
			}
			prev = p;
			p = p->next;
		}
	}
	return 0;
}

void main(){
	int x, n = 0;
	int num = 0;
	List* l = createList();
	List* list_reversed = createList();
	do{
		cout << "0.Exit" << endl;
		cout << "1.Add head" << endl;
		cout << "2.Add tail" << endl;
		cout << "3.Remove head" << endl;
		cout << "4.Remove tail" << endl;
		cout << "5.Remove all" << endl;
		cout << "6.Print list" << endl;
		cout << "7.Count element" << endl;
		cout << "8.Reverse list" << endl;
		cout << "9.Remove duplicate" << endl;
		cout << "10. Remove element" << endl;
		cout << "Enter number to excute: "; cin >> x;


		if (x == 0){
			return;
		}
		if (x == 1){
			system("cls");
			cout << "Enter value: "; cin >> num;
			if (addHead(l, num)){ cout << "added\n"; }

			goto next;
		}
		if (x == 2){
			system("cls");
			cout << "Enter value: "; cin >> num;
			if (addTail(l, num)){ cout << "added\n"; }

			goto next;
		}
		if (x > 2 && l->pHead != NULL){
			if (x == 3){
				system("cls");

				removeHead(l);
				goto next;
			}
			if (x == 4){
				system("cls");

				removeTail(l);
				goto next;
			}
			if (x == 5){
				system("cls");

				removeAll(l);
				goto next;
			}
			if (x == 6){
				system("cls");

				printList(l);

				goto next;
			}
			if (x == 7){
				system("cls");

				cout << "Number of elements in linked list is: " << countElements(l) << endl;

				goto next;
			}
			if (x == 8){
				system("cls");

				cout << "Before revers: ";
				printList(l);
				cout << "After reverse: ";
				list_reversed = reverseList(l);
				printList(list_reversed);

				goto next;
			}
			if (x == 9){
				system("cls");

				removeDuplicate(l);
				n--;
				goto next;
			}
			if (x == 10){
				system("cls");

				int k;
				cout << "Enter value of element you want to remove: "; cin >> k;
				cout << removeElement(l, k) << endl;
				goto next;
			}
		}
		else{
			system("cls");
			cout << "In order to manipulation linkedlist, you have to add head or add tail first!" << endl;
		}

	next:
		cout << "Press \"Enter\" to run other task!" << endl; getchar(); getchar();
		system("cls");

	} while (1);

}