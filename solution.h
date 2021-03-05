#ifndef solution_h
#define solution_h
#include "BoardGame.h"

class solution{
private:    
	BoardGame * simulatorboard = NULL;
public:
    solution(BoardGame *board);
    int countAlive(int x , int y);
    int countCell(int x , int y);
    int getNextState(int x , int y);
    void fwd();
    void show_board();
    vector <pair <int , int> > get_result();
};
#endif