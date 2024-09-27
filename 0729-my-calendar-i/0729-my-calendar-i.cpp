class MyCalendar {
public:
    vector<pair<int, int>> period;
    MyCalendar() {}
    bool book(int start, int end) {
        if (period.empty()) {
            period.push_back({start, end});
        } else {
            for (auto it : period) {
                if (start < it.second && it.first < end) {
                    return false;
                }
            }
             period.push_back({start, end});
        }
        return true;
    }
};
//  for (const auto& it : time) {
//                 if (start < it.end && end > it.start) {
//                     return false;
//                 }
//             }

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */