#include "solution.h"
#include "BoardGame.h"

using namespace std;

solution::solution(BoardGame *board)
{
    this->simulatorboard = board;
}

int solution::countAlive(int x, int y)
{
    int count = 0;
    count += countCell(x - 1, y - 1);
    count += countCell(x, y - 1);
    count += countCell(x + 1, y - 1);

    count += countCell(x - 1, y);
    count += countCell(x + 1, y);

    count += countCell(x - 1, y + 1);
    count += countCell(x, y + 1);
    count += countCell(x + 1, y + 1);

    return count;
}

int solution::countCell(int x, int y)
{
    if (this->simulatorboard->get_state(x, y) == 1)
        return 1;
    else
        return 0;
}

int solution::getNextState(int x, int y)
{
    int aliveNeighbours = countAlive(x, y);
    if (this->simulatorboard->get_state(x, y) == 1)
    {
        if (aliveNeighbours < 2)
            return 0;
        else if (aliveNeighbours == 2 || aliveNeighbours == 3)
            return 1;
        else if (aliveNeighbours > 3)
            return 0;
    }
    else
    {
        if (aliveNeighbours == 3)
            return 1;
    }
    return 0;
}

void solution::fwd()
{
    BoardGame nextState = simulatorboard->copy();

    for (int x = 0; x < simulatorboard->get_height(); x++)
    {
        for (int y = 0; y < simulatorboard->get_width(); y++)
        {
            int newState = getNextState(x, y);
            nextState.set_state(x, y, newState);
        }
    }
    *(this->simulatorboard) = nextState;
}

void solution::show_board()
{
    cout << "Shifted Grid at current time step " << endl;

    cout << endl;
    for (int i = 0; i < this->simulatorboard->get_height(); i++)
    {
        for (int j = 0; j < this->simulatorboard->get_width(); j++)
            cout << this->simulatorboard->get_state(i, j) << " ";
        cout << endl;
    }
    cout<<endl;
}

vector<pair<int, int>> solution::get_result()
{
    vector<pair<int, int>> res;
    
    for (int i = 0; i < this->simulatorboard->get_height(); i++)
    {
        for (int j = 0; j < this->simulatorboard->get_width(); j++)
        {
            if (this->simulatorboard->get_state(i, j) == 1)
            {
                int x = i + this->simulatorboard->get_rowstart();
                int y = j + this->simulatorboard->get_colstart();
                res.push_back(make_pair(x, y));
            }
        }
    }
    return res;
}