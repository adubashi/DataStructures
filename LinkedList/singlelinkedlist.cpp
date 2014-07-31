//Simple Linked List Class



#include <iostream>
using namespace std;

class Node {
	public:
	   int data;
       Node* next;
		
	   Node() {
	   };
	   void SetData(int aData)
	   {
	   	 data = aData; 
	   }
	   void SetNext(Node* aNext)
	   {
	   	 next = aNext;
	   }
	   
	   int Data() { 
	   return data; 
	   }
	   
	   Node* Next(){
	   	 return next;
	   }
	    
};

class List {
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
	
		
		
};

void List::Print() {
	
	//Temporary Pointer 
	Node *tmp = head;
	
	//Empty List 
	if( tmp == NULL ) {
		cout << "EMPTY" << endl;
		return;
	}
	
	if(tmp->Next() == NULL) {
		cout << tmp->Data();
		cout << " --> ";
		cout << "NULL" << endl;
	} else {
		do{
		   cout << tmp->Data();
		   cout << " --> ";
		   tmp = tmp->Next();
		} 
		while( tmp != NULL);
		
		cout << "NULL" << endl;
	}
}
void List::Append(int data)
{
	//Create a new node
	Node* newNode = new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	
	//Create a temp pointer
	Node *tmp = head;
	
 	if ( tmp != NULL ) {
    // Nodes already present in the list
    // Parse to end of list
    while ( tmp->Next() != NULL ) {
        tmp = tmp->Next();
    }

    // Point the last node to the new node
    tmp->SetNext(newNode);
    } else {
    // First node in the list
    head = newNode;
    }	
}

void List::Delete(int data)
{
	Node *tmp = head;
	
	if( tmp == NULL)
	return;
	
	if( tmp->Next() == NULL ) {
		delete tmp;
		head = NULL;
	} else {
		Node *prev;
		do {
		   	 if( tmp->Data() == data ) break;
		 	 prev = tmp;
		 	 tmp = tmp->Next();
		} while( tmp != NULL);
	
	//Adjust the pointers
	prev->SetNext(tmp->Next());
	
	//Delete the current node
	delete tmp; 
		
	}
}
void List::delete_back(){
    Node *tmp = head;
	if(head != NULL){
            Node *end = head;
            Node *prev_end;
            while(end->next != NULL)
            {
                 prev_end = end;
                 end = end->next;
            }
            prev_end->next = 0;
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
	int countV = 0;
	Node *tmp = head;
	
	if(position <= 0){
		DeleteFront();
		return;
	}
	if(position >= count()){
		delete_back();
		return;
	}
	
	if( tmp == NULL)
	return;

	if( tmp->Next() == NULL) {
		delete tmp;
		head = NULL;
	} else {
		Node *prev;
		do {
		   	 if( countV == position ) break;
		 	 prev = tmp;
		 	 tmp = tmp->Next();
		 	 countV++;
		} while( tmp != NULL);
	
	//Adjust the pointers
	prev->SetNext(tmp->Next());
	
	//Delete the current node
	delete tmp; 
		
	}
}

void List::prepend(int data)
{
	
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
  if(head != NULL)
  {
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
      cout << " Position is out of bounds " << endl;
    else {
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
	Node* cur = head;
	int count = 0; 
	
	while(cur != NULL) {
		count++;
		cur = cur->Next();
	}
	return count;
}


int main()
{
	// New list
    List list;

    // Append nodes to the list
    list.Append(100);
   
    list.Print();
    list.Append(200);
    list.Print();
    list.Append(300);
    list.Print();
    list.Append(400);
    list.Print();
    list.Append(500);
    list.Print();
    cout << list.count() << endl;
    list.InsertInMiddle(3,0);
	list.InsertInMiddle(4,0);
	list.InsertInMiddle(5,7);
	list.Print();
	cout << list.count() << endl;
	
	
	
    //Delete nodes from the list 
    
    list.DeletePosition(1);
    list.Print();
    list.Delete(400);
    list.delete_back();
    list.Print();
    list.DeleteFront();
    list.Print();
    list.DeletePosition(-1); //Testing at a number less than count
    list.DeletePosition(5); //Testing at a number greater than count.
    list.Print();
 
    
}
