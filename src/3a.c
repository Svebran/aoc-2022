#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint64_t sum = 0, bitmapL, bitmapR;
    char n;
    char buffer[1024];
    while(fgets(buffer, 1024, stdin) != NULL)
    {
        bitmapL = 0; bitmapR = 0; n = 0;
        while(buffer[n] != '\n') n++;
        for(int i = 0; i < n/2; i++)
            bitmapL |= (uint64_t)1 << (buffer[i] <= 'Z' ? 26+buffer[i]-'A' : buffer[i]-'a');
        for(int i = n/2; i < n; i++)
            bitmapR |= (uint64_t)1 << (buffer[i] <= 'Z' ? 26+buffer[i]-'A' : buffer[i]-'a');
        sum += __builtin_ffsll(bitmapL & bitmapR);
    }
    printf("%"PRIu64"\n", sum);
    return 0;
}
