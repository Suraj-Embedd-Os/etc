#include<stdio.h>
#include<stdlib.h>
#include "practical.h"

void DieWithUserMessage(const char *msg, const char *details)
{
        fputs(msg,stderr);
        fputs(": ",stderr);
        fputs(details,stderr);
        fputs("\n",stderr);

}
void DieWithSystemMessage(const char *msg)
{
        perror(msg);
        exit(1);

}