// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include "Queue.h"
#include "Queue.h" // Ifndef test

int main()
{
  // Programmer's Identification
  cout << "Programmer Name (Last, First): Frediani-Jost, Cheyenne\n";
  cout << "Programmer's ID: 1429200\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  //---------------------------------------------------------------------------------------
  // Int Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Queue Int Testing -------------\n\n";
  
  // Initialize a
  Queue<int> a;
  
  // Testing Main Constructor
  cout << "Testing Constructor:\n";
  // Testing size()
  cout << "Testing size()\n";
  assert(a.size() == 0);
  cout << "Pass\n";
  // Testing empty() = true
  cout << "Testing empty() = true\n";
  assert(a.empty() == true);
  cout << "Pass\n\n";
  
  // Testing push()
  cout << "Testing push()\n";
  a.push(1);
  a.push(3);
  a.push(5);
  
  // Testing front()
  cout << "Testing front()\n";
  cout << "Expected: 1\n";
  cout << "Actual: " << a.front() << endl;
  assert(a.front() == 1);
  cout << "Pass\n\n";
  
  // Testing back()
  cout << "Testing back()\n";
  cout << "Expected: 5\n";
  cout << "Actual: " << a.back() << endl;
  assert(a.back() == 5);
  cout << "Pass\n\n";
  
  // Testing pop()
  cout << "Testing pop()\n";
  a.pop();
  cout << "Expected: 3\n";
  cout << "Actual: " << a.front() << endl;
  assert(a.front() == 3);
  cout << "Pass\n\n";
  
  // Testing empty() = false
  cout << "Testing empty() = false\n";
  assert(a.empty() == false);
  cout << "Pass\n\n";
  
  // Testing clear()
  cout << "Testing clear()\n";
  a.clear();
  assert(a.size() == 0);
  assert(a.empty() == true);
  cout << "Pass\n\n";
  
  // Const Object Testing
  cout << "Const Object Testing\n";
  const Queue<int> b;
  assert(b.size() == 0);
  assert(b.empty() == true);
  assert(b.front() == int());
  assert(b.back() == int());
  cout << "Pass\n";
  
  // Copy Constructor Testing
  cout << "\nTesting Copy Constructor\n";
  a.push(2);
  a.push(4);
  Queue<int> copyA = a; // Make copy
  assert(copyA.size() == a.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= a.size(); i++)
  {
    assert(a.front() == copyA.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    a.pop();
    copyA.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  copyA.clear();
  a.push(2);
  a.push(4);
  for (int i = 0; i <= a.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(a.front() != copyA.front());
    a.pop();
    copyA.pop();
  }
  cout << "Pass\n\n";
  
  // Assignment Operator Testing
  cout << "\nTesting Assignment Operator\n";
  Queue<int> c; // Initialize new object
  a.push(8);
  a.push(9);
  c = a; // Copy over from other object
  assert(c.size() == a.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= a.size(); i++)
  {
    assert(c.front() == a.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "c.front = " << copyA.front() << endl;
    a.pop();
    c.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  c.clear();
  a.push(2);
  a.push(4);
  for (int i = 0; i <= a.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(a.front() != c.front());
    a.pop();
    c.pop();
  }
  cout << "Pass\n\n";
  
  //---------------------------------------------------------------------------------------
  // Double Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Queue Double Testing -------------\n\n";
  
  // Initialize a
  Queue<double> da;
  
  // Testing Main Constructor
  cout << "Testing Constructor:\n";
  // Testing size()
  cout << "Testing size()\n";
  assert(da.size() == 0);
  cout << "Pass\n";
  // Testing empty() = true
  cout << "Testing empty() = true\n";
  assert(da.empty() == true);
  cout << "Pass\n\n";
  
  // Testing push()
  cout << "Testing push()\n";
  da.push(1.1);
  da.push(3.3);
  da.push(5.5);
  
  // Testing front()
  cout << "Testing front()\n";
  cout << "Expected: 1.1\n";
  cout << "Actual: " << da.front() << endl;
  assert(da.front() == 1.1);
  cout << "Pass\n\n";
  
  // Testing back()
  cout << "Testing back()\n";
  cout << "Expected: 5.5\n";
  cout << "Actual: " << da.back() << endl;
  assert(da.back() == 5.5);
  cout << "Pass\n\n";
  
  // Testing pop()
  cout << "Testing pop()\n";
  da.pop();
  cout << "Expected: 3.3\n";
  cout << "Actual: " << da.front() << endl;
  assert(da.front() == 3.3);
  cout << "Pass\n\n";
  
  // Testing empty() = false
  cout << "Testing empty() = false\n";
  assert(da.empty() == false);
  cout << "Pass\n\n";
  
  // Testing clear()
  cout << "Testing clear()\n";
  da.clear();
  assert(da.size() == 0);
  assert(da.empty() == true);
  cout << "Pass\n\n";
  
  // Const Object Testing
  cout << "Const Object Testing\n";
  const Queue<double> db;
  assert(db.size() == 0);
  assert(db.empty() == true);
  assert(db.front() == double());
  assert(db.back() == double());
  cout << "Pass\n";
  
  // Copy Constructor Testing
  cout << "\nTesting Copy Constructor\n";
  da.push(2);
  da.push(4);
  Queue<double> copyDA = da; // Make copy
  assert(copyDA.size() == da.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= da.size(); i++)
  {
    assert(da.front() == copyDA.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    da.pop();
    copyDA.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  copyDA.clear();
  da.push(2);
  da.push(4);
  for (int i = 0; i <= da.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(da.front() != copyDA.front());
    da.pop();
    copyDA.pop();
  }
  cout << "Pass\n\n";
  
  // Assignment Operator Testing
  cout << "\nTesting Assignment Operator\n";
  Queue<double> dc; // Initialize new object
  da.push(8.8);
  da.push(9.9);
  dc = da; // Copy over from other object
  assert(dc.size() == da.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= da.size(); i++)
  {
    assert(dc.front() == da.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "c.front = " << copyA.front() << endl;
    da.pop();
    dc.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  dc.clear();
  da.push(2.2);
  da.push(4.4);
  for (int i = 0; i <= da.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(da.front() != dc.front());
    da.pop();
    dc.pop();
  }
  cout << "Pass\n\n";
  
  //---------------------------------------------------------------------------------------
  // Char Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Queue Char Testing -------------\n\n";
  
  // Initialize a
  Queue<char> ca;
  
  // Testing Main Constructor
  cout << "Testing Constructor:\n";
  // Testing size()
  cout << "Testing size()\n";
  assert(ca.size() == 0);
  cout << "Pass\n";
  // Testing empty() = true
  cout << "Testing empty() = true\n";
  assert(ca.empty() == true);
  cout << "Pass\n\n";
  
  // Testing push()
  cout << "Testing push()\n";
  ca.push('a');
  ca.push('b');
  ca.push('c');
  
  // Testing front()
  cout << "Testing front()\n";
  cout << "Expected: 'a'\n";
  cout << "Actual: " << ca.front() << endl;
  assert(ca.front() == 'a');
  cout << "Pass\n\n";
  
  // Testing back()
  cout << "Testing back()\n";
  cout << "Expected: 'c'\n";
  cout << "Actual: " << ca.back() << endl;
  assert(ca.back() == 'c');
  cout << "Pass\n\n";
  
  // Testing pop()
  cout << "Testing pop()\n";
  ca.pop();
  cout << "Expected: 'b'\n";
  cout << "Actual: " << ca.front() << endl;
  assert(ca.front() == 'b');
  cout << "Pass\n\n";
  
  // Testing empty() = false
  cout << "Testing empty() = false\n";
  assert(ca.empty() == false);
  cout << "Pass\n\n";
  
  // Testing clear()
  cout << "Testing clear()\n";
  ca.clear();
  assert(ca.size() == 0);
  assert(ca.empty() == true);
  cout << "Pass\n\n";
  
  // Const Object Testing
  cout << "Const Object Testing\n";
  const Queue<char> cb;
  assert(cb.size() == 0);
  assert(cb.empty() == true);
  assert(cb.front() == char());
  assert(cb.back() == char());
  cout << "Pass\n";
  
  // Copy Constructor Testing
  cout << "\nTesting Copy Constructor\n";
  ca.push('x');
  ca.push('y');
  Queue<char> copyCA = ca; // Make copy
  assert(copyCA.size() == ca.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= ca.size(); i++)
  {
    assert(ca.front() == copyCA.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    ca.pop();
    copyCA.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  copyCA.clear();
  ca.push('r');
  ca.push('s');
  for (int i = 0; i <= ca.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(ca.front() != copyCA.front());
    ca.pop();
    copyCA.pop();
  }
  cout << "Pass\n\n";
  
  // Assignment Operator Testing
  cout << "\nTesting Assignment Operator\n";
  Queue<char> cc; // Initialize new object
  ca.push('t');
  ca.push('u');
  cc = ca; // Copy over from other object
  assert(cc.size() == ca.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= ca.size(); i++)
  {
    assert(cc.front() == ca.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "c.front = " << copyA.front() << endl;
    ca.pop();
    cc.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  cc.clear();
  ca.push('v');
  ca.push('w');
  for (int i = 0; i <= ca.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(ca.front() != cc.front());
    ca.pop();
    cc.pop();
  }
  cout << "Pass\n\n";
  
  //---------------------------------------------------------------------------------------
  // String Tests
  //---------------------------------------------------------------------------------------
  cout << "------------- Queue String Testing -------------\n\n";
  
  // Initialize a
  Queue<string> sa;
  
  // Testing Main Constructor
  cout << "Testing Constructor:\n";
  // Testing size()
  cout << "Testing size()\n";
  assert(sa.size() == 0);
  cout << "Pass\n";
  // Testing empty() = true
  cout << "Testing empty() = true\n";
  assert(sa.empty() == true);
  cout << "Pass\n\n";
  
  // Testing push()
  cout << "Testing push()\n";
  sa.push("red");
  sa.push("blue");
  sa.push("yellow");
  
  // Testing front()
  cout << "Testing front()\n";
  cout << "Expected: 'red'\n";
  cout << "Actual: " << sa.front() << endl;
  assert(sa.front() == "red");
  cout << "Pass\n\n";
  
  // Testing back()
  cout << "Testing back()\n";
  cout << "Expected: 'yellow'\n";
  cout << "Actual: " << sa.back() << endl;
  assert(sa.back() == "yellow");
  cout << "Pass\n\n";
  
  // Testing pop()
  cout << "Testing pop()\n";
  sa.pop();
  cout << "Expected: 'blue'\n";
  cout << "Actual: " << sa.front() << endl;
  assert(sa.front() == "blue");
  cout << "Pass\n\n";
  
  // Testing empty() = false
  cout << "Testing empty() = false\n";
  assert(sa.empty() == false);
  cout << "Pass\n\n";
  
  // Testing clear()
  cout << "Testing clear()\n";
  sa.clear();
  assert(sa.size() == 0);
  assert(sa.empty() == true);
  cout << "Pass\n\n";
  
  // Const Object Testing
  cout << "Const Object Testing\n";
  const Queue<string> sb;
  assert(sb.size() == 0);
  assert(sb.empty() == true);
  assert(sb.front() == string());
  assert(sb.back() == string());
  cout << "Pass\n";
  
  // Copy Constructor Testing
  cout << "\nTesting Copy Constructor\n";
  sa.push("orange");
  sa.push("green");
  Queue<string> copySA = sa; // Make copy
  assert(copySA.size() == sa.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= sa.size(); i++)
  {
    assert(sa.front() == copySA.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    sa.pop();
    copySA.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  copySA.clear();
  sa.push("pink");
  sa.push("purple");
  for (int i = 0; i <= sa.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(sa.front() != copySA.front());
    sa.pop();
    copySA.pop();
  }
  cout << "Pass\n\n";
  
  // Assignment Operator Testing
  cout << "\nTesting Assignment Operator\n";
  Queue<string> sc; // Initialize new object
  sa.push("banana");
  sa.push("apple");
  sc = sa; // Copy over from other object
  assert(sc.size() == sa.size()); // Check capacity
  // Check contents
  for (int i = 0; i <= sa.size(); i++)
  {
    assert(sc.front() == sa.front());
    //cout << "a.front = " << a.front() << endl;
    //cout << "c.front = " << copyA.front() << endl;
    sa.pop();
    sc.pop();
  }
  
  // Deep Copy Test
  cout << "Deep Copy Test...\n";
  sc.clear();
  sa.push("grape");
  sa.push("melon");
  for (int i = 0; i <= sa.size(); i++)
  {
    // Uncomment to see output vvvvv
    //cout << "a.front = " << a.front() << endl;
    //cout << "copyA.front = " << copyA.front() << endl;
    assert(sa.front() != sc.front());
    sa.pop();
    sc.pop();
  }
  cout << "Pass\n\n";
}
