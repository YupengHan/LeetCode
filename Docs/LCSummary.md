# C/C++ Templates
### Double Pointer O(n) Search

- Sliding Window Template
``` C++
for (i = 0; i < n; i++) {
    while(j<n ) {
        if (satisfied) {
            j++
            update j
        }
        else (unsatisfied){
            break;
        }
        update i;
    }
}
```

- LeetCode
    - 209, 3, 76 

- Permutation Template
```C++
void digui(string str,int begin,int l,vector<string> &res)
    {
        if(begin==l)
            res.push_back(str)
        else
        {
            for(int i=begin;i<=l;i++)
            {
                if(begin!=i&&str[begin]==str[i])//防止有相同的字符，就不用进行交换了，前面个判断条件是因为自身也需要交换一次，如果不加，就会一起跳过，就本来的排列都不会被添加进结果。。
                    continue;
                swap(str[begin],str[i]);
                digui(str,begin+1,l,res);
                swap(str[begin],str[i]);
            }
        }
        return ;
    }
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.size()==0)
            return res;
        int l=str.size()-1;
        digui(str,0,l,res);
        return res;        
    }
```

- Kth Smallest in sorted matrix
    - Use queue, each time remove one item and add it's neighbor
    - Usage of queue with your own class
    ```C++
    class mypair {
        int x, y, val;
        mapair(int _x, int _y, int _val) {
            this->x = _x;
            this->y = _y;
            this->val = _val;
        }
    };

    struct mycompare {
    public:
        bool operator() (mypair& a, mypair& b) {
            return a.val > b.val;
        }
    }

    priority_queue<mypair, vecotor<mypair>, mycompare> minH;

    ```
    - 378, 1439(Hard), 373(convert two array into a matrix, then similar to 378)




