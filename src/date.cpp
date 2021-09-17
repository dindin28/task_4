// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <task_4/date.h>

#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <iostream>

Date::Date()
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Date()" << std::endl;
#endif

  std::time_t now = std::time(nullptr);
  char buff[4];

  strftime(buff, sizeof(buff) + 1, "%d", std::localtime(&now));
  day_ = atoi(buff);

  strftime(buff, sizeof(buff) + 1, "%m", std::localtime(&now));
  month_ = atoi(buff);

  strftime(buff, sizeof(buff) + 1, "%Y", std::localtime(&now));
  year_ = atoi(buff);
}

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year)
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Date(int day, int month, int year)" << std::endl;
#endif
}

Date::Date(const Date &copy)
    : day_(copy.day_), month_(copy.month_), year_(copy.year_)
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "Date(const Date &copy)" << std::endl;
#endif
}

Date::~Date()
{
#ifdef SHOW_CONSTRUCTORS
  std::cout << "~Date()" << std::endl;
#endif
}

//Getters
int Date::GetDay() const { return day_; }
int Date::GetMonth() const { return month_; }
int Date::GetYear() const { return year_; }

//Selectors
Date &Date::SetDay(int day)
{
  day_ = day;
  return *this;
}

Date &Date::SetMonth(int month)
{
  month_ = month;
  return *this;
}

Date &Date::SetYear(int year)
{
  year_ = year;
  return *this;
}

void Date::Print()
{
  std::cout << std::setfill('0');
  std::cout << std::setw(2) << day_ << "/"
            << std::setw(2) << month_ << "/"
            << std::setw(4) << year_ << std::endl;
}

Date Date::operator+(const Date &obj)
{
  int _day = obj.day_ + day_;
  int _month = obj.month_ + month_;
  int _year = obj.year_ + year_;
  while (_month > 12)
  {
    _year++;
    _month -= 12;
  }
  int dayInYear = _day;
  _month--;
  while (_month > 0)
  {
    if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
    {
      _month--;
      dayInYear += 31;
      continue;
    }
    if ((_month == 2 && !IsYearLeap(_year)) || (_month == 2 && IsYearLeap(_year)))
    {
      _month--;
      if (IsYearLeap(_year))
      {
        dayInYear += 29;
      }
      else
      {
        dayInYear += 28;
      }
      continue;
    }
    if ((_month == 4 || _month == 6 || _month == 9 || _month == 11))
    {
      _month--;
      dayInYear += 30;
      continue;
    }
  }
  _month = 1;
  if ((dayInYear > 365 && !IsYearLeap(_year)) || (dayInYear > 366 && IsYearLeap(_year)))
  {
    _year++;
    if (IsYearLeap(_year))
    {
      dayInYear -= 366;
    }
    else
    {
      dayInYear -= 365;
    }
  }
  if (dayInYear > 31)
  {
    _month++;
    dayInYear -= 31;
  } //January
  if ((dayInYear > 28 && !IsYearLeap(_year)) || (dayInYear > 29 && IsYearLeap(_year)))
  {
    _month++;
    if (IsYearLeap(_year))
    {
      dayInYear -= 29;
    }
    else
    {
      dayInYear -= 28;
    }
  } //February
  if (dayInYear > 31)
  {
    _month++;
    dayInYear -= 31;
  } //March
  if (dayInYear > 30)
  {
    _month++;
    dayInYear -= 30;
  } //April
  if (dayInYear > 31)
  {
    _month++;
    dayInYear -= 31;
  } //May
  if (dayInYear > 30)
  {
    _month++;
    dayInYear -= 30;
  } //June
  if (dayInYear > 31)
  {
    _month++;
    dayInYear -= 31;
  } //July
  if (dayInYear > 31)
  {
    _month++;
    dayInYear -= 31;
  } //August
  if (dayInYear > 30)
  {
    _month++;
    dayInYear -= 30;
  } //September
  if (dayInYear > 31)
  {
    _month++;
    dayInYear -= 31;
  } //October
  if (dayInYear > 30)
  {
    _month++;
    dayInYear -= 30;
  } //November
  if (dayInYear > 31)
  {
    _month++;
    dayInYear -= 31;
  } //December
  return Date(dayInYear, _month, _year);
}

bool Date::IsYearLeap(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return true;
  return false;
} //Static Function (IsYearLeap)

bool Date::IsYearLeap()
{
  if ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0))
    return true;
  return false;
} //Function (IsYearLeap)

std::ostream &operator<<(std::ostream &out, const Date &obj)
{
  out << std::setfill('0');
  out << std::setw(2) << obj.day_ << "/"
      << std::setw(2) << obj.month_ << "/"
      << std::setw(4) << obj.year_;
  return out;
}

std::istream &operator>>(std::istream &in, Date &obj)
{
  std::cout << "Enter new day of date: ";
  in >> obj.day_;
  std::cout << "Enter new month of date: ";
  in >> obj.month_;
  std::cout << "Enter new year of date: ";
  in >> obj.year_;
  return in;
}

bool Date::operator==(const Date &obj)
{
  return (day_ == obj.day_ && month_ == obj.month_ && year_ == obj.year_);
}
bool Date::operator!=(const Date &obj)
{
  return !Date::operator==(obj);
}