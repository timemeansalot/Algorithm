# Problem 1
## 大概的思路
1. 单独考虑每一段？的值如何可以取最小。每一段？的首尾一共有3^2=9种情况（每一端都可以取A, B和空）
2. 考虑？段长度对于其最小值的影响
3. 考虑AB，BA不同取值的情况；AB，BA可以取负数
    - AB>=0, BA>=0: “AA,BB"优先级高于AB，BA，每段？？？修改后最多包含一个AB或者BA
    - AB<0, BA>0, AB+BA<=0: AB,BA优先级高于“AA，BB”，尽可能将？？？转化成ABAB交替序列
    - BA<0, AB>0, AB+BA<=0: BA,AB优先级高于“AA，BB”，尽可能将？？？转化成BABA交替序列
    - AB<0, BA>0, AB+BA>0:优先级高于“AA，BB”，在不增加BA的基础上增加AB 
    - BA<0, AB>0, AB+BA>0:优先级高于“AA，BB”，在不增加AB的基础上增加BA 
    - AB<0, BA<0, AB <= BA: 优先级AB高于BA高于“AA，BB”
    - AB<0, BA<0, AB > BA: 优先级BA高于AB高于“AA，BB”

## 针对不同情况进行讨论
- A?A,B?B
- C?C
- A?C,B?C,C?A,C?B
- A?B,B?A

PS: C表示为空$\infty$


# $AB\geq0,BA\geq0$时
> "AA,BB"的优先级比“AB”，“BA”的优先级高
### case1: A???A or B???B
1. AB,BA不可以取负数时：sum最少可以是0
2. 因为可以将？全部设置成A或者B

### case2: C?C
1. 在AB，BA不可以取负数时：sum最少可以为0
2. 因为所有的？都可以取A或者B

### case3: A?C,B?C,C?A,C?B
1. 在AB，BA不可以取负数的时候，sum最少可以为0
2. 因为可以取所有？为其另一端的值 

### case4: A?B,B?A
1. A?B: 至少有一个AB
2. B?A: 至少有一个BA

# $AB\leq0,BA\geq0,AB+BA\leq0$
> 此时应该尽可能的去构造AB，少构造BA

## 具体的分类处理
PS: 以B或者C结尾，最好是从A开始循环替代？
### case1: C?C, C?B, B?A, C?A
> begin with A: ABABA...
eg:
- ?->A
- ??->AB
- ???->ABA
- ????->ABAB
- A???->ABAB
- A?B->AAB
- A??B->AABB
- A???B->AABAB
- C?B->CAB
- C??B->CABB,CBAB
- C???B->CABAB,CBABB
- B?A->BAA,BBA
- B??A->BABA,BBAA(begin A)
- B???A->BABAA,BBABA
- B????A->BABABA,BBABAA(begin A)
- C?A->CAA,CBA
- C??A->CABA,CBBA
- C???A->CABAA,CBABA

### Case 2: B?B
> length=2, begin with B, ??->BA
> length==1 or length>2,begin with A: ABABA....
- B?B->BAB
- B??B->BAAB,BABB,BBAB(choose),BBBB
- B???B->BABAB,BBABB
- B????B->BABABB,BBABAB

### Case 3: B?C, A?C
> length%2==1, begin B, or begin A
- B?C->BBC(begin B)
- B??C->BABC(begin A)
- B???C->BABAC,BBABC(begin B)
- B????C->BABABC,BBABAC(begin A)
- B?????C->BABABAC,BBABABC(begin B)
- A?C->ABC(begin B)
- A??C->AABC,ABAC(begin A)
- A???C->AABAC,ABABC(begin B)
- A????C->AABABC,ABABAC(begin A)

### Case 4: A?A
> begin with B always
- A?A->ABA,AAA
- A??A->AABA,ABAA
- A???A->AABAA,ABABA


### Case 5: A?B
> if (length%2==1) begin A, or begin B
- A?B->AAB,ABA(begin A)
- A??B->AABA,ABAB(begin B)
- A???B->AABAB,ABABB
- A????B->AABABB,ABABAB(begin B)
- A?????B->AABABAB,ABABABB
- A??????B->AABABABB,ABABABAB(begin B)
- A???????B->AABABABAB,ABABABABB

# $AB\leq0,BA\geq0,AB+BA\leq0$
与前者的选择以A开始或者以B开始相反即可

# $AB\leq0,BA\geq0,AB+BA>0$
> 尽可能的多AB，但是如果追求AB而增加了BA，则不可取

> 当前的思路是在追求“AA，BB”占多数的情况下，将AA转化成AB且不增加BA
### case1: A???A or B???B
1. AB,BA不可以取负数时：sum最少可以是0
2. 因为可以将？全部设置成A或者B
> 引入AB必然导致引入BA，不要变

### case2: C?C
1. 在AB，BA不可以取负数时：sum最少可以为0
2. 因为所有的？都可以取A或者B
> 全部写成A，最后一个写成B，构造AAA...AAB

### case3: A?C,B?C,C?A,C?B
1. 在AB，BA不可以取负数的时候，sum最少可以为0
2. 因为可以取所有？为其另一端的值 
> A?C可以最后改成AB，C?B可以最后改成AB    
### case4: A?B,B?A
1. A?B: 至少有一个AB
2. B?A: 至少有一个BA



# $BA\leq0,AB\geq0,BA+AB>0$
> 跟上面一种情况大概相同，具体如何增加BA不增加AB略有不同
### case1: A???A or B???B
1. AB,BA不可以取负数时：sum最少可以是0
2. 因为可以将？全部设置成A或者B
> 引入BA必然导致引入AB，不要变

### case2: C?C
1. 在AB，BA不可以取负数时：sum最少可以为0
2. 因为所有的？都可以取A或者B
> 全部写成B，最后一个写成A，构造BBB...BBA

### case3: A?C,B?C,C?A,C?B
1. 在AB，BA不可以取负数的时候，sum最少可以为0
2. 因为可以取所有？为其另一端的值 
> B?C可以最后改成AB，C?A可以最后改成BA    
### case4: A?B,B?A
1. A?B: 至少有一个AB
2. B?A: 至少有一个BA

