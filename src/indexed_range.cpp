//by motive https://en.cppreference.com/w/cpp/iterator/iterator
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<class T>
struct indexed_range_impl {
	T& m_container;
	typedef typename T::iterator container_iterator;
	indexed_range_impl(T & container):m_container(container){}

	struct iterator {
		container_iterator it;
		size_t index;
		explicit iterator(container_iterator _it) : index(0), it(_it) {}

		iterator& operator++() {
			++index;
			++it;
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const {
			return it == other.it;
		}
		bool operator!=(iterator other) const {return !(*this == other);}
		std::pair<container_iterator, size_t> operator*() const {
			return {it, index};
		}
	};

	iterator begin() {return iterator(std::begin(m_container));}
	iterator end() {return iterator(std::end(m_container));}
};
template<class T>
indexed_range_impl<T> indexed_range(T &container){
	return indexed_range_impl<T>(container);
}
int main() {
	std::vector<std::string> test{"aa", "bb", "cc"};
 
	for(auto [it, index] : indexed_range(test)) {
		std::cout << index << ":"<< *it<<'\n';
	}




}