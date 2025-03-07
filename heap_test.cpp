#include <iostream>
#include "heap.h"

using namespace std;

int main(){
  Heap<int> min(2, less<int>()); // min heap; binary
  min.push(1);
  min.push(2);
  min.push(0);
  min.push(4);
  min.push(3);

  cout << "top should be 0: " << min.top() << endl;
  min.pop();
  cout << "top should be 1: " << min.top() << endl;
  min.pop();
  cout << "size should be 3: " << min.size() << endl;
  cout << "is heap empty? " << min.empty() << endl;

    Heap<int, greater<int>> max(2, greater<int>()); // max heap; binary
  max.push(1);
  max.push(2);
  max.push(4);
  max.push(3);

  cout << "top should be 4: " << max.top() << endl;
  max.pop();
  cout << "top should be 3: " << max.top() << endl;
  max.pop();
  cout << "size should be 2: " << max.size() << endl;
  max.pop();
  max.pop();
  cout << "is heap empty? " << max.empty() << endl;

  try {
    max.pop(); // should throw exception
  } 
  catch(underflow_error e){
    cout <<"Exception was thrown." << endl;
  }


  return 0;
}