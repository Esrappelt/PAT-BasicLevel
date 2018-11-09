#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	int n,i,j = 0,a[10000],b[10000],k = 0,N,sum = 0;
	cin >> n;
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(i = 0; i < n; i++)
	{
		sum = 0;
		N = a[i];
		while(N)
		{
			sum += N % 10;
			N /= 10;
		}
		b[k++] = sum;
	}
	sort(b,b+k);
	int len = k;
    for (i = 0; i < k - 1; i++)
	{  
       for (int j = i + 1; j < k; j++)
	   {  
             if (b[j] == b[i])
			 {   
                  len--;  
                  i++;  
             }  
         }  
    }  
    cout << len << endl;
	for(i = 0; i < k; i++)
	{
		if(i + 1 == k)
			cout << b[i];
		else
			if(b[i] != b[i+1])
				cout << b[i] << " ";
	}
     
	return 0;
}