#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <wait.h>
typedef void (*func)();
void success();
void error();
int64_t hash();

int main (int argc, char* argv[])
{
    int64_t h;
    int64_t s;
    int64_t offset;
    int pid = fork();
    if (pid == 0) {
    s = 883; //hash(password)
    if (argv[1] == NULL) return -1; //check for pass
    h = hash(argv[1]); //hash counter
    offset = (int64_t)(&success)+s;
    offset -=h;
    func f =(func)offset;
    f();
    return 0;
    }
    int status = 0;
    wait(&status);
    if (WIFEXITED(status)) 
    { 
        const int es = WEXITSTATUS(status);
        (void)es;
    } else {
        printf ("Wrong password!\n");
    }
    return 0;
}

void success()
{
    char* msg = "Welcome!\n";
    printf ("%s", msg);
}

int64_t hash(char *S)
{
    int64_t i,r = 0;
    while (*S)
    {
    r+=(int64_t)(*S);
    S++;
    }
    return r;
}
