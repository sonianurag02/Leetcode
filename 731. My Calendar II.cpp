// --------------------- Approach - 1 --------------------------

class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleOverlappedRegion;
    vector<pair<int, int>> overallBookings;

    bool checkOverlap(int start1, int end1, int start2, int end2){
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // Check if tripe booking region is created or not
        for(pair<int, int> region: doubleOverlappedRegion){
            if(checkOverlap(region.first, region.second, start, end)){
                return false;
            }
        }

        // check if it creating double booking
        for(pair<int, int> bookings: overallBookings){
            if(checkOverlap(bookings.first, bookings.second, start, end)){
                doubleOverlappedRegion.push_back(findOverlappedRegion(bookings.first, bookings.second, start, end));
            }
        }

        overallBookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */