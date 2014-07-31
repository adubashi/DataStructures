
#include <iostream>
#include <stack>
#include <queue>
#include <string>


using namespace std;

//Simple Is Palindrome
bool isPalindrome(string s)
{
	int i = 0, j = s.length() - 1;
	
	while(i < j && s[i] == s[j]){
			i++;
			j--;
	}
	if(i<j) {
		return false; 
	} else {
		return true;
	}
}

bool isPalindromeStack() {
	
  	queue<char> q;
    stack<char> s;
    string the_string;
    int mismatches = 0;

    cout << "Enter a line and I will see if it's a palindrome:" << endl;
    int i = 0;

    while (cin.peek() != '\n')
    {
        cin >> the_string[i];
        if (isalpha(the_string[i]))
        {
            q.push(toupper(the_string[i]));
            s.push(toupper(the_string[i]));
        }
    i++;
    }

    while ((!q.empty()) && (!s.empty()))
    {
        if (q.front() != s.top())
            ++mismatches;
            if(mismatches > 0){
            	return false;
            }
            

        q.pop();
        s.pop();
    }

if (mismatches == 0)
    //cout << "This is a palindrome" << endl;
    return true;
else
    //cout << "This is not a palindrome" << endl;
    return false;

   
}


int main(){
	cout << isPalindromeStack() << endl;
	
	
}
