#include <vector>

float count_mean_even(const std::vector<int>& data)
{
    float res = 0;
    int cnt = 0;
    for(std::vector<int>::size_type i = 0; i < data.size(); ++i)
    {
        if(data[i] % 2 == 0 && data[i] > 0)
        {
            res += data[i];
            ++cnt;
        }
    }
    return res / cnt;
}
