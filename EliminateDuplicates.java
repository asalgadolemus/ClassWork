/*
 * Name: Antonio Salgado
 * Course: CIS - 315  
 * Description: This program will eliminate duplicate numbers that have
 * been entered.
 *  
 * 
 */
import java.util.*;
public class EliminateDuplicates {public static void main(String[] args)
    {Scanner in=new Scanner(System.in);
    int []num=new int[10];
    int i;
    System.out.print("Enter 10 integers: ");
    num[0]=in.nextInt();
    while(num[0]!=-1)
       {for(i=1;i<10;i++)
           num[i]=in.nextInt();
       int []newNum=eliminateDuplicates(num);
       System.out.print("The distinct numbers are: ");
       for(i=0;i<newNum.length;i++)
            System.out.print(newNum[i]+" ");
       System.out.println();

       }
  
    }
public static int[ ] eliminateDuplicates(int[ ] list)
{int []num=new int[10];
int count=1,i,j;
boolean found;
num[0]=list[0];
for(i=1;i<10;i++)       //for each number in list
      {found=false;       //assume it's not a duplicate
       for(j=0;j<count;j++)
           if(list[i]==num[j])   //until it is found in the list
                found=true;
       if(!found)
           num[count++]=list[i];   //if not found put in the list
      }
int [] numbers=new int[count];    //create new list to return
for(i=0;i<count;i++)              //and move non duplicates to it
       numbers[i]=num[i];
return numbers;
}
}