// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#ifndef Queue_h
#define Queue_h

template <typename T>
class Queue
{
  struct node
  {
    T value;
    node* next;
  };
  
  int siz;
  node* firstNode;
  node* lastNode;
  T dummy;
  
public:
  Queue();
  Queue(const Queue&);
  Queue<T>& operator=(const Queue<T>&);
  ~Queue();
  void push(const T&);
  const T& front() const;
  const T& back() const;
  void pop();
  int size() const {return siz;}
  bool empty() const {return siz == 0;}
  void clear();
};

//---------------------------------------------------------------------------------------
// Constructor Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
Queue<T>::Queue()
{
  siz = 0;
  firstNode = 0;
  lastNode = 0;
  dummy = T();
}

//---------------------------------------------------------------------------------------
// Copy Constructor Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
Queue<T>::Queue(const Queue<T>& original)
{
  this->firstNode = 0;
  this->lastNode = 0;
  this->siz = original.siz;
  
  for (node* p = original.firstNode; p; p = p->next)
  {
    node* temp = new node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

//---------------------------------------------------------------------------------------
// Assignment Operator Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& original)
{
  if (this != &original)
  {
    // Delete original nodes
    while (firstNode)
    {
      node* p = firstNode;
      firstNode = firstNode->next;
      delete p;
    }
    
    // Build new copy
    this->firstNode = 0;
    this->lastNode = 0;
    this->siz = original.siz;
    for (node* p = original.firstNode; p; p = p->next)
    {
      node* temp = new node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
  }
  return *this;
}

//---------------------------------------------------------------------------------------
// Destructor Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
Queue<T>::~Queue()
{
  node* temp;
  while(firstNode)
  {
    temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
  }
}

//---------------------------------------------------------------------------------------
// Push Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
void Queue<T>::push(const T& value)
{
  node* temp = new node{value, 0};
  
  if(lastNode) lastNode->next = temp;
  else firstNode = temp;
  
  lastNode = temp;
  siz++;
}

//---------------------------------------------------------------------------------------
// Front Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
const T& Queue<T>::front() const
{
  if (firstNode)
    return firstNode->value;
  else
    return dummy;
}

//---------------------------------------------------------------------------------------
// Back Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
const T& Queue<T>::back() const
{
  if (lastNode)
    return lastNode->value;
  else
    return dummy;
}

//---------------------------------------------------------------------------------------
// Pop Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
void Queue<T>::pop()
{
  if(firstNode)
  {
    node* temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
    siz--;
  }
  if(siz == 0) lastNode = 0;
}

//---------------------------------------------------------------------------------------
// Clear Function Definition
//---------------------------------------------------------------------------------------
template <typename T>
void Queue<T>::clear()
{
  while(firstNode)
  {
    node* temp = firstNode;
    firstNode = firstNode->next;
    delete temp;
    siz--;
  }
  lastNode = 0;
}

#endif /* Queue_h */

