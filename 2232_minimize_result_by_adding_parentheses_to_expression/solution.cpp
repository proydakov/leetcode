class Solution
{
public:
    string minimizeResult(string const& expression)
    {
        size_t const pos = expression.find('+');
        std::string const w1 = expression.substr(0, pos);
        std::string const w2 = expression.substr(pos + 1);

        bool has_prev{}, has_last{};
        std::array<int, 4> resvec;
        int minval = std::numeric_limits<int>::max();

        for(size_t prefix_length = 0; prefix_length < w1.size(); prefix_length++)
        {
            std::string const prefix = w1.substr(0, prefix_length);
            std::string const plast = w1.substr(prefix_length);

            int const iprefix = prefix.empty() ? 1 : std::stoi(prefix);
            int const ilast = std::stoi(plast);

            for(size_t suffix_length = 0; suffix_length < w2.size(); suffix_length++)
            {
                std::string const suffix = w2.substr(w2.size() - suffix_length);
                std::string const sprev = w2.substr(0, w2.size() - suffix_length);

                int const iprev = std::stoi(sprev);
                int const isuffix = suffix.empty() ? 1 : std::stoi(suffix);

                int const testres = iprefix * (ilast + iprev) * isuffix;
                if (testres < minval)
                {
                    minval = testres;
                    resvec[0] = iprefix;
                    resvec[1] = ilast;
                    resvec[2] = iprev;
                    resvec[3] = isuffix;

                    has_prev = not prefix.empty();
                    has_last = not suffix.empty();
                }
            }
        }

        std::string sstream;
        sstream.reserve(expression.size() + 2);

        if (has_prev)
        {
            sstream.append(std::to_string(resvec[0]));
        }

        sstream.append("(");
        sstream.append(std::to_string(resvec[1]));
        sstream.append("+");
        sstream.append(std::to_string(resvec[2]));
        sstream.append(")");

        if (has_last)
        {
            sstream.append(std::to_string(resvec[3]));
        }

        return sstream;
    }
};

