all:
	g++ -std=c++1z src/iterator_constexpr_range.cpp -o iterator_constexpr_range
	g++ -std=c++1z src/iterator_constexpr_long_range.cpp -o iterator_constexpr_long_range
	g++ -std=c++1z src/vector_to_out.cpp -o vector_to_out
	g++ -std=c++1z src/container_to_out.cpp -o container_to_out
	g++ -std=c++1z src/matrix.cpp -o matrix
	g++ -std=c++1z src/indexed_range.cpp -o indexed_range
	g++ -std=c++1z src/forward_list_wrapper.cpp -o forward_list_wrapper
	g++ -std=c++1z src/combain_rande.cpp -o combain_rande
	g++ -std=c++1z src/sum_digit.cpp -o sum_digit
	g++ -std=c++1z src/backtrack.cpp -o backtrack
	g++ -std=c++1z src/container_convolution.cpp -o container_convolution