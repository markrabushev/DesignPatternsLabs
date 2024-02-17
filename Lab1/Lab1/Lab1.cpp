#include <iostream>
#include "BusStation.h"
#include "Board.h"
using namespace std;


int main()
{
    BusStation* BS = new BusStation();
    auto BT = BoardTaxi();
    auto BB = BoardBus();
    for (int i = 0; i < 180; i++)
    {
        BS->passengers.push_back(BT.BoardPassenger());
    }
    for (int i = 0; i < 4; i++)
    {
        BS->drivers.push_back(BT.BoardDriver());
    }
    for (int i = 0; i < 3; i++)
    {
        BS->drivers.push_back(BB.BoardDriver());
    }
    cout << BS->passengersCount() << endl;

    for (int i = 0; i < BS->drivers.size(); i++)
    {
        if (BS->drivers[i]->licenze == Licenze::BCategory)
        {
            BS->passengers.erase(BS->passengers.begin(), BS->passengers.begin() + 4);
        }
        else
        {
            BS->passengers.erase(BS->passengers.begin(), BS->passengers.begin() + 30);
        }
    }

    cout << BS->passengersCount() << endl;


}

