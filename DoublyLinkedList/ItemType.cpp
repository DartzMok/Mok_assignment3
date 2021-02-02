#include <string>
#include <iostream>
#include <stdlib.h>
#include "ItemType.h"

using namespace std;

ItemType::ItemType(){
}

int ItemType::getValue() const{
  return value;
}

void ItemType::initialize(int num){
  value = num;
}

void ItemType::print(){
  cout << getValue();
}

Comparision ItemType::compareTo(ItemType item){
  if(getValue() < item.getValue()){
    return LESS;
  }
  else if(getValue() > item.getValue()){
    return GREATER;
  }
  else{
    return EQUAL;
  }
}
