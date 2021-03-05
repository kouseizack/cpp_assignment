#include "GameEngine.h"
#include "solution.h"
#include "BoardGame.h"

using namespace std;

void GameEngine::StartGame()
{
    vector <pair <int , int> > cells;
    int n;
    cout<<"Enter the number of living cells"<<endl;
    cin>>n;
    cout<<"Enter co-ordinates for each cell"<<endl;
    vector <int> row_range;
    vector <int> col_range;
    int row_min = INT_MAX , col_min = INT_MAX;
    int row_max = INT_MIN , col_max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int curr_row , curr_col;
        cin>>curr_row>>curr_col;
        cells.push_back(make_pair(curr_row , curr_col));

        //GET THE EXTREMAS OF REQUIRED BOARD AS BOARD IS INFINITE
        row_min = min(row_min, curr_row);
        col_min = min(col_min, curr_col);
        row_max = max(row_max, curr_row);
        col_max = max(col_max, curr_col); 
    }
    row_range.insert(row_range.end(),{row_min - 1 , row_max + 1});
    col_range.insert(col_range.end(),{col_min - 1 , col_max + 1});

    this->board_game = new BoardGame(cells , row_range , col_range);
    this->simulator = new solution(board_game);
}

void GameEngine::next_step()
{
    if(board_game != NULL)
        this->simulator->fwd();
    else
        cout<<"INITIALIZE THE BOARD BEFORE STARTING SIMULATION"<<endl;
}

void GameEngine::show_state()
{
    if(board_game != NULL)
        this->simulator->show_board();
    else
        cout<<"INITIALIZE THE BOARD BEFORE STARTING SIMULATION"<<endl;
}

void GameEngine::show_live_cells()
{
    if(board_game != NULL)
    {
        vector <pair <int , int> > res = this->simulator->get_result();
        cout<<"Live cells at the moment: "<<endl;
        for(auto itr = res.begin() ; itr != res.end() ; itr++)
            cout<<itr->first<<", "<< itr->second<<endl;
        cout<<endl;
    }
    else
        cout<<"INITIALIZE THE BOARD BEFORE STARTING SIMULATION"<<endl;
}