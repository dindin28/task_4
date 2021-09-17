#ifndef _TASK_4_INCLUDE_TASK_4_COMPETITION_H_
#define _TASK_4_INCLUDE_TASK_4_COMPETITION_H_

#include <task_4/performance.h>
#include <task_4/participant.h>

class Competition : public Participant
{
public:
  Competition();
  Competition(const char *name);
  Competition(const char *name, Performance *performance_pointer, int performance_size);
  Competition(const char *name, Performance *performance_pointer, int performance_size, const char *par_name, const char *par_surname, const Date &par_date);
  Competition(const Competition &copy);
  Competition &operator=(const Competition &copy);
  virtual ~Competition();

  void AddPerformance(const Performance &performance);

  const char *GetCompetitionName() const;
  Competition &SetCompetitionName(const char *name);

  virtual void Print();
  virtual void PrintShortly();

  friend std::ostream &operator<<(std::ostream &out, const Competition &obj);
  friend std::istream &operator>>(std::istream &in, Competition &obj);

  Performance &operator[](const int index);

private:
  char *competition_name_;
  Performance *performance_pointer_;
  int performance_size_;
}; //Class (Competition)

#endif //Header Guard