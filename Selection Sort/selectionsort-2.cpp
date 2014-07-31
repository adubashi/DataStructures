#include <iostream>
using namespace std;

const int INPUT_SIZE = 10;

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

void selectionsort(int arr[], int length)
{
	int i, j, minIndex, temp;
	
	for(i = 0; i < length - 1; i++) {
		minIndex = i;
		for(j = i + 1; j < length; j++)
			  if(arr[j] < arr[minIndex]) {
			  	minIndex = j;
			  }
			  
			  if(minIndex != i) {
			  	swap(minIndex,i,arr);
			  }
			  
		
	}
	
	
	
}


int main() 
{
	
	int input[10] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input,10);
	cout << endl;
	selectionsort(input,10);
	cout << "Output: ";
	print(input,10);
}
