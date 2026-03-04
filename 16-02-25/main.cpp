#include <iostream>

template <class T>
struct BiList
{
  T val;
  BiList<T> *next;
  BiList<T> *prev;
};

template <class T>
class DoublyLinkedList
{
private:
  BiList<T> *fake;
  size_t sz;

public:
  DoublyLinkedList()
  {
    fake = new BiList<T>();
    fake->next = fake;
    fake->prev = fake;
    sz = 0;
  }

  ~DoublyLinkedList()
  {
    delete fake;
  }
};

int main()
{
}
