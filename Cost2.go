/*
Name: 			Antonio Salgado Lemus
Description:    	This program will be asking for the customer's name and
			how many copies they need. This program will output
			the customer's name and the total cost.

Course: 		CS-410W
Date: 			01-24-2020
*/

package main

import(
	"fmt"
	"bufio"
	"os"
	"log"
	"strings"
	"strconv"
)

func main(){
	var two,one,count,total float64
	var first, next,yes string
	var answer int
	yes = "Y"
	valid := true
	for valid{
		// Input of name
		fmt.Print("Enter customer name: ")
	        fmt.Scanln(&first)



		// Input of copies
		fmt.Print("Enter number of copies: ")
		reader := bufio.NewReader(os.Stdin)
		input, err := reader.ReadString('\n')


		if err != nil{
	        	log.Fatal(err)
		}

		input = strings.TrimSpace(input)
		score, err := strconv.ParseFloat(input, 64)

		if err != nil{
	        	log.Fatal(err)
		}

		if score <= 100 {
			// Total cost of copies <=100
			one=score*.05

			//Outputs name and cost
			fmt.Println("Customer Name: ", first)
	 		fmt.Printf("Total cost: $",)
			fmt.Printf("%0.2f \n", one)

		} else {
			//Calcuates cost of copies <100 and 100>=
			one=100*.05
			count=score-100
			two=count*.03

			//Total amount of copies <100 and 100>=
			total=one+two

			fmt.Println("Customer Name: ", first)
			fmt.Printf("Total cost: $")
			fmt.Printf("%0.2f \n", total)


		}

		fmt.Print("\nAnother customer (Y/N)? ")
	        fmt.Scanln(&next)
		fmt.Print("\n")

		answer = strings.Compare(yes, next)

		if answer == 0{
			valid = true

		}else{
			valid = false
		}
	}
}
