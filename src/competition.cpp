// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <task_4/competition.h>

#include <cstring>
#include <string>

Competition::Competition()
    : performance_size_(0), performance_pointer_(nullptr), Participant(Participant())
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Competition()" << std::endl;
#endif

  const char *name = "Olympic Games";
  competition_name_ = new char[strlen(name) + 1];
  strcpy(competition_name_, name);
}

Competition::Competition(const char *name)
    : performance_size_(0), performance_pointer_(nullptr), Participant(Participant())
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Competition(const char *name)" << std::endl;
#endif

  competition_name_ = new char[strlen(name) + 1];
  strcpy(competition_name_, name);
}

Competition::Competition(const char *name, Performance *performance_pointer, int performance_size)
    : performance_size_(performance_size), Participant(Participant())
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Competition(const char *name, Performance *performance_pointer, int performance_size)" << std::endl;
#endif

  //copy name
  competition_name_ = new char[strlen(name) + 1];
  strcpy(competition_name_, name);

  //copy performance_pointer
  performance_pointer_ = new Performance[performance_size];
  for (int i = 0; i < performance_size; i++)
  {
    performance_pointer_[i] = performance_pointer[i];
  }
}

Competition::Competition(const char *name, Performance *performance_pointer, int performance_size, const char *par_name, const char *par_surname, const Date &par_date)
    : performance_size_(performance_size), Participant(par_name, par_surname, par_date)
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Competition(const char *name, Performance *performance_pointer, int performance_size, const char *par_name, const char *par_surname, const Date &par_date)"
            << std::endl;
#endif

  //copy name
  competition_name_ = new char[strlen(name) + 1];
  strcpy(competition_name_, name);

  //copy performance_pointer
  performance_pointer_ = new Performance[performance_size];
  for (int i = 0; i < performance_size; i++)
  {
    performance_pointer_[i] = performance_pointer[i];
  }
}

Competition::Competition(const Competition &copy)
    : performance_size_(copy.performance_size_), Participant(copy.GetName(), copy.GetSurname(), copy.GetDate())
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Competition(const Competition &copy)" << std::endl;
#endif

  //copy name
  competition_name_ = new char[strlen(copy.competition_name_) + 1];
  strcpy(competition_name_, copy.competition_name_);

  //copy performance_pointer
  performance_pointer_ = new Performance[copy.performance_size_];
  for (int i = 0; i < copy.performance_size_; i++)
  {
    performance_pointer_[i] = copy.performance_pointer_[i];
  }
}

Competition &Competition::operator=(const Competition &copy)
{
  if (this != &copy)
  {
    //Participant variables
    SetName(copy.GetName());
    SetSurname(copy.GetSurname());
    SetDate(copy.GetDate());

    //Name
    if (strlen(competition_name_) != 0)
    {
      delete[] competition_name_;
    }
    competition_name_ = new char[strlen(copy.competition_name_) + 1];
    strcpy(competition_name_, copy.competition_name_);

    //Performance pointer
    if (performance_size_ != 0)
    {
      delete[] performance_pointer_;
    }
    performance_pointer_ = new Performance[copy.performance_size_];
    for (int i = 0; i < copy.performance_size_; i++)
    {
      performance_pointer_[i] = copy.performance_pointer_[i];
    }

    //Performance size
    performance_size_ = copy.performance_size_;
  } //Condition (this != &copy)

  return *this;
}

Competition::~Competition()
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "~Competition()" << std::endl;
#endif

  if (strlen(competition_name_) != 0)
  {
    delete[] competition_name_;
  }
  if (performance_size_ != 0)
  {
    delete[] performance_pointer_;
  }
}

void Competition::AddPerformance(const Performance &performance)
{
  Performance *new_ptr = new Performance[performance_size_ + 1];
  for (int i = 0; i < performance_size_; i++)
  {
    new_ptr[i] = performance_pointer_[i];
  }
  new_ptr[performance_size_] = performance;
  if (performance_size_ != 0)
  {
    delete[] performance_pointer_;
  }
  performance_pointer_ = new_ptr;
  performance_size_++;
}

const char *Competition::GetCompetitionName() const { return competition_name_; }
Competition &Competition::SetCompetitionName(const char *name)
{
  if (strlen(competition_name_) != 0)
  {
    delete[] competition_name_;
  }
  competition_name_ = new char[strlen(name) + 1];
  strcpy(competition_name_, name);
  return *this;
}

void Competition::Print()
{
  Participant::Print();
  std::cout << competition_name_ << std::endl;
  for (int i = 0; i < performance_size_; i++)
  {
    std::cout << i + 1 << ". " << performance_pointer_[i] << std::endl;
  }
}

void Competition::PrintShortly()
{
  Participant::Print();
  std::cout << competition_name_ << std::endl;
  for (int i = 0; i < performance_size_; i++)
  {
    std::cout << i + 1 << ". " << performance_pointer_[i].GetParticipant().GetSurname() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const Competition &obj)
{
  //Participant out
  out << obj.GetName() << " "
      << obj.GetSurname() << " ("
      << obj.GetDate() << ")" << std::endl;

  //Competition out
  out << obj.competition_name_ << std::endl;
  for (int i = 0; i < obj.performance_size_; i++)
  {
    out << i + 1 << ") " << obj.performance_pointer_[i] << std::endl;
  }
  return out;
}

std::istream &operator>>(std::istream &in, Competition &obj)
{
  std::string buff_string;

  std::cout << "Enter new name of competition: ";
  in >> buff_string;

  if (strlen(obj.competition_name_) != 0)
  {
    delete[] obj.competition_name_;
  }
  obj.competition_name_ = new char[buff_string.length() + 1];
  strcpy(obj.competition_name_, buff_string.c_str());

  return in;
}

Performance &Competition::operator[](const int index)
{
  return performance_pointer_[index];
}