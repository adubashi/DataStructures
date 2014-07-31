#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <string>
using namespace std;



class linkedlist{
	
	public:
	//Constructor
	linkedlist();
	
	//Destructor 
	~linkedlist();
	
	//Add Item 
	void insert(int newItem);
	
	//Remove Item
	void remove(int dataItem);
	
	//Add printing 
	void print();
	
	private:
			struct Node {
				int item;
				Node *next;
				Node *prev;
			};
			
			//Pointers for head(dummy node) and current 
			Node *listHead;
			Node *curr
};

#endif
















