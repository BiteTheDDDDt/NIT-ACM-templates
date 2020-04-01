1、新建一个值为123的大整数对象
BigInteger a=new BigInteger(“123”); //第一种，参数是字符串
BigInteger a=BigInteger.valueOf(123); //第二种，参数可以是int、long
2、大整数的四则运算
a. add(b); //a,b均为BigInteger类型，加法
a.subtract(b); //减 法
a.divide(b); //除法
a.multiply(b); //乘法

3、大整数比较大小
a.equals(b); //如果a、b相等返回true否则返回false
a.comareTo(); //a小于b返回-1，等于返回0，大于返回1

4、常用方法
a.mod(b); //求余
a.gcd(b); //求最大公约数
a.max(b); //求最大值
a.min(b); //求最小值

5、BigInteger中的常数
BigInteger.ZERO //大整数0
BigInteger.ONE //大整数1
BigInteger.TEN //大整数10

Scanner cin = new Scanner(System.in);//读入
while(cin.hasNext()) {//等同于!=EOF
    BigInteger a;
    a = cin.BigInteger(); //读入一个BigInteger;
    System.out.println(a); //输出a并换行
}


1、A == B ?//高精度小数运算
题目描述：输入两个非常大的数A和B，判断A是否等于B，如果相等输出YES，否则输出NO
分析：这个题在hdu上实际上并没有给出范围，WA了之后才知道这是道大数题，因为仅仅涉及到输入、比较和输出，所以非常适合用作大数的入门题
注意：这里只是说给出两个数A和B，并没有说是两个整数，所以应该采用BigDecimal
import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) { // TODO Auto-generated method stub BigDecimal a, b;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            if (a.compareTo(b) == 0) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}

BigDecimal的常用方法：
加：add（BigDecima）
减：subtract（BigDecimal）
乘：multiply（BigDecimal）
除：divide（BigDecimal）
乘方：pow（int）
取绝对值：abs（）
取反：negate（）
对比：compareTo（BigDecimal）
设置小数点精确度：setScale（int）
设置保留小数点精确度并添加保留方式（直接加1或者四舍五入）：setScale（int， int）
BigDecimal a=new BigDecimal("0.1000");
System.out.println(a.stripTrailingZeros().toPlainString());
String a = "1";//去掉后面无用的0；
String b = "4.56";
BigDecimal aBD = new BigDecimal(a);
BigDecimal bBD = new BigDecimal(b);
BigDecimal resultBD = aBD.divide(bBD).setScale(3, java.math.BigDecimal.ROUND_HALF_UP);

例子：
import java.util.*;
import java.math.*;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
    	
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
        	int n=in.nextInt();
        	BigInteger ans=new BigInteger("1");
        	while(n-->0)
        	{
        		BigInteger a = in.nextBigInteger();
        		ans=ans.multiply(a);
        	}
            System.out.println(ans);
        }
        in.close();
    }
}

import java.math.BigInteger;
import java.util.Scanner;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner in =new Scanner (System.in);
        while(in.hasNext()) {
            int t=in.nextInt();
            while(t-->0) {
                BigInteger m=in.nextBigInteger();
                BigInteger n=in.nextBigInteger();
                BigInteger n2=new BigInteger("1");
                BigInteger ans=new BigInteger("1");
                for(BigInteger i=n2;; i=i.add(n2)) {
                    if(i.compareTo(n)==0)
                        break;
                    ans=ans.multiply(m);
                }
                BigInteger temp=ans.gcd(n);
                BigInteger up=n.divide(temp);
                BigInteger down=ans.divide(temp);
                System.out.println(up+"/"+down);
            }
        }
    }
}
