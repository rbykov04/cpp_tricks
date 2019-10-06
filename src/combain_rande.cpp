#include <iostream>
#include <algorithm>
#include <vector>
template<class T1, class T2>
struct combain_range_impl {
	T1& m_a;
	T2& m_b;
	typedef typename T1::iterator container_iterator_a;
	typedef typename T2::iterator container_iterator_b;
	combain_range_impl(T1& a, T2& b):
		m_a(a),
		m_b(b)
	{}

	struct iterator {
		container_iterator_a it_a;
		container_iterator_b it_b;
		explicit iterator(container_iterator_a a, container_iterator_b b) : it_a(a), it_b(b) {}

		iterator& operator++() {
			++it_a;
			++it_b;
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const {
			return it_a == other.it_a || it_b == other.it_b;
		}
		bool operator!=(iterator other) const {return !(*this == other);}
		std::pair<container_iterator_a, container_iterator_b> operator*() const {
			return {it_a, it_b};
		}
	};

	iterator begin() {return iterator(std::begin(m_a), std::begin(m_b));}
	iterator end() {return iterator(std::end(m_a), std::end(m_b));}
};
template<class T, class T2>
combain_range_impl<T, T2> combain_range(T &a, T2 &b){
	return combain_range_impl<T, T2>(a, b);
}


int main() {
	std::vector<int> a = {0, 2, 4, 6};
	std::vector<int> b = {1};


 	// auto co = combain_range(a, b);
	std::vector<int>::iterator last_a = a.begin(), last_b= b.begin();
	for(auto [it_a, it_b] : combain_range(a, b)) {
		last_a = it_a;
		last_b = it_b;
		std::cout << *it_a <<" : "<<*it_b<<'\n';
	}
	// auto [it_a, it_b ] = co.last();

	if (last_a!=std::end(a) && std::next(last_a) != std::end(a)){

		std::cout<< "a is not end \n";
		for (auto i=std::next(last_a); i!=std::end(a); ++i){
			std::cout<< "a:"<< *i<<" \n";
		}
	}
	if (last_b!=std::end(b) &&  std::next(last_b) != std::end(b)){

		std::cout<< "b is not end \n";
		for (auto i=std::next(last_b); i!=std::end(b); ++i){
			std::cout<< "b:"<< *i<<" \n";
		}
	}
	



}