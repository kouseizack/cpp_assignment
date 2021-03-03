#ifndef GameEngine_h
#define GameEngine_h

#include "BoardGame.h"
#include "solution.h"
class GameEngine
{
private:
    BoardGame * board_game = NULL;
public:
    void StartGame();
    void next_step();
    void show_state();
    void show_live_cells();
};

#endif