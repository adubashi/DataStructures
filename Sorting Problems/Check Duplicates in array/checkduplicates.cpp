#include <iostream>
#include <cmath>
#include <assert.h>
#include <algorithm>  
using namespace std;


/*
Checking for Duplicates: Two for loops -> O(n^2) performance  -- n(n-1)/2 = O(n^2)
O(1) space 


*/
bool CheckDuplicatesInArray(int arr[], int n)
{
	sort(arr, arr + 10); //Fancy pointer arithmetic to sort an array
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++)
				if(arr[i]== arr[j]){
					return true;
				}
	}
	
	return false;
}

/*
Checking for Duplicates: One for loop + one sort. = O(nlogn + n) = O(nlogn)
O(1) space 


*/

bool CheckDuplicatesSorted(int arr[], int n)
{
	sort(arr,arr + 10); //Fancy pointer arithmetic to sort an array
	for(int i = 0; i < n - 1; i++){
		if(arr[i]== arr[i+1]){
		   return true;
	    }
	}
	return false;
}
/*
Assuming that each candidate has a unique ID, and each element in the array represents a single vote
, figure out who wins the election-variation of duplicates problem, just keep track of the counter.
Time complexity = O(n^2) 
Space complexity = O(1)


*/

int checkWhoWinsElection(int arr[], int n)
{
	int i,j, counter = 0, maxCounter = 0, candidate;
	candidate = arr[0];
	for(i = 0; i < n; i++){
		candidate = arr[i];
		counter = 0;
		for(j = i + 1; j < n; j++){
			if(arr[i] == arr[j]){
			 counter++;
             }
		} 
		if(counter > maxCounter){
			maxCounter = counter;
			candidate = arr[i];
		}
	}
	return candidate;
	
}
/*
Assuming that each candidate has a unique ID, and each element in the array represents a single vote
, figure out who wins the election-variation of duplicates problem, just keep track of the counter.
Time complexity = O(nlogn) 
Space complexity = O(1)


*/

int checkWhoWinsElectionSorted(int arr[], int n)
{
	int i,j,currentCounter = 1, maxCounter = 1;
	int currentCandidate, maxCandidate;
	currentCandidate = arr[0];
	
	sort(arr, arr + n);
	
	for(i = 1; i <= n; i++){
		if(arr[i] == currentCandidate){
			 currentCounter++;
		} else {
			currentCandidate = arr[i];
			currentCounter = 1;
		}
		
		if(currentCounter > maxCounter){
			maxCounter = currentCounter;
		} else {
			maxCandidate = currentCandidate;
			maxCounter = currentCounter;
		}
		   
	}
	
	return maxCandidate;
	
}



int main()
{
	int input[10] = {1,2,3,4,5,6,7,8,9,10};
	//cout << CheckDuplicatesSorted(input,10) << endl;
	
	cout << checkWhoWinsElection(input, 10) << endl;
	
	
	
}

