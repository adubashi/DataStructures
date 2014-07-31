#include <iostream>
#include <cmath>
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

void bubbleSort(int arr[], int n) {
      bool swapped = true;
      int j = 0;
      while(swapped){
      	swapped = false;
      	j++;
      	for(int i = 0; i < n - j; i++ )
      	    if(arr[i] > arr[i+1]){
      	    	int k = i + 1;
      	    	swap(i,k,arr);
      	    	swapped = true;
      	    }
      }
     
} 


int main()
{
    int input[INPUT_SIZE] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input);
    bubbleSort(input, 10);
    cout << "Output: ";
    print(input);
    return 0;
}
