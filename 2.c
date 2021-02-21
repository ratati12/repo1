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
        for (int i=0; i<COLS; i++)
        {
            mvaddch(0,i,'#');
            mvaddch(LINES-1,i,'#');
            mvaddch(i,0,'#');
            mvaddch(i,COLS-1,'#');
        }    
        y--;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();
        

        if (y <= 0) {y=LINES-2;}
        else {if (y>=LINES -1) y=1;};
        if (x <= 0) {x=COLS-1;}
        else {if (x >= COLS-1) x=0;};

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
        for (int i=0; i<COLS; i++)
        {
            mvaddch(0,i,'#');
            mvaddch(LINES-1,i,'#');
            mvaddch(i,0,'#');
            mvaddch(i,COLS-1,'#');
        }    
        y++;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();
        if (y <= 0) {y=LINES-2;}
        else {if (y>=LINES -1) y=1;};
        if (x <= 0) {x=COLS-1;}
        else {if (x >= COLS-1) x=0;};
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
        for (int i=0; i<COLS; i++)
        {
            mvaddch(0,i,'#');
            mvaddch(LINES-1,i,'#');
            mvaddch(i,0,'#');
            mvaddch(i,COLS-1,'#');
        }    
        x--;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();
        if (y <= 0) {y=LINES-2;}
        else {if (y>=LINES -1) y=1;};
        if (x <= 0) {x=COLS-1;}
        else {if (x >= COLS-1) x=0;};
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
        for (int i=0; i<COLS; i++)
        {
            mvaddch(0,i,'#');
            mvaddch(LINES-1,i,'#');
            mvaddch(i,0,'#');
            mvaddch(i,COLS-1,'#');
        }    
        x++;
        mvaddch(y,x,'x');
        refresh();
        usleep(100000);
        int ch;
        ch = getch();
        if (y <= 0) {y=LINES-2;}
        else {if (y>=LINES -1) y=1;};
        if (x <= 0) {x=COLS-1;}
        else {if (x >= COLS-1) x=0;};
        if (ch == KEY_DOWN) down();
        if (ch == KEY_UP) up();
        if (ch == KEY_LEFT) left();
        if (ch == 'q') {clear(); exit(0);} 
    }
}


