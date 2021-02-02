#include "ItemType.h"
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){
  DoublyLinkedList list;
  ItemType item, item1, item2, item3;
  int input;
  fstream fs;
  fs.open(argv[1], fstream::in);
  if(fs.is_open()){
    fs >> input;
    while(!fs.eof()){
      item.initialize(input);
      list.insertItem(item);
      fs >> input;
    }
  }
  else{
    cout << "Failed to open the input file" << endl;
    return 0;
  }

  bool isRunning = true;
  int intInput;
  char charInput;

  while(isRunning){
    cout << "insert (i), delete (d), length (l), print (p), printReverse(r), quit (q)" << endl;
    cout << "Enter a command: ";
    cin >> charInput;
    cin.clear(); fflush(stdin);
    if(charInput == 'p'){
      list.print();
      cout << endl;
    }
    else if(charInput == 'r'){
      list.printReverse();
      cout << endl;
    }
    else if(charInput == 'l'){
      cout << "The length is: " << list.lengthIs() << endl;
    }
    else if(charInput == 'i'){
      cout << "Number to insert: ";
      cin >> intInput;
      cin.clear(); fflush(stdin);
      item.initialize(intInput);
      list.insertItem(item);
      list.print();
      cout << endl;
    }
    else if(charInput == 'd'){
      cout << "Number to delete: ";
      cin >> intInput;
      cin.clear(); fflush(stdin);
      item.initialize(intInput);
      list.deleteItem(item);
      list.print();
      cout << endl;
    }
    else if(charInput == 'q'){
      cout << "Quitting program..." << endl;
      isRunning = false;
    }
    else{
     cout << "Invalid input. Try again" << endl;
    }
  }
}
