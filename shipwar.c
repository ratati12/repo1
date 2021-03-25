#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

WINDOW* pole;
pthread_mutex_t mutex;

void* shoot();

struct coord {
    int x;
    int y[4];
};

static int count = 0;
struct coord ship;

int main()
{   
    pthread_t thread[3];

    initscr();
    const int width = COLS/3;
    const int height = LINES/3;
    int offsetx = COLS/3;
    int offsety = LINES/3;
    int ch, i;
    curs_set(0);
    keypad(stdscr,TRUE);
    noecho();
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);


    nodelay(stdscr,TRUE);
    refresh();
    
    WINDOW *win = newwin(height, width, offsety, offsetx);
    pole = newwin(height-2, width-6,offsety+1, offsetx+5);
    wattron(win, COLOR_PAIR(2));
    wattron(pole, COLOR_PAIR(1));
    mvaddstr(LINES/2, COLS/3+1, "====");
    box(win, 0, 0);
    wrefresh(win);
    
    ship.y[0] = LINES/3-3;
    ship.x = COLS/3-8;
    
    while ((ch = getch()) != 'q')
        {
        if (ch == ' ' && count < 3)
        {   
            count++;
            pthread_create(&thread[count], NULL, shoot, NULL);
        }
        for (i = 1; i < 4; i++)
        {
            ship.y[i]=ship.y[i-1]+1;
        }
        for (i = 0; i < 4; i++)
        {
            mvwaddch(pole,ship.y[i], ship.x, '#');
        }
        wrefresh(pole);
        ship.y[0]--;
        if (ship.y[0]<-3) ship.y[0]=LINES/3-3;
        wclear(pole);
        usleep(400000);
    }

    pthread_mutex_destroy (&mutex);
    delwin(win);
    delwin(pole);
    endwin();
    return 0;
}

void* shoot (void *args)
{   
    int x=0;
    while(x<COLS/3)
    {
        mvwaddch(pole,LINES/6-1, x, '#');
        x++;
        usleep(410000);
        pthread_mutex_lock (&mutex);
        if (x == COLS/3-8 && ship.y[0] == LINES/6-1)
        {
            while (1)
            {
                clear();
                mvaddstr(LINES/2, COLS/2-3, "You win!");
                mvaddstr(LINES/2+1, COLS/2-9, "Press 'q' to exit.");
                refresh();
            }
        }
        if (x == COLS/3-8 && ship.y[1] == LINES/6-1)
        {
            while (1)
            {
                clear();
                mvaddstr(LINES/2, COLS/2-3, "You win!");
                mvaddstr(LINES/2+1, COLS/2-9, "Press 'q' to exit.");
                refresh();
            }
        }
        if (x == COLS/3-8 && ship.y[2] == LINES/6-1)
        {
            while (1)
            {
                clear();
                mvaddstr(LINES/2, COLS/2-3, "You win!");
                mvaddstr(LINES/2+1, COLS/2-9, "Press 'q' to exit.");
                refresh();
            }
        }
        if (x == COLS/3-8 && ship.y[3] == LINES/6-1)
        {
            while (1)
            {
                clear();
                mvaddstr(LINES/2, COLS/2-3, "You win!");
                mvaddstr(LINES/2+1, COLS/2-9, "Press 'q' to exit.");
                refresh();
            }
        }
        pthread_mutex_unlock (&mutex);

    }
    count--;
    return 0;
}
