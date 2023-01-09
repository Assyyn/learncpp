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
            static std::string name;
            std::cin >> name;

            return name;
        }
    };

    Player m_player{PlayerInit::create()};
    // to store player's name on the occassion that they try again.
    std::string_view playerName;
    int tries{1}; // to keep track of player retries

private:
    // ignore everything after this call until newline('\n')
    void ignoreLine();
    // get user's choice
    char getChoice();

    // player encounters a monster
    Monster encounterMonster();
    // player chooses to fight the monster after being prompted to @choose()
    void chooseToFight(Monster& monster);
    // fight logic: player turn
    void attackMonster(Monster& monster);
    // fight logic: monster turn
    void getAttacked(const Monster& monster);
    // player chooses to flee @choose()
    bool tryFleeing(Monster& monster);

    // main Game loop, Encounter()->choose()->...
    void fightMonster();

public:
    Game() { playerName = m_player.getName(); }

    // make Game non-copyable/assignable
    Game(const Game& game) = delete;
    Game operator=(const Game& game) = delete;

    // game loop handler
    void play();

    // to play a new game
    void reset()
    {
        m_player = Player{playerName};
        playerName = m_player.getName();
    }

    // prompt to choose to play again
    bool playAgain();
};

#endif