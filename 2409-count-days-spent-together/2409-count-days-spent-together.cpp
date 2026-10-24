class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto toDayOfYear = [&](const string& date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int result = day;
            for (int i = 0; i < month - 1; ++i) {
                result += daysInMonth[i];
            }
            return result;
        };

        int aliceStart = toDayOfYear(arriveAlice);
        int aliceEnd = toDayOfYear(leaveAlice);
        int bobStart = toDayOfYear(arriveBob);
        int bobEnd = toDayOfYear(leaveBob);

        int overlapStart = max(aliceStart, bobStart);
        int overlapEnd = min(aliceEnd, bobEnd);
        return max(0, overlapEnd - overlapStart + 1);
    }
};