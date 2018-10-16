#include<iostream>
#include <stdlib.h>
#include<algorithm>
#include<string>
using namespace std;


struct node {
	int value;
	node* head;
};

void modXchain(node* stuff,int size);
void modXopen(int* stuff,int size);
void midSXchain(node* stuff,int size);
void midSXopen(int* stuff,int size);