#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t stacks = 0, layers = 0;
char buffer[1024];

struct crate
{
    struct crate* under;
    struct crate* over;
    char mark;
};

typedef struct crate crate;

void move_crates(crate layer_bottom[])
{
    uint64_t count, from, to;
    crate* layer_top[stacks], * moving_crate, * moving_top;
    for(uint64_t i = 0; i < stacks; i++)
    {
        layer_top[i] = layer_bottom+i;
        layer_top[i]->under = NULL;
    }
    for(uint64_t i = 0; i < stacks; i++)
    {
        while(layer_top[i]->over != NULL)
            layer_top[i] = layer_top[i]->over;
    }
    fgets(buffer, 1024, stdin);
    while(fgets(buffer, 1024, stdin) != NULL)
    {
        sscanf(buffer, "move %"SCNu64" from %"SCNu64" to %"SCNu64, &count, &from, &to);
        from--; to--;
        //change crates properties if exist: from - over (1), to - over (2), moving_crate - under (3)
        //change top layer: from (4), to (5)
        moving_top = layer_top[from];
        moving_crate = moving_top;
        for(uint64_t i = 1; i < count; i++)
            moving_crate = moving_crate->under;
        layer_top[to] != NULL ? layer_top[to]->over = moving_crate : (void*)"nobody expects useless evaluation"; //2
        moving_crate->under != NULL ? moving_crate->under->over = NULL : (void*)"nobody expects useless evaluation"; //1
        layer_top[from] = moving_crate->under; //4
        moving_crate->under = layer_top[to]; //3
        layer_top[to] = moving_top; //5
    }
    for(uint64_t i = 0; i < stacks; i++)
        putchar(layer_top[i]->mark);
    putchar('\n');
}

void descend_row(crate layer_up[])
{
    crate layer_current[stacks];

    for(uint64_t i = 0; i < stacks; i++)
    {
        if(buffer[i*4] == '[')
        {
            layer_current[i].mark = buffer[i*4+1];
            layer_current[i].over = layer_up[i].mark == '.' ? NULL : ((layer_up[i].under = layer_current+i),layer_up+i);
        }
        else
        {
            layer_current[i].mark = '.';
        }
    }
    fgets(buffer, 1024, stdin);
    if(buffer[1] == '1')
    {
        move_crates(layer_current);
        return;
    }
    descend_row(layer_current);
}

int main()
{
    uint64_t n = 0;
    fgets(buffer, 1024, stdin);
    while(buffer[n] != '\n') n++;
    stacks = (n+1)/4;
    crate layer_dummy[stacks];
    for(uint64_t i = 0; i < stacks; i++)
        layer_dummy[i].mark = '.';
    descend_row(layer_dummy);
    return 0;
}
