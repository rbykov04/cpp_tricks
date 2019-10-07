#include <iostream>
#include <cstddef>
#include <vector>
#include <map>
#include <stack>
#include <assert.h>
#include <memory>
#define MAXCAND 9
#define NMAX 100

struct SubSet{
    static bool is_result(int a[], int k, int input){
        return k == input;
    }
    static void process_result(int a[], int k, int input){
        std::cout<<"{";
        for (int i=0;i<k; ++i){
            if (a[i]){
                std::cout<<" "<<i;
            }
            

        }
        std::cout<<" }\n";
    }
    static int generate_candidate(int a[], int k, int c[]){
        c[0] = true;
        c[1] = false;
        return 2;
    }

};
template<typename F>
void backtrack(int a[], int k, int input){
    if (F::is_result(a, k, input)){
        F::process_result(a, k, input);
        return;
    }
    k++;
    int candidates[MAXCAND];
    int count =F::generate_candidate(a, k, candidates);
    for (int i=0; i<count; ++i){
        a[k] = candidates[i];
        backtrack<F>(a, k, input);
    }

}

struct data2{
    int *a;
    int k;
    int input;
};
struct SubSet11{
    typedef data2 data;
    static bool is_result(data& d){
        return d.k == d.input;
    }
    static void process_result(data& d){
        std::cout<<"{";
        for (int i=0;i<d.k; ++i){
            if (d.a[i]){
                std::cout<<" "<<i;
            }
            

        }
        std::cout<<" }\n";
        /*std::cout<<"d.a = {";
        for (int i=0;i<d.k; ++i){
            std::cout<<" "<<d.a[i];
        }
        std::cout<<" }\n";
        */
    }
    static std::vector<int> generate_candidate(data&){
        return {true, false};
    }

};
struct BracketsSolution{
    BracketsSolution(int n): input(n){

    }
    std::vector<char> a; 
    int input = 5;
    std::map<char, int> statistic;
    std::stack<char> last_open;
};
struct Brackets{
    typedef BracketsSolution data;
    typedef std::vector<char> candidates;

    static bool is_result(data& d){
        return d.a.size() == d.input*2;
    }
    static void process_result(data& d){
        for (auto i: d.a){
            std::cout<<i;
        }
        std::cout<<"\n";
    }
    static candidates generate_candidate(data& d){
        if (d.statistic['{'] > d.statistic['}']){
            if (d.statistic['{'] < d.input){
                return {'{', '}'};
            }
            return {'}'};
        }

        return {'{'};
    }
    static data push_back(data& d, char candidate){ //a lot of many copy (vector + multimap) 
        data next {d};
        next.statistic[candidate]++;
        next.a.push_back(candidate);
        return next;
    }
    static void incriment_k(data& d){
        
    }

};
struct Brackets2{
    typedef BracketsSolution data;
    typedef std::vector<char> candidates;

    static bool is_result(data& d){
        return d.a.size() == d.input*4;
    }
    static void process_result(data& d){
        for (auto i: d.a){
            std::cout<<i;
        }
        std::cout<<"\n";
    }
    static candidates generate_candidate(data& d){
        std::map<char, int> a;
        a['{'] = true;
        a['}'] = true;
        a['['] = true;
        a[']'] = true;
       

        for (auto &i: a){
            if (d.statistic[ i.first] >=  d.input){
               i.second = false; 
            }
        }   
        if (d.statistic['{'] <= d.statistic['}']){
             a['}'] = false;
        }
        if (d.statistic['['] <=  d.statistic[']']){
             a[']'] = false;
        }
        if (d.last_open.size()&& d.last_open.top() == '['){
           a['}'] = false; 
        }        
        if (d.last_open.size()&& d.last_open.top() == '{'){
           a[']'] = false; 
        }
        candidates result;
        for (auto i: a){
            if (i.second){
               result.push_back(i.first); 
            }
        }
        return result;
    }
    static data push_back(data& d, char candidate){ //a lot of many copy (vector + multimap) 
        data next {d};
        next.statistic[candidate]++;
        if (candidate == '[' || candidate == '{'){
            next.last_open.push(candidate);
        }
        if (candidate == ']' || candidate == '}'){
            assert(next.last_open.size());
            next.last_open.pop();
        }
        next.a.push_back(candidate);
        return next;
    }
    static void incriment_k(data& d){

    }

};
int count = 0;
struct Brackets3{
    typedef BracketsSolution data;
    typedef std::vector<char> candidates;

