// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <task_4/uses_priority_queue.h>

#include <functional>
#include <iostream>

template <typename T, class Compare = std::less<T>>
void QueueDemonstration()
{
  int ch = -1;
  uses_priority_queue<T, Compare> queue;
  while (ch != 0)
  {
    do
    {
      std::system("clear");
      for (int i = 0; i < queue.size(); i++)
      {
        std::cout << i + 1 << ") " << queue[i] << std::endl;
      }
      std::cout << "uses_priority_queue::empty(): " << (queue.empty() ? "true" : "false") << std::endl;
      std::cout << "uses_priority_queue::size(): " << queue.size() << std::endl;
      std::cout << std::endl;
      std::cout << "1)push()" << std::endl;
      std::cout << "2)pop()" << std::endl;
      std::cout << "0)exit" << std::endl;
      std::cin >> ch;
    } while (ch != 0 && ch != 1 && ch != 2);
    switch (ch)
    {
    case (1):
    {
      std::cout << "Enter new value: ";
      T variable;
      std::cin >> variable;
      queue.push(variable);
      break;
    }
    case (2):
    {
      queue.pop();
      break;
    }
    }
  }
}

int main()
{
  QueueDemonstration<int>();
  return 0;
}