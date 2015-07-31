/* 
    @Author: Karshan Karmur<karshan2012@gmail.com>

    This program calculates factorial of a big number.
    Array is used to store digits of very large number
    */

#include <iostream>
#define MAX 1000

using namespace std;

int kkfact(int i,int kkresult[],int kkresult_size)
{
	int carry=0;
	for(int j=0;j<kkresult_size;j++)
	{
		int product = kkresult[j]*i + carry;
		kkresult[j] = product%10;
		carry = product/10;
	}
	
	while(carry)
	{
		kkresult[kkresult_size] = carry%10;
		carry = carry/10;
		kkresult_size++;
	}
	
	return kkresult_size;
}

void fact(int n)
{
	int kkresult[MAX];
	int kkresult_size = 1;
	
	kkresult[0] = 1;
	
	for(int i=2;i<=n;i++)
	{
		kkresult_size = kkfact(i,kkresult,kkresult_size);
	}
	
	for(int i=kkresult_size-1;i>=0;i--)
	{
		cout<<kkresult[i];
	}

}
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		fact(n);
		cout<<endl;
	}
	return 0;
}
