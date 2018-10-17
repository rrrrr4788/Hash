#include<iostream>
#include <stdlib.h>
#include<algorithm>
#include<string>
using namespace std;


struct node {
	int value;
	node* next;
};
class list {
private:
	node * head, *tail, *lIst;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void insertEnd(int textToInsert);
	void firstNode(int textToInsert);
	bool isEmpty();
};


void modXchain(list* stuff,int size);
void modXopen(int* stuff,int size);
void midSXchain(list* stuff,int size);
void midSXopen(int* stuff,int size);