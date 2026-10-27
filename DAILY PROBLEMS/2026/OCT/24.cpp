// 2409. Count Days Spent Together
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        string startdate = max(arriveAlice, arriveBob);
        string enddate = min(leaveAlice, leaveBob);

        int startmonth = stoi(startdate.substr(0, 2));
        int endmonth = stoi(enddate.substr(0, 2));

        int startday = stoi(startdate.substr(3, 2));
        int endday = stoi(enddate.substr(3, 2));

        if(startmonth > endmonth)
            return 0;
        else if(startmonth == endmonth && startday > endday)
            return 0;

        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int ans = 0;

        if(startmonth == endmonth)
            ans += endday - startday + 1;
        else{
            ans += days[startmonth] - startday + 1;

            for(int i = startmonth + 1; i < endmonth; i++)
                ans += days[i];
            
            ans += endday;
        }

        return ans;
    }
};