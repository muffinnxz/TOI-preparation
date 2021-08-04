#include<bits/stdc++.h>
#include<math.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	double n;
	cin >> n;
	
	int i = 0;
	double mn = DBL_MAX, abp, asp;
	while(i <= 30)
	{
		double pb = 1000 + i * 500;
		double pp = 100 - i;
		for(int sp = 74; sp <= 144; sp++)
		{
			double sb =  ((100 - (0.8569 * exp(0.09*(sp - 100)))) * pb) / 100;
			double m = sb * sp;
			double profit = m - (pb * pp) - n;
			if(profit > 0 && profit < mn)
			{
				abp = pb;
				asp = sp;
				mn = profit;
			} 
		}
		i++;
	}
	
	cout << fixed << setprecision(0);
	cout << abp << "\n" << asp << "\n";
	
	cout << fixed << setprecision(2);
	cout << mn;
}
