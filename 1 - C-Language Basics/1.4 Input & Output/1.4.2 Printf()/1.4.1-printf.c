#include <stdio.h>
#define DEBUG 1

#if DEBUG

#define LOG(x) printf x

#else

#define LOG(x)

#endif


int main()
{
    int sensor = 25;

    LOG(("Sensor value=%d\r\n",sensor));

    return 0;
}