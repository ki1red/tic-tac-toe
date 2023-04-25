#include "HunterOnLines.hpp"

// Constructors
HunterOnLines::HunterOnLines(const std::vector<Position>& playerMoves, int lengthWinLine)
    : _playerMoves(playerMoves), _lengthWinLine(lengthWinLine) 
    {}

// Methods
void HunterOnLines::Hunt(const Position& newMove)
    {
        _winningLines.clear();

        int x = newMove.x();
        int y = newMove.y();

        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if (dx == 0 && dy == 0) continue;

                std::vector<Position> line;
                for (int i = 0; i < _lengthWinLine; i++)
                {
                    int new_x = x + i*dx;
                    int new_y = y + i*dy;
                    Position pos(new_x, new_y);

                    auto it = std::find(_playerMoves.begin(), _playerMoves.end(), pos);
                    if (it == _playerMoves.end())
                    {
                        line.clear();
                        break;
                    }
                    else
                    {
                        line.push_back(pos);
                    }
                }
                
                if (line.size() == static_cast<std::size_t>(_lengthWinLine))
                {
                    _winningLines.push_back(line);
                }
            }
        }
    }
const std::vector<std::vector<Position>>& HunterOnLines::winningLines() const
    {
        return _winningLines;
    }
