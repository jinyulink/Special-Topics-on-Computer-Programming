# 10/26 程式設計研討專題

1. 10721 Bar Codes
2. 10157 Expressions
3. 10328 Coin Toss
4. 12045 Fun with Strings
5. NCPC 2018C : Partition an Integer

組合學 基本上很多題目會推出一個轉移式，然後用dp去解
加法原則 乘法原則

## 10721 Bar Codes

`DP 組合`
[題目連結](https://vjudge.net/problem/UVA-10721)

### 題目

bar是由同顏色的連續unit組成 (單一條是一個unit)
第一個bar永遠都是black bar
題目給(n,k,m)

* n是有幾個unit
* k個bar
* m 每個bar長度不可超過m個unit

問你bar code的組合數有幾種?

**輸入**

```
7 4 3 
7 4 2
```

**輸出**

```
16
4
```

### 解題

用dp算排列組合
先直接用dp建一個表
題目問什麼 直接查表輸出
`BC(n,k,m)`=`[有n個unit 要組成k個bar 每個bar長度不超過m]`的組合數
只用到加法原則

* exp: BC(7,3,4)=BC(6,2,4)+BC(5,2,4)+BC(4,2,4)+BC(3,2,4) `可以看到m永遠一樣`
  1. 代表最前面第一個黑色Bar 有1個unit
  2. 代表最前面第一個黑色Bar 有2個unit
  3. 代表最前面第一個黑色Bar 有3個unit
  4. 代表最前面第一個黑色Bar 有4個unit
     ![](https://i.imgur.com/3lE7I3A.png)

記得用 `long long`題目會到 `signed 64 bits`

### 參考

https://www.pinghenotes.com/UVa-10721-Bar-Codes/
https://blog.csdn.net/mobius_strip/article/details/45092387

## 10157 Expressions

`DP 組合 數學 大整數`
[題目連結](https://vjudge.net/problem/UVA-10157)

### 題目

* 括號串，exp: 4對括號串 代表有8個字元 `()()()()`
* 括號深度為 `d`代表被 `d-1`個括號包著

題目給定整數 `n` `d`，求 `n/2`對括號能夠形成最大深度 `d`的括號排列數
**輸入**

```
6 2
300 150
```

**輸出**

```
3
1
```

### 解題

1. 暴力解
   * 檢查一括號串最大深度 `O(n)`
   * 複雜度=`所有合法括號串的組合數*線性時間`(每個組合都花O(n)檢查深度)
   * 假設有 `n`對括號串，其括號串的組合數為 `Catalan number`
2. DP解

### 參考

https://blog.csdn.net/mobius_strip/article/details/39269541

## 10328 Coin Toss

`DP 高精度`
[題目連結](https://vjudge.net/problem/UVA-10328)

### 題目

丟同一個硬幣 `n`次，問丟出來連續至少有 `k`個正面的次數。
即從 `2^n`種方法中，有幾種連續至少有 `k`個正面。

### 解題

1. 暴力
   * 枚舉有 `2^100`次方 tle
2. 排列組合
   * 連續出現最多n個H - 連續出現最多n-1個H

![](https://i.imgur.com/Lw3nGu4.png)

![](https://i.imgur.com/ejqrZKV.png)

### 參考

https://blog.csdn.net/accelerator_/article/details/16830585

## 12045 Fun with Strings

[題目連結](https://vjudge.net/problem/UVA-12045)

### 題目

* 給一個字串，字串僅包含 `'a'`跟 `'b'`兩個字元
* 每經過一個步驟，`'a'`->`'b'`，`'b'`->`'ab'`
* 經過 `N`個步驟後，長度為 `X`，經過 `M`個步驟後，長度為 `Y`，問第 `K`個步驟長度為多少?
* 答案Mod `1e9+7`
* 如果無解輸出 `Impossible`

### 解題

1. 用加法 慢慢算費氏數列 -> 會TLE `O(n)`
   * F [ n ] = F [ n – 1 ] + F [ n – 2 ] (全用加法) 會超時
     ![](https://i.imgur.com/kJawZY7.png)
2. 矩陣快速冪 更快求出費氏數列 `O(logN)`
   * [更快算出費氏數列](https://medium.com/starbugs/find-nth-fibonacci-number-by-fast-doubling-6ac2857a7834)
     ![](https://i.imgur.com/jsBasCv.png)

### 參考

https://www.cnblogs.com/LyonLys/archive/2013/04/23/LOJ_1052_uva_12045_Lyon.html

## NCPC 2018C : Partition an Integer

![](https://i.imgur.com/ORTczc4.png)

### 題目

`n`為一個大於2的整數(最大到 `2^31`)，對於每個 `n` 找出三個正整數 `(a,b,c)`，滿足 `n=a+b+c`,且 `lcm(a,b,c)`最小 (最小公倍數)

### 解題

* 如果 `n`是奇數
  * `n`=`2k+1=k+k+1`
  * 

## 額外筆記

* `__int128` 不能用 `cin` `cout` 要自己處理
* 一般dp只要有遞迴式，就不用pseudo code了
* k|c k整除c的意思
