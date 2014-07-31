//Simple Linked List Class -- Using a Node Struct



#include <iostream>
using namespace std;

struct Node {
	int data;
    Node* next;
};

class List {
	private:
	Node *head;
	
	
	public:
		List() {
			head = NULL;
		}
		
		void Print();
		void Append(int data);
		void Delete(int data);
		int  count();
		void InsertInMiddle(int data, int position);
		void prepend(int data);
		void DeletePosition(int position);
		void delete_back();
		void DeleteFront();
		int getNth(int n);
		int Pop();
		int RemoveDup();
		void reversedLinkedList();
		struct Node *searchNode(int n);
		void insertSortedNode(int n);
		void insertSortedNode2(int n);
		
		
		
		
};

void List::Print() {
	
	//Temporary Pointer 
	Node *tmp = head;
	
	//Empty List 
	if( tmp == NULL ) {
		cout << "EMPTY" << endl;
		return;
	}
	
	if(tmp->next == NULL) {
		cout << tmp->data;
		cout << " --> ";
		cout << "NULL" << endl;
	} else {
		do{
		   cout << tmp->data;
		   cout << " --> ";
		   tmp = tmp->next;
		} 
		while( tmp != NULL);
		
		cout << "NULL" << endl;
	}
}

void List::Append(int data)
{
	//Create a new node
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	
	//Create a temp pointer
	Node *tmp = head;
	
 	if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
       		 while ( tmp->next != NULL ) {
        	 	   	 tmp = tmp->next;
	 	      }
    // Point the last node to the new node
       		 tmp->next = newNode;
    } else {
      	   	 // First node in the list
 		     head = newNode;
    }	
}

void List::prepend(int data)
{
	//Creates new node, sets it's link to the head, sets head equal to the new node
	Node* tmp = new Node();
    tmp -> data = data;
    tmp -> next = head;
    head = tmp;	
}

void List::InsertInMiddle(int data, int pos)
{
	Node* prev = new Node();
  	Node* curr = new Node();
  	Node* newNode = new Node();
  	newNode->data = data;
  	
  	int tempPos = 0;   // Traverses through the list
  	curr = head;      // Initialize current to head;
  	
  	if(head != NULL) {
  		
  		while(curr->next != NULL && tempPos != pos)
    	{
            prev = curr;
            curr = curr->next;
            tempPos++;
    	}
    	if(pos==0)
    	{
 		     cout << "Adding at Front! " << endl;
		     prepend(data);
       
        }
    	else if(curr->next == NULL && pos == tempPos + 1)
        {
             cout << "Adding at End! " << endl;
             Append(data);
        }
        else if(pos > tempPos+1)
        {
        	cout << " Position is out of bounds " << endl;
        
		}
	 	else
	    {
        prev->next = newNode;
        newNode->next = curr;
        cout << "Node added at position: " << pos << endl;
        }	 
  		
  	} else {
       head = newNode;
       newNode->next=NULL;
       cout << "Added at head as list is empty! " << endl;
 	}
}

int List::count()
{
	int count = 0; 
	Node* curr = head;
	while(curr != NULL){
		  count = count + 1;
		  curr = curr -> next;
	}
	
	return count;
}

void List::delete_back(){
    
	if(head != NULL){
            Node *end = head;
            Node *prev_end;
            while(end->next != NULL)
            {
                 prev_end = end;
                 end = end->next;
            }
            prev_end->next = NULL;
            delete end;
    }
}

void List::DeleteFront(){
	Node* tmp = head;
	if (head == NULL) {
          return;
    } else {
        head = head -> next;
        
    }
        
}

void List::DeletePosition(int position)
{
	int tempPos = 0;
	Node *tmp = head;
	
	if(position <= 0){
		DeleteFront();
		return;
	}
	if(position >= count()){
		delete_back();
		return;
	}
	if( tmp == NULL) return;
	
	if( tmp->next == NULL) {
		delete tmp;
		head = NULL;
	} else {
		Node *prev;
		do {
		   	 if( tempPos == position ){
		   	  	 break;
		     }
		 	 prev = tmp;
		 	 tmp = tmp->next;
		 	 tempPos++;
		} while( tmp != NULL);
	
	//Adjust the pointers
	prev -> next = tmp -> next;
	//Delete the current node
	delete tmp; 
		
	}
}

