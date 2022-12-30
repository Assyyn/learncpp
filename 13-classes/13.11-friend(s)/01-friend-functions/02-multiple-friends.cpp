#include <iostream>

// functions can be friends of more than one class

// forward declaration so the compiler knows that we are going to define Time
// later
class Time;

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day) :
        m_year{year}, m_month{month}, m_day{day}
    {}

    // named the Time variable taime cos idk if there will be namespace
    // collisions with some C keyword(apparently not, but its hilarious so fine)
    friend void printDateAndTime(const Date& date, const Time& taime);
};

class Time
{
private:
    int m_hour{};
    int m_minute{};
    int m_second{};

public:
    Time(int hour, int minute, int second) :
        m_hour{hour}, m_minute{minute}, m_second{second}
    {}

    friend void printDateAndTime(const Date& date, const Time& taime);
};

// is a friend to both Date and Time classes
void printDateAndTime(const Date& date, const Time& time)
{
    std::cout << "Today's Date: " << date.m_year << '/' << date.m_month << '/'
              << date.m_day << '\n';

    std::cout << "Time: " << time.m_hour << ':' << time.m_minute << ':'
              << time.m_second << '\n';
}

int main()
{
    Date today{2022, 12, 30};
    Time rightNow{21, 40, 35};

    printDateAndTime(today, rightNow);

    return 0;
}