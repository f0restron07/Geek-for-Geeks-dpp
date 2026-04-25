class Solution {
    public ArrayList<Integer> reducePairs(int[] arr) {
        ArrayList<Integer> s=new ArrayList<>();
        for(int x:arr){
            boolean alive=true;
            while(!s.isEmpty()&&((long)x*s.get(s.size()-1)<0)){
                int t=s.get(s.size()-1);
                int at=Math.abs(t),ax=Math.abs(x);
                if(at<ax){
                    s.remove(s.size()-1);
                }else if(at==ax){
                    s.remove(s.size()-1);
                    alive=false;
                    break;
                }else{
                    alive=false;
                    break;
                }
            }
            if(alive) s.add(x);
        }
        return s;
    }
}