// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum
// possible value at index K
void maxValueAtIndexK(int N, int K, int M)
{
	// Stores the sum of elements
	// in the left and right of index K
	int S1 = 0, S2 = 0;

	S1 = K * (K + 1) / 2;
	S2 = (N - K - 1) * (N - K) / 2;

	// Stores the maximum
	// possible value at index K
	int X = (M + S1 + S2) / N;

	// Print the answer
	cout << X;
}

// Driver Code
int main()
{
	// Given N, K & M
	// int N = 3, K = 1, M = 7;
	maxValueAtIndexK(4,0,6);

	return 0;
}
