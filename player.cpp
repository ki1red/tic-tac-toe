#include "player.hpp"

// Constructors
Player::Player()
    {}

// Player::Player(const Player& other)
//     {
//         this->_positions = other._positions;
//     }

// Methods
void Player::MakeMove(const Position& newMove)
    {
        _positions.push_back(newMove);
    }

const std::vector<Position> Player::positions() const
    {
        return _positions;
    }

int Player::moves() const
    {
        return _positions.size();
    }

// Player Player::operator=(const Player &other)
//     {
//         if (this != &other) // check for self-assignment
//         {
//             _positions = other._positions;
//         }
//         return *this;
//     }

// Methods
