// An access function is a short public function whose job is to retrieve or
// change the value of a private member variable

// Examples:
class MyString
{
private:
    char* m_string; // we'll dynamically allocate our string here
    int m_length;   // we need to keep track of the string length

public:
    int getLength()
    {
        return m_length;
    } // access function to get value of m_length
};

// Getters are functions responsible for retrieving value of private member
// variables
// Setters are responsible for setting value of private member variables

// A sample class that has getters and setters
class Date
{
private:
    int m_month;
    int m_day;
    int m_year;

public:
    int getMonth()
    {
        return m_month;
    } // getter for month
    void setMonth(int month)
    {
        m_month = month;
    } // setter for month

    int getDay()
    {
        return m_day;
    } // getter for day
    void setDay(int day)
    {
        m_day = day;
    } // setter for day

    int getYear()
    {
        return m_year;
    } // getter for year
    void setYear(int year)
    {
        m_year = year;
    } // setter for year
};

// Getters should provide “read-only” access to data. Therefore, the best
// practice is that they should return by value or const reference (not by
// non-const reference).