#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "gameboard.hpp"
#include "player.hpp"
#include "position.hpp"
#include "hunteronlines.hpp"

class Controller
{
    // Variables
    public:
        const int max_players = 2;
        const int length_win_line = 3;
    private:
        GameBoard _gameBoard;
        std::vector<Player> _players;
        int _currentPlayerIndex;
    
    // Constructors
    public:
        Controller(int rows, int columns);
    
    // Methods
    public:
        void AddPlayer(const Player& player);
        void StartGame();
        bool MakeMove(const Position& position);
        bool IsHaveWinLine();
        bool IsGameOver() const;
        Player current_player() const;
        const std::vector<Player> players() const;
        Player winner() const;
        GameBoard board() const;
};

#endif // CONTROLLER_HPP_