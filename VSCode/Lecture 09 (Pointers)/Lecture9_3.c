#include <stdio.h>

int main()
{
    char c, d;
    char * const c_ptr = &c; //making the ptr always point to c
    char const * d_ptr = &c; //cannot change value of variables, can point to different variables
    *c_ptr = 'Y'; //valid statement
    //c_ptr = &d; //invalid
    d_ptr = &d; //valid statement
    //*d_ptr = 'Y'; invalid
}