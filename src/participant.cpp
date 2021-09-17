// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <task_4/participant.h>

#include <cstring>
#include <string>

Participant::Participant()
    : date_(15, 8, 2002)
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Participant()" << std::endl;
#endif

  const char *name = "Dima";
  const char *surname = "Shtrikker";
  name_ = new char[strlen(name) + 1];
  surname_ = new char[strlen(surname) + 1];
  strcpy(name_, name);
  strcpy(surname_, surname);
}

Participant::Participant(const char *name, const char *surname, const Date &date)
    : date_(date)
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Participant(const char *name, const char *surname, const Date &date)" << std::endl;
#endif

  name_ = new char[strlen(name) + 1];
  surname_ = new char[strlen(surname) + 1];
  strcpy(name_, name);
  strcpy(surname_, surname);
}

Participant::Participant(const Participant &copy)
    : date_(copy.date_)
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Participant(const Participant &copy)" << std::endl;
#endif

  name_ = new char[strlen(copy.name_) + 1];
  surname_ = new char[strlen(copy.surname_) + 1];
  strcpy(name_, copy.name_);
  strcpy(surname_, copy.surname_);
}

Participant &Participant::operator=(const Participant &copy)
{
  if (this != &copy)
  {
    //Name
    if (strlen(name_) != 0)
    {
      delete[] name_;
    }
    name_ = new char[strlen(copy.name_) + 1];
    strcpy(name_, copy.name_);

    //Surname
    if (strlen(surname_) != 0)
    {
      delete[] surname_;
    }
    surname_ = new char[strlen(copy.surname_) + 1];
    strcpy(surname_, copy.surname_);

    //Date
    date_ = copy.date_;
  } //Condition(this != &copy)

  return *this;
}

Participant::~Participant()
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "~Participant()" << std::endl;
#endif

  if (strlen(name_) != 0)
  {
    delete[] name_;
  }
  if (strlen(surname_) != 0)
  {
    delete[] surname_;
  }
}

//Getters
const char *Participant::GetName() const { return name_; }
const char *Participant::GetSurname() const { return surname_; }
Date Participant::GetDate() const { return date_; }

//Selectors
Participant &Participant::SetName(const char *name)
{
  if (strlen(name_) != 0)
  {
    delete[] name_;
  }
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
  return *this;
}

Participant &Participant::SetSurname(const char *surname)
{
  if (strlen(surname_) != 0)
  {
    delete[] surname_;
  }
  surname_ = new char[strlen(surname) + 1];
  strcpy(surname_, surname);
  return *this;
}

Participant &Participant::SetDate(const Date &date)
{
  date_ = date;
  return *this;
}

void Participant::Print()
{
  std::cout << name_ << " "
            << surname_ << " ("
            << date_ << ")" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Participant &obj)
{
  out << obj.name_ << " "
      << obj.surname_ << " ("
      << obj.date_ << ")";
  return out;
}

std::istream &operator>>(std::istream &in, Participant &obj)
{
  std::string buff_string;

  //Name
  std::cout << "Enter new name of participant: ";
  in >> buff_string;

  if (strlen(obj.name_) != 0)
  {
    delete[] obj.name_;
  }
  obj.name_ = new char[buff_string.length() + 1];
  strcpy(obj.name_, buff_string.c_str());

  //Surname
  std::cout << "Enter new surname of participant: ";
  in >> buff_string;

  if (strlen(obj.surname_) != 0)
  {
    delete[] obj.surname_;
  }
  obj.surname_ = new char[buff_string.length() + 1];
  strcpy(obj.surname_, buff_string.c_str());

  //Date
  in >> obj.date_;

  return in;
}

bool Participant::operator==(const Participant &obj)
{
  return (strcmp(name_, obj.name_) == 0 &&
          strcmp(surname_, obj.surname_) == 0 &&
          date_ == obj.date_);
}
bool Participant::operator!=(const Participant &obj)
{
  return !Participant::operator==(obj);
}