class Solution {
public:

    struct workerInfo {
        int base_cost;
        long long seconds_spent;
        long long cur_cost;
    };

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        std::multimap<long long, workerInfo> times;
        for (auto worker: workerTimes) {
            workerInfo info(worker, 0, worker);
            times.emplace(worker, info);
        }
        for (int i = 0; i != mountainHeight; ++i) {
            auto elem = *(times.begin());
            auto elem_info = elem.second;
            times.erase(times.begin());
            long long new_key = elem.first + elem_info.cur_cost + elem_info.base_cost;
            workerInfo info(elem_info.base_cost, elem.first, elem_info.cur_cost + elem_info.base_cost);
            times.emplace(new_key, info);
        }
        long long res = (*(times.begin())).second.seconds_spent;
        for (auto& elem : times) {
            res = std::max(res, elem.second.seconds_spent);
        }
        return res;
    }
};