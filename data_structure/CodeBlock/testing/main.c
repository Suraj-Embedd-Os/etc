#include <stdio.h>
#include <stdlib.h>

struct node
{
    int a;
    int b;
    int *ptr2;
};

struct s
{
    struct node *top;
};

void create(struct s **db_ptr );
int main()
{



    struct s *ss;
    ss=(struct s*)malloc(1*sizeof(struct s));
    ss->top=NULL;

    create(&ss);

    printf("%d %d %d",ss->top->a,ss->top->b,*(ss->top->ptr2));
    return 0;
}

void create(struct s **db_ptr )
{
    struct node *ptr=(struct node *)malloc(1*sizeof(struct node ));
    ptr->a=5;
    ptr->b=6;

    ptr->ptr2=(int*)malloc(1*sizeof(int));

   *(ptr->ptr2)=10;

   (*db_ptr)->top=ptr;

}
