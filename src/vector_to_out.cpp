#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v){
	for (const auto& i : v){
		os<<i<<" ";
	}
	return os;
}

int main() {
	std::vector<int> test{1, 2, 9, 3 ,4};
	std::cout << test<<"\n";
}