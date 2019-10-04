//by motive https://en.cppreference.com/w/cpp/iterator/iterator
#include <iostream>
#include <algorithm>

template<typename T, T FROM, T TO>
struct Range_Impl {
	static T next(T a){
		if constexpr (TO >= FROM){
			return a + 1;
		}else{
			return a - 1; 
		}
	}
	typedef Range_Impl<T, FROM, TO> range; 
	struct iterator: public std::iterator<
						std::input_iterator_tag,   // iterator_category
						T,                      // value_type
						T,                      // difference_type
						const T*,               // pointer
						T                       // reference
									  >{
		T num = FROM;
		explicit iterator(T _num = 0) : num(_num) {}

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
		T operator*() const {
			return num;
		}
	};

	static iterator begin() {return iterator(FROM);}
	static iterator end() {return iterator(next(TO));}
};

template<long FROM, long TO> 
struct Range: public Range_Impl<long, FROM, TO>{};

int main() {
	auto range = Range<15, 25>();
	auto itr = std::find(range.begin(), range.end(), 18);
	std::cout << *itr << '\n'; // 18
 
	for(long l : Range<3, 5>()) {
		std::cout << l << ' '; // 3 4 5
	}


	std::cout << '\n';


}