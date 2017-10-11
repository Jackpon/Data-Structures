import java.util.Stack;

public class Stack_Test {
	static Stack<Character> s = new Stack<Character>();
	public final static int MAXN = 100;
	
	public static char[] tranfExp(char exp[]) {
		char tempStr[] = new char[MAXN];//保存后缀表达式的字符串  
		  
	    int i=0,j=0;  
	    while(exp[i] !='\0')  
	    {  
	        if(exp[i]>='0' &&exp[i]<='9')  //如果是数字字符串就保存到后缀表达式字符串中  
	        {  
	            tempStr[j++] = exp[i];  
	        }  
	        else if(exp[i] == '(' )  //如果是左括号及入栈  
	        {  
	            s.push(exp[i]);  
	        }  
	        else if(exp[i] == ')' )  //如果是右括号就把接近栈顶的左括号上面所有的运算符出栈存进字符串中  左括号出栈  
	        {  
	            while(s.empty() == false)  
	            {  
	                if(s.peek().equals('(') )  
	                {  
	                    s.pop();  
	                    break;  
	                }  
	                else  
	                {  
	                   tempStr[j++] = (char) s.peek();  
	                   s.pop();  
	                }  
	            }  
	        }  
	        else if(exp[i] == '+' || exp[i] == '-')   //如果的事+-|操作符就把比他优先级高或者等于的所有运算符出栈进入字符串  
	        {  
	            while(s.empty() == false)  
	            {  
	                char ch = (char) s.peek();  
	                if(ch == '+'||ch == '-'||ch == '/'||ch == '*')  
	                {  
	  
	                   tempStr[j++] = (char) s.peek();  
	                   s.pop();  
	                }  
	                else  
	                    break;  
	            }  
	            s.push(exp[i]);  
	        }  
	        else if(exp[i] == '*' || exp[i] == '/')  //类似于扫描到+- 只是如果栈中有=-运算符就不用出栈  因为运算符优先级比较小  
	        {  
	            while(s.empty() == false)  
	            {  
	                char ch = (char) s.peek();  
	                if(ch == '/' || ch=='*')  
	                {  
	                    tempStr[j++] = (char) s.peek();  
	                   s.pop();  
	                }  
	                else  
	                    break;  
	            }  
	            s.push(exp[i]);  
	        }  
	        i++;  
	    }  
	    while(s.empty() == false)   //把栈中剩余的所有运算符出栈  
	    {  
	        tempStr[j++] = (char) s.peek();  
	        s.pop();  
	    }  
	    tempStr[j] = 0;   //最后一个赋值为0  也就是字符串结束的标志  
	    return tempStr;   //返回已经得到的后缀表达式  
	}
	// 计算后缀表达式 
	public static int calcExp(char exp[]) {
		//展示已经得到的后缀 
		for (int i = 0; i < exp.length; i++) {
			System.out.print(exp[i]);
		}    
	    while( !s.empty() )  
	      s.pop();  
	    int i=0;  
	    while(exp[i] != '\0')  
	    {  
	        if(exp[i]>='0' && exp[i]<='9')  
	        {  
	            s.push((char) (exp[i]-'0'));  
	        }  
	        else if(exp[i] == '-')  
	        {  
	            int m = (char) s.peek();  
	            s.pop();  
	            int n = (char) s.peek();  
	            s.pop();  
	            s.push((char) (n-m));  
	        }  
	        else if(exp[i] == '+')  
	        {  
	            int m = (char) s.peek();  
	            s.pop();  
	            int n = (char) s.peek();  
	            s.pop();  
	            s.push((char) (n+m));  
	        }  
	        else if(exp[i] == '/')  
	        {  
	            int m = (char) s.peek();  
	            s.pop();  
	            int n = (char) s.peek();  
	            s.pop();  
	            s.push((char) (n/m));  
	        }  
	        else if(exp[i] == '*')  
	        {  
	            int m = (char) s.peek();  
	            s.pop();  
	            int n = (char) s.peek();  
	            s.pop();  
	            s.push((char) (n*m));  
	        }  
	   
	        i++;  
	        
	        
	    }  
 
	    System.out.print("\n\n");
	    return (char) s.peek();  
	} 
	
	public static void main(String[] args) {
		String dString ="1+2-(3-2)*3+4\0";
		char a[] = dString.toCharArray();
		char b[]=tranfExp(a);
		
		System.out.println(calcExp(b));
	}

}
