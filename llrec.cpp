#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {

  if( head == NULL ){
    return;
  }

  Node* temp = head->next; 

  if( head->val > pivot ){
    head->next = larger;
    larger = head;
  }
  else if( head->val <= pivot ){
    head->next = smaller;
    smaller = head;
  }  

  head = NULL;
  llpivot(temp, smaller, larger, pivot);

}

