#include <stdio.h>
#include<stdlib.h>
#include "a_cursor.h"

/*** Function prototypes ***/
 void box( int ul_row, int ul_col, int lr_row, int lr_col,
 unsigned char ch );

void main(void)
{
	 int row,column,x,y;

	save_cursor_position();
	clear_screen();
	system("clear");

	box(1,18,3,61,'*');

	put_cursor(3,21);
	printf( " THIS IS AT THE TOP OF THE SCREEN " );

	 box( 15, 20, 19, 60, 1 );
	 box( 16, 24, 18, 56, 2 );

	 restore_cursor_position();
}


void box( int ul_row, int ul_col, int lr_row, int lr_col,unsigned char ch )
{
	 int x, y;

	if( (ul_row > lr_row) || (ul_col > lr_col) )
	 {
		printf( "Error calling box." );
	 }
	 else
	 {
		 for( x = ul_row; x <= lr_row; x++ )
		 {
			 put_cursor( x, ul_col);


			 for( y = ul_col; y <= lr_col; y++ )
			 {
				printf( "%c", ch );
			 }
		 }
	 }
 }
 