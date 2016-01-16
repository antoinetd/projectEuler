/*
* q32 projectEuler.net/problem=32
*
* 9 Pandigital products. 9 pandigital numbers are numbers 9 digits long containing
* the digits from 1-9 (ex. 123456789 or 873214569).
* Find all the multiplications which are 9 pandigital (ex 39 x 186 = 7254)
* and print the sum of all the unique products
*/


#include<stdio.h>
#include<stdbool.h>
bool validatePandigital(long multiplicand, long multiplier, long product);
long long concatenateInt(long x, long y);
long long combinationTester();
bool validateNoDoubleDigits(long long number);


long main(long argc, char** argv)
{
  printf("Total = %lld\n", combinationTester());
  return 0;
}

long long combinationTester()
{
  long multiplicand = 1;
  long multiplier = 1;
  long product;
  long sumOfProducts = 0;
  int i = 0;
  int j = 0;
  bool validProd;
  long productTable[100];

  for(multiplicand = 1; multiplicand <= 9999; multiplicand++)
  {
    for(multiplier = 1; multiplier <= 999 && multiplicand > multiplier; multiplier++)
    {
      if(validatePandigital(multiplicand, multiplier, 0) == true)
      {
        product = multiplicand*multiplier;
        if(validatePandigital(multiplicand, multiplier, product))
        {
          validProd = true;
          for(j = 0; j < i; j++)
          {
            if(product == productTable[j])
              validProd = false;
          }
          if(validProd)
          {
            productTable[i] = product;
            i++;
            sumOfProducts += product;
            printf("%ld x %ld = %ld\n", multiplicand, multiplier, product);
          }
        }
      }
    }
  }
  return sumOfProducts;
}

//Validates if the combination of 3 longs is 9 pandigital (contains digits 1 to 9)
bool validatePandigital(long multiplicand, long multiplier, long product)
{
  bool valid = true;
  long long number;

  number = concatenateInt(multiplicand, multiplier);
  if(product != 0)
  {
    number = concatenateInt(number, product);
  }
  else
  {
    valid = validateNoDoubleDigits(number);
  }

  if(number >= 123456789 && number <= 987654321)
  {
    valid = validateNoDoubleDigits(number);
  }
  else if(product != 0)
  {
    valid = false;    
  }

  return valid;
}

bool validateNoDoubleDigits(long long number)
{
  bool valid = true;
  bool digits[9];
  long i;
  long digit;
   
  //Initialise boolean array to false
  for(i = 0; i <= 9; i++)
  {
    digits[i] = false;
  } 

  while(number > 0)
  {
    digit = number % 10;
    digits[digit] = !digits[digit];
    if(!digits[digit] || digit == 0)
    {
      valid = false;
      break;
    }
    number /= 10;    
  }

  return valid;
}

long long concatenateInt(long x, long y)
{
  long power = 10;
  while(y >= power)
  {
    power *= 10;
  }
  return x * power + y;
}
