#include <iostream>

using namespace std;
const int INPUT_SIZE = 10;

void print(int* input,int length)
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

void insertionsort(int arr[], int length)
{
   int i, j, k;
   for(i = 1; i < length; i++){
   	   for(j = i; j > 0; j--){
   	   	   k = j - 1;
   	   	   if(arr[j -1 ] > arr[j]){
   	   	   	  swap(j,k,arr);
   	   	   } else {
   	   	   	  break;
   	   	   }
   	   }
   }
    
}

int main()
{
    int input[10] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input,10);
    insertionsort(input,10);
    cout << "Output: ";
    print(input,10);
    return 0;
}
