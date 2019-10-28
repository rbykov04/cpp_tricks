#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
struct Matrix22{
	friend Matrix22 operator*(const Matrix22 &l, const Matrix22 &r);
	int a[2][2];
	Matrix22(int a00, int a01, int a10, int a11): a{a00, a01, a10, a11}
	{}
	static Matrix22 one(){
		return Matrix22(1, 0, 0, 1);
	}
	Matrix22 pow(int n){

		if (n<=0){
			return one();
		}
		if (n%2){
			return *this * this->pow(n-1);
		}
		Matrix22 sqrt = (*this).pow(n/2);
		return sqrt * sqrt;
	}	
};
Matrix22 operator*(const Matrix22 &l, const Matrix22 &r){

	return Matrix22(
		l.a[0][0]*r.a[0][0] + l.a[0][1]*r.a[1][0],
		l.a[0][0]*r.a[0][1] + l.a[0][1]*r.a[1][1],
		l.a[1][0]*r.a[0][0] + l.a[1][1]*r.a[1][0],
		l.a[1][0]*r.a[0][1] + l.a[1][1]*r.a[1][1]

	);
}
std::ostream& operator<<(std::ostream& os, const Matrix22& m){
	os<<m.a[0][0]<<"\t"<<m.a[0][1]<<"\n"<<m.a[1][0]<<"\t"<<m.a[1][1];
	return os;
}
int fib(int n){
	auto m = Matrix22(0, 1, 1, 1).pow(n-1);
	return m.a[0][1] + m.a[1][1];
}
int main() {
	int count;
	std::cin >>count;
	int res=0;
	for (int i= 0; i<count; ++i){
		res = fib(i);
	}
	std::cout<<res<<"\n";
	return 0;
}

//matrix vs fib req

// 0.03s vs 12.02s

// time echo 100000 | ./fib     
// 873876091
// ./fib  12,02s user 0,00s system 99% cpu 12,027 total


// time echo 100000 | ./matrix22
// 873876091
// ./matrix22  0,03s user 0,00s system 99% cpu 0,038 total