/*通过位移求得变量a的8倍

  可左移3位得到

  更多的细节可能要考虑。
*/

#include <stdio.h>

int
main(void)
{
    int nvar = 2;

    printf("%d %d\r\n", nvar, nvar<<3);

    return 0;
}