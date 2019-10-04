
#include <vector>
#include <iostream>
template <typename Element>
struct matrix;

template<typename Element>
struct SpiralRange {
	matrix<Element> &m_matrix;
	SpiralRange(matrix<Element> &matrix) : m_matrix(matrix){

	}
	struct iterator: public std::iterator<
						std::input_iterator_tag,   // iterator_category
						Element,                      // value_type
						Element,                      // difference_type
						const Element*,               // pointer
						Element                       // reference
									  >{
		matrix<Element> &m_matrix;

		size_t i = 0;
		size_t j= 0;
		size_t N;
		size_t M;
		enum {left, right, up, bottom};
		size_t number_perimetr = 0;
		size_t direction = right;
		size_t current = 0;
		explicit iterator(matrix<Element> &matrix, Element _num = 0):
			m_matrix(matrix),
		    i(0), j(0),
			current(_num),
			N(matrix.row_size()),
			M(m_matrix.col_size())
		{}
		bool is_end_direction(){
			switch(direction){
				case right: return (j== M - number_perimetr -1);
				case left: return (j== number_perimetr );
				case bottom: return (i== N - number_perimetr -1);
				case up: return (i== number_perimetr+1);
			}
			return false;
		}

		void change_direction(){
			switch(direction){
				case right: direction =  bottom; break;
				case left: direction = up; break;
				case bottom: direction = left; break;
				case up: number_perimetr++; direction =  right; break;
			}
		}
		void next(){
			switch(direction){
				case right: ++j; break;
				case left: --j; break;
				case bottom: ++i; break;
				case up: --i; break;
			}
		};
		iterator& operator++() {
			current = current + 1;
			if (is_end_direction()){
				// std::cout<<"change direction\n";
				change_direction();
			}
			
			next();
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const {
			return current == other.current;
		}
		bool operator!=(iterator other) const {return !(*this == other);}
		Element& operator*() const {
			// std::cout<<"i ="<<i<<";j="<<j<<"\n";
			return m_matrix[i][j];
		}
	};

	iterator begin() {return iterator(m_matrix, 0);}
	iterator end() {return iterator(m_matrix, m_matrix.row_size() * m_matrix.col_size());}
};

template <typename Element>
struct matrix{
	std::vector< std::vector<Element> > &m_matrix;
	matrix(std::vector< std::vector<Element> > &matrix) :m_matrix(matrix){};
	std::vector<Element>& operator[](size_t i){
		return m_matrix[i];
	}
	size_t row_size(){
		return m_matrix.size();
	}
	size_t col_size(){
		return m_matrix[0].size();
	}
	SpiralRange<Element> spiral_range(){
		return SpiralRange<Element>(*this);
	}
};




template <typename Element>
std::ostream& operator<<(std::ostream& os, const matrix<Element>& m){
	for (const auto& row: m.m_matrix){
		for (auto i: row){
			os<< i <<"\t";
		}
		os<< "\n";
	}
	return os;
}
int main() {
	std::vector< std::vector<int> > data(10, std::vector<int> (5, 0));
	matrix<int> m(data);
	int n = 1;
	for (auto &i: m.spiral_range()){
		i = n;
		++n;
	}
	std::cout << m;
}