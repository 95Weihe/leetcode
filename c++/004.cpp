class Solution {
//关键：寻找第 k 小的数
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        if(len%2){
            return getKth(nums1,nums2,len/2+1);
        }else{
            return (getKth(nums1,nums2,len/2)+getKth(nums1,nums2,len/2+1))/2.0;
        }
    }

    int getKth(vector<int>& nums1, vector<int>& nums2, int k){
        int index1=0, index2=0;
        int n1=nums1.size(), n2=nums2.size();
        while(true){
            if(index1 == n1)
                return nums2[index2+k-1];
            if(index2 == n2)
                return nums1[index1+k-1];
            if(k==1)
                return min(nums1[index1],nums2[index2]);

            int Nindex1 = index1+k/2-1>n1-1?n1-1:index1+k/2-1;
            int Nindex2 = index2+k/2-1>n2-1?n2-1:index2+k/2-1;
            int c1 = nums1[Nindex1];
            int c2 = nums2[Nindex2];
            if(c1<=c2){
                k -= Nindex1-index1+1;
                index1 = Nindex1+1;
            }else{
                k -= Nindex2-index2+1;
                index2 = Nindex2+1;
            }
        }
    }
};