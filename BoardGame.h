#include <bits/stdc++.h>
using namespace std;
#ifndef BoardGame_h
#define BoardGame_h
class BoardGame{
protected:
    vector <vector <int> > grid;
    int width , height;
    int row_start , col_start;

public:
    virtual void step(){};
    virtual void show_board(){};
    virtual void get_result(){};

    void set_width(int width);
    void set_height(int height);
    
    int get_width();
    int get_height();
};

#endif