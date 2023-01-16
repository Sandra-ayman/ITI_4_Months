#include <pigpio.h>
#include <unistd.h>
#include "SS.h"
SS::SS()
{

}
void SS::SevenSegmentInit(void)
{
    signed char i;
    for(i=0;i<8;i++)
    {
        gpioSetMode(Seven_Segment_PORT[i],PI_OUTPUT);
    }
}
void SS::SevenSegmentDisplay(void)
{
   signed char i,j;
   for(i=0;i<10;i++)
   {
    for(j=0;j<7;j++)
    {
        gpioWrite(Seven_Segment_PORT[j],((Seven_Segment[i]>>j)&1));
    }
    usleep(500000);
   } 
}