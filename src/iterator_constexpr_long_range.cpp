//by motive https://en.cppreference.com/w/cpp/iterator/iterator
#include <iostream>
#include <algorithm>

template<long FROM, long TO>
struct Range {
	static long next(long a){
		if constexpr (TO >= FROM){
			return a + 1;
		}else{
			return a - 1; 
		}
	}
	struct iterator: public std::iterator<
						std::input_iterator_tag,   // iterator_category
						long,                      // value_type
						long,                      // difference_type
						const long*,               // pointer
						long                       // reference
									  >{
		long num = FROM;
		explicit iterator(long _num = 0) : num(_num) {}

		iterator& operator++() {
			num = next(num); 
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const {
			return num == other.num;
		}
		bool operator!=(iterator other) const {return !(*this == other);}
		reference operator*() const {
			return num;
		}
	};

	static iterator begin() {return iterator(FROM);}
	static iterator end() {return iterator(next(TO));}
};
 
int main() {
	auto range = Range<15, 25>();
	auto itr = std::find(range.begin(), range.end(), 18);
	std::cout << *itr << '\n'; // 18
 
	for(long l : Range<3, 5>()) {
		std::cout << l << ' '; // 3 4 5
	}
	std::cout << '\n';

	for(long l : Range<-13, 5>()) {
		std::cout << l << ' '; // -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 
	}
	std::cout << '\n';
}