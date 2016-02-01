#include <stdio.h>
#include <iostream>

using namespace std;
bool sumOfDigitsFactorialEq(long long nb);

int main()
{
  long long sum = 0;
 // cout << sumOfDigitsFactorialEq(40585) << endl;
  for(long long i = 10; i < 99999999; i++)
  {
    if(sumOfDigitsFactorialEq(i))
    {
      sum += i;
      cout << i << endl;
    } 
  }

  cout << " Answer = " << sum << endl;

  return 0;
}

bool sumOfDigitsFactorialEq(long long nb)
{
  int const digitsFactorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
  long long sum = 0;
  long long nbcpy = nb;
  long long i;
  int digitsSum = 0;

  while( nb > 0)
  {
    i = nb%10;
    nb /= 10;
    digitsSum++;
    sum += digitsFactorial[i];
  }
  if(1)
  {
//    cout << digitsSum << " nb = " << nbcpy << " sum = " << sum << endl;
  }
  return sum == nbcpy;  
}
