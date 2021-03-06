一、巴什博弈

    1、问题模型：只有一堆n个物品，两个人轮流从这堆物品中取物，规定每次至少取一个，最多取m个，最后取光者得胜。

    2、解决思路：当n=m+1时，由于一次最多只能取m个，所以无论先取者拿走多少个，后取者都能够一次拿走剩余的物品，后者取胜，所以当一方面对的局势是n%(m+1)=0时，其面临的是必败的局势。所以当n=（m+1)*r+s，（r为任意自然数，s≤m)时,如果先取者要拿走s个物品，如果后取者拿走x（≤m)个，那么先取者再拿走m+1-k个，结果剩下（m+1）（r-1）个，以后保持这样的取法，那么先取者肯定获胜。总之，要保持给对手留下（m+1）的倍数，就能最后获胜。

    3、变形：条件不变，改为最后取光的人输。

    结论：当（n-1）%（m+1）==0时后手胜利。

二、威佐夫博奕

    1、问题模型：有两堆各若干个物品，两个人轮流从某一堆或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

    2、解决思路：A：设（ai,bi）（ai ≤bi  ,i=0，1，2，…,n)表示两堆物品的数量并称其为局势，如果甲面对（0，0），那么甲已经输了，这种局势我们称为奇异局势。前几个奇异局势是：（0，0）、（1，2）、（3，5）、（4，7）、（6，10）、（8，13）、（9，15）、（11，18）、（12，20）。任给一个局势（a，b），如下公式判断它是不是奇异局势： ak =[k（1+√5）/2]，bk= ak + k  （k=0，1，2，…,n 方括号表示取整函数）。（证明见百度百科）
三、Fibonacci博弈

    1、问题模型：

     有一堆个数为n的石子，游戏双方轮流取石子，满足： 

    （1）先手不能在第一次把所有的石子取完； 

    （2）之后每次可以取的石子数介于1到对手刚取的石子数的2倍之间（包含1和对手刚取的石子数的2倍）。 约定取走最后一个石子的人为赢家。

    2、解决思路：

      当n为Fibonacci数时，先手必败。即存在先手的必败态当且仅当石头个数为Fibonacci数。 
四、尼姆博弈

    1、问题模型：有三堆各若干个物品，两个人轮流从某一堆取任意多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

    2、解决思路：用（a，b，c）表示某种局势，显证（0，0，0）是第一种奇异局势，无论谁面对奇异局势，都必然失败。第二种奇异局势是（0，n，n），只要与对手拿走一样多的物品，最后都将导致（0，0，0）。

      搞定这个问题需要把必败态的规律找出：(a,b,c)是必败态等价于a^b^c=0(^表示异或运算）。
    3、推广一：如果我们面对的是一个非奇异局势（a，b，c），要如何变为奇异局势呢？假设 a < b< c,我们只要将 c 变为 a^b,即可,因为有如下的运算结果: a^b^(a^b)=(a^a)^(b^b)=0^0=0。要将c 变为a^b，只从 c中减去 c-（a^b）

    4、推广二：当石子堆数为n堆时，则推广为当对每堆的数目进行亦或之后值为零是必败态。