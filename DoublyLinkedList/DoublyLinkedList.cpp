#include "DoublyLinkedList.h"
#include "ItemType.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include <exception>

using namespace std;

DoublyLinkedList::DoublyLinkedList(){
  head = NULL;
  tail = NULL;
  length = 0;
}

int DoublyLinkedList::lengthIs() const{
  return length;
}

void DoublyLinkedList::print(){
  if(length != 0){
    NodeType *temp = head;
    for(int i = 0; i < length; i++){
      temp -> data.print();
      cout << " ";
      temp = temp -> next;
    }
  }
  cout << endl;
}

void DoublyLinkedList::printReverse(){
  NodeType *temp = tail;
  for(int i = 0; i < length; i++){
    temp -> data.print();
    cout << " ";
    temp = temp -> back;
  }
  cout << endl;
}

void DoublyLinkedList::insertItem(ItemType &item){
  NodeType *temp = new NodeType;
  temp -> data = item;
  if(length == 0){
    head = temp;
    tail = temp;
    length++;
  }
  else{
    NodeType *dupl = head;
    bool duplicate = false;
    for(int i = 0; i < length; i++){
      if(dupl -> data.compareTo(item) == EQUAL){
        duplicate = true;
      }
      dupl = dupl -> next;
    }
    if(!duplicate){
      if(head -> data.compareTo(item) == GREATER){
        temp -> next = head;
        head -> back = temp;
        head = temp;
        length++;
      }
      else if(tail -> data.compareTo(item) == LESS){
        temp -> back = tail;
        tail -> next = temp;
        tail = temp;
        length++;
      }
      else{
        NodeType *checker = head;
        bool found = false;
        while(!found){
          if(checker -> data.compareTo(item) == LESS){
            checker = checker -> next;
          }
          else{
            found = true;
          }
        }
        temp -> back = checker -> back;
        temp -> next = checker;
        checker -> back -> next = temp;
        checker -> back = temp;
        length++;
      }
    }
    else{
      delete temp;
      cout << "Sorry. You cannot insert a duplicate item" << endl;
    }
  }
}

void DoublyLinkedList::deleteItem(ItemType &item){
  if(length == 0){
    cout << "Sorry you cannot delete from an empty list" << endl;
  }
  else if(length == 1){
    delete head;
    head = NULL;
    tail = NULL;
    length--;
  }
  else{
    bool itemFound = false;
    NodeType *checker = head;
    for(int i = 0; i < length; i++){
      if(checker -> data.compareTo(item) == EQUAL){
        itemFound = true;
      }
      else{
        checker = checker -> next;
      }
    }

    if(itemFound){
      if(head -> data.compareTo(item) == EQUAL){
        item = head -> data;
        head = head -> next;
        delete checker;
        length--;
      }
      else if(tail -> data.compareTo(item) == EQUAL){
        item = tail -> data;
        tail = tail -> back;
        delete checker;
        length--;
      }
      else{
        item = checker -> data;
        checker -> back -> next = checker -> next;
        checker -> next -> back = checker -> back;
        delete checker;
        length--;
      }
    }
    else{
      cout << "Item not in list!" << endl;
    }
  }
}

DoublyLinkedList::~DoublyLinkedList(){
  if(length != 0){
    NodeType *temp = NULL;
    for(int i = 0; i < length; i++){
      temp = head;
      head = head -> next;
      delete temp;
    }
  }
  length = 0;
}
