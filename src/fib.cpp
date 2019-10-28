#include <iostream>

int fib(int n){
	if  (n< 3){
	    return n;
	}
	int prev = 1;
	int cur = 2;
	for (int i =2; i<n;++i){
	    int next = prev + cur;
	    prev = cur;
	    cur = next;
	}
	return cur;
}
int main() {
	int count = 10;
	std::cin >>count;
	std::cout<<fib(count)<<"\n";
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