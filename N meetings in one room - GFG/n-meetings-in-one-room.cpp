//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool myComp(vector<int>&v1 , vector<int>&v2){
        return v1[1] < v2[1];
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> temp;
        
        for(int i = 0 ; i < n; i++){
            temp.push_back({start[i],end[i]});
        }
        
        sort(temp.begin() , temp.end() , myComp);
        
        int count = 1;
        int last = temp[0][1];
        
        for(int i = 1; i < n ; i++){
            if(temp[i][0] > last){
                last = temp[i][1];
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends