#include "messenger.h"

int main()
{
    messenge mess;
    // thread to check if user's typed q+enter to quit
    std::thread hasQuit(&messenge::quitYet, &mess);
    hasQuit.join();
    
    return 0;
}
