#include "position.hpp"
#include <vector>

void print_game(std::vector<Position> positions_player_first, std::vector<Position> positions_player_second);

void print_game(std::vector<Position> positions_player_first, std::vector<Position> positions_player_second)
{
    // Loop through all positions on the game board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Position current_position(i+1, j+1);

            // Check if the current position was played by the first player
            auto it_first = std::find(positions_player_first.begin(), positions_player_first.end(), current_position);
            if (it_first != positions_player_first.end())
            {
                std::cout << "O";
                continue;
            }

            // Check if the current position was played by the second player
            auto it_second = std::find(positions_player_second.begin(), positions_player_second.end(), current_position);
            if (it_second != positions_player_second.end())
            {
                std::cout << "X";
                continue;
            }

            // If no player has played this position, print a hashtag
            std::cout << "#";
        }
        std::cout << std::endl;
    }
}
