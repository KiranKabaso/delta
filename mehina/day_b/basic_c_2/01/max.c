/*------------------------------------------------------
* Filename: [max.c]
* Description: [print the max of two numbers]
* Author: [Kiran Kabaso]
-------------------------------------------------------*/

#include <stdio.h>

/*------------------------------------------------------
* Function Name - [main]
*
* Function Purpose - [print the max of two numbers]
*
* Parameters – NONE
*
* Return Values - [0]
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
int main() {
    int x = 5;
    int y = 7;
    int z = x > y ? x:y;
    printf("z = %d", z);

    return 0;
}
