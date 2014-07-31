#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

void print(int* input, int length)
{
	for ( int i = 0; i < length; i++) {
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



void shiftRight(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
    	int leftChild = (root * 2) + 1;
    	int rightChild = leftChild + 1;
    	int swapIdx = root;
    	
    	//Check if the root is less than the left child
    	if( arr[swapIdx] <= arr[leftChild])
    	{
    		swapIdx = leftChild;
    	}
    	
    	//If the right child exists check if it is less than the current root 
    	if( (rightChild <= high ) && (arr[swapIdx] < arr[rightChild]))
        {
        	swapIdx = rightChild;
        }
        
        if(swapIdx != root)
        {
        	int temp = arr[root];
        	arr[root] = arr[swapIdx];
        	arr[swapIdx] = temp;
        	
        	root = swapIdx;
        }
        else 
        {
        	break;
        }
    	
    	
    	
    	
    	
    }
}
void heapify(int* arr, int low, int high)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIndex = (high - low - 1)/2;
    while(midIndex >= 0)
    {
    	shiftRight(arr,midIndex,high);
    	--midIndex;
    }
    
}
void heapSort(int* arr, int size)
{
    
    /*This will put max element in the index 0*/
    heapify(arr,0,size - 1);
    int high = size - 1;
    
    while(high > 0)
    {
    	int temp = arr[high];
    	arr[high] = arr[0];
    	arr[0] = temp;
    	--high;
    	
    	shiftRight(arr,0,high);
    }
}

int main()
{
	int input[10] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input,10);
    heapSort(input, 10);
    cout << "Output: ";
    print(input,10);
    return 0;
}
