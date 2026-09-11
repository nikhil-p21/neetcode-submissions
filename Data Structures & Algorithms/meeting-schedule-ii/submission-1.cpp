/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort(intervals.begin(), intervals.end()); 
        vector<int>starts; 
        vector<int>ends; 
        for(auto &x: intervals)
        {
            starts.push_back(x.start); 
            ends.push_back(x.end); 
        }
        sort(starts.begin(), starts.end()); 
        sort(ends.begin(), ends.end()); 
        int i=0, j=0; 
        int n = starts.size(); 
        int curr_rooms = 0, max_rooms = 0; 
        while(i<n)
        {
            if(starts[i]<ends[j])
            {
                curr_rooms++; 
                i++; 
            }
            
            else
            {
                curr_rooms--; 
                j++; 
            }

            max_rooms = max(max_rooms, curr_rooms); 
            
        }

        return max_rooms; 

    }
};
