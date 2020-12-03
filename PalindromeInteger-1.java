/*
 * Name: Antonio Salgado
 * Course: CIS - 315  
 * Description: This program will prompt the user to enter
 * a positive integer and will report whether the the integer is 
 * palindrome.
 * 
 */

import java.util.Scanner;


public class PalindromeInteger {

	public static int reverse(int number)       // Return the reversal of an integer, i.e., reverse(456) returns 654
	{
		int newNum=0;
		while( number != 0 )
		{
			newNum = newNum * 10;
			newNum = newNum + number%10;
			number = number/10;
		}
		return newNum;

	}

	public static boolean isPalindrome(int number) // Return true if number is a palindrome
	{
		if(number==reverse(number))
		{
			return true;

		}
		else
		{
			return false;
		}

	}

	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter a positive integer: ");
		int num=sc.nextInt();
		System.out.println("The number "+num+" in reverse order is " +reverse(num)+".");
		if(isPalindrome(num))
		{
			System.out.print("The number "+num+" is palindrome.");
		}
		else
			System.out.print("The number "+num+" is not a palindrome.");

	}

}