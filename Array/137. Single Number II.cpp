

/*
  
    该题对应的位运算方法太复杂，以下是另一种思路，是针对找不同数目数字的通用解
    通过对32位每一个出现的次数进行统计，额外多出来的肯定是额外数提供的

*/




int length = nums.size();
        int result = 0;
        for(int i = 0; i<32; i++){
            int count = 0; 
            int mask = 1<< i;
            for(int j=0; j<length; j++){
                if(nums[j] & mask)
                    count++;
            }
          if(count %3)
                result |= mask;
        }
        return result;
