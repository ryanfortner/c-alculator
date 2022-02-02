#include <stdio.h>
#define VER "0.1.0"
#define CALC_MAJOR 0
#define CALC_MINOR 1
#define CALC_REVISION 0
#define NAME "c-alculator"

void help(char *argv0) {
	printf("\e[1m%s version %s built on %s.\e[0m\n", NAME, VER, __TIMESTAMP__);
	printf("Usage: %s [num1] [operation] [num2]\n", argv0);
	printf("Operations: +, -, x, /\n");
}

//using argv[2][0] or *argv[2] is the same
int main (int argc, char **argv)
{
    // if --help or others are passed, print help() dialog
    if(argc>1) {
		if(!strcasecmp(argv[1], "--help")||!strcasecmp(argv[1], "-h")||!strcasecmp(argv[1], "-v")||!strcasecmp(argv[1], "--version")) {
			help(argv[0]);
			return 0;
		}
	}

    // if no input passed
    if (argc < 2) {
    	help(argv[0]);
        return 0;
    }

    // if 4 args passed
    int arg1, arg2;
    if (argc == 4)
    {
        sscanf (argv[1], "%d", &arg1);
        sscanf (argv[3], "%d", &arg2);
        if (*argv[2] == '+') printf ("%d\n", arg1 + arg2);
        if (*argv[2] == '-') printf ("%d\n", arg1 - arg2);
        if (*argv[2] == 'x') printf ("%d\n", arg1 * arg2);
        if (*argv[2] == '/') printf ("%d\n", arg1 / arg2);
    }
    return 0;
}
