#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "exceptions.hpp"

class Position
{
    // Variables
    private:
    int position_x;
    int position_y;

    // Constructors
    public:
    Position(int x, int y);
    Position(const Position& position);

    // Methods
    public:
    int x() const;
    int y() const;
    void x(int newX);
    void y(int newY);

    // Operators
    bool operator== (const Position& otherPosition) const;
    bool operator!= (const Position& otherPosition) const;
    Position operator=(const Position& other);
};

#endif // POSITION_HPP_