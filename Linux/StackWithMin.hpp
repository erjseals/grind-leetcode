#ifndef STACKWITHMIN_HPP
#define STACKWITHMIN_HPP

#include "Stack.hpp"

class StackWithMin : public Stack {
private:
  Stack::Stack *m_minStack;

public:
  StackWithMin();
  ~StackWithMin();

  void push(int value) override;
  int pop() override;
};

#endif
