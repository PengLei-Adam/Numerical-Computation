
/************************二分法求解方程*********************/

#ifndef _BISECT_H_
#define _BISECT_H_

#include <math.h>

template <typename T>
class Bisect {
	typedef T (*FSN ) ( T );		//函数指针类型模板
public:

	Bisect(): a(0), b(10), eps(1), solution(1) {};
	Bisect( FSN ,const T & ,const T & , const float & );
	~Bisect(){};
	T root() const;
private:
	T a;
	T b;	//二分法解的区间[a,b]
	float eps;	//允许误差
	T solution;
	void bisect( FSN f );	//解法实现
};
template <typename T>
Bisect<T>::Bisect( FSN f,const T & lt,const T & rt, const float & e )  {
	a = lt;
	b = rt;
	eps = e;
	bisect( f );
}
template <typename T>		//解法实现
void Bisect<T>::bisect ( FSN f ) {
	T c, fa, fb, fc;
	while ( fabs(a-b) > eps ) {
		c = (a+b) /2.0;
		fa = (*f) (a);
		fb = (*f) (b);
		fc = (*f) (c);
		if( fa*fc < 0 ) b = c;
		else  a = c;
	}
	solution = c;
}

template <typename T>
T Bisect<T>::root() const {  return solution; }

#endif
