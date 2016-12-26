#include <string>

class Solution {
public:
    int myAtoi(std::string str) {
        long res = 0;

        char temp = '0';
        bool minus = false;
        bool has_symbol = false;

        bool done = false;

        const long max_res = 2147483647l;
        const long min_res = 2147483648l;

        for(size_t i = 0; i < str.size() && !done; i++) {
            temp = str[ i ];
            if(temp >= '0' && temp <= '9') {
                long item = (long)temp - (long)'0';
                res = res * 10 + item;
            }
            else {
                if(has_symbol)  {
                    break;
                }
                switch(temp) {
                    case '-': {
                        minus = true;
                        has_symbol = true;
                    }
                    break;

                    case '+': {
                        has_symbol = true;
                    }
                    break;

                    case ' ': {
                        if(res > 0) {
                            done = true;
                        }
                    }
                    break;

                    default: {
                        done = true;
                    }
                    break;
                }
            }

            if(res >= max_res && !minus) {
                return 2147483647;
            }
            if(res >= min_res && minus) {
                return -2147483648;
            }
        }

        if(minus) {
            res *= -1;
        }

        return res;
    }
};
