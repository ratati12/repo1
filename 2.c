#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define LENG 5
#define POINT '#'

void up();
void down();
void left();
void right();
void paint_arena();

struct coord 
{
    int x[LENG];
    int y[LENG];
};



int main()
{
    struct coord snake;
    initscr();
    keypad (stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    int ch;
    snake.y[0]=LINES/2;
    snake.x[0]=COLS/2;
   /* int i;
    for (i=1; i<LENG; i++)
    {
        snake.y[i]=snake.y[i-1];
        snake.x[i]=snake.x[i-1]-1;
    }
    for (i=0; i<LENG; i++)
    {
        mvaddch(snake.y[i],snake.x[i],POINT);
    }

    refresh();*/
    sleep (3);
    right(snake);
    sleep(5);
    endwin();
    return 0;
}




void up(struct coord snake)
{   
    int i;
/*    clear();

    for (i = 0; i<LENG; i++)
    {
        snake.x[i]=snake.x[i-1];
        snake.y[i]=snake.y[i-1]-1;
    }
    snake.y[0]--;

    for (i = 1; i<LENG; i++)
    {
        mvaddch(snake.y[i],snake.x[i],POINT);
    }
    
    refresh();*/
    while (1)
    {

        clear();
        paint_arena();

        for (i = 1; i<LENG; i++)
        {
                snake.x[i]=snake.x[i-1];
                snake.y[i]=snake.y[i-1]+1;
        }
        snake.y[0]--;

        for (i = 1; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
        }

        refresh();
        usleep(500000);
        int ch;
        ch = getch();
        if (snake.y[0] <= 0) {snake.y[0]=LINES-LENG;}
        else {if (snake.y[0]>=LINES -LENG) snake.y[0]=(-1)*LENG;};
        if (snake.x[0] <= 0) {snake.x[0]=COLS-LENG;}
        else {if (snake.x[0] >= COLS-LENG) snake.x[0]=(-1)*LENG;};
        if (ch == KEY_RIGHT) right(snake);
        if (ch == KEY_LEFT) left(snake);
        if (ch == 'q') {clear(); exit(0);} 


    }
}
void down(struct coord snake)
{   
    while (1)
    {
        int i;
        clear();
        paint_arena();
        for (i = 1; i<LENG; i++)
        {

                snake.x[i]=snake.x[i-1];
                snake.y[i]=snake.y[i-1]-1;
        }
        snake.y[0]++;
        for (i = 1; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
        }

        refresh();
        usleep(500000);
        int ch;
        ch = getch();
        if (snake.y[0] <= 0) {snake.y[0]=LINES-LENG;}
        else {if (snake.y[0]>=LINES -LENG) snake.y[0]=(-1)*LENG;};
        if (snake.x[0] <= 0) {snake.x[0]=COLS-LENG;}
        else {if (snake.x[0] >= COLS-LENG) snake.x[0]=(-1)*LENG;};
        if (ch == KEY_RIGHT) right(snake);
        if (ch == KEY_LEFT) left(snake);
        if (ch == 'q') {clear(); exit(0);} 
    }
}
void left(struct coord snake)
{   
    while (1)
    {
        int i;
        clear();
        paint_arena();
        for (i = 1; i<LENG; i++)
        {
                snake.x[i]=snake.x[i-1]-1;
                snake.y[i]=snake.y[i-1];
        }
        snake.x[0]--;
        for (i = 1; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
        }

        refresh();
        usleep(500000);
        int ch;
        ch = getch();
        if (snake.y[0] <= 0) {snake.y[0]=LINES-LENG;}
        else {if (snake.y[0]>=LINES-LENG) snake.y[0]=(-1)*LENG;};
        if (snake.x[0] <= 0) {snake.x[0]=COLS-LENG;}
        else {if (snake.x[0] >= COLS-LENG) snake.x[0]=(-1)*LENG;};
        if (ch == KEY_DOWN) down(snake);
        if (ch == KEY_UP) up(snake);
        if (ch == 'q') {clear(); exit(0);} 


    }
}
void right(struct coord snake)
{   
    while (1)
    {
        int i;
        clear();
        paint_arena();
        for (i = 1; i<LENG; i++)
        {
                snake.x[i]=snake.x[i-1]+1;
                snake.y[i]=snake.y[i-1];
        }
        snake.x[0]++;
        for (i = 1; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
        }

        refresh();
        usleep(500000);
        int ch;
        ch = getch();
        if (snake.y[0] <= 0) {snake.y[0]=LINES-LENG;}
        else {if (snake.y[0]>=LINES -LENG) snake.y[0]=(-1)*LENG;};
        if (snake.x[0] <= 0) {snake.x[0]=COLS-LENG;}
        else {if (snake.x[0] >= COLS-LENG) snake.x[0]=(-1)*LENG;};
        if (ch == KEY_DOWN) down(snake);
        if (ch == KEY_UP) up(snake);
        if (ch == 'q') {clear(); exit(0);} 

    }
}

void paint_arena()
{
        for (int i=0; i<COLS; i++)
        {
            mvaddch(0,i,'#');
            mvaddch(LINES-1,i,'#');
            mvaddch(i,0,'#');
            mvaddch(i,COLS-1,'#');
        }    
}
