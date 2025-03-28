// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include <cassert>
#include "StaticArray.h"
#include "StaticArray.h" // Ifndef test

int main()
{
  // Programmer's Identification
  cout << "Programmer Name (Last, First): Frediani-Jost, Cheyenne\n";
  cout << "Programmer's ID: 1429200\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  //---------------------------------------------------------------------------------------
  // Int Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Static Array Int Testing -------------\n\n";
  
  // Initialize object a - size 100
  StaticArray<int, 100> a;
  
  // Testing Capacity
  cout << "Testing Static Array Capacity\n";
  cout << "Expected: 100\n";
  cout << "Actual: " << a.capacity() << "\n";
  assert(100 == a.capacity());
  cout << "Pass\n";
  
  // Testing Constructor
  cout << "\nTesting Static Array Constructor\n";
  for(int i = 0; i < a.capacity(); i++)
  {
    assert(a[i] == int());  // Should be default int
  };
  cout << "Pass\n";
  
  // Testing Square Bracket Setter
  cout << "\nTesting Static Array [] Setter\n";
  a[6] = 123456;
  a[7] = 7654321;
  a[-1000] = 123123; // dummy test
  cout << "Expected: 123456 for a[6]\n";
  cout << "Actual: " << a[6]<< "\n";
  assert(123456 == a[6]);
  cout << "Expected: 7654321 for a[7]\n";
  cout << "Actual: " << a[7]<< "\n";
  assert(7654321 == a[7]);
  cout << "Expected: 123123 for a[-1000]\n";
  cout << "Actual: " << a[-1000]<< "\n";
  assert(123123 == a[-1000]);
  assert(123123 == a[-6]); // shared dummy address
  //check upper and lower ranges
  assert(123123 == a[a.capacity()]);
  assert(123123 != a[99]);
  assert(123123 != a[0]);
  cout << "Pass\n";
  
  // Testing Square Bracket Getter
  cout << "\nTesting Static Array [] Getter\n";
  //Initiallize const object b as copy of a
  const StaticArray<int, 100> b = a;
  for(int i = 0; i < b.capacity(); i++)
  {
    assert(b[i] == a[i]);
  };
  cout << "Pass\n";
  
  // Const Object Test
  cout << "\nConst Object Test\n";
  const StaticArray<int,100> c; // main constructor exists if this compiles
  assert(c.capacity()); // checks that capacity() is a getter
  assert(c[0] == c[0]); // square bracker getter exists if this compiles
  assert(c[-1] == c[-1]); // tests the getter's range checking
  cout << "Pass\n" << endl;
  
  //---------------------------------------------------------------------------------------
  // Double Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Static Array Double Testing -------------\n\n";
  
  // Initialize object double a - size 100
  StaticArray<double, 100> da;
  
  // Testing Capacity
  cout << "Testing Static Array Capacity\n";
  cout << "Expected: 100\n";
  cout << "Actual: " << da.capacity() << "\n";
  assert(100 == da.capacity());
  cout << "Pass\n";
  
  // Testing Constructor
  cout << "\nTesting Static Array Constructor\n";
  for(int i = 0; i < da.capacity(); i++)
  {
    assert(da[i] == double());  // Should be default double
  };
  cout << "Pass\n";
  
  // Testing Square Bracket Setter
  cout << "\nTesting Static Array [] Setter\n";
  da[6] = 123.456;
  da[7] = 76543.21;
  da[-1000] = 12.3123; // dummy test
  cout << "Expected: 123.456 for a[6]\n";
  cout << "Actual: " << da[6]<< "\n";
  assert(123.456 == da[6]);
  cout << "Expected: 76543.21 for a[7]\n";
  cout << "Actual: " << da[7]<< "\n";
  assert(76543.21 == da[7]);
  cout << "Expected: 12.3123 for a[-1000]\n";
  cout << "Actual: " << da[-1000]<< "\n";
  assert(12.3123 == da[-1000]);
  assert(12.3123 == da[-6]); // shared dummy address
  //check upper and lower ranges
  assert(12.3123 == da[da.capacity()]);
  assert(12.3123 != da[99]);
  assert(12.3123 != da[0]);
  cout << "Pass\n";
  
  // Testing Square Bracket Getter
  cout << "\nTesting Static Array [] Getter\n";
  //Initiallize const object double b as copy of double a
  const StaticArray<double, 100> db = da;
  for(int i = 0; i < db.capacity(); i++)
  {
    assert(db[i] == da[i]);
  };
  cout << "Pass\n";
  
  // Const Object Test
  cout << "\nConst Object Test\n";
  const StaticArray<double,100> dc; // main constructor exists if this compiles
  assert(dc.capacity()); // checks that capacity() is a getter
  assert(dc[0] == dc[0]); // square bracker getter exists if this compiles
  assert(dc[-1] == dc[-1]); // tests the getter's range checking
  cout << "Pass\n" << endl;
  
  //---------------------------------------------------------------------------------------
  // Char Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Static Array Char Testing -------------\n\n";
  
  // Initialize object char a - size 100
  StaticArray<char, 100> ca;
  
  // Testing Capacity
  cout << "Testing Static Array Capacity\n";
  cout << "Expected: 100\n";
  cout << "Actual: " << ca.capacity() << "\n";
  assert(100 == ca.capacity());
  cout << "Pass\n";
  
  // Testing Constructor
  cout << "\nTesting Static Array Constructor\n";
  for(int i = 0; i < ca.capacity(); i++)
  {
    assert(ca[i] == char());  // Should be default char
  };
  cout << "Pass\n";
  
  // Testing Square Bracket Setter
  cout << "\nTesting Static Array [] Setter\n";
  ca[6] = 'a';
  ca[7] = 'b';
  ca[-1000] = 'c'; // dummy test
  cout << "Expected: 'a' for a[6]\n";
  cout << "Actual: " << ca[6]<< "\n";
  assert('a' == ca[6]);
  cout << "Expected: 'b' for a[7]\n";
  cout << "Actual: " << ca[7]<< "\n";
  assert('b' == ca[7]);
  cout << "Expected: 'c' for a[-1000]\n";
  cout << "Actual: " << ca[-1000]<< "\n";
  assert('c' == ca[-1000]);
  assert('c' == ca[-6]); // shared dummy address
  //check upper and lower ranges
  assert('c' == ca[ca.capacity()]);
  assert('c' != ca[99]);
  assert('c' != ca[0]);
  cout << "Pass\n";
  
  // Testing Square Bracket Getter
  cout << "\nTesting Static Array [] Getter\n";
  //Initiallize const object char b as copy of a
  const StaticArray<char, 100> cb = ca;
  for(int i = 0; i < cb.capacity(); i++)
  {
    assert(cb[i] == ca[i]);
  };
  cout << "Pass\n";
  
  // Const Object Test
  cout << "\nConst Object Test\n";
  const StaticArray<char,100> cc; // main constructor exists if this compiles
  assert(cc.capacity()); // checks that capacity() is a getter
  assert(cc[0] == cc[0]); // square bracker getter exists if this compiles
  assert(cc[-1] == cc[-1]); // tests the getter's range checking
  cout << "Pass\n" << endl;
  
  //---------------------------------------------------------------------------------------
  // String Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Static Array String Testing -------------\n\n";
  
  // Initialize object char a - size 100
  StaticArray<string, 100> sa;
  
  // Testing Capacity
  cout << "Testing Static Array Capacity\n";
  cout << "Expected: 100\n";
  cout << "Actual: " << sa.capacity() << "\n";
  assert(100 == sa.capacity());
  cout << "Pass\n";
  
  // Testing Constructor
  cout << "\nTesting Static Array Constructor\n";
  for(int i = 0; i < sa.capacity(); i++)
  {
    assert(sa[i] == string());  // Should be default string
  };
  cout << "Pass\n";
  
  // Testing Square Bracket Setter
  cout << "\nTesting Static Array [] Setter\n";
  sa[6] = "apple";
  sa[7] = "banana";
  sa[-1000] = "coconut"; // dummy test
  cout << "Expected: 'apple' for a[6]\n";
  cout << "Actual: " << sa[6]<< "\n";
  assert("apple" == sa[6]);
  cout << "Expected: 'banana' for a[7]\n";
  cout << "Actual: " << sa[7]<< "\n";
  assert("banana" == sa[7]);
  cout << "Expected: 'coconut' for a[-1000]\n";
  cout << "Actual: " << sa[-1000]<< "\n";
  assert("coconut" == sa[-1000]);
  assert("coconut" == sa[-6]); // shared dummy address
  //check upper and lower ranges
  assert("coconut" == sa[sa.capacity()]);
  assert("coconut" != sa[99]);
  assert("coconut" != sa[0]);
  cout << "Pass\n";
  
  // Testing Square Bracket Getter
  cout << "\nTesting Static Array [] Getter\n";
  //Initiallize const object char b as copy of a
  const StaticArray<string, 100> sb = sa;
  for(int i = 0; i < sb.capacity(); i++)
  {
    assert(sb[i] == sa[i]);
  };
  cout << "Pass\n";
  
  // Const Object Test
  cout << "\nConst Object Test\n";
  const StaticArray<string,100> sc; // main constructor exists if this compiles
  assert(sc.capacity()); // checks that capacity() is a getter
  assert(sc[0] == sc[0]); // square bracker getter exists if this compiles
  assert(sc[-1] == sc[-1]); // tests the getter's range checking
  cout << "Pass\n" << endl;
  
} // End Main
