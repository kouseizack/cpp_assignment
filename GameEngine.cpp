#include "GameEngine.h"
#include "solution.h"
using namespace std;

void GameEngine::StartGame()
{
    vector <pair <int , int> > cells;
    int n;
    cout<<"Enter the number of living cells"<<endl;
    cin>>n;
    cout<<"Enter co-ordinates for each cell"<<endl;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin>>x>>y;
        cells.push_back(make_pair(x , y));
    }
    GameEngine::board_game = new solution(cells);
}

void GameEngine::next_step()
{
    if(board_game != NULL)
        GameEngine::board_game->step();
    else
        cout<<"INITIALIZE THE BOARD BEFORE STARTING SIMULATION"<<endl;
}

void GameEngine::show_state()
{
    if(board_game != NULL)
        GameEngine::board_game->show_board();
    else
        cout<<"INITIALIZE THE BOARD BEFORE STARTING SIMULATION"<<endl;
}

void GameEngine::show_live_cells()
{
    if(board_game != NULL)
        GameEngine::board_game->get_result();
    else
        cout<<"INITIALIZE THE BOARD BEFORE STARTING SIMULATION"<<endl;
}