// an example of a user(program)-defined Fraction type:
// This only defines what a Fraction type looks like, it doesn't create one
struct Fraction
{
  int numerator{};
  int denominator{};
};

int main()
{
  Fraction f{3, 4}; // this actually instantiates a Fraction object named f

  return 0;
}

// By convention, program-defined types are named starting with a capital letter
// and don't use a suffix
