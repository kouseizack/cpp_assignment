#include "BoardGame.h"

BoardGame::BoardGame(vector <pair <int , int> > cells , vector <int> row_range , vector <int> col_range)
{
	preprocess_cells(row_range , col_range);
    int rows = get_height();
    int cols = get_width();
    cout<<"grid size "<<rows<<" "<<cols<<endl;
    for(int i = 0; i < rows ; i++)
    {
        vector<int> layer(cols, 0);
        grid.push_back(layer);
    }

    int cell_size = cells.size();
    
    for(int j = 0; j < cell_size; j++)
    {   
        //seed cells should be shifted to accomodate for infinite grid hypothesis
        set_state(cells[j].first - this->row_start , cells[j].second - this->col_start , 1);
    }

    cout<<endl;   
    return;
}

BoardGame::BoardGame(const BoardGame & obj)
{
    width = obj.width;
    height = obj.height;
    row_start = obj.row_start;
    col_start = obj.col_start;
    for(int i = 0; i < height ; i++)
    {
        vector<int> layer(width, 0);
        grid.push_back(layer);
    }
    
}

BoardGame BoardGame::copy()
{
    BoardGame obj = *this;
	for (int x = 0; x < this->get_height(); x++) {
        for (int y = 0; y < this->get_width(); y++) {
            obj.set_state(x, y, this->get_state(x, y));
        }
	}
    cout<<grid.size()<<" "<<grid[0].size();
    return obj;
}

void BoardGame::preprocess_cells(vector <int> row_range , vector <int> col_range)
{
    int rows = row_range[1] - row_range[0];
    int cols = col_range[1] - col_range[0];
    row_start = row_range[0];
    col_start = col_range[0];
    set_width(cols + 1);
    set_height(rows + 1);
}

void BoardGame::set_width(int width){
    this->width = width;
}

void BoardGame::set_height(int height){
    this->height = height;
}

int BoardGame::get_width(){
    return this->width;
}

int BoardGame::get_height(){
    return this->height;
}

void BoardGame::set_state(int x , int y , int state)
{
    grid[x][y] = state;
}

int BoardGame::get_state(int x , int y)
{
    if(x < 0  || x >= this->height)
        return 0;
    if(y < 0  || y >= this->width)
        return 0;
	return this->grid[x][y];
}

int BoardGame::get_rowstart()
{
    return this->row_start;
}

int BoardGame::get_colstart()
{
    return this->col_start;
}

void BoardGame::set_rowstart(int r)
{
    this->row_start = r;
}
void BoardGame::set_colstart(int r)
{
    this->col_start = r;
}