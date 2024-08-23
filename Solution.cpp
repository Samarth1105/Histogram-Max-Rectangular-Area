class Solution {
    public:
    long long getMaxArea(long long arr[], int n)
    {
        long long max_area=0;
        stack<long long>s;
        long long tp;
        long long curr_area;
        
        int i=0;
        while(i<n){
            if(s.empty() || arr[i] >= arr[s.top()]){
                s.push(i++);
            }
            else{
                tp= s.top();
                s.pop();
                
                curr_area= arr[tp]*(s.empty() ?
                    i
                    :
                    (i-s.top()-1)
                );
                if(curr_area>max_area) max_area=curr_area;
            }
        }
        while(!s.empty()){
            tp= s.top();
            s.pop();
            curr_area= arr[tp]*(s.empty() ?
                    i
                    :
                    (i-s.top()-1)
                );
                if(curr_area>max_area) max_area=curr_area;
        }
        return max_area;
    }
};
