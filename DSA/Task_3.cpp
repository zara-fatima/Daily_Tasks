#include <iostream>
#include<cmath>
#include <string>
using namespace std;

int countWays(int numStairs)
{
    if (numStairs==1 || numStairs==2)
	{
		return numStairs;
	}
    return countWays(numStairs-1) + countWays(numStairs-2);
}

int main() 
{
   int num;
   cout<<"Enter a number : ";
   cin>>num;
   cout<<"Total number of ways are: "<<countWays(num);
   return 0;
}
