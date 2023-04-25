#ifndef HUNTER_ON_LINES_HPP_
#define HUNTER_ON_LINES_HPP_

#include <vector>
#include "position.hpp"

class HunterOnLines
{
    // Variables
    private:
        const std::vector<Position>& _playerMoves;
        int _lengthWinLine;
        std::vector<std::vector<Position>> _winningLines;

    // Constructors
    public:
        HunterOnLines(const std::vector<Position>& playerMoves, int lengthWinLine);

    // Methods
    public:
        void Hunt(const Position& newMove);
        const std::vector<std::vector<Position>>& winningLines() const;
};

#endif // HUNTER_ON_LINES_HPP_
