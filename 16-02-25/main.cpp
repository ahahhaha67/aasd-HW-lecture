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
    clear();
    delete fake;
  }

  void push_back(const T &value)
  {
    insertAfter(fake->prev, value);
  }

  void push_front(const T &value)
  {
    insertAfter(fake, value);
  }

  size_t size() const { return sz; }
  bool empty() const { return sz == 0; }

  void clear()
  {
    while (sz > 0)
      removeNode(fake->next);
  }

  T &front() { return fake->next->val; }
  T &back() { return fake->prev->val; }

  void pop_front() { removeNode(fake->next); }
  void pop_back() { removeNode(fake->prev); }

  void print() const
  {
    BiList<T> *cur = fake->next;
    std::cout << "[ ";
    while (cur != fake)
    {
      std::cout << cur->val << " ";
      cur = cur->next;
    }
    std::cout << "]\n";
  }

  void print_reverse() const
  {
    BiList<T> *cur = fake->prev;
    std::cout << "[ ";
    while (cur != fake)
    {
      std::cout << cur->val << " ";
      cur = cur->prev;
    }
    std::cout << "]\n";
  }
};

int main()
{
}
