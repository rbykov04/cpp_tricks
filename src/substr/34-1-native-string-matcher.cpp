#include <iostream>
#include <string>

void native_string_matcher(const std::string& text, const std::string& pattern){
	std::cout<<"shift\t"<<text<<"\n";
	size_t n = text.size();
	size_t m = pattern.size();
	for (size_t s =0; s<=n-m; ++s){
		bool is_sub = true;
		for (size_t i = 0; i<m; ++i){
			if (text[s+i] != pattern[i]){
				is_sub = false;
				break;
			}
		}
		if (is_sub){
			std::string shift(s, '.');
			std::cout<<s<<"\t"<<shift<<pattern<<"\n";
		}
	}

}

int main() {
	native_string_matcher("abacdefabac","abac");
	return 0;
}