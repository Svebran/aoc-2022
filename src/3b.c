#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint64_t sum = 0, bitmap1, bitmap2, bitmap3;
    char n;
    char buffer[1024];
    while(fgets(buffer, 1024, stdin) != NULL)
    {
        bitmap1 = 0; bitmap2 = 0; bitmap3 = 0;
        n = 0;
        while(buffer[n] != '\n')
        {
            bitmap1 |= (uint64_t)1 << (buffer[n] <= 'Z' ? 26+buffer[n]-'A' : buffer[n]-'a');
            n++;
        }
        fgets(buffer, 1024, stdin);
        n = 0;
        while(buffer[n] != '\n')
        {
            bitmap2 |= (uint64_t)1 << (buffer[n] <= 'Z' ? 26+buffer[n]-'A' : buffer[n]-'a');
            n++;
        }
        fgets(buffer, 1024, stdin);
        n = 0;
        while(buffer[n] != '\n')
        {
            bitmap3 |= (uint64_t)1 << (buffer[n] <= 'Z' ? 26+buffer[n]-'A' : buffer[n]-'a');
            n++;
        }
        sum += __builtin_ffsll(bitmap1 & bitmap2 & bitmap3);
    }
    printf("%"PRIu64"\n", sum);
    return 0;
}
