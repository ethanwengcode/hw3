#include <iostream>
#include "stack.h"

using namespace std;

int main(){
  Stack<int> stack;

  cout << "Stack is empty? " << stack.empty() << endl;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  cout << "Stack's size is " << stack.size() << endl;
  stack.pop();
  int top = stack.top();
  cout << "Should be 2 "<< top << endl;

  stack.pop();
  stack.pop();
  
  cout << "Stack is empty? " << stack.empty()<<endl;

  try{
    stack.pop(); // should throw an exception
  }
  catch( underflow_error e) {
    cout << "Exception was thrown"<< endl;
  }

  return 0;
}