

/*

  google面试题，最粗暴的有两种方法： 每次扫描K个List，然后找到他们的最小值加入，这样对于总规模N的结构来说时间复杂度  O(KN)
  另一种方法，就是以此扫描所有链表，将数值全部加入到一个数组中然后排序，最后再以此生成 时间复杂度  O(NlgN+2N)  +  O(N) 的空间复杂度
  
  但是这样还是太慢，如果能对K个List两两合并，最会汇总，那么时间复杂度就是 O(NlgK)
  以下提供两种解法

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
       vector<int>res;
		for (int i = 0; i < lists.size(); i++)
		{
			while (lists[i] != NULL)
			{
				res.push_back(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		sort(res.begin(), res.end());
		if (res.empty()) return NULL;
		ListNode* start = new ListNode(res[0]);
		ListNode* end = start;

		for (int i = 1; i < res.size(); i++)
		{
			end->next = new ListNode(res[i]);
			end = end->next;
		}
		return start;
    }
};

/*
    利用两个Head指针list，相互更新，直到其中一个list里面只有一个指针为止，主要要在合并的时候进行奇偶长度的判断
    该方法能够打败99.68%的答案，而且时间复杂度在O(NlgK) 空间复杂度在O(K)，需要借助上一问的两个list合并的函数

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        ListNode* result=new ListNode(0);
        ListNode* tmp=result;
        while(l1!=NULL||l2!=NULL)
        {
            if(l2==NULL||(l1!=NULL&&l1->val<=l2->val))
            {
                tmp->next=l1;
                l1=l1->next;
            }
            else
            {
                tmp->next=l2;
                l2=l2->next;
            }
            tmp=tmp->next;
        }
        return result->next;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0) return NULL;
        vector<vector<ListNode*>>head(2,vector<ListNode*>());
        
        for(auto c:lists) head[0].push_back(c);
        
        int time=0;
        while(head[0].size()!=1&&head[1].size()!=1)
        {
            int i;
            for(i=0;i<head[time%2].size()-1;i+=2)
                head[(time+1)%2].push_back(mergeTwoLists(head[time%2][i],head[time%2][i+1]));
            if(i==head[time%2].size()-1) head[(time+1)%2].push_back(head[time%2][i]);
            head[time%2].clear();
            time++;
        }
        
        return head[0].size()==1?head[0][0]:head[1][0];
        
    }
};

