# 10/26 �{���]�p��Q�M�D

1. 10721 Bar Codes
2. 10157 Expressions
3. 10328 Coin Toss
4. 12045 Fun with Strings
5. NCPC 2018C : Partition an Integer

�զX�� �򥻤W�ܦh�D�ط|���X�@���ಾ���A�M���dp�h��
�[�k��h ���k��h

## 10721 Bar Codes

`DP �զX`
[�D�سs��](https://vjudge.net/problem/UVA-10721)

### �D��

bar�O�ѦP�C�⪺�s��unit�զ� (��@���O�@��unit)
�Ĥ@��bar�û����Oblack bar
�D�ص�(n,k,m)

* n�O���X��unit
* k��bar
* m �C��bar���פ��i�W�Lm��unit

�ݧAbar code���զX�Ʀ��X��?

**��J**

```
7 4 3 
7 4 2
```

**��X**

```
16
4
```

### ���D

��dp��ƦC�զX
��������dp�ؤ@�Ӫ�
�D�ذݤ��� �����d���X
`BC(n,k,m)`=`[��n��unit �n�զ�k��bar �C��bar���פ��W�Lm]`���զX��
�u�Ψ�[�k��h

* exp: BC(7,3,4)=BC(6,2,4)+BC(5,2,4)+BC(4,2,4)+BC(3,2,4) `�i�H�ݨ�m�û��@��`
  1. �N��̫e���Ĥ@�Ӷ¦�Bar ��1��unit
  2. �N��̫e���Ĥ@�Ӷ¦�Bar ��2��unit
  3. �N��̫e���Ĥ@�Ӷ¦�Bar ��3��unit
  4. �N��̫e���Ĥ@�Ӷ¦�Bar ��4��unit
     ![](https://i.imgur.com/3lE7I3A.png)

�O�o�� `long long`�D�ط|�� `signed 64 bits`

### �Ѧ�

https://www.pinghenotes.com/UVa-10721-Bar-Codes/
https://blog.csdn.net/mobius_strip/article/details/45092387

## 10157 Expressions

`DP �զX �ƾ� �j���`
[�D�سs��](https://vjudge.net/problem/UVA-10157)

### �D��

* �A����Aexp: 4��A���� �N��8�Ӧr�� `()()()()`
* �A���`�׬� `d`�N��Q `d-1`�ӬA���]��

�D�ص��w��� `n` `d`�A�D `n/2`��A������Φ��̤j�`�� `d`���A���ƦC��
**��J**

```
6 2
300 150
```

**��X**

```
3
1
```

### ���D

1. �ɤO��
   * �ˬd�@�A����̤j�`�� `O(n)`
   * ������=`�Ҧ��X�k�A���ꪺ�զX��*�u�ʮɶ�`(�C�ӲզX����O(n)�ˬd�`��)
   * ���]�� `n`��A����A��A���ꪺ�զX�Ƭ� `Catalan number`
2. DP��

### �Ѧ�

https://blog.csdn.net/mobius_strip/article/details/39269541

## 10328 Coin Toss

`DP �����`
[�D�سs��](https://vjudge.net/problem/UVA-10328)

### �D��

��P�@�ӵw�� `n`���A�ݥ�X�ӳs��ܤ֦� `k`�ӥ��������ơC
�Y�q `2^n`�ؤ�k���A���X�سs��ܤ֦� `k`�ӥ����C

### ���D

1. �ɤO
   * �T�|�� `2^100`���� tle
2. �ƦC�զX
   * �s��X�{�̦hn��H - �s��X�{�̦hn-1��H

![](https://i.imgur.com/Lw3nGu4.png)

![](https://i.imgur.com/ejqrZKV.png)

### �Ѧ�

https://blog.csdn.net/accelerator_/article/details/16830585

## 12045 Fun with Strings

[�D�سs��](https://vjudge.net/problem/UVA-12045)

### �D��

* ���@�Ӧr��A�r��ȥ]�t `'a'`�� `'b'`��Ӧr��
* �C�g�L�@�ӨB�J�A`'a'`->`'b'`�A`'b'`->`'ab'`
* �g�L `N`�ӨB�J��A���׬� `X`�A�g�L `M`�ӨB�J��A���׬� `Y`�A�ݲ� `K`�ӨB�J���׬��h��?
* ����Mod `1e9+7`
* �p�G�L�ѿ�X `Impossible`

### ���D

1. �Υ[�k �C�C��O��ƦC -> �|TLE `O(n)`
   * F [ n ] = F [ n �V 1 ] + F [ n �V 2 ] (���Υ[�k) �|�W��
     ![](https://i.imgur.com/kJawZY7.png)
2. �x�}�ֳt�� ��֨D�X�O��ƦC `O(logN)`
   * [��ֺ�X�O��ƦC](https://medium.com/starbugs/find-nth-fibonacci-number-by-fast-doubling-6ac2857a7834)
     ![](https://i.imgur.com/jsBasCv.png)

### �Ѧ�

https://www.cnblogs.com/LyonLys/archive/2013/04/23/LOJ_1052_uva_12045_Lyon.html

## NCPC 2018C : Partition an Integer

![](https://i.imgur.com/ORTczc4.png)

### �D��

`n`���@�Ӥj��2�����(�̤j�� `2^31`)�A���C�� `n` ��X�T�ӥ���� `(a,b,c)`�A���� `n=a+b+c`,�B `lcm(a,b,c)`�̤p (�̤p������)

### ���D

* �p�G `n`�O�_��
  * `n`=`2k+1=k+k+1`
  * 

## �B�~���O

* `__int128` ����� `cin` `cout` �n�ۤv�B�z
* �@��dp�u�n�����j���A�N����pseudo code�F
* k|c k�㰣c���N��
