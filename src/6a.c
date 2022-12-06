#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

uint64_t counts[256];

int main()
{
    uint64_t duplicate_count = 0, buffer_count = 0;
    char prebuffer[1025+4];
    char* buffer = prebuffer+4;
    int64_t i = 0;
    fgets(buffer, 1025, stdin);
    while(i < 4)
        duplicate_count+=++counts[buffer[i++]]==2;
    do
    {
        while(i < 1024)
            duplicate_count != 0
                ? duplicate_count+=(++counts[buffer[i]]==2)-(--counts[buffer[i++-4]]==1)
                : (printf("%"PRId64"\n",i+buffer_count*1024),exit(0));
        i = 0, buffer_count++;
        prebuffer[0] = buffer[1020], prebuffer[1] = buffer[1021], prebuffer[2] = buffer[1022], prebuffer[3] = buffer[1023];
    }
    while(fgets(buffer, 1025, stdin) != NULL);
    return 0;
}
