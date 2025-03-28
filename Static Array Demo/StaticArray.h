// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#ifndef LabExercise3_h
#define LabExercise3_h

template <typename T, int CAP>
class StaticArray
{
  T values[CAP];
  T dummy;
  
public:
  StaticArray();  // constructor function
  int capacity() const {return CAP;} // capacity function - inline definition
  T operator[](int) const;  // Square Bracket Getter function
  T& operator[](int); // Square Bracket Setter function
};

//---------------------------------------------------------------------------------------
// Constructor Function Definition
//---------------------------------------------------------------------------------------
template <typename T, int CAP>
StaticArray<T,CAP>::StaticArray()
{
  // initialize all values to default T values
  for (int i = 0; i < CAP; i++)
    values[i] = T();
  // initialize dummy
  dummy = T();
}
//---------------------------------------------------------------------------------------
// Square Bracket Getter function
//---------------------------------------------------------------------------------------
template <typename T, int CAP>
T StaticArray<T,CAP>::operator[](int index) const
{
  // Check if in bounds - if not, return default data
  if (index < 0 || index >= CAP)
    return T();
  // Otherwise return value at given index
  return values[index];
}
//---------------------------------------------------------------------------------------
// Square Bracket Setter function
//---------------------------------------------------------------------------------------
template <typename T, int CAP>
T& StaticArray<T,CAP>::operator[](int index)
{
  // Check if in bounds - if not, return dummy address
  if (index < 0 || index >= CAP)
    return dummy;
  // Otherwise return the address of the value at given index
  return values[index];
}

#endif /* LabExercise3_h */
