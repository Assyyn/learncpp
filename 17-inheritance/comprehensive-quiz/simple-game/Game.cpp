#include "Game.h"

char Game::getChoice()
{
    char ch{' '};
    while (!(ch == 'F' || ch == 'f' || ch == 'R' || ch == 'r'))
    {
        std::cout << "(R)un or (F)ight: ";
        std::cin >> ch;
    }

    ignoreLine();
    return ch;
}

void Game::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Monster Game::encounterMonster()
{
    Monster monster{Monster::getRandomMonster()};
    std::cout << "You have encountered a " << monster.getName() << '('
              << monster.getSymbol() << ").\n";

    return monster;
}

void Game::chooseToFight(Monster& monster)
{
    while (!m_player.isDead() && !monster.isDead())
    {
        attackMonster(monster);
        getAttacked(monster);
    }

    return;
}

bool Game::tryFleeing(Monster& monster)
{
    // has 1/2 chance to flee
    if (getRandomNumber(0, 1))
    {
        std::cout << "You have successfully fled.\n";
        return true;
    }

    // failed, Monster gets free hit, prompted to choose again
    std::cout << "You failed to flee.\n";
    getAttacked(monster);
    return false;
}

void Game::fightMonster()
{
    Monster monster{encounterMonster()};

    while (!m_player.isDead() && !monster.isDead())
    {
        char choice{getChoice()};
        if (choice == 'f' || choice == 'F')
        {
            chooseToFight(monster);
            return;
        }
        else if (choice == 'r' || choice == 'R')
        {
            if (tryFleeing(monster)) // if successfully fled, return. else
                                     // choose again
                return;
        }
    }
}

void Game::attackMonster(Monster& monster)
{
    // if the player is already dead...
    if (m_player.isDead())
        return;

    monster.reduceHealth(
        m_player.getDamage()); // hit monster for player's damage

    std::cout << "You hit the " << monster.getName() << " for "
              << m_player.getDamage() << " damage.\n";

    if (monster.isDead())
    {
        std::cout << "You defeated the " << monster.getName() << ".\n";
        m_player.levelUp();
        std::cout << "You are now level " << m_player.getLevel() << ".\n";
        std::cout << "You found " << monster.getGold() << " gold.\n";
        m_player.addGold(monster.getGold());
    }
}

void Game::getAttacked(const Monster& monster)
{
    if (monster.isDead())
        return;

    m_player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " hit you for "
              << monster.getDamage() << " damage.\n";
}

bool Game::playAgain()
{
    char ch{};
    while (true)
    {
        std::cout << "\nDo you want to play again?(Y/N): ";
        std::cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            ignoreLine();
            ++tries;
            return true;
        }
        if (ch == 'n' || ch == 'N')
        {
            ignoreLine();
            return false;
        }
    }
}

void Game::play()
{
    if (tries > 1)
        std::cout << "\nHello again, Adventurer " << playerName << '\n';

    while (!m_player.isDead() && m_player.getLevel() < 20)
        fightMonster();

    if (m_player.isDead())
        std::cout << "You died at level " << m_player.getLevel() << " with "
                  << m_player.getGold() << " gold.\n"
                  << "Too bad you can't take it with you!\n";
    else
        std::cout << "You won with " << m_player.getGold() << " gold.\n"
                  << "Remaining HP: " << m_player.getHealth() << '\n';
}