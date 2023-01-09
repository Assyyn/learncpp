#ifndef GAME_H
#define GAME_H

// Game Class, the game contains('has-a') Creatures(specifically only a Player
// atm), and some logic on top The Game Instance will also then handle it's
// components

#include "Monster.h"
#include "Player.h"

#include <iostream>
#include <limits>
#include <string>
#include <string_view>

/* Game logic:
 The Game will continue until, A) Player died
                               B) Player reached lvl.20
 ----------------------------------------------------------------------------
 * #1 Create player
 * #2 Player encounters (random) Monster
 * #3 Player can choose to flee(Run) or fight:
 * ---A) Fleeing has a 1/2 chance of being successful
 * ------ If the player fails to flee, the Monster gets a free hit. Goto #3
 * ------ If fleeing is successful, Goto #2
 * ---B) Both entities take turns doing damage, with the Player going
 *                                                   first(until one is dead).
 * #4 If Player died, Game Over(Print stats and end).
 *      Else, Goto #2.
 ----------------------------------------------------------------------------
 */

class Game
{
private:
    // To initialize a player when constructing a Game, but not passing
    // parameters from outside
    struct PlayerInit
    {
        static inline std::string_view create()
        {
            std::cout << "Enter your name: ";
            std::string name;
            std::cin >> name;

            return name;
        }
    };

    Player m_player{PlayerInit::create()};

    // for @fightMonster()
    char getChoice()
    {
        char ch{'x'};
        while (!(ch == 'F' || ch == 'f' || ch == 'R' || ch == 'r'))
        {
            std::cout << "(R)un or (F)ight: ";
            std::cin >> ch;
        }

        ignoreLine();
        return ch;
    }

    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // player encounters a monster
    Monster encounterMonster()
    {
        Monster monster{Monster::getRandomMonster()};
        std::cout << "You have encountered a " << monster.getName() << '('
                  << monster.getSymbol() << ").\n";

        return monster;
    }

    /* #1 Encounter()
     * #2 choose(R or F:)
     *      - (F): fightMonster()
     *      - (R): tryFleeing(), success? #1 : #2
     */

    void fightMonster() // needs refactoring
    {
        Monster monster{encounterMonster()};

        while (!m_player.isDead())
        {
            char choice{getChoice()};

            if (choice == 'F' || choice == 'f')
            {
                while (!m_player.isDead() && !monster.isDead())
                {
                    attackMonster(monster);
                    getAttacked(monster);
                }
                return;
            }
            else if (choice == 'r' || choice == 'R')
            {
                if (getRandomNumber(0, 1))
                {
                    std::cout << "You successfully fled.\n";
                    return;
                }

                std::cout << "You failed to flee.\n";
                getAttacked(monster);
                break;
            }
        }
    }

    // Player chooses to fight @fightMonster() after encountering monster
    void attackMonster(Monster& monster)
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

    // Monster's turn to attack player
    void getAttacked(const Monster& monster)
    {
        if (monster.isDead())
            return;

        m_player.reduceHealth(monster.getDamage());
        std::cout << "The " << monster.getName() << " hit you for "
                  << monster.getDamage() << " damage.\n";
    }

public:
    Game() = default;
    Game(const Game& game) = delete;
    Game operator=(const Game& game) = delete;

    void play()
    {
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

    // to play a new game
    void reset() { m_player = Player{PlayerInit::create()}; }

    bool playAgain()
    {
        char ch{};
        while (true)
        {
            std::cout << "\nDo you want to play again?(Y/N): ";
            std::cin >> ch;

            if (ch == 'y' || ch == 'Y')
            {
                ignoreLine();
                return true;
            }
            if (ch == 'n' || ch == 'N')
            {
                ignoreLine();
                return false;
            }
        }
    }
};

#endif