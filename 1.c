#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void paint_arena();
struct coord 
{
    int x[3];
    int y[3];
};
void coord_debugger();
void tank_ad();
void tank_wx();

int main()
{
    struct coord tank;
    initscr();
    keypad (stdscr, TRUE);
    curs_set(0);
    tank.y[1] = LINES/2;
    tank.x[1] = COLS/2;
    //FIRST LINE;
    tank.y[0] = tank.y[1]-1;
    tank.x[0] = tank.x[1]-1;
    
    tank.y[0] = tank.y[1]-1;
    tank.x[1] = tank.x[1];
    
    tank.y[0] = tank.y[1]-1;
    tank.x[2] = tank.x[1]+1;
    //SECOND LINE
    tank.y[1] = tank.y[1];
    tank.x[0] = tank.x[1]-1;
    
    tank.y[1] = tank.y[1];
    tank.x[2] = tank.x[1]+1; 
    //THIRD LINE
    tank.y[2] = tank.y[1]+1;
    tank.x[0] = tank.x[1]-1;
    
    tank.y[2] = tank.y[1]+1;
    tank.x[1] = tank.x[1];
    
    tank.y[2] = tank.y[1]+1;
    tank.x[2] = tank.x[1]+1;
    tank_ad(tank,2);
}

void tank_move(struct coord tank)
{
    int ch;
    int napr;
    while (1)
    {
//FIRST LINE;
    tank.y[0] = tank.y[1]-1;
    tank.x[0] = tank.x[1]-1;
    
    tank.y[0] = tank.y[1]-1;
    tank.x[1] = tank.x[1];
    
    tank.y[0] = tank.y[1]-1;
    tank.x[2] = tank.x[1]+1;
//SECOND LINE
    tank.y[1] = tank.y[1];
    tank.x[0] = tank.x[1]-1;
    
    tank.y[1] = tank.y[1];
    tank.x[2] = tank.x[1]+1; 
//THIRD LINE
    tank.y[2] = tank.y[1]+1;
    tank.x[0] = tank.x[1]-1;
    
    tank.y[2] = tank.y[1]+1;
    tank.x[1] = tank.x[1];
    
    tank.y[2] = tank.y[1]+1;
    tank.x[2] = tank.x[1]+1;
    coord_debugger(tank);
    ch = getch();
    if (ch == KEY_RIGHT) 
    {   
        tank.x[1]++;
        //FIRST LINE;
        tank.y[0] = tank.y[1]-1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[0] = tank.y[1]-1;
        tank.x[1] = tank.x[1];
    
        tank.y[0] = tank.y[1]-1;
        tank.x[2] = tank.x[1]+1;
        //SECOND LINE
        tank.y[1] = tank.y[1];
        tank.x[0] = tank.x[1]-1;
    
        tank.y[1] = tank.y[1];
        tank.x[2] = tank.x[1]+1; 
        //THIRD LINE
        tank.y[2] = tank.y[1]+1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[2] = tank.y[1]+1;
        tank.x[1] = tank.x[1];
    
        tank.y[2] = tank.y[1]+1;
        tank.x[2] = tank.x[1]+1;
        napr = 2;
        tank_ad(tank,napr);
    }
    if (ch == KEY_LEFT) 
    {   
        tank.x[1]--;
        //FIRST LINE;
        tank.y[0] = tank.y[1]-1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[0] = tank.y[1]-1;
        tank.x[1] = tank.x[1];
    
        tank.y[0] = tank.y[1]-1;
        tank.x[2] = tank.x[1]+1;
        //SECOND LINE
        tank.y[1] = tank.y[1];
        tank.x[0] = tank.x[1]-1;
    
        tank.y[1] = tank.y[1];
        tank.x[2] = tank.x[1]+1; 
        //THIRD LINE
        tank.y[2] = tank.y[1]+1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[2] = tank.y[1]+1;
        tank.x[1] = tank.x[1];
    
        tank.y[2] = tank.y[1]+1;
        tank.x[2] = tank.x[1]+1;
        napr = 0;
        tank_ad(tank,napr);
    }
    if (ch == KEY_UP) 
    {   
        tank.y[1]--;
        //FIRST LINE;
        tank.y[0] = tank.y[1]-1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[0] = tank.y[1]-1;
        tank.x[1] = tank.x[1];
    
        tank.y[0] = tank.y[1]-1;
        tank.x[2] = tank.x[1]+1;
        //SECOND LINE
        tank.y[1] = tank.y[1];
        tank.x[0] = tank.x[1]-1;
    
        tank.y[1] = tank.y[1];
        tank.x[2] = tank.x[1]+1; 
        //THIRD LINE
        tank.y[2] = tank.y[1]+1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[2] = tank.y[1]+1;
        tank.x[1] = tank.x[1];
    
        tank.y[2] = tank.y[1]+1;
        tank.x[2] = tank.x[1]+1;
        napr = 0;
        tank_wx(tank,napr);
    }
    if (ch == KEY_DOWN) 
    {   
        tank.y[1]++;
        //FIRST LINE;
        tank.y[0] = tank.y[1]-1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[0] = tank.y[1]-1;
        tank.x[1] = tank.x[1];
    
        tank.y[0] = tank.y[1]-1;
        tank.x[2] = tank.x[1]+1;
        //SECOND LINE
        tank.y[1] = tank.y[1];
        tank.x[0] = tank.x[1]-1;
    
        tank.y[1] = tank.y[1];
        tank.x[2] = tank.x[1]+1; 
        //THIRD LINE
        tank.y[2] = tank.y[1]+1;
        tank.x[0] = tank.x[1]-1;
    
        tank.y[2] = tank.y[1]+1;
        tank.x[1] = tank.x[1];
    
        tank.y[2] = tank.y[1]+1;
        tank.x[2] = tank.x[1]+1;
        napr = 2;
        tank_wx(tank,napr);
    }
    if (ch == 'd') 
    {   
        napr = 2;
        tank_ad(tank,napr);
    }
    if (ch == 'a') 
    {   
        napr = 0;
        tank_ad(tank,napr);
    }
    if (ch == 'w') 
    {   
        napr = 0;
        tank_wx(tank,napr);
    }
    if (ch == 'x') 
    {   
        napr = 2;
        tank_wx(tank,napr);
    }

    if (ch == 'q') {clear(); exit(0);}
    }
}

