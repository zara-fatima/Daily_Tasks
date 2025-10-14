#include<iostream>
#include<string>
using namespace std;

int dec2oct(int n)
{
	if (n == 0)
	{
		return 0;
	}
    return (n % 8) + 10 * dec2oct(n / 8);
}

int main()
{
	int n=69; 
    cout << "Octal equivalent of " << n<<" is: "<<dec2oct (n) << endl; 
	n = 389; 
    cout << "Octal equivalent of " << n<<" is: "<<dec2oct(n) << endl;
	return 0; 
}
