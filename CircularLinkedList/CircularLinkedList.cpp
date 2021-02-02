#include "CircularLinkedList.h"
#include "ItemType.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include <exception>

using namespace std;

CircularLinkedList::CircularLinkedList(){
  head = NULL;
  length = 0;
}

void CircularLinkedList::insertItem(ItemType &item){
  NodeType *temp = new NodeType;
  temp -> data = item;
  if(length == 0){
    head = temp;
    temp -> next = head;
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
      if(length == 1){
        if(head -> data.compareTo(item) == LESS){
          head -> next = temp;
          temp -> next = head;
          head = temp;
          length++;
        }
        else{
          head -> next = temp;
          temp -> next = head;
          length++;
        }
      }
      else if(head -> data.compareTo(item) == LESS){
        temp -> next = head -> next;
        head -> next = temp;
        head = temp;
        length++;
      }
      else{
        NodeType *checker = head -> next;
        NodeType *preChecker = head;
        bool found = false;
        while(!found){
          if(checker -> data.compareTo(item) == LESS){
            preChecker = checker;
            checker = checker -> next;
          }
          else{
            found = true;
          }
        }
        temp -> next = checker;
        preChecker -> next = temp;
        length++;
      }
    }
    else{
      delete temp;
      cout << "Sorry. You cannot insert the duplicate item" << endl;
    }
  }
}

void CircularLinkedList::deleteItem(ItemType &item){
  if(length == 0){
    cout << "You cannot delete from an empty list" << endl;
  }
  else if(length == 1){
    delete head;
    length--;
  }
  else{
    bool itemFound = false;
    NodeType *checker = head -> next;
    NodeType *preChecker = head;
    for(int i = 0; i < length; i++){
      if(checker -> data.compareTo(item) == EQUAL){
        itemFound = true;
      }
      else{
        preChecker = checker;
        checker = checker -> next;
      }
    }
    
    if(itemFound){
      if(head -> data.compareTo(item) == EQUAL){
        item = checker -> data;
        preChecker -> next = checker -> next;
        head = preChecker;
        delete checker;
        length--;
      }
      else{
        item = checker -> data;
        preChecker -> next = checker -> next;
        delete checker;
        length--;
      }
    }
    else{
      cout << "Item not in list!" << endl;
    }
  }
}

int CircularLinkedList::lengthIs() const{
  return length;
}

void CircularLinkedList::print(){
  if(length != 0){
    NodeType *temp = head -> next;
    for(int i = 0; i < length; i++){
      temp -> data.print();
      cout << " ";
      temp = temp -> next;
    }
  }
  cout << endl;
}

CircularLinkedList::~CircularLinkedList(){
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
