#include <string>

// we can overload a function so that it behaves differently when its const and
// when its not
class Something
{
private:
    std::string m_value{};

public:
    Something(const std::string& value = "") : m_value{value} {}

    const std::string& getValue() const
    {
        return m_value;
    } // getValue() for const objects (returns const reference)
    std::string& getValue()
    {
        return m_value;
    } // getValue() for non-const objects (returns non-const reference)
};

int main()
{
    // we get two different behavior when we need them by overloading functions
    // based on 'const'
    Something s{};
    s.getValue() = "Changed"; // changed

    const Something y{};
    y.getValue() = "Changed"; // cannot change

    return 0;
}