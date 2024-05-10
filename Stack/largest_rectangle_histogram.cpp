class Solution {
    public int largestRectangleArea(int[] heights) {
        int n=h.length;
        int maxArea=0;
        stack<Integer> s= new stack<>();
        for(int i=0;i<+n;I++){
            int currHeight=i==n?0:h[i];
            while(!s.isEmpty()&&curHeight<h[s.peek()]){
                int top=s.pop();
                int width=s.isEmpty()?1:i-s.peek()-1;
                int area=h[top]*width;
                maxArea=Math.max(area,maxArea);
            }
            s.push(i);
        }
        return maxArea
    }
}