/*
1078: Torry的困惑(提高型)

题目描述
算法提高  Torry的困惑(提高型)    
时间限制：1.0s     内存限制：512.0MB 
      
问题描述 
　　Torry从小喜爱数学。一天，老师告诉他，  像2、3、5、7……这样的数叫做质数。
Torry突然想到一个问题，前10、100、1000、10000……个质数的乘积是多少呢？
他把这个问题告诉  老师。老师愣住了，一时回答不出来。于是Torry求助于会编程的你，
请你算出前n个质数的乘积。不过，考虑到你才接触编程不久，Torry只要你算出这个数模上50000的值。 
输入格式 
　　仅包含一个正整数n，其中n< =100000。 
输出格式 
　　输出一行，即前n个质数的乘积模50000的值。 
样例输入 
1 

样例输出 
2 
*/
import java.util.Scanner;
 
public class Main {
     
     
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a;
        while(in.hasNext()) {
            a=in.nextInt();
            int n=1500000;
            boolean []isPrime =new boolean[n];
            for (int i = 2; i < n; ++i) {
              isPrime[i]=true;
            }
             
            //排除2,3等素数的倍数，剩余的true就是素数
            for (int i = 2; i * i < n; i++) {
                  if (!isPrime[i]) continue;
                  for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                  }
               }
            int count=0;
            long sum=1;
            for (int i = 2; i < n; i++) 
                if (isPrime[i]) {
                    sum = (sum * i) %50000;
             
                    count++;
                    if (count==a) 
                        break;
                }
             
            System.out.println(sum);
        }
    }
}