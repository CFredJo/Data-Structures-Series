 // Programmer: Cheyenne Frediani-Jost
 // Programmer ID: 1429200
 
 #include <iostream>
 #include <string>
 using namespace std;
 
 #include "AssociativeArray.h"
 #include "AssociativeArray.h" //ifndef test
 #include <queue>
 
 int main()
 {
 // Programmer's Identification
 cout << "Programmer Name (Last, First): Frediani-Jost, Cheyenne\n";
 cout << "Programmer's ID: 1429200\n";
 cout << "File: " << __FILE__ << endl << endl;
 
 //---------------------------------------------------------------------------------------
 // Int Tests
 //---------------------------------------------------------------------------------------
 cout << "------------- Associative Array Int, Int Testing -------------\n\n";
 
 // Initialize object a
 AssociativeArray<int, int> a;
 
 // Testing Size()--------------------------------------------------------------------------
 cout << "Testing Size\n";
 cout << "Expected: 0\n";
 cout << "Actual: " << a.size() << endl;
 assert(a.size() == 0);  // Closes program if false
 cout << "Pass!\n\n";
 
 // Testing square bracket getter/setter----------------------------------------------------
 cout << "Testing Square Bracket Getter/Setter\n";
 a[1] = 9251234;
 a[2] = 9257654;
 a[3] = 9259876;
 cout << "a[1]'s number: " << a[1] << endl;
 cout << "a[2]'s number: " << a[2] << endl;
 cout << "Pass!\n\n";
 
 // Testing Clear()-------------------------------------------------------------------------
 cout << "Testing clear()\n";
 a.clear();
 cout << "Size is now " << a.size() << endl;
 cout << "Pass!\n\n";
 
 // Testing Contains Key()------------------------------------------------------------------
 cout << "Testing containsKey()\n";
 a[1] = 213465;
 assert (a.containsKey(1) == true);
 assert (a.containsKey(5) == false);
 cout << "Pass!\n\n";
 
 // Testing deleteKey()---------------------------------------------------------------------
 cout << "Testing deleteKey()\n";
 a.deleteKey(1);
 assert (a.containsKey(1) == false);
 cout << "Pass!\n\n";
 
 // Testing keys()--------------------------------------------------------------------------
 cout << "Testing keys()\n";
 a[1] = 768940;
 a[6] = 976313;
 queue<int> currentKeys = a.keys();
 cout << "In use Keys: ";
 for (int i = 0; i < a.size(); i++)
 {
 cout << currentKeys.front();
 if (i != a.size() - 1)
 cout << ", ";
 currentKeys.pop();
 }
 cout << endl;
 cout << "Pass!\n\n";
 
 // Const Object Testing--------------------------------------------------------------------
 cout << "Const Object Testing\n";
 const AssociativeArray<int, int> b; // Main constructor exists if this compiles
 assert(b.size() == 0); // if this compiles, is a getter with trailing const
 cout << "Pass!\n\n";
 
 // Object Copy Testing---------------------------------------------------------------------
 cout << "Object Copy Test\n";
 //Clear and reassign contents to first array
 a.clear();
 a[0] = 9251234;
 a[1] = 9257654;
 a[2] = 9259876;
 AssociativeArray<int, int> c = a; // Make a copy
 assert(a.size() == c.size()); // Check for same size
 for (int i = 0; i < c.size(); i++)  // Check for same contents
 {
 assert(a[i] == c[i]);
 }
 
 // change the content in the original array to verify it's not a shallow copy
 a.clear(); // clear a, reset as different values
 a[0] = 4150987;
 a[1] = 4151234;
 a[2] = 4150001;
 
 cout << "(Should be different)\n";
 for (int i = 0; i < a.size(); i++)   // Test for match
 {
 cout << "a[" << i << "]: " << a[i] << endl;
 cout << "c[" << i << "]: " << c[i] << endl;
 assert(a[i] != c[i]);
 }
 cout << "Pass!\n\n";
 
 // Object Assignment Testing---------------------------------------------------------------
 cout << "Object Assignment Test\n";
 AssociativeArray<int, int> c3; // Initialize new object
 c3 = a; // copy
 assert(a.size() == c3.size()); // Check for same size
 
 cout << "(Should be the same)\n";
 for (int i = 0; i < a.size(); i++)  // Check for same contents
 {
 cout << "a[" << i << "]: " << a[i] << endl;
 cout << "c3[" << i << "]: " << c3[i] << endl;
 assert(a[i] == c3[i]);
 }
 
 // change the content in the original array to verify it's not a shallow copy
 a.clear(); // clear a, reset as different values
 a[0] = 8001234;
 a[1] = 8009876;
 a[2] = 8009991;
 
 cout << "(Should be different)\n";
 for (int i = 0; i < a.size(); i++)   // Test for match
 {
 cout << "a[" << i << "]: " << a[i] << endl;
 cout << "c3[" << i << "]: " << c3[i] << endl;
 assert(a[i] != c[i]);
 }
 cout << "Pass!\n\n";
 
 //---------------------------------------------------------------------------------------
 // String Tests
 //---------------------------------------------------------------------------------------
 cout << "------------- Associative Array String, String Testing -------------\n\n";
 
 // Initialize object a
 AssociativeArray<string, string> sa;
 
 // Testing Size()--------------------------------------------------------------------------
 cout << "Testing Size\n";
 cout << "Expected: 0\n";
 cout << "Actual: " << sa.size() << endl << endl;
 assert(sa.size() == 0);  // Closes program if false
 
 // Testing square bracket getter/setter----------------------------------------------------
 cout << "Testing Square Bracket Getter/Setter\n";
 sa["1"] = "9251234";
 sa["2"] = "9257654";
 sa["3"] = "9259876";
 cout << "a[1]'s number: " << sa["1"] << endl;
 cout << "a[2]'s number: " << sa["2"] << endl << endl;
 
 // Testing Clear()-------------------------------------------------------------------------
 cout << "Testing Clear:\n";
 sa.clear();
 cout << "Size is now " << sa.size() << endl << endl;
 
 // Const Object Testing--------------------------------------------------------------------
 cout << "Const Object Testing\n";
 const AssociativeArray<string, string> sb; // Main constructor exists if this compiles
 assert(sb.size() == 0); // if this compiles, is a getter with trailing const
 cout << "Pass!\n\n";
 
 // Object Copy Testing---------------------------------------------------------------------
 cout << "Object Copy Test\n";
 //Assign contents to first array
 sa["0"] = "9251234";
 sa["1"] = "9257654";
 sa["2"] = "9259876";
 
 AssociativeArray<string, string> sc = sa; // Make a copy
 assert(sa.size() == sc.size()); // Check for same size
 assert(sa["0"] == sc["0"]); // Check for same contents
 assert(sa["1"] == sc["1"]);
 assert(sa["2"] == sc["2"]);
 
 // change the content in the original array to verify it's not a shallow copy
 sa.clear(); // clear a, reset as different values
 sa["0"] = "4150987";
 sa["1"] = "4151234";
 sa["2"] = "4150001";
 
 // Check values for shallow copy
 assert(sa["0"] != sc["0"]);
 assert(sa["1"] != sc["1"]);
 assert(sa["2"] != sc["2"]);
 cout << "Pass!\n\n";
 
 // Object Assignment Testing---------------------------------------------------------------
 cout << "Object Assignment Test\n";
 AssociativeArray<string, string> sc2; // Initialize new object
 sc2 = sa; // copy
 assert(sa.size() == sc2.size()); // Check for same size
 
 
 
 // change the content in the original array to verify it's not a shallow copy
 sa.clear(); // clear a, reset as different values
 sa["0"] = "8001234";
 sa["1"] = "8009876";
 sa["2"] = "8009991";
 
 // Check values for shallow copy
 assert(sa["0"] != sc2["0"]);
 assert(sa["1"] != sc2["1"]);
 assert(sa["2"] != sc2["2"]);
 
 cout << "Pass!\n\n";
 } // End Main
