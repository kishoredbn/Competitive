#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

struct node {
    int val, pos;
    node(int val, int pos) : val(val), pos(pos) {}
    bool const operator<(const node &that) const {
        return val > that.val;
    }
};

std::unordered_map<unsigned int, unsigned long long> mem;

unsigned long long GetCloser(unsigned int end_p, unsigned long long input, unsigned int jump, std::priority_queue<node> &start_q, std::vector<unsigned int>&vec) {
    unsigned long long min_result = ULLONG_MAX;
    while(start_q.size()) {
        auto item = start_q.top();
        start_q.pop();
        unsigned long long result = input * item.val;
        auto find_item = mem.find(item.pos);
        if(find_item == mem.end()) {
            if(item.pos + jump >= end_p) {
//                std::cout << "-pos: " << item.pos << " " << result << "\n";
                mem[item.pos] = item.val * vec[end_p];
            }
            else {
                std::priority_queue<node> q;
                auto final_p = item.pos+jump;
                for(unsigned int i=item.pos+1; i<=final_p; i++) {
                    q.emplace(vec[i], i);
                }
                result = GetCloser(end_p, result, jump, q, vec);
//                std::cout << "pos: " << item.pos << " " << result << "\n";
                mem[item.pos] = (result / input) * vec[end_p];
            }
        }
        else {
            result = input * mem[item.pos] / vec[end_p];
        }
        min_result = std::min(min_result, result);
    }
    return min_result;
}

int main() {
    // your code goes here
    unsigned int n, k;
    std::vector<unsigned int> vec(100000);
    
    std::cin >> n >> k;
    unsigned int i = 0;
    while(i++<n){
        std::cin>>vec[i-1];
    }
    
    unsigned long long result = vec[0] * vec[n-1];
    if (k == n) {
        return result;
    }

    unsigned int start_pos = 1, end_pos = n-1;
    std::priority_queue<node> start_q;
    for(unsigned int i=start_pos; i<=k; i++) {
        start_q.emplace(vec[i], i);
    }
    
    result = GetCloser(n-1, result, k, start_q, vec);
    std::cout << result % 1000000007 << "\n";
    
    return 0;
}