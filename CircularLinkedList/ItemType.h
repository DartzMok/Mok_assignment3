#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//Enumeration used in the compare methods
enum Comparision{LESS, EQUAL, GREATER};

class ItemType{
 public:
  //Default constructor
  ItemType();

  //Compares two items of class ItemType and
  //returns the corresponding enumeration
  Comparision compareTo(ItemType item);

  //Returns the value instance variable
  int getValue() const;

  //Initializes the data member by variable num
  void initialize(int num);

  //Prints the value
  void print();

 private:
  //Value held in an itemtype
  int value;
};
#endif