    static bool is_result(data& d){
        return d.a.size() == d.input*6;
    }
    static void process_result(data& d){
        count++;
        std::cout<<count;
        for (auto i: d.a){
            std::cout<<i;
        }
        std::cout<<"\n";
    }
    static candidates generate_candidate(data& d){
        std::map<char, int> a;
        a['{'] = true;
        a['}'] = true;
        a['['] = true;
        a[']'] = true;
        a['('] = true;
        a[')'] = true;

        for (auto &i: a){
            if (d.statistic[ i.first] >=  d.input){
               i.second = false; 
            }
        }   
        if (d.statistic['{'] <= d.statistic['}']){
             a['}'] = false;
        }
        if (d.statistic['['] <=  d.statistic[']']){
             a[']'] = false;
        }
        if (d.statistic['('] <=  d.statistic[')']){
             a[')'] = false;
        }
        if (d.last_open.size()&& d.last_open.top() != '{'){
           a['}'] = false; 
        }        
        if (d.last_open.size()&& d.last_open.top() != '['){
           a[']'] = false; 
        }
        if (d.last_open.size()&& d.last_open.top() != '('){
           a[')'] = false; 
        }
        candidates result;
        for (auto i: a){
            if (i.second){
               result.push_back(i.first); 
            }
        }
        return result;
    }
    static data push_back(data& d, char candidate){ //a lot of many copy (vector + multimap) 
        data next {d};
        next.statistic[candidate]++;
        if (candidate == '[' || candidate == '{' || candidate == '('){
            next.last_open.push(candidate);
        }
        if (candidate == ']' || candidate == '}'|| candidate == ')'){
            assert(next.last_open.size());
            next.last_open.pop();
        }
        next.a.push_back(candidate);
        return next;
    }
    static void incriment_k(data& d){

    }

};


struct BracketsSolution_ex{
    BracketsSolution_ex(int n, std::shared_ptr<std::vector<char>  > t ): input(n), a(t){
    }

    std::shared_ptr<std::vector<char> >a; 
    int k = 0;
    int input = 5;
    std::map<char, int> statistic;
    std::stack<char> last_open;

};

struct BracketsLight{
    typedef BracketsSolution_ex data;
    typedef std::vector<char> candidates;

    static bool is_result(data& d){

        return d.k == d.input*2;
    }
    static void process_result(data& d){
        count++;
        auto a = d.a.get();
        for (auto i: *a){
            std::cout<<i;
        }
        std::cout<<"\n";
    }
    static candidates generate_candidate(data& d){
        if (d.statistic['{'] > d.statistic['}']){
            if (d.statistic['{'] < d.input){
                return {'{', '}'};
            }
            return {'}'};
        }

        return {'{'};
    }
    static data push_back(data d, char candidate){ //a lot of many copy (vector + multimap)
        auto a = d.a.get();
        (*a)[d.k-1] = candidate;
        d.statistic[candidate]++;
        return d;
    }
    static void incriment_k(data& d){
        d.k++;
    }

};


template<typename F>
void backtrack11(typename F::data d){
    if (F::is_result(d)){
        F::process_result(d);
        return;
    }
    F::incriment_k(d);
    for (auto candidate:  F::generate_candidate(d)){
        backtrack11<F>(F::push_back(d, candidate));
    }
    
}


int main()
{

    std::shared_ptr<std::vector<char> > a (new std::vector<char> (100)); 
    BracketsSolution_ex bs(4, a);

    backtrack11<BracketsLight>(bs);
    std::cout <<"count = "<<count << "\n";
    count = 0;
    BracketsSolution bs1(3);
    backtrack11<Brackets3>(bs1);

    std::cout <<"count = "<<count << "\n";
    return 0;
}
