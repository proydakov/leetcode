#include <set>

class MedianFinder
{
public:
    MedianFinder() {
    }

    void addNum(int num) {
        m_low.insert(num);

        {
            auto it = m_low.end();
            --it;
            int temp = *it;
            m_low.erase(it);
            m_big.insert(temp);
        }

        if(m_big.size() > m_low.size()) {
            auto it = m_big.begin();
            int temp = *it;
            m_low.insert(temp);
            m_big.erase(it);
        }
    }

    double findMedian() {
        if(m_low.empty()) {
            return 0;
        }

        if(m_low.size() > m_big.size()) {
            auto it = m_low.rbegin();
            int temp = *it;
            return temp;
        }

        const double v2 = static_cast<double>(*m_low.rbegin()) + static_cast<double>(*m_big.begin());
        return v2 / 2;
    }

private:
    std::multiset<int> m_low;
    std::multiset<int> m_big;
};
