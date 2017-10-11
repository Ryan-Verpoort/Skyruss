//#include "Interface.h"
#include "GameLogic.h"

int main()
{

    while(true) {
	GameLogic logic{};
	logic.run();
    }

    return 0;
}
