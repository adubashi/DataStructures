#include "linkedlist.h"
#include <iostream>
#include <string>

using namespace std;

//simple Ordered Double, Circle Linked List, of numbers 

linkedlist::linkedlist(){

	listHead = new Node;
	listHead->next = listHead;
	listHead->prev = listHead;
}

linkedlist::~linkedlist(){
	cur = listHead->next;
	Node* temp;
	
	while(curr!=listHead){
		temp = cur->next;
		delete cur;
		cur=temp;
	}
}

void linkedlist::insert(int newItem){
	Node* temp = new Node;
	temp->item = newItem;
	
	curr = listHead -> next;
	
	while(curr != listHead && newItem > curr ->item)
			   curr = curr->next;
    
	temp->next = curr;
	temp->prev = curr->prev;
	curr->prev = temp;
	(n->prev)->next = temp;
}

void linkedlist::remove(int dataItem)
{
	curr = listHead->next;
	
	while(curr->item != dataItem)
          curr = curr->next;
          
    (curr->prev)->next = curr->next;
    (curr->next)->prev = curr->prev;
}

void linkedlist::print(){
	curr = listHead->next;
	
	do {
       cout << curr->item <<endl;
       curr = curr->next;
		
	}while( curr != listHead);
	
	cout << endl;
}
