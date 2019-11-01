#include <iostream>
#include <cstddef>
#include <vector>
#include <map>
#include <stack>
#include <assert.h>
#include <memory>

struct bit_print{
    unsigned int x;
    unsigned int tabs;
    bit_print(unsigned int x_, int tabs_=32):x(x_), tabs(tabs_){}
};
unsigned int revers(unsigned int x){
    x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;
    x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;
    x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;
    x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
    x = (x & 0x0000FFFF) <<16 | (x & 0xFFFF0000) >> 16;
    return x;
}
std::ostream& operator<<(std::ostream& os, bit_print b){
    for (unsigned int i = 0; i< 32; ++i){
        if (i % b.tabs == 0){
            os<<" ";
        }
        os<<!!(b.x &0x80000000);
        b.x<<=1;
        
    }

    return os;
}
unsigned int revers_step_by_step(unsigned int x){
    std::cout <<bit_print(x)<<" x\n";

    std::cout <<bit_print(x, 2)<<" x\n";
    x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;
    std::cout <<bit_print(x, 2) << " :x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;\n\n";
    std::cout <<bit_print(x, 2)<<" x\n";
    x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;
    std::cout <<bit_print(x, 2) << " :x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;\n\n";

     std::cout <<bit_print(x, 4)<<" x\n";
    x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;
    std::cout <<bit_print(x, 4) << " :x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;\n\n";

     std::cout <<bit_print(x, 8)<<" x\n";
    x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
    std::cout <<bit_print(x, 8) << " :x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;\n\n";
     std::cout <<bit_print(x, 16)<<" x\n";
    x = (x & 0x0000FFFF) <<16 | (x & 0xFFFF0000) >> 16;
    std::cout <<bit_print(x, 16) << " :x = (x & 0x0000FFFF) <<16 | (x & 0xFFFF0000) >> 16\n\n";
    std::cout <<bit_print(x)<<" result revers\n";
    return x;
}

int main(){
    revers_step_by_step(100000401);
    return 0;
}
