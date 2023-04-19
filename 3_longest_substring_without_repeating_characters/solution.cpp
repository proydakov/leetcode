class Solution final
{
public:
//
//  f
//  |
//
//  t t t t
//  | | | |
//
// [a b c a b c b b]
// char -> unsigned
//
// [c b a a]
//
// f
// |
//
//       t
//       |
//
// a d v d f c y
//

    static int lengthOfLongestSubstring(string const& s)
    {
        unsigned long res{};

        size_t from = 0, to = 0;
        std::bitset<256> set;

        for (; to < s.size(); to++)
        {
            auto const index = char2index(s[to]);
            if (not set.test(index))
            {
                set.set(index);
            }
            else
            {
                res = std::max(res, set.count());
                auto const currc = s[to];
                for(; s[from] != currc; from++)
                {
                    set.reset(char2index(s[from]));
                }
                from++;
            }
        }
        res = std::max(res, set.count());
        return res;
    }

private:
    inline static size_t char2index(char c)
    {
        return static_cast<size_t>(c);
    }
};

