#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

class QueueOverFlowException
{
public:
   QueueOverFlowException()
   {
       cout << "Queue overflow" << endl;
   }
};

class QueueEmptyException
{
public:
   QueueEmptyException()
   {
       cout << "Queue empty" << endl;
   }
};


class ArrayQueue
{
	private:
	int data[MAX_SIZE];
    int front;
    int rear;
    
    public:
   	
   	ArrayQueue() {
   		front  = -1;
   		rear = -1;
   	}
   	
	   
    
	
	void Enqueue(int element); //Donr
   	int Dequeue(); //Done 
   	int Front();
   	int Size();
    bool isEmpty();
};

void ArrayQueue::Enqueue(int element)
{
	
	if (Size() == MAX_SIZE - 1 )
	   throw new QueueOverFlowException();

    data[rear] = element;
    
    rear = rear + 1; 
    rear = rear % MAX_SIZE;
   
    
}

int ArrayQueue::Dequeue()
{
	 if ( isEmpty() )
           throw new QueueEmptyException();

       int ret = data[front];

       // MOD is used so that front indicator
       // can wrap around
       
       front = front + 1;
       front = front % MAX_SIZE;
       

       return ret;  
}

int ArrayQueue::Front()
{
	if ( isEmpty() )
           throw new QueueEmptyException();
	
	return data[front];
}

int ArrayQueue::Size()
{
	return abs(front - rear);
}

bool ArrayQueue::isEmpty()
{
	bool empty = false;
	if (Size() == 0){
		empty = true;
	} else {
		empty = false;
	}
	
	return empty;

}



int main()
{
	 ArrayQueue q;
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
