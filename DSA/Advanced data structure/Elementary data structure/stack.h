

#include<stdio.h>
#include<stdlib.h>

#define ONE 5

typedef int itme_t;


#if ONE == 1
/*******************************************************************************************/
typedef struct 
{
    itme_t * base;
    itme_t * top;
    int size;
}stack_t ;


stack_t* stack_initializations(int size)
{
    stack_t *sp =(stack_t*)calloc(1,sizeof(stack_t));
    
    sp->base =(itme_t*)calloc(size,sizeof(itme_t));
    
    sp->top=sp->base;
    
    sp->size=size;
}

void push(stack_t *sp,itme_t x)
{
    if(sp->top < (sp->base + sp->size))
    {
        *(sp->top)=x;
        sp->top++;
    }
}

itme_t pop(stack_t *sp)
{
    if(sp->base != sp->top)
    {
        sp->top--;
        return *(sp->top);
    }
}

void remove_stack(stack_t *sp)
{
    free(sp->base);
    free(sp);
}

/*******************************************************************************************/
#elif ONE == 2
/*******************************************************************************************/
typedef struct st_t
{
  itme_t item;
  struct st_t *next;
}stack_t;


stack_t* stack_initializations()
{
    stack_t *sp =(stack_t*)calloc(1,sizeof(stack_t));
    sp->next = NULL;
    
}

void push(stack_t **sp,itme_t x)
{
     stack_t *new_item =(stack_t*)calloc(1,sizeof(stack_t));
     new_item->next=*sp;
     new_item->item =x;
    *sp=new_item;
    
}

itme_t pop(stack_t **sp)
{
   if(*sp !=NULL )
   {
        stack_t *temp=*sp;
        *sp=(*sp)->next;
        
        itme_t x =temp->item;
        free(temp);
        return x;
   }
}

void remove_stack(stack_t **sp)
{
     stack_t *temp;
    do
    {
         temp=*sp;
         *sp=(*sp)->next;
         free(temp);
    }while(*sp !=NULL);
}
/*******************************************************************************************/
#else
/*******************************************************************************************/
typedef struct ss_t
{
    itme_t *top;
    itme_t *base;
    int size;
    struct ss_t *previous;
}stack_t;


stack_t* stack_initializations(int size)
{
    stack_t *sp =(stack_t*)calloc(1,sizeof(stack_t));
    sp->base = (itme_t*)calloc(size,sizeof(itme_t));
    sp->top=sp->base;
    sp->previous=NULL;
    sp->size=size;
    
    return sp;
    
}

void push(stack_t **sp,itme_t x)
{
     if((*sp)->top<(*sp)->base+(*sp)->size)
     {
         *((*sp)->top)=x;
         (*sp)->top++;
     }
     else
     {
         stack_t *new_sp=(stack_t*)calloc(1,sizeof(stack_t));
         new_sp->top=(*sp)->top;
         new_sp->base=(*sp)->base;
         new_sp->previous=(*sp)->previous;
         new_sp->size=(*sp)->size;
         
         (*sp)->base=(itme_t*)calloc((*sp)->size,sizeof(itme_t));
         (*sp)->top=(*sp)->base;
         (*sp)->previous=new_sp;
         
         
         *((*sp)->top)=x;
         (*sp)->top++;
     }
    
}

itme_t pop(stack_t **sp)
{
    if((*sp)->top == (*sp)->base && (*sp)->previous ==NULL)
    {
        printf("stack empty\n");
        return -1;
    }
     
    if((*sp)->top != (*sp)->base)
    {
      (*sp)->top--;
      return *((*sp)->top);
    }
    else
    {
        stack_t * old=*sp;
        *sp=(*sp)->previous;
        
        free(old->base);
        free(old);
        
      (*sp)->top--;
      return *((*sp)->top);
        
    }
}

void remove_stack(stack_t **sp)
{
   stack_t *temp;
   do
   {
       temp=*sp;
       (*sp)=(*sp)->previous;
       free(temp->base);
       free(temp);
   }while(*sp !=NULL);
}
/*******************************************************************************************/
#endif











