#include <stdio.h>
#include <string.h>

int main (int argc, char * argv[])
{
char* pass = "password";
if (strcmp(pass, argv[1]) == 0) printf ("OK!"); else printf("Error!");

}
