#ifndef _TASK_4_INCLUDE_TASK_4_PERFORMANCE_H_
#define _TASK_4_INCLUDE_TASK_4_PERFORMANCE_H_

#include <task_4/participant.h>

class Performance
{
public:
  Performance();
  Performance(bool performance_type, Participant participant, int sequence_number, int result);
  Performance(const Performance &copy);
  Performance &operator=(const Performance &copy);
  virtual ~Performance();

  //Getters
  bool GetPerformanceType() const;
  int GetNumberOfCompetitions() const;
  Participant GetParticipant() const;
  int GetSequenceNumber() const;
  int GetResult() const;

  //Selectors
  Performance &SetPerformanceType(bool performance_type);
  Performance &SetParticipant(Participant participant);
  Performance &SetSequenceNumber(int sequence_number);
  Performance &SetResult(int result);

  virtual void Print();

  friend std::ostream &operator<<(std::ostream &out, const Performance &obj);
  friend std::istream &operator>>(std::istream &in, Performance &obj);

  bool operator<(const Performance &obj);
  bool operator>(const Performance &obj);

private:
  // performance_type_= 0(false) => team performance
  // performance_type_= 1(true) => individual performance
  bool performance_type_;
  static int number_of_performance_;
  Participant participant_;
  int sequence_number_, result_;
}; //Class (Performance)

#endif //Header Guard