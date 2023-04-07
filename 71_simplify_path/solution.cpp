class Solution final
{
public:
    static string simplifyPath(string const& path)
    {
        if (path.front() != '/')
        {
            throw std::runtime_error("");
        }

        std::vector<std::string> rawtockens;
        {
            size_t from = 0;
            size_t indx = path.find('/');
            while(indx != std::string::npos)
            {
                size_t const after = indx + 1;
                rawtockens.push_back(path.substr(from, after - from)); // придумать как не угадывать
                from = after;
                indx = path.find('/', after);
            }

            // handle tail
            if (from < path.size())
            {
                rawtockens.push_back(path.substr(from));
            }

            if ("." == rawtockens.back())
            {
                rawtockens.pop_back();
            }
        }

        std::vector<std::string> validtockens;
        validtockens.push_back(rawtockens.front());
        for(size_t i = 1; i < rawtockens.size(); i++)
        {
            auto const& elem = rawtockens[i];
            if ("./" == elem || "/" == elem)
            {
                // skip
            }
            else if ("../" == elem || ".." == elem)
            {
                validtockens.pop_back();
                if (validtockens.empty())
                {
                    validtockens.push_back("/");
                }
            }
            else
            {
                validtockens.push_back(elem);
            }
        }

        std::string result(validtockens.empty() ? "/" : "");
        {
            for(auto const& e : validtockens)
            {
                result.append(e);
            }
            if (result.size() > 1 && result.back() == '/')
            {
                result.pop_back();
            }
        }

        return result;
    }
};

// "/", "home/"

// "home/", "/", "/"
// "../"
// "./"

