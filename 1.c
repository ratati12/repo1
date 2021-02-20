#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int ch=0;
    int i;
    initscr();
    keypad (stdscr, TRUE);
    curs_set(0);
    int y=LINES/2;
    int x=COLS/2;
    
    while((ch = getch()) != 'q')
    {
        sleep(0.1);
        for (i=0; i<COLS; i++) 
        {
            mvaddch(0,i,'#');
            mvaddch(LINES-1,i,'#');
            mvaddch(i,0,'#');
            mvaddch(i,COLS-1,'#');
        }
        mvaddch(y,x,'*');
        x++;
/*        if (ch == KEY_UP) y--;
        if (ch == KEY_DOWN) y++;
        if (ch == KEY_LEFT) x--;
        if (ch == KEY_RIGHT) x++;*/
        if (ch == 'q') {break;}
        if (y <= 0) {y=LINES-2;} 
        else {if (y >= LINES-1) y=1;};
        if (x <= 0) {x=COLS-1;} 
        else {if (x >= COLS-1) x=0;};
        clear();
        
    }
    refresh();
    endwin();
    return 0;
}
