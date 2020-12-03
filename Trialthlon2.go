/*
Name: 			Antonio Salgado Lemus
Description:    	This program will be requesting the number of hours
			spent at each activity and then displaying the number
			of calories burned and the number of pounds worked off.
	
Course: 		CS-410W
Date: 			01-24-2020
*/

package main 

import(
	"fmt"
)

func main(){
	var swimming,running,cycling,c,r,s, pounds,calories float64
	var count int
 	
	// Define variables
	swimming = 275
	running = 475
	cycling = 200

	fmt.Print("How many triathletes are there? ")
	fmt.Scan(&count)


	for guesses:=0; guesses <count; guesses++{
	
	fmt.Printf("\nAthlete #%d:", guesses + 1)
	//Inputs taken
	fmt.Print("\nEnter hours spent on cycling: ")
	fmt.Scan(&c)

	fmt.Print("Enter hours spent on running: ")
	fmt.Scan(&r)

	fmt.Print("Enter hours spent on swimming: ")
	fmt.Scan(&s)
	
	//Calculates total calories
	calories = float64((swimming*s)+(running*r)+(cycling*c))

	//Calculates total pounds lost
	pounds = calories /3500
	
	//Outputs
	fmt.Println("\nTotal calories: ", calories)	
	fmt.Print("Pounds lost: ")
	fmt.Printf("%0.2f \n", pounds)
	}
}
