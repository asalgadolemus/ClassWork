/*
 * Name: Antonio Salgado
 * Course: CIS - 315  
 * Decription: This program will calculate the day of the week by the
 *  getting the month, day, and year.
 *  
 * 
 */
import java.util.Scanner;

public class DayOfTheWeek{

	public static void main(String []args){

		Scanner sc=new Scanner(System.in);

		// Accepting the year,month and day from the user
		System.out.println("Enter the year: (e.g., 2014): ");
		int year=sc.nextInt();

		System.out.println("Enter the month (i.e., 1-12): ");
		int month=sc.nextInt();

		System.out.println("Enter the day of the month (i.e., 1-31): ");
		int day=sc.nextInt();

		// Checking for invalid inputs
		if(year<=0 || month<1 || month>12 || month>31 || month<1)
			System.out.println("Enter valid inputs");

		else{ // Changing month to 13 and 14 if it is 1 and 2 respectively
			if(month==1 || month==2)
			{ month+=12;
			year--;
			}

			// Calculating k and j
			int k=year%100;
			int j=year/100;

			// Applying the formula
			int h=(day+26*(month+1)/10+k+k/4+j/4+5*j)%7;

			switch(h){
			case 0:
				System.out.println("Day of the week is Saturday.");
				break;
			case 1:
				System.out.println("Day of the week is Sunday.");
				break;
			case 2:
				System.out.println("Day of the week is Monday.");
				break;
			case 3:
				System.out.println("Day of the week is Tuesday.");
				break;
			case 4:
				System.out.println("Day of the week is Wednesday.");
				break;
			case 5:
				System.out.println("Day of the week is Thursday.");
				break;
			case 6:
				System.out.println("Day of the week is Friday.");
				break;

			}
		}
	}
}