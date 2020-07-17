# CPP-LeetCode

## DFS

### 98.Validate Binary Search Tree

用LONG_MAX和LONG_MIN作为无穷大的数代替INT_MAX和INT_MIN去解决INT的边界问题





## 动态规划

### 62 - 64.不同路径

这三题题型十分类似，62为最简单的版本，63在62的基础上加了障碍物，64将格子内容改变，转换为普遍的整数和的形式。

yc个人认为难度不大，使用简单的动规即可解决。可以将二维的数组改进成一维，节省空间。此外使用数组似乎效率比向量高很多？（有待考证）

### 

## 链表

### 138. 复制带随机指针的链表

这题的其中一个解法十分有意思：第一步先将原链表进行扩展，在每个原结点的右边加入一个新分配的值一样的节点，从而方便进行随机指针的分配。在分配完毕之后，再进行链表的分解。

以这种思路就不需考虑复杂的环路等等，用几行代码就可以构造出新链表的随机指针指向

```c++
// construct random ptr
iter = head;
while (iter)
{
if (iter->random)
{
iter->next->random = iter->random->next;
}
else
{
iter->next->random = nullptr;
}

iter = iter->next->next;
}
```



### 148. 排序链表

特别适合练习基本功的一题，将O(nlogn)的排序算法应用到链表之中（我提交时使用的是归并排序）。

