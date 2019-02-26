/** My solution was ok. But it was too long and wasn't quite right.
	This solution was taken from the user. Much cleaner and better.
**/

vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    
    // Iterate through all elements aside from 1st.
    for (int i = 1; i < ins.size(); i++) {
        // If start is higher than the end of the previous elememt, that means there's no overlap.
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
        // If overlaps, just change the end of the last element to higher.
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}
