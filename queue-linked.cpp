#include <iostream>
using namespace std;

class QueueEmptyException
{
public:
   QueueEmptyException()
   {
       cout << "Queue empty" << endl;
   }
};

class Node
{
public:
   int data;
   Node* next;
};

class ListQueue
{  
private:
   Node* front;
   Node* rear;
   int count;

public:
   ListQueue()
   {
       front = NULL;
       rear = NULL;
       count = 0;
   }      
   
   /*Inserting an element at the end of a list */
   
   void Enqueue(int element)
   {
   	Node *tmp = new Node();
   	tmp->data = element;
   	tmp->next = NULL;
   	
   	if (isEmpty()) {
   		front = rear = tmp;
   	} else {
 	   rear->next = tmp;
	   rear = tmp;	
   		
   	}
   	
   	count = count + 1;
   }
   
   /*Deleting an element at beginning of a list*/
   int Dequeue()
   {
   	 if (isEmpty())
   	 	throw new QueueEmptyException();
			// Set ret as the number to be returned 
			// Set tmp as the new front node 
     int ret = front->data;
     Node* tmp = front;
     
     //Move the front pointer to the next node
     front = front->next;
     
     
     count = count - 1;
     
     //Delete that node 
     delete tmp;
     return ret; 
     
     
   }
   
   int Front()
   {
   	 if ( isEmpty() )
           throw new QueueEmptyException();
     return front->data;
   }
   
   int Size()
   {
       return count;
   }
   
   bool isEmpty()
   {
   	 if (count == 0) {
   	 	return true;
   	 } else {
   	 	return false;
   	 }
   }
   
};

int main()
{
	ListQueue q;
   try {
       if ( q.isEmpty() )
       {
           cout << "Queue is empty" << endl;
       }

       // Enqueue elements
       q.Enqueue(100);
       q.Enqueue(200);
       q.Enqueue(300);

       // Size of queue
       cout << "Size of queue = " << q.Size() << endl;

       // Front element
       cout << q.Front() << endl;

       // Dequeue elements
       cout << q.Dequeue() << endl;
       cout << q.Dequeue() << endl;
       cout << q.Dequeue() << endl;
   }
   catch (...) {
       cout << "Some exception occured" << endl;
   }
}
