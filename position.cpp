#include "position.hpp"

// Constructors
Position::Position(int x, int y)
    {
        this->position_x = x;
        this->position_y = y;
    }
Position::Position(const Position& position)
    {
        this->position_x = position.position_x;
        this->position_y = position.position_y;
    }

// Methods
int Position::x() const
    {
        return this->position_x;
    }
int Position::y() const
    {
        return this->position_y;
    }
void Position::x(int newX)
    {
        this->position_x = newX;
    }
void Position::y(int newY)
    {
        this->position_y = newY;
    }

// Operators
bool Position::operator== (const Position& otherPosition) const 
    {
        bool result = false;
        if (this == &otherPosition)
        {
            result = true;
        }
        else if (this->position_x == otherPosition.position_x && this->position_y == otherPosition.position_y)
        {
            result = true;
        }
        return result;
    }

bool Position::operator!= (const Position& otherPosition) const 
    {
        return !(*this == otherPosition);
    }

Position Position::operator=(const Position &other)
    {
        if (this != &other) // check for self-assignment
        {
            position_x = other.position_x;
            position_y = other.position_y;
        }
        return *this;
    }
