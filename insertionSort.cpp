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

void insertionsort(int* input)
{
    for (int i=1;i<INPUT_SIZE;i++)
    {
        for (int j=i;j>0;j--)
        {
            if (input[j]<input[j-1])
            {
                int k = j - 1;
                
                
                
                
                
                
				/*
				int tmp = input[j];
                input[j] = input[j-1];
                input[j-1] = tmp;
                */
                swap(j,k,input);
            } else
                break;
        }
        cout << "PASS: ";
        print(input);
    }
}

int main()
{
    int input[INPUT_SIZE] = {500, 700, 800, 100, 300, 200, 900, 400, 1000, 600};
    cout << "Input: ";
    print(input);
    insertionsort(input);
    cout << "Output: ";
    print(input);
    return 0;
}

