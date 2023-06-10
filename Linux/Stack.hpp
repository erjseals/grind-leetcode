#ifndef STACK_HPP
#define STACK_HPP

class Stack {
private:
  ListNode *m_top;
  int m_size;

public:
  Stack() : m_top(nullptr), m_size(0) {}

  ~Stack() {
    ListNode *tmp;
    while (m_top) {
      tmp = m_top;
      m_top = m_top->next;
      delete tmp;
    }
  }

  virtual void push(int value) {
    ListNode *tmp = new ListNode(value);
    tmp->next = m_top;
    m_top = tmp;
    m_size++;
  }

  virtual int pop() {
    if (isEmpty())
      return 0;

    int ret = m_top->val;
    ListNode *tmp = m_top;
    m_top = m_top->next;
    delete tmp;
    m_size--;

    return ret;
  }

  int peek() {
    if (isEmpty())
      return 0;
    else
      return m_top->val;
  }

  bool isEmpty() { return (m_size < 1); }
};

#endif
