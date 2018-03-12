#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int N, M, i, j;

void rot90(int, int);
int Mat[50][50];

/**
 * Rotates a =>! NxM ! <= matrix 90 degrees (to the right) user specified times
 * Ex: 1 2  =>  3 1
 *     3 4      4 2
 *  Above matrix rotated once 
 
 * Ex: 1 2 3 4  =>  8 7 6 5
 *     5 6 7 8      4 3 2 1
 *  Above matrix rotated twice
 */
 
int main() {
//	freopen("in", "r", stdin);
	cin >> N >> M; //Dimensions of matrix (max 50 each)
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			cin >> Mat[i][j];
		}
	}
	int t; cin >> t; //number of rotations;
	while(t--) {
		rot90(N, M);
	}
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			cout << Mat[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void rot90(int rows, int cols) {
	int tmp[50][50];
	for(i=0; i<rows; i++) for(int j=0; j<cols; j++) {
		tmp[j][rows-1-i] = Mat[i][j];
	}
	for(i=0; i<cols; i++)
	{
		for(j=0; j<rows; j++)
		{
			Mat[i][j] = tmp[i][j];
		}
	}
	int temp=M;
	M=N;
	N=temp;
	
}
