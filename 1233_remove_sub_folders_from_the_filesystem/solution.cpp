class Trie final
{
public:
    struct node final
    {
        std::unordered_map<std::string, std::unique_ptr<node>> nodes;
        bool is_present{};
    };

    //
    // return true if subvalue is exists
    //
    bool put(std::string const& cref)
    {
        auto const splitter = [cref, from = 0, current = 1](std::string& res) mutable -> bool
        {
            if (from != std::string::npos)
            {
                auto const pos = cref.find('/', current);
                res = cref.substr(from, pos - from);
                from = pos;
                current = pos + 1;
                return true;
            }
            else
            {
                return false;
            }
        };

        bool exists_before{};
        std::string path;
        node* current = &m_root;
        while (splitter(path))
        {
            auto& ptr = current->nodes[path];
            if (ptr == nullptr)
            {
                ptr = std::make_unique<node>();
            }
            current = ptr.get();
            if (current->is_present)
            {
                exists_before = true;
            }
        }
        current->is_present = true;

        return exists_before;
    }

private:
    node m_root;
};

class Solution final
{
public:
    static vector<string> removeSubfolders(vector<string>& folders)
    {
        std::sort(folders.begin(), folders.end(), [](auto const& s1, auto const& s2)
        {
            return s1.length() < s2.length();
        });

        Trie trie;
        std::vector<std::string> res;

        for(auto const& folder : folders)
        {
            if (not trie.put(folder))
            {
                res.push_back(folder);
            }
        }

        return res;
    }
};

