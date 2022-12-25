//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool MyComp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<vector<int>> temp;
        
        for(int i = 0 ; i < start.size(); i++){
            temp.push_back({start[i] , end[i]});
        }
        
        sort(temp.begin() , temp.end() , MyComp);
        
        int count = 1;
        int last = temp[0][1];
        
        for(int i = 1 ; i < temp.size() ; i++){
            if(temp[i][0] > last){
                last = temp[i][1];
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends