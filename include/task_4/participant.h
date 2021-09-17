#ifndef _TASK_4_INCLUDE_TASK_4_PARTICIPANT_H_
#define _TASK_4_INCLUDE_TASK_4_PARTICIPANT_H_

#include <iostream>

#include <task_4/date.h>

class Participant
{
public:
  Participant();
  Participant(const char *name, const char *surname, const Date &date);
  Participant(const Participant &copy);
  Participant &operator=(const Participant &copy);
  virtual ~Participant();

  //Getters
  const char *GetName() const;
  const char *GetSurname() const;
  Date GetDate() const;

  //Selectors
  Participant &SetName(const char *name);
  Participant &SetSurname(const char *surname);
  Participant &SetDate(const Date &date);

  virtual void Print();

  friend std::ostream &operator<<(std::ostream &out, const Participant &obj);
  friend std::istream &operator>>(std::istream &in, Participant &obj);

  bool operator==(const Participant &obj);
  bool operator!=(const Participant &obj);

private:
  char *name_, *surname_;
  Date date_;
}; //Class (Participant)

#endif //Header Guard