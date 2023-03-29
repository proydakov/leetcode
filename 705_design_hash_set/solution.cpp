class MyHashSet final
{
public:
    MyHashSet()
        : m_count(0)
        , m_table(16)
    {
    }

    void add(int key)
    {
        const auto idx = hash(key, m_table.size());
        auto& cell = m_table[idx];

        // try update item
        auto it = std::find(cell.begin(), cell.end(), key);

        if (it != cell.end())
        {
            return;
        }

        // insert a new item
        cell.push_back(key);
        m_count++;

        if (m_count >= m_table.size())
        {
            rehash();
        }
    }

    bool contains(int key) const
    {
        const auto idx = hash(key, m_table.size());
        auto const& cell = m_table[idx];

        // try find item
        auto const it = std::find(cell.cbegin(), cell.cend(), key);

        return it != cell.end();
    }

    void remove(int key)
    {
        if (m_count > 0)
        {
            const auto idx = hash(key, m_table.size());
            auto& cell = m_table[idx];
            auto const it = std::find(cell.begin(), cell.end(), key);
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
        std::vector<std::list<int>> new_table(m_table.size() * 2);
        for(auto& cell : m_table)
        {
            for(auto it = cell.begin(); it != cell.end();)
            {
                auto copy_it = it++;
                auto const new_index = hash((*copy_it), new_table.size());
                auto& new_cell = new_table[new_index];
                new_cell.splice(new_cell.end(), cell, copy_it);
            }
        }
        std::swap(new_table, m_table);
    }

private:
    size_t m_count;
    std::vector<std::list<int>> m_table;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

