// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#ifndef AssociativeArray_h
#define AssociativeArray_h

#include <queue>

template <typename K, typename V>
class AssociativeArray
{
  struct Node
  {
    K key;
    V value;
    bool inUse;
  };
  
  Node* values;
  int siz;
  int cap;
  void capacity(int);
  
public:
  AssociativeArray(int = 2); // constructor function
  AssociativeArray(const AssociativeArray<K,V>&); // copy constructor
  AssociativeArray<K,V>& operator=(const AssociativeArray<K,V>&); // assignment operator
  ~AssociativeArray() {delete [] values;} // destructor
  V operator[](const K&) const; // Square Bracket Getter function
  V& operator[](const K&); // Square Bracket Setter function
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  queue<K> keys() const;
  int size() const {return siz;}
  void clear();
};

//---------------------------------------------------------------------------------------
// Constructor Function Definition
//---------------------------------------------------------------------------------------
template <typename K, typename V>
AssociativeArray<K,V>::AssociativeArray(int cap)
{
  siz = 0;
  this->cap = cap;
  this->values = new Node[cap];
  for (int i = 0; i < cap; ++i)
  {
    values[i].inUse = false;
  }
}

//---------------------------------------------------------------------------------------
// Copy Constructor Function Definition
//---------------------------------------------------------------------------------------
template <typename K, typename V>
AssociativeArray<K,V>::AssociativeArray(const AssociativeArray<K,V>& original)
{
  this->cap = original.cap; // Copy over cap
  this->siz = original.siz; // Copy size
  this->values = new Node[cap]; // Assign object pointer to new node array
  for (int i = 0; i < cap; i++) // Copy over all values
  {
    values[i] = original.values[i];
  }
}

//---------------------------------------------------------------------------------------
// Assignment Operator Function Definition
//---------------------------------------------------------------------------------------
template <typename K, typename V>
AssociativeArray<K,V>& AssociativeArray<K,V>::operator=(const AssociativeArray<K,V>& original)
{
  if (this != &original) // check for self copy first
  {
    delete [] values; // Delete current pointer
    
    cap = original.cap; // Copy over cap
    siz = original.siz; // Copy size
    values = new Node[cap]; // Assign object pointer to new node array
    for (int i = 0; i < cap; i++) // Copy over all values
    {
      values[i] = original.values[i];
    }
  }
  return *this;
}

//---------------------------------------------------------------------------------------
// Capacity Setter Function Definition
//---------------------------------------------------------------------------------------
template <typename K, typename V>
void AssociativeArray<K,V>::capacity(int cap)
{
  if (cap <= 0) // if cap is not increased, then just return
  {
    return;
  }
  Node* temp = new Node[cap]; // create temp array to store new data members
  
  for (int i = 0; i < cap; i++) // Set all inUse to false
  {
    temp[i].inUse = bool();
  }
  
  for (int i = 0; i < this->cap; i++) // Copy old contents
  {
    temp[i] = this->values[i];
  }
  
  delete [] values; // Deallocate original array
  values = temp;  // Assign new temp attributes to actual array
  this->cap = cap; // Set new cap
}

//---------------------------------------------------------------------------------------
// Square Bracket Getter function
//---------------------------------------------------------------------------------------
template <typename K, typename V>
V AssociativeArray<K,V>::operator[](const K& key) const
{
  for (int i = 0; i < cap; i++)
    if (values[i].key == key && values[i].inUse)
      return values[i].value;
  return V();
}

//---------------------------------------------------------------------------------------
// Square Bracket Setter function
//---------------------------------------------------------------------------------------
template <typename K, typename V>
V& AssociativeArray<K,V>::operator[](const K& key)
{
  int unusedIndex = cap;
  for (int i = 0; i < cap; i++)
  {
    if (values[i].inUse == false)
    {
      if (i < unusedIndex) unusedIndex = i;
    }
    else if (values[i].inUse == true && values[i].key == key)
    {
      return values[i].value;
    }
  }
  if (unusedIndex == cap) capacity(cap*2);
  values[unusedIndex].key = key;
  values[unusedIndex].inUse = true; siz++;
  return values[unusedIndex].value;
}

//---------------------------------------------------------------------------------------
// Contains Key function
//---------------------------------------------------------------------------------------
template <typename K, typename V>
bool AssociativeArray<K,V>::containsKey(const K& key) const
{
  for (int i = 0; i < cap; i++)
    if (values[i].key == key && values[i].inUse)
      return true;
  return false;
}

//---------------------------------------------------------------------------------------
// Delete Key function
//---------------------------------------------------------------------------------------
template <typename K, typename V>
void AssociativeArray<K,V>::deleteKey(const K& key)
{
  for (int i = 0; i < cap; i++)
    if (values[i].key == key && values[i].inUse)
    {
      values[i].inUse = false;
      siz--;
    }
}

//---------------------------------------------------------------------------------------
// Keys Queue function
//---------------------------------------------------------------------------------------
template <typename K, typename V>
queue<K> AssociativeArray<K,V>::keys() const
{
  queue<K> keyQueue;
  for (int i = 0; i < cap; i++)
  {
    if(values[i].inUse == true)
      keyQueue.push(values[i].key);
  }
  return keyQueue;
}

//---------------------------------------------------------------------------------------
// Clear Function Definition
//---------------------------------------------------------------------------------------
template <typename K, typename V>
void AssociativeArray<K,V>::clear()
{
  for (int i = 0; i < cap; i++)
  {
    values[i].inUse = false;
  }
  siz = 0;
}

#endif /* AssociativeArray_h */
