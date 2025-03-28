/*// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include "DynamicArray.h"

int main()
{
  // Programmer's Identification
  cout << "Programmer Name (Last, First): Frediani-Jost, Cheyenne\n";
  cout << "Programmer's ID: 1429200\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  // Initialize static arrays
  DynamicArray<double> a; // Value Tracker
  DynamicArray<double> b; // Used Index Tracker
  int used = 0; // number of used indexes
  
  // Get number pair inputs
  string buf1, buf2; // input buffers for index and value variables
  cout << "Input an index and a value [Q to quit]: ";
  cin >> buf1;
  while (buf1 != "Q" && buf1 != "q")
  {
    int index = atof(buf1.c_str());
    cin >> buf2;
    double value = atof(buf2.c_str());
    a[index] = value;  // assign value
    b[index] = 1;      // keep track of the used index
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buf1;
  }
  
  // tally total number of pairs and output it
  for (int i = 0; i < b.capacity(); i++)
  {if(b[i] == 1) used++;}
  cout << "\nYou stored this many values: " << used << endl;
  
  // output the ordered pairs
  cout << "The index - value pairs are: \n\n";
  for (int i = 0; i < b.capacity(); i++)
  {if(b[i] == 1) cout << i << " => " << a[i] << endl;}
  cout << endl;
  
  // Lookup values by index
  cout << "Input an index to look up [Q to quit]: ";
  cin >> buf1;
  while (buf1 != "Q" && buf1 != "q")
  {
    int index = atoi(buf1.c_str());
    if (b[index] == 1 && index < b.capacity() && index > 0)
      cout << "Found - the value stored at index " << index << " is " << a[index] << endl;
    else
      cout << "Not found." << endl;
    cout << "Input an index to look up [Q to quit]: ";
    cin >> buf1;
  }
}
*/
