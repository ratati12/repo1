#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define LENG 7
#define POINT '#'
#define DELAY 700000

void up();
void down();
void left();
void right();
void paint_arena();
void debug(int c)
{
int i;
for (i=c; i>0; i--)
{
    mvprintw(2,COLS/2, "DEBUG: %d",i);
    refresh();
    sleep(1);
}
}

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
    right(snake);
    sleep(5);
    endwin();
    return 0;
}




void up(struct coord snake)
{   
    int i, ch;
    int j;
    int k;
    for (i = LENG; i>0; i--)
    {
        clear();
        paint_arena();
        j=LENG-1;
        while (j!= 0)
        {
            snake.x[j]=snake.x[j-1];
            snake.y[j]=snake.y[j-1];
            j--;
        }
        snake.y[0]--; 

        for (k = 0; k <LENG; k++) 
        {
            mvprintw(k+2, 2,"x[%d]=%d,y[%d]=%d", k, snake.x[k],k, snake.y[k]);
            mvaddch(snake.y[k],snake.x[k],POINT);
        }
        usleep(DELAY);
        refresh();
    }
        
    while (1)
    {
        clear();

        paint_arena();

        for (i = 1; i<LENG; i++)
        {
                snake.x[i]=snake.x[i-1];
                snake.y[i]=snake.y[i-1]+1;
        }
        mvprintw(1, 2,"x[MAX]=%d,y[MAX]=%d", COLS, LINES);
        


        for (i = 0; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
                mvprintw(i+2, 2,"x[%d]=%d,y[%d]=%d", i, snake.x[i], i, snake.y[i]);

        }
        snake.y[0]--;
        refresh();
        usleep(DELAY);

        ch = getch();
        if (ch == KEY_RIGHT) right(snake);
        if (ch == KEY_LEFT) left(snake);
        if (ch == 'q') {clear(); exit(0);} 


    }
}


void down(struct coord snake)
{   
   int i, ch;
    int j;
    int k;
    for (i = LENG; i>0; i--)
    {
        clear();
        paint_arena();
        j=LENG-1;
        while (j!= 0)
        {
            snake.x[j]=snake.x[j-1];
            snake.y[j]=snake.y[j-1];
            j--;
        }

        snake.y[0]++; 

        for (k = 0; k <LENG; k++) 
        {
            mvprintw(k+2, 2,"x[%d]=%d,y[%d]=%d", k, snake.x[k],k, snake.y[k]);
            mvaddch(snake.y[k],snake.x[k],POINT);
        }
        usleep(DELAY);
        refresh();
    } 
    while (1)
    {
        clear();
        paint_arena();
        
        for (i = 1; i<LENG; i++)
        {
                snake.x[i]=snake.x[i-1];
                snake.y[i]=snake.y[i-1]-1;
        }
        mvprintw(1, 2,"x[MAX]=%d,y[MAX]=%d", COLS, LINES);
        
        for (i = 0; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
                mvprintw(i+2, 2,"x[%d]=%d,y[%d]=%d", i, snake.x[i], i, snake.y[i]);
        }
        snake.y[0]++;
        refresh();
        usleep(DELAY);
        ch = getch();
        
        if (ch == KEY_RIGHT) right(snake);
        if (ch == KEY_LEFT) left(snake);
        if (ch == 'q') {clear(); exit(0);} 
    }
}
void left(struct coord snake)
{   
    int i, ch;
    while (1)
    {
        clear();
        paint_arena();
        
        for (i = 1; i<LENG; i++)
        {
                snake.x[i]=snake.x[i-1]+1;
                snake.y[i]=snake.y[i-1];

        }
        mvprintw(1, 2,"x[MAX]=%d,y[MAX]=%d", COLS, LINES);

        for (i = 0; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
                mvprintw(i+2, 2,"x[%d]=%d,y[%d]=%d", i, snake.x[i], i, snake.y[i]);
        }
        snake.x[0]--;
        refresh();
        usleep(DELAY);
        ch = getch();
        if (ch == KEY_DOWN) down(snake);
        if (ch == KEY_UP) up(snake);
        if (ch == 'q') {clear(); exit(0);} 


    }
}
void right(struct coord snake)
{   
    int i, ch;
    while (1)
    {
        clear();
        paint_arena();
        
        for (i = 1; i<LENG; i++)
        {
                snake.x[i]=snake.x[i-1]-1;
                snake.y[i]=snake.y[i-1];
        }


        mvprintw(1, 2,"x[MAX]=%d,y[MAX]=%d", COLS, LINES);
        for (i = 0; i<LENG; i++)
        {
                mvaddch(snake.y[i],snake.x[i],POINT);
                mvprintw(i+2, 2,"x[%d]=%d,y[%d]=%d", i, snake.x[i], i, snake.y[i]);
        }
        snake.x[0]++;
        refresh();
        usleep(DELAY);
        ch = getch();
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
