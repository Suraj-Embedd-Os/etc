#include <stdio.h>
#include <stdlib.h>

#include"stack.h"

int main()
{
    struct stack *st=NULL;
    st=(struct stack *)malloc(1*sizeof(struct stack ));
    st->top=NULL;
    push(&st,10);
    push(&st,100);
    push(&st,1000);
    pop(&st);
    displayStack(&st);
    return 0;
}

