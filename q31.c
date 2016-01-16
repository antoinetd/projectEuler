/*
*  Calculates the number of ways to make 2$ with 8 coins being
*  1cents, 2cents, 5cents, 10cents, 50cents, 1$ and 2$
*/


#include<stdio.h>

int calc();

int main(int argc, char** argv)
{
  printf("%d\n", calc());
  return 0;
}

int calc()
{
  int answer = 0;
  int i, j, k, l, m, n, o;

  answer++; //case when you get a 2$ coin

  for(i = 0; i <= 200; i = i + 1)
  {
    printf("Cents = %d nbAnswers = %d\n", i, answer);
    for(j = 0; i+j <= 200; j = j + 2)
    {
      for(k = 0; i+j+k <= 200; k = k + 5)
      {
        for(l = 0; i+j+k+l <= 200; l = l + 10)
        {
          for(m = 0; i+j+k+l+m <= 200; m = m + 20)
          {
            for(n = 0; i+j+k+l+m+n <= 200; n = n + 50)
            {
              for(o = 0; i+j+k+l+m+n+o <= 200; o = o + 100)
              {
                if(i+j+k+l+m+n+o == 200)
                {              
                  answer++;    
                }
              }       
            }
          }
        }
      }
    }
  }  
  return answer;
}
