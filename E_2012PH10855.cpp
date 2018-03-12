#include <iostream>
#include<stdlib.h>

using namespace std;



int main()
{	float *f,*pf;
	*pf=2.6;
	f=pf;

	cout << (*f) <<endl;
//	delete pf;
	cout << (*f);
	return 0;
}
