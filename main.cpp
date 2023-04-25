#include "utils.hpp"
#include "position.hpp"
#include "player.hpp"
#include "gameboard.hpp"
#include "controller.hpp"

int main(int argc, char**argv)
{
    if (argc == 0 && argv == 0)
        return 1;

    Player p1 = Player(); Player p2 = Player();
    Controller controller = Controller(3,3);
    controller.AddPlayer(p1);
    controller.AddPlayer(p2);
    controller.StartGame();

    int player = 0;
    system("cls");
    std::vector<Player> players = controller.players();
    print_game(players[0].positions(), players[1].positions());
    while (true)
    {
        int x, y;
        Position pos = Position(0,0);
        do
        {
            std::cin >> x >> y;
            pos = Position(x,y);
            if (controller.board().IsValidMove(pos))
                break;
            std::cout << "REPEAT" << std::endl;
        } while(true);

        controller.MakeMove(pos);

        system("cls");
            std::vector<Player> players = controller.players();
            print_game(players[0].positions(), players[1].positions());
        if (controller.IsHaveWinLine())
        {
            std::cout << (player == 0 ? "X WON" : "O WON") << std::endl;
            break;
        } else if (controller.IsGameOver())
        {
            std::cout << "NOBODY WON" << std::endl;
            break;
        }

        player = (player + 1) % 2;
    }
    
    
    return 0;
}