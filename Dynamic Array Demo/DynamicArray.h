// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#ifndef DynamicArray_h
#define DynamicArray_h

template <typename T>
class DynamicArray
{
  T* values;
  int cap;
  T dummy;
  
public:
  DynamicArray(int=2);  // constructor function, default cap = 2
  DynamicArray(const DynamicArray<T>&); // copy constructor
  ~DynamicArray() {delete [] values;} // destructor - inline definition
  DynamicArray<T>& operator=(const DynamicArray<T>&); // assignment operator
  int capacity() const {return cap;} // capacity getter function - inline definition
  void capacity(int); // capacity setter function
  T operator[](int) const;  // Square Bracket Getter function
  T& operator[](int); // Square Bracket Setter function
};

//---------------------------------------------------------------------------------------
// Constructor Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
DynamicArray<T>::DynamicArray(int cap)
{
  // Set this object's cap value
  this -> cap = cap;
  // Assign object pointer to a new array of type T and size cap
  values = new T[cap];
  // initialize all values to default T values
  for (int i = 0; i < cap; i++)
    values[i] = T();
  // initialize dummy
  dummy = T();
}

//---------------------------------------------------------------------------------------
// Copy Constructor Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& original)
{
  this->cap = original.cap; // Copy over cap
  this->values = new T[cap]; // Assign object pointer to new array
  for (int i = 0; i < cap; i++) // Copy over all values
    values[i] = original.values[i];
}

//---------------------------------------------------------------------------------------
// Assignment Operator Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& original)
{
  if(this != &original) // check for self copy first
  {
    delete [] values; // Delete current pointer
    
    this->cap = original.cap; // Copy over cap size
    this->values = new T[cap]; // Assign object pointer to new array
    for (int i = 0; i < cap; i++) // Copy over all values
      values[i] = original.values[i];
  }
  return *this;
}

//---------------------------------------------------------------------------------------
// Capacity Setter Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
void DynamicArray<T>::capacity(int cap)
{
  T* temp = new T[cap]; // create temp array to store new data members
  int limit = cap < this->cap ? cap : this->cap; // set limit for copying old array contents
  
  for (int i = 0; i < limit; i++) // Copy old contents
    temp[i] = values[i];
  
  for (int i = limit; i < cap; i++) // Set the rest to default values
    temp[i] = T();
  
  delete [] values; // Deallocate original array
  values = temp;  // Assign new temp attributes to actual array
  this->cap = cap; // Set new cap
}

//---------------------------------------------------------------------------------------
// Square Bracket Getter function
//---------------------------------------------------------------------------------------
template <typename T>
T DynamicArray<T>::operator[](int index) const
{
  // Check if in bounds - if not, return default data
  if (index < 0 || index >= cap)
    return dummy;
  // Otherwise return value at given index
  return values[index];
}

//---------------------------------------------------------------------------------------
// Square Bracket Setter function
//---------------------------------------------------------------------------------------
template <typename T>
T& DynamicArray<T>::operator[](int index)
{
  // Check if index is positive - if not, return dummy address
  if (index < 0) return dummy;
  // Check if index is greater than current cap - if so, double current cap
  if (index >= cap) capacity(2 * index);
  // Otherwise, return address
  return values[index];
}

#endif /* DynamicArray_h */
