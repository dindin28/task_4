// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#ifndef _TASK_4_INCLUDE_TASK_4_USES_PRIORITY_QUEUE_H_
#define _TASK_4_INCLUDE_TASK_4_USES_PRIORITY_QUEUE_H_

#include <functional>
#include <algorithm>
#include <vector>

template <class T, class Compare = std::less<T>>
class uses_priority_queue
{
public:
  uses_priority_queue() : size_(0), pointer_(nullptr){};
  uses_priority_queue(const T *pointer, size_t size) : size_(size)
  {
    pointer_ = new T[size];
    for (int i = 0; i < size; i++)
    {
      pointer_[i] = pointer[i];
    }
  }

  uses_priority_queue(const uses_priority_queue &copy) : size_(copy.size_)
  {
    pointer_ = new T[copy.size_];
    for (int i = 0; i < size_; i++)
    {
      pointer_[i] = copy.pointer_[i];
    }
  }
  uses_priority_queue<T, Compare> &operator=(const uses_priority_queue &copy)
  {
    size_ = copy.size_;
    for (int i = 0; i < size_; i++)
    {
      pointer_[i] = copy.pointer_[i];
    }

    return *this;
  }

  bool empty() const
  {
    return (size_ > 0) ? (false) : (true);
  }

  size_t size() const
  {
    return size_;
  }

  void push(const T value)
  {
    ++size_;
    std::vector<T> v;
    for (int i = 0; i < size_ - 1; i++)
    {
      v.push_back(pointer_[i]);
    }
    v.push_back(value);
    std::sort(v.begin(), v.end(), Compare());

    T *new_pointer = new T[v.size()];
    for (int i = 0; i < v.size(); i++)
    {
      new_pointer[i] = v.at(i);
    }
    delete[] pointer_;
    pointer_ = new_pointer;
  } //Function (push)

  void pop()
  {
    if (size_ > 0)
    {
      --size_;
      if (size_ == 0)
      {
        delete[] pointer_;
        pointer_ = nullptr;
      }
      else
      {
        T *new_pointer = new T[size_];
        for (int i = 0; i < size_; i++)
        {
          new_pointer[i] = pointer_[i];
        }
        delete[] pointer_;
        pointer_ = new_pointer;
      } //Condition (size_ == 0)
    }   //Condition(size_ > 0)
  }     //Function (pop)

  T &operator[](const int index)
  {
    return pointer_[index];
  }

private:
  size_t size_;
  T *pointer_;
};

#endif //Header Guard