#include <iostream>
using namespace std;
int x[10];

void csort(int n) { //counting sort
	int counts[100] = {0};
	for(int i=0; i<n; i++) counts[x[i]]++;
	int j=0;
	for(int i=0; i<100; i++ ) while( counts[i]--)  x[j++] = i;
}

/**
 * Program to sort at most 10 numbers in range 0 - 99
 */
int main() {
	int i=0, t,a; cin >> t; //assume t is at max 10
	while(t--) cin >> a, x[i++] = a;
	csort(i);
	for(int k=0; k<i; k++) cout << x[k] <<endl;
	return 0;
}

/**
SAMPLE INPUT

10
5 3 4 2 1 4 1 6 7 8

OUTPUT
1 1 2 3 4 4 5 6 7 8
*/
