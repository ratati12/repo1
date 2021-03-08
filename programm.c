#include <stdio.h>
#include <stdint.h>
typedef void (*func)();
void success();
void error();
int64_t hash();

int main (int argc, char* argv[])
{
    int64_t h;
    int64_t s;
    int64_t offset;
    s = 883; //hash(password)
    if (argv[1] == NULL) return -1; //check for pass

    h = hash(argv[1]); //hash counter
    printf ("HASH: %ld\n", h); //DEBUG
    
    offset = (int64_t)(&success)+s;
    printf ("OFFSET:%ld\n", offset); //DEBUG
    
    offset -=h;
    printf ("ADDR:%ld\n", offset); //DEBUG
    
    func f =(func)offset;
    f(); 

    return 0;
}

void success()
{
    char* msg = "Welcome!\n";
    printf ("%s", msg);
}


void error()
{
    char* msg = "Wrong password!\n";
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
