#ifndef BoardGame_h
#define BoardGame_h
#include <bits/stdc++.h>
using namespace std;


class BoardGame{
protected:
    vector <vector <int> > grid;
    int width , height;
    int row_start , col_start;
public:

    BoardGame(const BoardGame & obj);
    BoardGame(vector <pair <int , int> > cells , vector <int> row_range , vector <int> col_range);
    
    void preprocess_cells(vector <int> row_range , vector <int> col_range);
    void set_width(int width);
    void set_height(int height);
    int get_width();
    int get_height();

    void set_state(int x , int y , int state);
    int get_state(int x , int y);
    void set_rowstart(int r);
    void set_colstart(int c);
    int get_rowstart();
    int get_colstart();
    
    BoardGame copy();
};

#endif