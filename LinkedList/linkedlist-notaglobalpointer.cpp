#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void createList(struct Node *head,int n){
	head -> data = n;
	head -> next = NULL;
}

bool addNode(struct Node *head, int n){
	 Node *newNode = new Node;
	 newNode -> data = n;
	 newNode -> next = NULL;
	 
	 Node *current = head;
	 
	 while(current != NULL){
	 	
          if(current -> next == NULL){
          	current->next = newNode;
          	return true;
          		
          } else {
          	return false;
          }
          current = current -> next;
	 	   
	 }
}

void display(struct Node *head){
	Node *current = head;
	while(current != NULL) {
		 cout << current->data << endl;
		 current = current->next;
	}
	cout << endl;
}

void insertFront(struct Node **head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

bool deleteNode(struct Node **head, Node *ptrDel){
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
	
}

struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
	}
	cout << "No Node " << n << " in list.\n";
}

void deleteLinkedList(struct Node **node)
{
	struct Node *tmpNode;
	while(*node) {
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}

struct Node* reverse(struct Node** head) 
{
	Node *parent = *head;
	Node *me = parent->next;
	Node *child = me->next;

	/* make parent as tail */
	parent->next = NULL;
	while(child) {
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}


int main() {
	struct Node *newHead;
	struct Node *head = new Node;
	
	createList(head,10);
	display(head);

	addNode(head,20);
	display(head);

	addNode(head,30);
	display(head);

	addNode(head,35);
	display(head);

	addNode(head,40);
	display(head);

	insertFront(&head,5);
	display(head);

	int numDel = 10;
	Node *ptrDelete = searchNode(head,numDel);
	if(deleteNode(&head,ptrDelete)) 
		cout << "Node with value: "<< numDel << " deleted!\n";
	display(head);
	
	cout << "The list is reversed\n";
	reverse(&head);
	display(head);
}
