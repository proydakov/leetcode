class Solution
{
public:
    bool isPerfectSquare(int num) {
        size_t x = num;
        while (x * x > num) {
            x = (x + num / x) >> 1;
            std::cout << x << std::endl;
        }
        return x * x == num;
    }
};
