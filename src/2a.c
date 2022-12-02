#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint64_t score = 0;
    uint64_t match;
    char a,b;
    char buffer[1024];
    while(fgets(buffer, 1024, stdin) != NULL)
    {
        a = buffer[0];
        b = buffer[2];
        match = ((uint64_t)(1+a-'A'))*4 + ((uint64_t)(1+b-'X'));
        switch(match)
        {
            case 5:
                score += 4;
                break;
            case 6:
                score += 8;
                break;
            case 7:
                score += 3;
                break;
            case 9:
                score += 1;
                break;
            case 10:
                score += 5;
                break;
            case 11:
                score += 9;
                break;
            case 13:
                score += 7;
                break;
            case 14:
                score += 2;
                break;
            case 15:
                score += 6;
                break;
        }
    }
    printf("%"PRIu64"\n", score);
    return 0;
}
