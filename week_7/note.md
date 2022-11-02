# 11/02 程式設計研討專題

這周有一題(應該不是第五題跟第三題)+01背包有一題

## 定時K彈 (10/19)

### 想法一 動態規劃 O(K)

### 想法二

[約瑟夫問題 youtube](https://www.youtube.com/watch?v=Yeh1_2GyS5s&vl=zh-Hant)
[約瑟夫問題 wiki](https://zh.wikipedia.org/zh-tw/%E7%BA%A6%E7%91%9F%E5%A4%AB%E6%96%AF%E9%97%AE%E9%A2%98)

## 164 String Computer

### 題目

[題目連結](https://vjudge.net/problem/UVA-164)
![](https://i.imgur.com/k0Gupcb.png)

![](https://i.imgur.com/8wY6ifG.png)

### 題解

`edit distance`

[leetcode相似題 72 edit distance](https://leetcode.com/problems/edit-distance/)

![](https://i.imgur.com/sJPi2Si.png)

![](https://i.imgur.com/yFRS1Tc.png)

![](https://i.imgur.com/oN92Fz1.png)

![](https://i.imgur.com/MqrpEme.png)

![](https://i.imgur.com/o90oWa4.png)

![](https://i.imgur.com/18P2Efd.png)

由表格右下角向左上或向上去追溯。

## 10069 Distinct Subsequences

### 題目

![](https://i.imgur.com/lWiYj2O.png)
exp:

```
input:
1
babgbag
bag

output:
5
```

### 題解LCS

## LeetCode 354. Russian Doll Envelopes

### 題目

![](https://i.imgur.com/yjUFXsK.png)

### 題解 LIS

[leetcode 300 lis基本題解 O(nlogn)](https://leetcode.cn/problems/longest-increasing-subsequence/solutions/14796/dong-tai-gui-hua-she-ji-fang-fa-zhi-pai-you-xi-jia/)

先排序，排序後，就轉換成LIS問題了。(但這題排序要比較特別一點)

![](https://i.imgur.com/D7eWiCU.png)

[leetcode cn 題解](https://leetcode.cn/problems/russian-doll-envelopes/solution/zui-chang-di-zeng-zi-xu-lie-kuo-zhan-dao-er-wei-er/)

![](https://i.imgur.com/12ZsBN9.png)

![](https://i.imgur.com/fmJfpFG.png)

## 10154 Weights and Measures

### 題目

![](https://i.imgur.com/QgJKSHz.png)

![](https://i.imgur.com/RBX1CiR.png)

### 題解

[題解](https://nicknick0630.github.io/2019/03/07/UVa-10154-Weights-and-Measures/)

1. dp
   ![](https://i.imgur.com/CW16dP1.png)
2. priority queue
   ![](https://i.imgur.com/mfDtP24.png)

## 11031 Looking for a Subset

### 題目

![](https://i.imgur.com/IeslG6C.png)
**input**

```
S={3,4,1,2,3,6}
3
2
```

**output**

```
1 2 3
3 4
```

### 題解

[網路題解](https://morris821028.github.io/2014/06/12/oj/uva/uva-11031/)

## 額外筆記

* 寫遞迴式 不要用小括號(通常小括號是代表用呼叫的 top down) 建議用中括號(代表用陣列 bottom up)
* 以後報告 可以先隱藏output 問題問人覺得這題output是多少
