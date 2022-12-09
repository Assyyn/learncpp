// some examples of using enumerations to improve code documentation and readability

/****************************************************************/

// Representing sets of related constants:

enum DaysOfWeek // enumeration to represent days of the week
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

enum CardinalDirections
{
    north,
    south,
    east,
    west,
};

enum Sex
{
    male,
    female,
};

enum CardSuits
{
    clubs,
    diamonds,
    spades,
    hearts,
};

/****************************************************************/

// returning status codes from functions

bool openFile();  // function to open file
bool readFile();  // function to read from file
bool parseFile(); // function to parse file contents

enum FileReadResult
{
    readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,
};

FileReadResult readFileContents() // easy to understand errors
{
    if (!openFile())
        return readResultErrorFileOpen;
    if (!readFile())
        return readResultErrorFileRead;
    if (!parseFile())
        return readResultErrorFileParse;

    return readResultSuccess;
}

void doSomething()
{
    if (readFileContents() == readResultSuccess)
    {
        // do something
    }
    else
    {
        // print error message accordingly
    }
}

/****************************************************************/

// In games with a small set of related objects, eg. items and clothes

enum ItemType
{
    weapon,
    potion,
    torch,
    nothing,
};

enum Clothes
{
    naked,
    armor,
    suit,
};

void defaultPlayerStatus(ItemType holding, Clothes wearing)
{
    holding = nothing;
    wearing = naked;
}

/****************************************************************/

// function parameters when the user needs to make choices

enum SortOrder
{
    alphabetical,
    alphabeticalReverse,
    numerical,
};

void sortData(SortOrder order)
{
    if (order == alphabetical)
    {
        // sort data in forwards alphabetical order
    }
    else if (order == alphabeticalReverse)
    {
        // sort data in backwards alphabetical order
    }
    else if (order == numerical)
    {
        // sort data numerically
    }
}

/****************************************************************/