/*Function: main
*--------------
*using macro function to find the surface area of any right rectangular prism
*
*use #define to define the macro function
*use scanf to input all the needed data (length, width, height)
*use macro function to solve for surface area
*print out result
*/

#include <stdio.h>

#define SURFACEAREA(l, w, h) 2 * (w * l + h * l + h * w) //macro function for surface area

int main()
{
    int l, w, h, sa;    //declare all the needed integer variables

    printf("Length: "); //Request for length data
    scanf("%d", &l);    //used to input length data, use %d for integer variables
    printf("Width: ");  //Request for width data
    scanf("%d", &w);    //used to input width data, use %d for integer variables
    printf("Height: "); //Request for height data
    scanf("%d", &h);    //used to input height data, use %d for integer variables
    sa = SURFACEAREA(l, w, h);  //Recall the macro function
    
    printf("The surface area of the right rectangular prism: %d", sa); //print out result; output

    return 0;
}