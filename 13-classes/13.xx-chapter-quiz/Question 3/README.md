# Making a Monster Generator

## Instructions

- Create a new project folder called `monster-generator`.

1. First, let’s create an enumeration of monster types named MonsterType. Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. Add an additional max_monster_types enum so we can count how many enumerators there are.
2. Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): a type (MonsterType), a name (std::string), a roar (std::string), and the number of hit points (int). Create a Monster class that has these 4 member variables.
3. enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration. When the enum is inside the class, “MonsterType” can be renamed “Type” since the context is already Monster.
4. Create a constructor that allows you to initialize all of the member variables. The following program should compile:

```cpp
int main()
{
 Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };

 return 0;
}
```

5. Now we want to be able to print our monster so we can validate it’s correct. To do that, we’re going to need to write a function that converts a Monster::Type into a string. Write that function (called getTypeString()), as well as a print() member function. The following program should compile:

```cpp
int main()
{
 Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
 skeleton.print();

 return 0;
}
```

and print:

`Bones the skeleton has 4 hit points and says *rattle*`

6. Now we can create a random monster generator. Let’s consider how our MonsterGenerator class will work. Ideally, we’ll ask it to give us a Monster, and it will create a random one for us. We don’t need more than one MonsterGenerator. This is a good candidate for a static class (one in which all functions are static). Create a static MonsterGenerator class. Create a static function named generateMonster(). This should return a Monster. For now, make it return anonymous `Monster(Monster::Type::skeleton, "Bones", "*rattle*", 4);` The following program should compile:

```cpp
int main()
{
 Monster m{ MonsterGenerator::generateMonster() };
 m.print();

 return 0;
}
```

and print:

`Bones the skeleton has 4 hit points and says *rattle*`

7. Now, MonsterGenerator needs to generate some random attributes. To do that, we’ll need to make use of this handy function:

```cpp
// Generate a random number between min and max (inclusive)
static int getRandomNumber(int min, int max)
{
    // seed our random number generator with the current time
    static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    // distribute results from our RNG between min and max (inclusive)
    return std::uniform_int_distribution{ min, max }(mersenne);
}
```

However, because MonsterGenerator relies directly on this function, let’s put it inside the class, as a static function.

8. Now edit function generateMonster() to generate a random Monster::Type (between 0 and Monster::Type::max_monster_types-1) and a random hit points (between 1 and 100). This should be fairly straightforward. Once you’ve done that, define two static fixed arrays of size 6 inside the function (named s_names and s_roars) and initialize them with 6 names and 6 sounds of your choice. Pick a random name and roar from these arrays. The following program should compile:

```cpp
int main()
{
    for(int count{0}; count < 10; ++count)
    {
        MonsterGenerator::generateMonster().print();
        std::cin.get(); // wait for user to press enter
    }

    return 0;
}
```

That's it! You've created a monster generator!

check the solution at: [monster-generator](monster-generator/)