void tank_ad(struct coord tank,int napr)
{
    int i=0;
    clear();
    for (i = 0; i<3; i++)
    {
    mvaddch(tank.y[0], tank.x[i], '#');
    }

    mvaddch(tank.y[1], tank.x[1], 'O');
    mvaddch(tank.y[1], tank.x[napr], '-');
    for (i = 0; i<3; i++)
    {
    mvaddch(tank.y[2], tank.x[i], '#');
    }
    refresh();
    tank_move(tank);
}
void tank_wx(struct coord tank,int napr)
{
    int i=0;
    clear();
    for (i = 0; i<3; i++)
    {
    mvaddch(tank.y[i], tank.x[0], '#');
    }

    mvaddch(tank.y[1], tank.x[1], 'O');
    mvaddch(tank.y[napr], tank.x[1], '|');
    for (i = 0; i<3; i++)
    {
    mvaddch(tank.y[i], tank.x[2], '#');
    }
    refresh();
    tank_move(tank);
}


void coord_debugger(struct coord tank)
{
    int i;
    mvprintw(0, 2,"x[MAX]=%d,y[MAX]=%d", COLS, LINES);
    for (i=0; i<3; i++)
    {
    mvprintw(1+i, 2,"x[%d]=%d,y[%d]=%d", 0, tank.x[0], i, tank.y[i]);
    mvprintw(4+i, 2,"x[%d]=%d,y[%d]=%d", 1, tank.x[1], i, tank.y[i]);
    mvprintw(7+i, 2,"x[%d]=%d,y[%d]=%d", 2, tank.x[2], i, tank.y[i]);
    }
}


