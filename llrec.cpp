#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {

  if( head == NULL ){ 
    smaller = NULL;  // end the linked lists
    larger = NULL;
    return;
  }

  Node* temp = head->next; 

  if( head->val > pivot ){ // current value is larger than pivot
    larger = head;
    llpivot(temp, smaller, larger->next, pivot);
  }
  else if( head->val <= pivot ){ // current value is smaller than or equal to pivot 
    smaller = head;
    llpivot(temp, smaller->next, larger, pivot);
  }  

  head = NULL;

}

