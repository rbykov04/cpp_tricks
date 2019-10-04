#include <iostream>
#include <vector>
#include <list>

template<class CONTAINER, char SEPARATOR>
struct Container2Stream {
	const CONTAINER& m_v;
	char separator = SEPARATOR;
	Container2Stream(const CONTAINER& v_): m_v(v_){
	}

};

template<class CONTAINER,  char SEPARATOR>
std::ostream& operator<<(std::ostream& os, const Container2Stream<CONTAINER, SEPARATOR>& v){
	for (const auto& i : v.m_v){
		os<<i<<v.separator;
	}
	return os;
}

template<char SEPARATOR, class CONTAINER>
Container2Stream<CONTAINER, SEPARATOR> container_to_os(const CONTAINER& v){
	return Container2Stream<CONTAINER, SEPARATOR>(v);

}


int main() {
	std::vector<int> test{1, 2, 9, 3 ,4};
	std::list<int> list_test{5, 6, 7, 8};
	std::cout << container_to_os<';'>(test)<<"\n";
	std::cout << container_to_os<'-'>(list_test)<<"\n";
}