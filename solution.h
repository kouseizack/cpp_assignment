#ifndef solution_h
#define solution_h
#include "BoardGame.h"

class solution : public BoardGame{
public:
    solution(vector <pair <int , int> > cells);
    void step();
    void show_board();
    void prepare_grid(vector <pair <int , int> > cells);
    void get_result();
};
#endif