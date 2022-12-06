#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

uint64_t counts[256];

int main()
{
    uint64_t duplicate_count = 0, buffer_count = 0;
    char prebuffer[1025+14];
    char* buffer = prebuffer+14;
    int64_t i = 0;
    fgets(buffer, 1025, stdin);
    while(i < 14)
        duplicate_count+=++counts[buffer[i++]]==2;
    do
    {
        while(i < 1024)
            duplicate_count != 0
                ? duplicate_count+=(++counts[buffer[i]]==2)-(--counts[buffer[i++-14]]==1)
                : (printf("%"PRId64"\n",i+buffer_count*1024),exit(0));
        i = 0, buffer_count++;
        for(uint64_t j = 0; j < 14; j++)
            prebuffer[j] = buffer[1024-14+j];
    }
    while(fgets(buffer, 1025, stdin) != NULL);
    return 0;
}
