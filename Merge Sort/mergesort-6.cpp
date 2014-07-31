#include <iostream>
#include <cmath>
using namespace std;

const int INPUT_SIZE = 10;


void print(int *input, int length)
{
    for ( int i = 0; i < length; i++ )
        cout << input[i] << " ";
    cout << endl;
}

void merge(int* input, int p, int r)
{
	int mid = floor((p+r)/2);
	int i1 = 0;
	int i2 = p; 
	int i3 = mid + 1;
	
	int temp[r-p+1];
	
	while( i2 <= mid && i3 <= r)
		   if( input[i2] <= input[i3])
		       temp[i1++] = input[i2++];
		   else
		   	   temp[i1++] = input[i3++];
		   	   
    while(i2 <= mid)
    		 temp[i1++] = input[i2++];
    		 
    while(i3 <= r)
    		 temp[i1++] = input[i3++];
    		 
    for(int i = p; i <= r; i++)
    		 input[i] = temp[i-p];
    
          	  	   
            
            
            
    
}

void merge_sort(int* input, int p, int r)
{
	if( p < r )
	{
	    int mid = floor((p+r)/2);
	    merge_sort(input, p, mid);
	    merge_sort(input, mid+1,r);
	    merge(input,p,r);
		
	}
 	 
    
}

int main()
{
    int input[INPUT_SIZE] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input, 10);
    merge_sort(input, 0, 9);
    cout << "Output: ";
    print(input, 10);
    return 0;
}
