all:
	g++ -std=c++1z src/iterator_constexpr_range.cpp -o iterator_constexpr_range
	g++ -std=c++1z src/iterator_constexpr_long_range.cpp -o iterator_constexpr_long_range
	g++ -std=c++1z src/vector_to_out.cpp -o vector_to_out
	g++ -std=c++1z src/container_to_out.cpp -o container_to_out
	g++ -std=c++1z src/matrix.cpp -o matrix