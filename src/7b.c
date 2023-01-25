#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

uint64_t result = 0;
char buffer[1025];
uint64_t recur_offset = 0;
char* recur_tmp = NULL;


void evaldir(char* parent)
{
    uint64_t size = 0;
    uint64_t tmp;
    char flag = 0;
    char* current_size = (char*)&size;
    char* parent_iterator = NULL;
    if(recur_offset == 0)
    {
        if(recur_tmp == 0)
            recur_tmp = (char*)(void*)&size;
        else
            recur_offset = (char*)(void*)&size - recur_tmp;
    }
    while(flag || fgets(buffer, 1024, stdin) != NULL)
    {
        if(flag) flag = !flag;
        if(buffer[2] == 'c')
        {
            if(buffer[5] == '.')
            {
                //update parents
                parent_iterator = *(char**)(void*)(((char*)current_size)-((char*)&size-(char*)&parent));
                if(parent_iterator != NULL)
                {
                    *((uint64_t*)(void*)parent_iterator) += *(uint64_t*)(void*)current_size;
                    parent_iterator = *(char**)(void*)((char*)parent_iterator-(((char*)&size)-((char*)&parent)));
                }
                current_size = *(char**)(void*)(((char*)current_size)-((char*)&size-(char*)&parent));
            }
            else evaldir(current_size);
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
                    *(uint64_t*)(void*)current_size += tmp;
                }
            }
            if(flag == 0) //end of input
            {
                //update parents and find optimal size
                parent_iterator = *(char**)(void*)(((char*)current_size)-((char*)&size-(char*)&parent));
                while(parent_iterator != NULL)
                {
                    *((uint64_t*)(void*)parent_iterator) += size;
                    current_size = parent_iterator;
                    parent_iterator = *(char**)(void*)((char*)parent_iterator-(((char*)&size)-((char*)&parent)));
                }
                tmp = 30000000 - (70000000 - *(uint64_t*)(void*)current_size); // cannot get lower than that
                result = 70000000;
                do
                {
                    current_size += recur_offset;
                    if(*(uint64_t*)(void*)current_size < result && *(uint64_t*)(void*)current_size >= tmp)
                        result = *(uint64_t*)(void*)current_size;
                } while(current_size != (char*)(void*)&size);
                return;
            }
        }
    }
    return;
}

int main()
{
    fgets(buffer, 1024, stdin); // cd /
    evaldir(NULL);
    printf("%"PRIu64"\n", result);
    return 0;
}
