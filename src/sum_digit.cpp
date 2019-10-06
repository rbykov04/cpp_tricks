#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
std::pair<bool ,int> sum_digit(int a, int b){
	int s = a + b;
	std::cout<<s<<"\n";
	return {s>= 10, s%10};
}

int main() {
	auto [a, b] = sum_digit(9, 9);
	std::cout<<std::string(a? "1":" ")<<b<<"\n"; //18
	auto [a1, b1] = sum_digit(9, 0);
	std::cout<<std::string(a1? "1":" ")<<b1<<"\n"; //18



}