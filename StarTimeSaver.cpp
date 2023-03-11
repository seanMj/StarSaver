#include <chrono>
#include <cstdlib>
#include <thread>
#include <exception>
#include <iostream>
void how_often_to_repeat(size_t level)
{
    if(level == 1)
    {
        //section of code taken from: https://en.cppreference.com/w/cpp/thread/sleep_for
        using namespace std::chrono_literals;
        std::cout << "Level 1 Sleeping ..." << '\n';
        std::this_thread::sleep_for(60000ms);
    }
    if(level == 2)
    {
        using namespace std::chrono_literals;
        std::cout << "Level 2 Sleeping ..." << '\n';
        std::this_thread::sleep_for(3600000ms);
    //add level for 1/2 a day updates for the user.
    }
    if(level == 3)
    {
        using namespace std::chrono_literals;
        std::cout << "Level 3 Sleeping ..." << '\n';
        std::this_thread::sleep_for(86400000ms);

    }
    else if(!(level >= 1) && !(level <=3)){

        throw std::logic_error("sorry wrong timing input");
    }
}


/*
*   Save copies of listed files, and checks for new additions every N minutes,
*   Using Pre-Selected options (Days/ Minutes/ Seconds), that will determine how often the program will run:
        [1]: n      T
        [2]: n      T
        [3]: n      T
        [4]: 1      minute
        [5]: 1      Hour
        [6]: 1      Day

    *------------------------------------------------------------------------------------

                    * get input
                    * if user selects StarTime, then the program will activate, sleeping for N
                    * M's checking how much time has passed
                    * if time N time has passed: 
                    * 
                        * Copy symboled files to location L
                        * if the Symboled files exist, update existing to location L
                        * if not, copy Symboled files to location L
                        * sleep N minutes.
                        * check if N minutes have passed
                        * return to top of loop, and start program, and again sleep after

*/