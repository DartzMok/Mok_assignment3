#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include "ItemType.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct NodeType{
  ItemType data;
  NodeType *next;
};

class CircularLinkedList{
 public:
  //Default constructor
  CircularLinkedList();

  //Destructor
  ~CircularLinkedList();

  //Inserts a non-duplicate item into the list
  void insertItem(ItemType &item);

  //Deletes an item that is in the list
  void deleteItem(ItemType &item);

  //Returns the length of the list
  int lengthIs() const;

  //Prints the list to standard output
  void print();
  
 private:
  int length;
  NodeType *head; 
};
#endif
