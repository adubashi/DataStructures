#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
 
bool balancedExpression(char *); // Function prototype
 
int main()
{
  const int SIZE = 1000;
  char mathexpression[SIZE];
 
  cout << "Enter a mathematical expression. If you choose "
       << "to use parentheses, only use (), {}, and []: ";
  cin.getline(mathexpression, SIZE);
 
  if (balancedExpression(mathexpression))
    cout << "\n\nExpression is balanced.\n\n";
  else
    cout << "\n\nError. Expression is not balanced.\n\n";
  return 0;
}
 
bool balancedExpression(char *strPtr)
{
  stack<char> balanceStack;
  char leftpar = '(';
  char leftsquarebrack = '[';
  char leftcurlybrack = '{';
  char rightpar = ')';
  char rightsquarebrack = ']';
  char rightcurlybrack = '}';
  
  while (*strPtr != '\0')
  {
    if ( *strPtr == leftpar || *strPtr == leftsquarebrack ||
    *strPtr == leftcurlybrack )
      balanceStack.push(*strPtr);
    else if ( *strPtr == rightpar )
    {
      if (balanceStack.empty() || balanceStack.top() != leftpar)
        return false;
      balanceStack.pop();
    }
    else if ( *strPtr == rightsquarebrack )
    {
      if (balanceStack.empty() || balanceStack.top() != leftsquarebrack)
        return false;
      balanceStack.pop();
    }
    else if ( *strPtr == rightcurlybrack )
    {
      if (balanceStack.empty() || balanceStack.top() != leftcurlybrack)
        return false;
      balanceStack.pop();
    }
  strPtr++;
  }
  
  if (!balanceStack.empty())
    return false;
  return true;
}
