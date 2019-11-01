#include <iostream>
#include <cstddef>
#include <vector>
#include <map>
#include <stack>
#include <assert.h>
#include <memory>

struct bit_print{
    friend std::ostream& operator<<(std::ostream& os, bit_print b);
    unsigned int x;
    unsigned int tabs;
    bit_print(unsigned int x_, int tabs_=4):x(x_), tabs(tabs_){}
    void operator=(bit_print v){
        x = v.x;
        std::cout<<"--------------------------------------------\n";
        std::cout<<v<<" new value\n";
        std::cout<<"--------------------------------------------\n";

    }
};
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
// std::hex<<b.x<<std::dec<<
bit_print operator&(bit_print b, bit_print v){
    std::cout<<"    "<<b.x<<"(0x"<<std::hex<<b.x<<")"<<std::dec<<" & 0x"<<v.x<<"(0x"<<std::hex<<v.x<<")"<<std::dec<<"\n";
    std::cout<<b<<" &\n"<<v<<"\n";
    b.x&=v.x;
    std::cout<<b<<" : "<<b.x<<" : "<<std::hex<<b.x<<std::dec<<"\n";
   // std::cout<<"--------------------------------------------\n";
    return b;
}
bit_print operator<<(bit_print b, bit_print v){
    std::cout<<b<<" << "<<v.x<<"\n";
    b.x<<=v.x;
    std::cout<<b<<" : "<<b.x<<" : "<<std::hex<<b.x<<std::dec<<"\n";
   // std::cout<<"--------------------------------------------\n";
    return b;
}

bit_print operator|(bit_print b, bit_print v){
    std::cout<<"    "<<b.x<<"(0x"<<std::hex<<b.x<<")"<<std::dec<<" | "<<v.x<<"(0x"<<std::hex<<v.x<<")"<<std::dec<<"\n";
    std::cout<<b<<" |\n"<<v<<"\n";
    b.x|=v.x;
    std::cout<<b<<" : "<<b.x<<" : "<<std::hex<<b.x<<std::dec<<"\n";
   // std::cout<<"--------------------------------------------\n";
    return b;
}
bit_print operator>>(bit_print b, bit_print v){
    std::cout<<b<<" >> "<<v.x<<"\n";
    b.x>>=v.x;
    std::cout<<b<<" : "<<b.x<<" : "<<std::hex<<b.x<<std::dec<<"\n";
   // std::cout<<"--------------------------------------------\n";

    return b;
}

bit_print revers(bit_print x){
    x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;
    x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;
    x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;
    x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
    x = (x & 0x0000FFFF) <<16 | (x & 0xFFFF0000) >> 16;
    return x;
}


int main(){
    // revers(5);
    bit_print x = 2147516416;

    x = x|(x>>1); 
    x = x|(x>>2);
    x = x|(x>>4);
    x = x|(x>>8);
    x = x|(x>>16);
    return 0;
}
