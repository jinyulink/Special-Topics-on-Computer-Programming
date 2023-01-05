# 程式設計研討專題 12/14

開更號 直式開更號最快/牛頓/二分

## 主題

下禮拜是**幾何**

[csdn](https://blog.csdn.net/qq_17550379/article/details/102514058)


* [max flow min cut](https://cp-algorithms.com/graph/edmonds_karp.html) 第一題
  - Edmonds-Karp (比較古老 比較慢)
  - Ford-Fulkerson (更古老)
  - [dinic](https://cp-algorithms.com/graph/dinic.html)
* 二分圖匹配
  - 可以用 max flow 或 匈牙利算法 來解

## 10480 Sabotage

[連結](https://vjudge.net/problem/UVA-10480)

* 給節點數n(<=50)，無向邊個數m(<=500)，以及權重（1~4e7），以最小cost將一些邊去除掉，讓1根2分開，輸出要去除掉的邊。
* **最大流最小割，並印出路徑** | **max flow min cut**

## 10092 The Problem with the Problem Setter

[連結](https://vjudge.net/problem/UVA-10092)

* 二分圖最大匹配 (KM?)
* Ford-Fulkerson
* [題解](https://blog.csdn.net/J_Dark/article/details/8831826)

## 10330 Power Transmission

* 一张有向图由n个点构成，每个点都有一个容量限制，然后给出多个源点和多个汇点。
* [題解](https://blog.csdn.net/slow_wakler/article/details/47341263)
* [題解2](https://blog.csdn.net/hcbbt/article/details/17169869)

## 10804 Gopher Strategy

* 有點幾何再裡面
* 二分圖匹配(可以用匈牙利算法)

## 11418 Clever Naming Patterns
