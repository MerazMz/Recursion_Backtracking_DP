class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour*60;
        double m = minutes*11;
        double ans = abs((h-m)/2);
        return (ans<180)? ans : 360-ans;
    }
};