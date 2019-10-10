#include <iostream>
#include <vector>
#include <list>

std::ostream &operator<<(std::ostream &os, std::vector<int> &container){
	auto prev = std::begin(container);
	bool line = false;
	for (auto it = std::begin(container);  it != std::end(container); ++it){
		if (it == std::begin(container)){
			os<<*it;
			continue;
		}
		if ((*prev+ 1) == *it ){
			prev = it;
			if (line){
				continue;
			}
			line = true;
			os<<"-";
			continue;
		}
		if (line){
			os<<*prev;
		}
		line = false;
		os<<", "<<*it;
		prev = it;
	}
	if (line){
		os<<*prev;
	}
	os<<"\n";
	return os;
}

template<class T>
struct convolution{
	const T &cont;
	convolution(const T &_cont) : cont(_cont){}
	
};

template<class T>
convolution<T> to_convolution(T&conv){
	return convolution<T>(conv);
}

template<class T>
std::ostream &operator<<(std::ostream &os, const convolution<T> &container){
	auto prev = std::begin(container.cont);
	bool line = false;
	for (auto it = container.cont.begin();  it != container.cont.end(); ++it){
		if (it == std::begin(container.cont)){
			os<<*it;
			continue;
		}
		if ((*prev+ 1) == *it ){
			prev = it;
			if (line){
				continue;
			}
			line = true;
			os<<"-";
			continue;
		}
		if (line){
			os<<*prev;
		}
		line = false;
		os<<", "<<*it;
		prev = it;
	}
	if (line){
		os<<*prev;
	}

	os<<"\n";
	return os;
}


int main() {
	std::vector<int> t1 {1, 2, 3 ,4, 9, 12, 15, 16,17,20};
	std::vector<int> t2{1, 2, 3 ,4, 9, 12, 15, 16,17,20, 21};
	std::vector<int> t3{1, 3};
	std::vector<int> t4{};
	std::vector<int> t5{1, 2};
	std::cout <<t1<<t2<<t3<<t4<<t5;

	std::list<int> l1 {1, 2, 3 ,4, 9, 12, 15, 16,17,20,23};
	std::cout <<to_convolution(l1);


}