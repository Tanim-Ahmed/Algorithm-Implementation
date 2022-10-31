// CPP program to find Edit Distance (when only two
// operations are allowed, insert and delete) using LCS.
#include<bits/stdc++.h>
using namespace std;

int lcs(string &X, string &Y)
{
	// Find LCS
	int m = X.length();
	cout<<m;
	int n = Y.length();
	cout<<n;
	int L[m+1][n+1];
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	int res = L[m][n];
	return res;

	// Edit distance is delete operations +
	// insert operations.
	//return (m - lcs) + (n - lcs);
}

/* Driver program to test above function */
int main()
{
	string X = "abcfdeff", Y = "abcd";
	cout << lcs(X, Y);
	return 0;
}
