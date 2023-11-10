
/* Program: A_CURSOR.c
 * Author: Suraj Dev Pandit
 * Purpose: Source file for a multitude of ANSI cursor
 * functions.
 *=======================================================*/

#include<stdio.h>
#include"a_cursor.h"

/*-------------------------------------------*
*			The Function					 *
*--------------------------------------------*/

/******Put the cursor on the screen**********/

void put_cursor(int row,int col)
{
	printf("\x1B[%d;%dH",row,col);
}

/*******move the cursor up ****************/
void move_cursor_up(int nbr_row)
{
	printf("\x1B[%dA",nbr_row);
}

/*******move the cursor down ****************/
void move_cursor_down(int nbr_row)
{
	printf("\x1B[%dB",nbr_row);
}

/*******move the cursor to right ****************/
void move_cursor_right(int nbr_col)
{
	printf("\x1B[%dC",nbr_col);
}

/*******move the cursor to left ****************/
void move_cursor_left(int nbr_col)
{
	printf("\x1B[%dD",nbr_col);
}

/*******Save cursor positions ****************/
void save_cursor_position(void)
{
	printf("\x1B[s");
}

/*******Save cursor positions ****************/
void restore_cursor_position(void)
{
	printf("\x1B[u");
}

/*******clear screen******************************/
void clear_screen(void)
{
	printf("\x1B[2j");
}

/*** ******clear to end of line ******/
 void clear_eol(void)
 {
	printf( "\x1B[K" );
 }


