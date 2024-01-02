/* Program: A_CURSOR.H
 * Author: Bradley L. Jones
 * Purpose: Header file for the multitude of ANSI cursor
 * functions.
 *=======================================================*/

 /*-------------------------*
 * Function prototypes *
 *-------------------------*/
 
 void put_cursor(int row,int col);
 void move_cursor_up(int nbr_row);
 void move_cursor_up(int nbr_row);
 void move_cursor_right(int nbr_col);
 void move_cursor_left(int nbr_col);
 void move_cursor_position(void);
 void save_cursor_position(void);
 void restore_cursor_position(void);
 void clear_screen(void);
 void clear_eol(void);
 
 /*---------- end of file ----------*/
