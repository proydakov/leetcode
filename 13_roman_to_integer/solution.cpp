class Solution final
{
public:
    int romanToInt(string s) const
    {
        int prev = sym2val(s.front());
        int res{};
        for(const char c : s)
        {
            int const curr = sym2val(c);
            res += curr;
            if (prev < curr)
            {
                res -= prev;
                res -= prev;
            }
            prev = curr;
        }
        return res;
    }

private:
    static int sym2val(char c) const
    {
        switch(c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }

        return 0;
    }
};

