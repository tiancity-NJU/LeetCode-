
/*

   和前面的同理

*/


public class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int res = 0;
        int [] map = new int[256];
        int walker = 0;
        int runner = 0;
        int count = 0;
        while(runner < s.length()){
            if(map[s.charAt(runner++)]++ == 0){
                count++;
            }
            while(count > k){
                if(map[s.charAt(walker++)]-- == 1){
                    count--;
                }
            }
            res = Math.max(res, runner - walker);
        }
        return res;
    }
}
