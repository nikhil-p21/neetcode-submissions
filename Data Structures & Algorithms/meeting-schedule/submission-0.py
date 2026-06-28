"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        if len(intervals)==0 or len(intervals)==1:
            return True 
        intervals.sort(key=lambda x: x.start)
        for index, pairs in enumerate(intervals[1:]):
            prev_interval = intervals[index]
            curr_interval = pairs
            if curr_interval.start<prev_interval.end:
                return False 
        return True



