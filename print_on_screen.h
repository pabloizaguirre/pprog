#ifndef print_on_screen_h
#define print_on_screen_h

#include "types.h"
//#include "map.h"
#include <stdio.h>

typedef struct {
    int screen_height;
    int screen_width;
    Position map;
    int map_width;
    int map_height;
    Position cursor;
    Position messagebox;
    int messagebox_width;
    int messagebox_height;
} Screen;

/*
    Initialize screen
*/
Screen *init_screen(char *file_name);


/*
    Restore the terminal to the initial state
*/
Result restore_screen(Screen *screen);

/*
    Clears screen
*/
Result clear_screen();

/*
    Prints the magins between the map and the message boxes from a given file
*/
Result print_margins2(FILE *f, Screen *screen);
Result print_margins(Screen *screen);

/*
    Changes the color you are printing with to the color given by the string argument
*/
int change_color(char *background_color, char *foreground_color);

/*
    Changes the custor to the given position
*/
int change_cursor(Position position, Screen *screen);

/*
    Prints the given string in the given position
*/
int print_on_position(Position position, char *text);

/*
    Prints a message in the screen part of the interface
    It also crops it to the right dimensions
*/
Result print_message(Screen *screen, char *text);

Result print_resources(Screen *screen, Level *level);

Result print_title(Screen *screen, char *text);

/* 
    Prints on screen if you passed the level or not
 */

Result level_end(Level_result res, Screen *screen);

/* 
    prints the content of a file without printing the spaces you have to change
    the color of the cursor before calling this function for it to work
 */
Result print_file(char *path, Position pos, Screen *screen);

Result start_screen(Screen *screen);

/*
    Prints the given map in the appropiate place of the 
    screen, croping it to the right dimensions if it
    exceeds the limits set in the screen object
*/
//Result print_map (Box **map, Screen *s);

#endif
