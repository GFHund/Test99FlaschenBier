#include <stdio.h>
#include <math.h>
#include "calcNewton.h"

float f(float x)
{
      return sin(x);
}

float calcNewton(float x1, float x2, int intervals)
{
      float h = (x2 - x1) / intervals;

      float step1 = 0;
      float step2 = 0;
      float step4 = 0;

      int i;
      for (i = 1; i <= intervals-1; i++)
      {
             float xi = i*h+x1;

             if((i%2) == 0)
             {
                    if((i%4) == 0)
                    {
                            step4 += f(xi);
                    }
                    else
                    {
                            step2 += f(xi);
                    }
             }
             else
             {
                     step1 += f(xi);
             }
     }
}