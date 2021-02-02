#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "ItemType.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct NodeType{
  ItemType data;
  NodeType *next;
  NodeType *back;
};

class DoublyLinkedList{
 public:
  //Default constructor
  DoublyLinkedList();

  //Destructor
  ~DoublyLinkedList();

  //Inserts a non-duplicate item into the list
  void insertItem(ItemType &item);

  //Deletes an item that is in the list
  void deleteItem(ItemType &item);

  //Returns the length of the list
  int lengthIs() const;

  //Prints the list to standard output
  void print();

  //Prints the list in reverse to standard output
  void printReverse();

 private:
  int length;
  NodeType *head;
  NodeType *tail;
};
#endif
