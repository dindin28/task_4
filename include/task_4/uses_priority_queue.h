#ifndef _TASK_4_INCLUDE_TASK_4_USES_PRIORITY_QUEUE_H_
#define _TASK_4_INCLUDE_TASK_4_USES_PRIORITY_QUEUE_H_

#include <functional>
#include <algorithm>
#include <vector>

template <class T, class Compare = std::less<T>>
class uses_priority_queue
{
public:
  uses_priority_queue();
  uses_priority_queue(const T *pointer, size_t size);
  uses_priority_queue(const uses_priority_queue &copy);
  uses_priority_queue<T, Compare> &operator=(const uses_priority_queue &copy);

  bool empty() const;
  size_t size() const;

  void push(const T value);
  void pop();

  T &operator[](const int index);

private:
  size_t size_;
  T *pointer_;
};

#include <uses_priority_queue_impl.cpp> //Source file

#endif //Header Guard