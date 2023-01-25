#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

uint64_t result = 0;
char buffer[1025];

uint64_t evaldir()
{
    uint64_t size = 0;
    uint64_t tmp;
    char flag = 0;
    while(flag || fgets(buffer, 1024, stdin) != NULL)
    {
        if(flag) flag = !flag;
        if(buffer[2] == 'c')
        {
            if(buffer[5] == '.')
                break;
            else size += evaldir();
        }
        else
        {
            while(fgets(buffer, 1024, stdin) != NULL)
            {
                if(buffer[0] == '$')
                {
                    flag = 1;
                    break;
                }
                else if(buffer[0] != 'd')
                {
                    sscanf(buffer, "%"SCNu64, &tmp);
                    size += tmp;
                }
            }
        }
    }
    if(size < 100001)
        result += size;
    return size;
}

int main()
{
    fgets(buffer, 1024, stdin); // cd /
    evaldir();
    printf("%"PRIu64"\n", result);
    return 0;
}
