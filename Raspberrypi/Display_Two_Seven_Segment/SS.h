#ifndef SS_H
#define SS_H
class SS
{
    private:
    const char Seven_Segment[10]={
        0b00111111,//0
        0b00000110,//1
		0b01011011,//2
		0b01001111,//3
		0b01100110,//4
		0b01101101,//5
		0b01111101,//6
		0b00000111,//7
		0b01111111,//8
		0b01101111//9
    };
    const char SevenSegment_One_PORT[7]={2,3,4,17,27,22,10};
    const char SevenSegment_Two_PORT[7]={14,15,18,23,24,25,8};
    public:
    SS();
    void SevenSegmentInit(void);
    void SevenSegmentDisplay(void);
};
#endif