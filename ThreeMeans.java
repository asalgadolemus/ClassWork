/*
 * Name: Antonio Salgado
 * Course: CIS - 315  
 * Decription: This program will calculate the mean in arithmetic, geometric
 *  and harmonic.
 *  
 * 
 */


import java.util.Scanner;

public class ThreeMeans {
    
	public static void main(String[] args) {
        
    	Scanner scan = new Scanner(System.in);
        float first, second;
        
        // get two floating numbers from user
        System.out.print("Enter two positive floating-point numbers: ");
        first = scan.nextFloat();
        second = scan.nextFloat();
        
        // calculates 3 kinds of mean
        float arithmeticMean = (first+second)/2;
        float geometricMean = (float)Math.sqrt(first*second);
        float harmonicMean = (2 * first * second) / (first+second);
        
        // prints out the means in arithmetic, geometric, harmonic 
        System.out.println("The arithmetic mean is " + String.format("%.2f",arithmeticMean));
        System.out.println("The geometric mean is " + String.format("%.2f",geometricMean));
        System.out.println("The harmonic mean is " + String.format("%.2f",harmonicMean));
    }
}
