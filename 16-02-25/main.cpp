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

  void insertAfter(BiList<T> *pos, const T &value)
  {
    BiList<T> *node = new BiList<T>();
    node->val = value;
    node->next = pos->next;
    node->prev = pos;
    pos->next->prev = node;
    pos->next = node;
    ++sz;
  }

  void removeNode(BiList<T> *node)
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    --sz;
  }

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

  void push_back(const T &value)
  {
    insertAfter(fake->prev, value);
  }
};

int main()
{
}
