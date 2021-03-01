#include <bits/stdc++.h>
using namespace std;

class solution{
    vector <vector <int> > grid;
    //vector <pair <int , int>> cell_list;
    int row_start , col_start;
    public:
        solution(vector <pair <int , int> > cells);
        void update_grid();
        void prepare_grid(int n , int m , 
                          vector <pair <int , int> > cells);
        vector <pair <int , int> > get_result();
    
};

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
        col_max = max(col_max , cells[i].second);
    }
    row_min = row_min - 1;
    row_max = row_max + 1;
    col_min = col_min - 1;
    col_max = col_max + 1;
    int n = row_max - row_min;
    int m = col_max - col_min;
    row_start = row_min;
    col_start = col_min;
    cout<<"grid size "<<n+1<<" "<<m+1<<endl;
    prepare_grid(n + 1 , m + 1 , cells);

}

void solution::prepare_grid(int n , int m , 
                            vector <pair <int , int> > cells)
{
    for(int i = 0; i < n ; i++)
    {
        vector<int> s(m, 0);
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
    cout<<"Shifted Grid at time step 0"<<endl;
    cout<<endl;
    for(int i = 0; i < grid.size() ; i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    return;
}

void solution::update_grid()
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

vector <pair <int , int> > solution::get_result()
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
    return res;
}

int main()
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

    solution obj(cells);
    obj.update_grid();
    vector <pair <int , int> > res = obj.get_result();
    cout<<endl;
    cout<<"Final live cells at next time step: "<<endl;
    for(auto itr = res.begin() ; itr != res.end() ; itr++)
        cout<<itr->first<<", "<< itr->second<<endl;
    
    return 0;
}

