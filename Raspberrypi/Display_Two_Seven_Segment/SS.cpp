#include <pigpio.h>
#include <unistd.h>
#include "SS.h"
SS::SS()
{

}
void SS::SevenSegmentInit(void)
{
    signed char i;
    for(i=0;i<7;i++)
    {
        gpioSetMode(SevenSegment_One_PORT[i],PI_OUTPUT);
        gpioSetMode(SevenSegment_Two_PORT[i],PI_OUTPUT);

    }
}
void SS::SevenSegmentDisplay(void)
{
   signed char i,j,k;
   for(k=0;k<10;k++)
   {
    for(i=0;i<10;i++)
    {
        for(j=0;j<7;j++)
        {
            gpioWrite(SevenSegment_One_PORT[j],((Seven_Segment[k]>>j)&1));
            gpioWrite(SevenSegment_Two_PORT[j],((Seven_Segment[i]>>j)&1));
        }
        usleep(500000);
    }
   } 
}