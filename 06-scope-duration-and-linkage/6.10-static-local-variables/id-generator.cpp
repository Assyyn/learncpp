#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class User
{
public:
    User(std::string &user) // default constructor
        : username{user}, playerID{generateID()}
    {
    }

    int myID() const { return playerID; }
    std::string_view myUsername() const { return username; }

private:
    int playerID{};
    std::string username{};

    int generateID() // generate 'unique' playerID, status: incomplete
    {
        static int s_playerID{1e5};
            return s_playerID ++;
    }

    int RandInt()
    {
        srand(time(0));
        return rand();
    }

    const int maxIDlimit {2e6};
};

User newUser() // make new user account
{
    std::cout << "username: ";
    std::string newUsername;
    std::cin >> newUsername;
    return User(newUsername);
}

void updatePlayerDatabase(const User &newUser, std::vector<User> &playerInfo);

int main()
{
    static std::vector<User> users;

    for (int i = 0; i < 10; ++i)
        updatePlayerDatabase(newUser(), users);

    for (auto &x : users)
    {
        std::cout << "username: " << x.myUsername() << '\n';
        std::cout << "ID: " << x.myID() << '\n';
    }
    return 0;
}

void updatePlayerDatabase(const User &newUser, std::vector<User> &playerInfo)
{
    playerInfo.push_back(newUser);
}