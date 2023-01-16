#include <iostream>
#include <pigpio.h>
#include "SS.h"
using namespace std;

int main(void)
{
    if(gpioInitialise() < 0)
    {
        return 1;
    }
    SS mySevenSegment;
    mySevenSegment.SevenSegmentInit();
    while(1)
    {
        mySevenSegment.SevenSegmentDisplay();
    }
}