#include "GameEngine.h"
#include "solution.h"
#include "BoardGame.h"

int main()
{
    GameEngine engine;
    engine.StartGame();
    
    engine.show_live_cells();
    engine.show_state();

    engine.next_step();
    engine.show_state();
    engine.show_live_cells();
    
    return 0;
}