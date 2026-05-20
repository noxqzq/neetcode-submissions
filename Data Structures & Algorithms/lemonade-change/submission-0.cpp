class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;  // number of $5 bills we have
        int ten = 0;   // number of $10 bills we have

        for(int bill : bills) {
            if(bill == 5) {
                // No change needed, just keep the $5
                five++;
            } 
            else if(bill == 10) {
                // Need to give $5 change
                if(five >= 1) {
                    five--;  // give one $5
                    ten++;   // keep the $10
                } else {
                    return false; // can't give change
                }
            } 
            else if(bill == 20) {
                // Need to give $15 change
                if(ten >= 1 && five >= 1) {
                    // Prefer giving $10 + $5
                    ten--;
                    five--;
                } 
                else if(five >= 3) {
                    // Otherwise give 3×$5
                    five -= 3;
                } 
                else {
                    return false; // can't give change
                }
            }
        }

        // If we never ran out of change
        return true;
    }
};
