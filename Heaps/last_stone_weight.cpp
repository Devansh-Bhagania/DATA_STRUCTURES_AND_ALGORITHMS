class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;


        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()!= 1){
            int x =  pq.top();
            pq.pop();
            if(!pq.empty()){
                int y = pq.top();
                pq.pop();
                pq.push(x-y);
            }
            else{
                return pq.top();
            }
           
        }
 return pq.top();
    }
};