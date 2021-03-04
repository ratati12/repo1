#include <pthread.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>


static void *mul ();
static void *write ();

FILE *fp;
struct mas {
int* a;
int* b;
int n;
};

int main ()
{
struct mas m;
m.n=0;
int i, j, n;
int temp;
pthread_t pid;
pthread_t pid2;
void *retval;
printf("Message from main thread\n");
fp = fopen("task.txt", "r");
while (1)
    {
    if (fscanf(fp, "%d", &temp) == EOF) break;
    m.n++;
    }
n = m.n;
m.n = sqrt(m.n);
if (n != m.n*m.n) return -1;
printf ("%d", m.n);
getchar();
m.a = (int*)malloc((m.n)*(m.n) * sizeof(int));
m.b = (int*)malloc((m.n)*(m.n) * sizeof(int));

fseek (fp, 0, 0);
for (i = 0; i<(m.n); i++)
{
    for (j = 0; j<(m.n); j++)
        {
            fscanf (fp, "%d", (m.a + i*(m.n) +j));
        }
}
for (i = 0; i<(m.n); i++)
{
    for (j = 0; j<(m.n); j++)
        {
            printf("%d ", *(m.a + i*(m.n) +j));
        }
    printf ("\n");
}


pthread_create(&pid, NULL, mul, (void*)&m);
//pthread_create(&pid2, NULL, write, (void*)&m);


pthread_join(pid, &retval);
//pthread_join(pid2, &retval);
//fcloseall();
return 0;
}



static void *mul (void *none)
{
struct mas *m = (struct mas*) none;
int i, j,n,a,s;
printf ("\nSecond thread\n");
for (i = 0; i<(m->n); i++)
{
    for (j = 0; j<(m->n); j++)
    {
            for (n=0; n<(m->n); n++)
            {
                //printf ("%d %d", *(m->a + i*(m->n) +n) , *(m->a + n*(m->n) +j));
                //getchar();
                a = *(m->a + i*(m->n) +n) * *(m->a + n*(m->n) +j);
                s = s + a;
            }
        *(m->b + n*(m->n) + i) = s;
        s=0;
        printf("%d ", *(m->b + n*(m->n) + i));
    }
    printf ("\n");
}
}



static void *write (void *none)
{
struct mas *m = (struct mas*) none;

}
