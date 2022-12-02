#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint64_t max1 = 0;
    uint64_t max2 = 0;
    uint64_t max3 = 0;
    uint64_t count = 0;
    uint64_t val = 0;
    
    char buffer[1024];
    while(fgets(buffer, 1024, stdin) != NULL)
    {
        if(buffer[0] == '\n')
        {
            if(count >= max1)
            {
                 max3 = max2;
                 max2 = max1;
                 max1 = count;
            }
            else if(count >= max2)
            {
                max3 = max2;
                max2 = count;
            }
            else if(count >= max3)
                max3 = count;
            count = 0;
        }
        else
        {
            if(sscanf(buffer, "%"SCNu64, &val)) count += val;
        }
    }
    if(count >= max1)
    {
        max3 = max2;
        max2 = max1;
        max1 = count;
    }
    else if(count >= max2)
    {
        max3 = max2;
        max2 = count;
    }
    else if(count >= max3)
        max3 = count;
    printf("%"PRIu64"\n", max1+max2+max3);

    return 0;
}
