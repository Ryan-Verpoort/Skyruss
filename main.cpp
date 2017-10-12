//#include "Interface.h"
#include "GameLogic.h"

int main()
{

    while(true) {
	GameLogic logic{};
	logic.Run();
    }

    return 0;
}
