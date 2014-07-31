

#include <iostream>
using namespace std;

const int INPUT_SIZE = 10;

void print(int* input)
{
	for ( int i = 0; i < INPUT_SIZE; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
}

void swap(int& i, int& j, int* input)
{
	int tmp = input[j];
	input[j] = input[i];
	input[i] = tmp;
}

///Finds the Max moves to the front 
void selectionsort(int* input)
{
	for (int i=INPUT_SIZE-1;i>0;i--)
	{
		int maxPos = 0;
		for (int j = 1; j <= i; j++) 
		{
		    if (input[maxPos] <  input[j])
		    {
   	  		    maxPos = j; 
		    }
		
		}
		
		/*
		int tmp = input[maxPos];
		input[maxPos] = input[i];
		input[i] = tmp;
		*/
		swap(i,maxPos,input);
		cout << "PASS: ";
        print(input);

		
	
		
	}
	
	
}
//Finds the minimum moving the minimum to the front of the List 
void selectionsort2(int* input){
	for (int i=0; i< INPUT_SIZE-1; i++)
	{
		int minPos = i;
		for (int j = i + 1 ; j <= INPUT_SIZE - 1; j++) 
		{
		    if (input[j] < input[minPos])
		    {
   	  		    minPos = j;
		    }
		
		}
		
		/*
		int tmp = input[maxPos];
		input[maxPos] = input[i];
		input[i] = tmp;
		*/
		swap(i,minPos,input);
		cout << "PASS: ";
        print(input);
	}
}

	

int main()
{
    int input[INPUT_SIZE] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input);
    selectionsort2(input);
    cout << "Output: ";
    print(input);
}
