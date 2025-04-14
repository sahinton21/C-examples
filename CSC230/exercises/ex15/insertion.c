// Code to read numbers from standard input inserting them into a list
// in sorted order as we read them.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for building our linked list.
struct NodeStruct {
  // Value in this node.
  int value;

  // Pointer to the next node.
  struct NodeStruct *next;
};

// A short type name to use for a node.
typedef struct NodeStruct Node;

/*
  Create a node for the given value and insert it into the given list
  in the proper location to keep the list sorted.  Return an updated
  head pointer.  The head should only need to change if this value gets
  inserted at the front of the list.  Otherwise, you can just return
  the old head pointer.
*/
Node *insert( Node *head, int val )
{
  //Special case where insertion goes before the head

  if(head == NULL || val < head->value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    // {.value = val, .next = current.next};
    newNode->next = head;
    newNode->value = val;
    
    return newNode;
  }
  Node *current = head;
  
  
  //Peak ahead to check where to insert
  while(current->next != NULL && current->next->value < val){
    current = current->next;
  }
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->next = current->next;
  newNode->value = val;
  current->next = newNode;
  return head;
}

int main()
{
  // Pointer to the head node.
  Node *head = NULL;

  // Read a list of numbers from building a sorted list as we
  // read them.
  int x;
  while ( scanf( "%d", &x ) == 1 ){
    // Insert the new value, and get back the (possibly updated) head pointer.
    head = insert( head, x );
  }

  // Print out the list.
  Node *current = head;
  while(current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
  
  // Free all the nodes.
  current = head;
  while(head != NULL){
    Node *next = head->next;
    free(head);
    head = next;
  }
  
  return 0;
}
