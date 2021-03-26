#include <stdio.h>
#include <ncurses.h>
void coord_debugger();
struct coord{
    int x, y;
};

int main()
{
    struct coord tanchik[9];
    initscr();
    tanchik[5].x = COLS/2;
    tanchik[5].y = LINES/2;
    keypad(stdscr,TRUE);
    noecho();
    curs_set(0);
    int ch;
    int i = 0;
    while((ch = getch()) != 'q')
    {
        clear();
        tanchik[0].x = tanchik[5].x - 2;
        tanchik[0].y = tanchik[5].y - 1;

        tanchik[1].x = tanchik[5].x - 1;
        tanchik[1].y = tanchik[5].y - 1;

        tanchik[2].x = tanchik[5].x;
        tanchik[2].y = tanchik[5].y - 1;

        tanchik[3].x = tanchik[5].x - 2;
        tanchik[3].y = tanchik[5].y;

        tanchik[4].x = tanchik[5].x - 1;
        tanchik[4].y = tanchik[5].y;

        tanchik[6].x = tanchik[5].x - 2;
        tanchik[6].y = tanchik[5].y + 1;

        tanchik[7].x = tanchik[5].x - 1;
        tanchik[7].y = tanchik[5].y + 1;

        tanchik[8].x = tanchik[5].x;
        tanchik[8].y = tanchik[5].y + 1;

        coord_debugger(&tanchik);
        for (i = 0; i < 3; i++)
        {
            mvaddch(tanchik[i].y, tanchik[i].x, '#');
            mvaddch(tanchik[i + 6].y, tanchik[i + 6].x, '#');        
        }
        mvaddch(tanchik[4].y, tanchik[4].x, 'O');
        mvaddch(tanchik[5].y, tanchik[5].x, '-');
        if (ch == KEY_RIGHT) tanchik[5].x++;
        if (ch == KEY_LEFT) tanchik[5].x--;
        if (ch == KEY_UP) tanchik[5].y--;
        if (ch == KEY_DOWN) tanchik[5].y++;
        refresh();
    }
    endwin();
}

void coord_debugger(struct coord tank[9])
{
    int i;
    mvprintw(0, 2,"x[MAX]=%d,y[MAX]=%d", COLS, LINES);
    for (i=0; i<9; i++)
    {
    mvprintw(1+i, 2,"x[%d]=%d,y[%d]=%d", i, tank[i].x, i, tank[i].y);
    mvprintw(4+i, 2,"x[%d]=%d,y[%d]=%d", i, tank[i].x, i, tank[i].y);
    mvprintw(7+i, 2,"x[%d]=%d,y[%d]=%d", i, tank[i].x, i, tank[i].y);
    }
}
