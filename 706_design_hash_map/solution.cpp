class MyHashMap final
{
public:
    MyHashMap()
        : m_count(0)
        , m_table(16)
    {
    }

    void put(int key, int value)
    {
        const auto idx = hash(key, m_table.size());
        auto& cell = m_table[idx];

        // try update item
        auto it = std::find_if(cell.begin(), cell.end(), [key](auto const& pair){
            return pair.first == key;
        });

        if (it != cell.end())
        {
            (*it).second = value;

            return;
        }

        // insert a new item
        cell.push_back({key, value});
        m_count++;

        if (m_count >= m_table.size())
        {
            rehash();
        }
    }

    int get(int key) const
    {
        const auto idx = hash(key, m_table.size());
        auto const& cell = m_table[idx];

        // try find item
        auto const it = std::find_if(cell.cbegin(), cell.cend(), [key](auto const& pair){
            return pair.first == key;
        });

        return it != cell.end() ? (*it).second : -1;
    }

    void remove(int key)
    {
        if (m_count > 0)
        {
            const auto idx = hash(key, m_table.size());
            auto& cell = m_table[idx];
            auto const it = std::find_if(cell.begin(), cell.end(), [key](auto& pair){
                return pair.first == key;
            });
            if (it != cell.end())
            {
                cell.erase(it);
                m_count--;
            }
        }
    }

private:
    inline size_t hash(int key, size_t size) const
    {
        return key % size;
    }

    void rehash()
    {
        std::vector<std::list<std::pair<int, int>>> new_table(m_table.size() * 2);
        for(auto& cell : m_table)
        {
            for(auto it = cell.begin(); it != cell.end();)
            {
                auto copy_it = it++;
                auto const new_index = hash((*copy_it).first, new_table.size());
                auto& new_cell = new_table[new_index];
                new_cell.splice(new_cell.end(), cell, copy_it);
            }
        }
        std::swap(new_table, m_table);
    }

private:
    size_t m_count;
    std::vector<std::list<std::pair<int, int>>> m_table;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

