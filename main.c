#include <stdio.h>

#define PILE_IMPL
#include "pile.h"


static void *my_alloc(const size_t size){
    static PILE(pile,64<<10);
    if(size) return pile_request(pile,size);
    pile_info(pile); return NULL;
}

static void my_free(void * const p){
    pile_release(p);
}

int main()
{
    void *p[10]={NULL};
    p[0]=my_alloc(10);
    p[1]=my_alloc(20);
    p[2]=my_alloc(30);
    p[3]=my_alloc(40);
    p[4]=my_alloc(50);
    
    my_free(p[2]);
    
    my_alloc(0);

    return 0;
}
