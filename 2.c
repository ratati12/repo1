#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void up();
void down();
void left();
void right();

int x,y;



int main()
{
    initscr();
    keypad (stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    int ch;
    y=LINES/2;
    x=COLS/2;
    mvaddch(y,x,'#');
    refresh();
    sleep(1);
    up();
    sleep(5);
    endwin();
    return 0;
}


void up()
{   
    while (1)
    {
        clear();
        y--;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();

        if (ch == KEY_DOWN) down();
        if (ch == KEY_RIGHT) right();
        if (ch == KEY_LEFT) left();
        if (ch == 'q') {clear(); exit(0);} 


    }
}
void down()
{   
    while (1)
    {
        clear();
        y++;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();
        if (ch == KEY_UP) up();
        if (ch == KEY_RIGHT) right();
        if (ch == KEY_LEFT) left();
        if (ch == 'q') {clear(); exit(0);} 
    }
}
void left()
{   
    while (1)
    {
        clear();
        x--;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();
        if (ch == KEY_DOWN) down();
        if (ch == KEY_RIGHT) right();
        if (ch == KEY_UP) up();
        if (ch == 'q') {clear(); exit(0);} 
    }
}
void right()
{   
    while (1)
    {
        clear();
        x++;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();
        if (ch == KEY_DOWN) down();
        if (ch == KEY_UP) up();
        if (ch == KEY_LEFT) left();
        if (ch == 'q') {clear(); exit(0);} 
    }
}


