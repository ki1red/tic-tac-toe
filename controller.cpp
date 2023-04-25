#include "controller.hpp"

// Constructors
Controller::Controller(int rows, int columns)
    : _gameBoard(rows, columns)
    {}

// Methods
void Controller::AddPlayer(const Player& player)
    {
        int size = _players.size();
        if (size > max_players)
        {
            throw InvalidNumbersException("PLAYERS ARE MUCH");
        }

        _players.push_back(player);
    }

void Controller::StartGame()
    {
        int size = _players.size();
        if (size > max_players || size <= 1)
        {
            throw InvalidNumbersException();
        }

        _currentPlayerIndex = 0;
    }

bool Controller::MakeMove(const Position& position)
    {
        bool result;
        if (_gameBoard.IsValidMove(position))
        {
            _currentPlayerIndex = (_currentPlayerIndex + 1) % _players.size();
            Player& currentPlayer = _players[_currentPlayerIndex];
            currentPlayer.MakeMove(position);
            _gameBoard.AddPosition(position);
            result = true;
        }
        else
        {
            result = false;
        }
        return result;
    }

    bool Controller::IsHaveWinLine()
    {
        bool result = false;
        const Player& player = _players[_currentPlayerIndex];

        if (player.moves() >= length_win_line)
        {
            std::vector<Position> positions = player.positions();
            HunterOnLines hunter(positions, length_win_line);
            const Position position = positions.back();
            hunter.Hunt(position);
            const std::vector<std::vector<Position>> win_line = hunter.winningLines();
            if (win_line.size() > 0)
            {
                result = true;
            }
        }
        return result;
    }

bool Controller::IsGameOver() const
    {
        return _gameBoard.IsFull();
    }

Player Controller::current_player() const
    {
        return _players[_currentPlayerIndex];
    }

const std::vector<Player> Controller::players() const
    {
        return _players;
    }

Player Controller::winner() const
    {
        Player winPlayer;
        int maxMoves = -1;

        for (const Player& player : _players)
        {
            int moves = player.moves();
            if (moves > maxMoves)
            {
                maxMoves = moves;
                winPlayer = player;
            }
        }

        return winPlayer;
    }

GameBoard Controller::board() const
    {
        return _gameBoard;
    }
