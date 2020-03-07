####文本块
``` c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[i + start + n - k]);
            }
            n -= k;
            start += k;
        }
    }
};
```

---
####列表
>>有序数字
>>1. 封装
    >>1.1
>>2. 继承
>>3. 多态  

>复选框
>>- [ ] nihao
>>- [X] nibuhao  

---  
####高亮  
`nihao` `dajiahao` 

---
####引用
[wobuhao](www.baidu.com "百度")  

---
####表格  
| 我 | 你 | 他 |
| :---- | ----: | :----: |
| *斜体文本* | **粗体文本** | ***粗斜体文本*** |  
| _斜体文本_ | __粗体文本__ | ___粗斜体文本___ |  

---
####图片
![RUNOOB 图标](http://static.runoob.com/images/runoob-logo.png "标题") 

---
使用 <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Del</kbd> 重启电脑