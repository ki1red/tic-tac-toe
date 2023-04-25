#include "gameboard.hpp"

// Constructors
GameBoard::GameBoard(int rows, int cols)
    : _rows(rows), _cols(cols)
    {}

// Methods
void GameBoard::AddPosition(const Position &newPosition)
    {
        if (IsFull())
        {
            throw BeyondException("BOARD IS FULL");
        }
        else if (!IsValidMove(newPosition))
        {
            throw BeyondException();
        }
        _board.push_back(newPosition);
    }
bool GameBoard::IsFull() const
    {
        bool result = false;

        size_t size_board = (_rows * _cols);
        if (_board.size() == size_board)
            result = true;
        return result;
    }
bool GameBoard::IsValidMove(const Position& position) const
    {
        bool result = true;
        if (position.x() > _cols + 1 || position.x() < board_start.x())
        {
            result = false;
        }
        else if (position.y() > _rows + 1 || position.y() < board_start.y())
        {
            result = false;
        }
        else if (std::find(_board.begin(), _board.end(), position) != _board.end())
        {
            result = false;
        }
        return result;
    }

int GameBoard::rows()
    {
        return _rows;
    }

int GameBoard::columns()
    {
        return _cols;
    }
