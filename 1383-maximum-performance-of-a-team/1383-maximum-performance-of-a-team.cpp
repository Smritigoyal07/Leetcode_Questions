class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//         int m = 10e+7;
//         vector<pair<int,int>> v;
        
//         for(int i = 0 ; i < n ; i++){
//             v.push_back({efficiency[i],speed[i]});
//         }
        
//         sort(v.begin(),v.end());
        
//         long sum = 0;
//         long ans = 0;
        
//         // at most --> priority queue 
//         // we need to store speed in this queue 
//         // at pq.pop() we need to remove min speed that's why we will use min heap
        
//         priority_queue<int , vector<int> , greater<int> > pq;
        
//         for(auto i = n-1 ; i>=0 ;i--){
//             long e = v[i].first;
//             long s = v[i].second;
            
//             sum += s;
//             pq.push(s);
            
//             if(pq.size()>k){
//                 sum = sum - pq.top();
//                 pq.pop();
//             }
            
//             ans=max(ans,sum*e);
//         }        
        
//         return ans%m;
        
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i], speed[i]});
        }
        
        long sum=0,ans=0;
        sort(v.begin(),v.end());
        for(auto i=n-1;i>=0;i--){
            
            sum +=v[i].second;
            pq.push(v[i].second);
            if(pq.size()>k){
                sum-= pq.top();
                pq.pop();
            }
            
            ans=max(ans, sum*v[i].first);
        }
        
        return ans%1000000007;
    }
};