#include "bisect.h"
#include <iostream>

using namespace std;


float myfunc1( float x ) {
	return (x*x)-4; 
}


int main()
{
	Bisect<float> root1( myfunc1, 0.4, 70.0, 1.0e-6 );
	cout<< root1.root() <<endl;
	return 0;
}
