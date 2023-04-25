#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include "exceptions.hpp"
#include "position.hpp"

class Player
{
    // Variables
    private:
    std::vector<Position> _positions;

    // Constructors
    public:
    Player();
    //Player(const Player& other);

    // Methods
    public:
    void MakeMove(const Position& newMove);
    const std::vector<Position> positions() const;
    int moves() const;

    // Operators
    //public:
    //Player operator=(const Player& other);
};

#endif // PLAYER_HPP_