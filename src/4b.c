#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint64_t count = 0, r1B, r1E, r2B, r2E;
    char buffer[1024];
    while(fgets(buffer, 1024, stdin) != NULL)
    {
        sscanf(buffer, "%"SCNu64"-%"SCNu64",%"SCNu64"-%"SCNu64, &r1B, &r1E, &r2B, &r2E);
        if(r1B <= r2E && r1E >= r2B)
            count++;
        else if(r2B <= r1E && r2E >= r1B)
            count++;
    }
    printf("%"PRIu64"\n", count);
    return 0;
}
