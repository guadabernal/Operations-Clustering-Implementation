#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "koolplot.h"

int main()
{
   Plotdata x(-3.0, 3.0), y = sin(x) - 0.5*x;
   plot(x, y);
   return 0;
   
}
