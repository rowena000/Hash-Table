/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
  // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number"
          << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*

  while (true) {
    cout << "cmd>" << endl;
    string cmd;
    cin >> cmd;
    if (cmd == "quit"){
      return 0;
    }
    else if (cmd == "size") {
      cout << grades->numEntries() << endl;
    }
    else if (cmd == "stats"){
      grades->hashStats ( cout );
    }
    else if (cmd == "help"){
      cout<<"insert name score: Insert this name and score in the grade table."<<endl;
      cout<<"change name score: Change the score for name"<<endl;
      cout<<"lookup name: Lookup the name, and print out his or her score."<<endl;
      cout<<"remove name: Remove this name."<<endl;
      cout<<"print: Prints out all names and scores in the table."<<endl;
      cout<<"size: Prints out the number of entries in the table."<<endl;
      cout<<"stats: Prints out statistics about the hash table at this point. "<<endl;
      cout<<"help: Prints out a brief command summary."<<endl;
      cout<<"quit: Exits the program."<<endl;
    }
    else if (cmd == "print") {
      grades->printAll();
    }
    else if (cmd == "insert"){
      string name;
      cin >> name;
      string strScore;
      cin >> strScore;
      bool suc = grades->insert(name, atoi(strScore.c_str()));
      if(suc == true){
        cout << "Insert succeeded." << endl;
      }
      else{
        cout << "Insert failed, name already presented." << endl;
      }
    }
    else if (cmd == "change"){
      string name;
      cin >> name;
      string strScore;
      cin >> strScore;
      int* valueAdd = grades->lookup(name); // valueAdd is the address of the value correspongding to name.
      if(valueAdd == NULL){
        cout << "No such name. Change failed." << endl;
      }else{
        *valueAdd = atoi(strScore.c_str()); // change the value.
        cout<<"Change succeeded. "<<endl;
      }
    }
    else if(cmd == "lookup"){
      string name;
      cin >> name;
      int *score = grades->lookup(name);
      if(score == NULL){
        cout << "No such name." << endl;
      } else {
        cout << name << "\'s score is "<< *score << endl;
      }
    }
    else if(cmd == "remove"){
      string name;
      cin >> name;
      bool suc = grades->remove(name);
      if(suc == true){
        cout << "Remove succeeded." << endl;
      }else{
        cout << "Remove failed, no such name." << endl;
      }
    }
  }

  return 0;
}
