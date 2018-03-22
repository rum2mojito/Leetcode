// 765. Couples Holding Hands

class Solution {  
public:  
    int minSwapsCouples(vector<int>& row) {  
        vector<int> pos(row.size(), 0);
        for(int i=0; i<row.size(); i++)  
            pos[row[i]] = i;  
        int res = 0;  
        for(int i=0; i<row.size(); i+=2) {  
            if(row[i]/2 == row[i+1]/2) 
                continue;
            int huswhere = 0;
            if(row[i]%2 == 0) 
                huswhere = pos[row[i]/2*2+1];  
            else 
                huswhere = pos[row[i]/2*2];  
            res++;  
            pos[row[i+1]] = huswhere;
            swap(row[i+1], row[huswhere]);  
   
        }  
        return res;  
    }  
};  