void List::Delete(int data)
{
	Node *tmp = head;
	
	if( tmp == NULL)  return;
	
	if( tmp->next == NULL ) {
		delete tmp;
		head = NULL;
	} else {
		Node *prev;
		do {
		   	 if( tmp->data == data ) break;
		 	 prev = tmp;
		 	 tmp = tmp->next;
		} while( tmp != NULL);
	
	//Adjust the pointers
	prev -> next = tmp -> next;
	
	//Delete the current node
	delete tmp; 
		
	}
}

//Enter in a number from  0 to Count()-1, 
int List::getNth(int n)
{
    Node *tmp = head;
    int nth = count();
    int i = 0;
	
	//Empty List 
	if( tmp == NULL ) {
		cout << "EMPTY" << endl;
		return 0;
	}
	
	if(tmp->next == NULL) {
		cout << tmp->data;
		cout << " --> ";
		cout << "NULL" << endl;
		return 0;
	} else {
		do{
		   if(n == i){
		   	  return tmp->data;
		   }
		   tmp = tmp->next;
		   i++;
		} 
		while( tmp != NULL &&  i < nth );
		
		
	}
	
}

int List::Pop()
{
	int n = 0;
	Node* tmp = head;
	if (head == NULL) {
          return n;
    } else {
    	n = head -> data;
        head = head -> next;
        
    }
    
    return n;
	
}

int List::RemoveDup()
{
    Node *current;
    Node *previous;
    Node *runner;
    Node *tmp;

    if(head == NULL) return 0;
    if(head->next == NULL) return 1;

    current = head->next;
    previous = head;

    while(current != NULL){

        runner = head;

        while(runner != current){
            // remove node if equal
            if(runner->data == current->data){
                tmp = current;
                current = current->next;
                previous->next = current;
                delete tmp;
                break;
            }

            runner = runner->next;
        }

        if(runner == current){
            current = current->next;
            previous = previous->next;
        }
    }
}

void List::reversedLinkedList()
{
    if(head == NULL) return;

    Node *prev = NULL, *current = NULL, *next = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // now let the head point at the last node (prev)
    head = prev;
}

struct Node* List::searchNode(int n)
{
	if(head == NULL) return head;
	Node *cur = head;
	Node *prev = head;
	while(cur) {
		if(cur->data == n) return cur;
		if(cur->data > n) return prev;
		prev = cur;
		cur = cur->next;
	}
}

//Inserts a Node in sorted List, does not use search function 
void List::insertSortedNode(int n) {
    Node *ptr;
    
    Node *cur = head;
	Node *prev = head;
	while(cur) {
		if(cur->data == n){
			ptr =  cur;
		    break; 
		} 
		   
		if(cur->data > n){
		    ptr = prev;
		    break;
		} 
		prev = cur;
		cur = cur->next;
	}
    

	Node *newNode = new Node;
	newNode->data = n;
	Node *current = head;
	while(current) {
		if(current == ptr ) {
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}
}
//Inserts A node in a sorted list, does use search function
void List::insertSortedNode2(int n)
{
	Node *ptr = searchNode(n);
	Node *newNode = new Node;
	newNode->data = n;
	Node *cur = head;
	while(cur) {
		if(cur == ptr ) {
			newNode->next = cur->next;
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
	
	
	
	
	
	
	
}



int main()
{
	List list;
	list.Append(4);
	list.Append(5);
	list.Append(7);
	list.InsertInMiddle(3,0);
	list.InsertInMiddle(6,3);
	
	list.Print();
	cout << list.count() << endl;
	list.delete_back();
	list.DeletePosition(2);
	list.Print();
	list.Delete(4);
	list.Print();
	cout<< " " << endl;
	List list2;
	list2.prepend(2);
	list2.prepend(3);
	list2.prepend(4);
	list2.prepend(5);
	list2.prepend(6);
	list2.Print();
	cout << list2.getNth(2) << endl; 
	cout << " " << endl;
	
	list2.Pop();
	list2.Print();
	
	cout << " " << endl;
	
	List list3;
	list3.prepend(1);
	list3.prepend(1);
	list3.prepend(2);
	list3.prepend(2);
	list3.prepend(3);
	list3.prepend(3);
	list3.Print();
	list3.RemoveDup();
	list3.Print();
	cout<< " " << endl;
	list3.reversedLinkedList();
	list3.Print();
	
	List list4;
	list4.prepend(6);
	list4.prepend(5);
	list4.prepend(4);
	list4.prepend(2);
	list4.prepend(1);
	list4.prepend(0);
	list4.Print();
	list4.insertSortedNode(3);
	list4.Print();
	
	
	
 
    
}
