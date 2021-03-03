#include "solution.h"
using namespace std;

solution::solution(vector <pair <int , int> > cells)
{
    int cell_size = cells.size();
    int row_min = INT_MAX , col_min = INT_MAX;
    int row_max = INT_MIN , col_max = INT_MIN;
    for(int i = 0; i < cell_size ; i++)
    {
        row_min = min(row_min, cells[i].first);
        col_min = min(col_min, cells[i].second);
        row_max = max(row_max, cells[i].first);
        col_max = max(col_max, cells[i].second);
    }
    row_min = row_min - 1;
    row_max = row_max + 1;
    col_min = col_min - 1;
    col_max = col_max + 1;
    int n = row_max - row_min;
    int m = col_max - col_min;
    row_start = row_min;
    col_start = col_min;
    set_width(m + 1);
    set_height(n + 1);
    
    solution::prepare_grid(cells);

}

void solution::prepare_grid(vector <pair <int , int> > cells)
{
    int rows = solution::get_height();
    int cols = solution::get_width();
    cout<<"grid size "<<rows<<" "<<cols<<endl;
    for(int i = 0; i < rows ; i++)
    {
        vector<int> s(cols, 0);
        grid.push_back(s);
    }
    int cell_size = cells.size();
    cout<<"input cells----->"<<endl;
    for(int j = 0; j < cell_size; j++)
    {   
        cout<<cells[j].first<<" "<<cells[j].second<<endl;
        int shifted_x = cells[j].first - row_start;
        int shifted_y = cells[j].second - col_start;
        grid[shifted_x][shifted_y] = 1;
    }
    //debug grid
    cout<<endl;
    
    return;
}

void solution::show_board()
{
    cout<<"Shifted Grid at current time step "<<endl;
    cout<<endl;
    for(int i = 0; i < grid.size() ; i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}

void solution::step()
{
    if(grid.empty() or grid[0].empty()) return;
        std::vector<std::vector<int> > directions = 
        {{1, 1}, {1, 0}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 1}};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int countLive = 0;
                for(auto &dir: directions){
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size()) continue;
                    if(grid[x][y] & 1 == 1) countLive++; 
                }
                int state = grid[i][j] & 1;
                if(state == 0){
                    if(countLive == 3) state = 1;
                }
                else{
                    if(countLive < 2 or countLive > 3) state = 0;
                }
                grid[i][j] += (state << 1);
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                grid[i][j] >>= 1;
            }
        }
}

void solution::get_result()
{
    vector <pair <int , int> > res;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) 
        {
            if(grid[i][j])
            {
                int x = i + row_start;
                int y = j + col_start;
                res.push_back(make_pair(x , y));
            }
        }
    }
    cout<<"Live cells at the moment: "<<endl;
    for(auto itr = res.begin() ; itr != res.end() ; itr++)
        cout<<itr->first<<", "<< itr->second<<endl;
    return;
}