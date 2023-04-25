#ifndef GAMEBOARD_HPP_
#define GAMEBOARD_HPP_

#include <vector>
#include "position.hpp"

class GameBoard
{
    // Variables
    public:
        const Position board_start = Position(1,1);
    private:
        std::vector<Position> _board;
        int _rows;
        int _cols;
    
    // Constructors
    public:
        GameBoard(int rows, int cols);
    
    // Methods
    public:
        void AddPosition(const Position& newPosition);
        bool IsFull() const;
        bool IsValidMove(const Position& position) const;
        int rows();
        int columns();
};

#endif // GAMEBOARD_HPP_