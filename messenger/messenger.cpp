#include "messenger.h"

messenge::messenge()
{
    std::thread updateMess(&messenge::set_msg, this);
    updateMess.detach();
}

void messenge::set_msg()
{
    while (true)
    {
        std::ifstream theFile;
        theFile.open("to_cpp.txt");
        
        char ch;
        std::string updated;

        while (theFile.get(ch))
        {   // retrieves the file's contents
            updated += ch;
        }   // if msg isn't updated, no need to print anything
            // if there's a new message in file (that isn't
        if (msg != updated && updated != "")
        {   // just an empty string), update msg and print it
            msg = updated;
            std::cout << get_msg() << std::endl;
        }
        // sleeps thread for 1 second before checking again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

std::string messenge::get_msg() const
{   // accessor fcn for msg
    return msg;
}

bool messenge::quitYet() const
{
    while (std::cin.get() != 'q')
    {   // keep going til you get a q
    
    }
    // fcn/thread runs until q+enter is typed
    return true;
}
