#include <iostream>
#include <cmath>
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

int partition(int* input, int p, int r)
{
	int j = floor((p+r)/2);
	
	int pivot = input[j];
	
	while( p < r)
	{
		while(input[p] < pivot)
              p++;
        while(input[r] > pivot)
              r--;
        if(input[p] == input[r])
	   	      p++;
        else if(p < r )
        {
        	swap(p,r,input);
        }
	}
    
    return r;
}

void quicksort(int* input, int p, int r)
{
	if ( p < r )
    {
        int j = partition(input, p, r);        
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

int main()
{
    int input[INPUT_SIZE] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input,10);
    quicksort(input, 0, 9);
    cout << "Output: ";
    print(input,10);
    return 0;
}
