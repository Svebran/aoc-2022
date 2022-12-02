#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint64_t max = 0;
    uint64_t count = 0;
    uint64_t val = 0;
    
    char buffer[1024];
    while(fgets(buffer, 1024, stdin) != NULL)
    {
        if(buffer[0] == '\n')
        {
            if(count > max) max = count;
            count = 0;
        }
        else
        {
            if(sscanf(buffer, "%"SCNu64, &val)) count += val;
        }
    }
    if(count > max) max = count;
    printf("%"PRIu64"\n", max);

    return 0;
}
