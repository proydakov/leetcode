#include <set>
#include <vector>

class MedianFinder
{
public:
    MedianFinder() {
    }

    void addNum(int num) {
        m_low.insert(num);
        balance();
    }

    void removeNum(int num) {
        auto it = m_low.find(num);
        if(it == m_low.end()) {
            auto big_it = m_big.find(num);
            m_big.erase(big_it);
            balance();
        }
        else {
            m_low.erase(it);
            if(m_low.size() < m_big.size()) {
                auto it = m_big.begin();
                int val = *it;
                m_low.insert(val);
                m_big.erase(it);
            }
        }
    }

    double findMedian() {
        if(m_low.size() > m_big.size()) {
            auto it = m_low.rbegin();
            int temp = *it;
            return temp;
        }
        else {
            const double v2 = static_cast<double>(*m_low.rbegin()) + static_cast<double>(*m_big.begin());
            return v2 / 2;
        }
    }

private:
    void balance()
    {
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

private:
    std::multiset<int> m_low;
    std::multiset<int> m_big;
};

class Solution {
public:
    std::vector<double> medianSlidingWindow(const std::vector<int>& nums, int k) {
        MedianFinder filter;

        std::vector<double> result;
        result.reserve(nums.size());

        for(int i = 0; i < k; i++) {
            filter.addNum(nums[i]);
        }
        
        result.push_back(filter.findMedian());
        
        for(int i = k; i < nums.size(); i++) {
            filter.removeNum(nums[i - k]);
            filter.addNum(nums[i]);
            result.push_back(filter.findMedian());
        }
        
        return result;
    }
};
