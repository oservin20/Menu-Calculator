/*-----------------------------------------------------
 * AUTHOR: Osman Servin
 * FILENAME: Assignment4.cpp
 * SPECIFICATION: This calculates 4 different things based on what the user wants done. The program uses 5 different functions in order to complete the users needs.
 * ---------------------------------------------------*/



#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;


// FOWARD DECLARATION OF FUNCTIONS THAT WILL BE USED IN THE PROGRAM
void printMenu();
bool isEven(int first, int second);
bool isPrime(int integerCheck);
int sum(int first, int second);
int gcd(int x, int y);


int main()
{
	// VARIABLES NEEDED IN THE PROGRAM
	char choice, ch;
	int firstInt, secondInt;
	
	// PRINTS MENU TO USER FOR THE FIRST TIME
	printMenu();	
	cout << endl;

	// USED TO KEEP PROGRAM RUNNING UNTIL Q IS CHOSEN
	do
	{
		// ASKS USER FOR INPUT
		cout << "\nPlease enter a command or type ?";
		cin >> ch; 
		
		// MAKES THE CHOICE ENTERED TO LOWERCASE
		choice = tolower(ch);

		switch(choice)
		{
			case 'a':
				// PROMPT THE USER
				cout << "\nEnter a number: ";
				cin >> firstInt;
				cout << "Enter a number: ";
				cin >> secondInt;
		
				// CALLS THE isEven FUNCTION
				if(isEven(firstInt, secondInt))
				{
					// IF THE SUM IS EVEN THEN PRINT THE FOLLOWING
					cout << "Sum of " << firstInt << " + " << secondInt << " is even" << endl;
				}
				else
				{
					// IF THE SUM ISN'T EVEN PRINT THE FOLLOWING
					cout << "Sum of " << firstInt << " + " << secondInt << " is not even" << endl;
				}
				
				// LEAVE SWITCH STATEMENT
				break;
			
			case 'b':
				// PROMPT THE USER 
				cout << "\nEnter a number: ";
				cin >> firstInt;				
				
				// GOES TO isPrime AND CHECKS IS THE NUMBER IS PRIME
				if(isPrime(firstInt))
				{
					// IF INPUT IS PRIME THEN PRINT THE FOLLOWING
					cout << firstInt << " is prime" << endl;
				}
				else
				{
					// IF INPUT IS NOT PRIME PRINT THE FOLLOWING
					cout << firstInt << " is not prime" << endl;
				}

				// LEAVE SWITCH STATEMENT
				break;

			case 'c':
				// PROMPT AND STORE INPUT
				cout << "\nEnter the first number: ";
				cin >> firstInt;
				cout << "Enter the second number: ";
				cin >> secondInt;

				// GO TO sum FUNCTION AND PRINTS OUT THE INFORMATION TO USER
				cout << "The sum between " << firstInt << " and " << secondInt << " is " << sum(firstInt, secondInt) << endl;
				
				// LEAVE SWITCH STATEMENT
				break;

			case 'd':
				// PROMPT THE USER AND STORE INPUTS
				cout << "\nEnter the first integer: ";
				cin >> firstInt;
				cout << "Enter the second integer: ";
				cin >> secondInt;

				// GO TO THE gcd FUNCTION AND PRINT THE RESULTS
				cout << "The gcd of " << firstInt << " and " << secondInt << " is " << gcd(firstInt, secondInt) << endl;
		
				// LEAVE SWITCH STATEMENT
				break;

			case 'e':
				cout << endl;
				printMenu();
			
				// LEAVE SWITCH STATEMENT
				break;

			case 'q':
				// LEAVE SWITCH STATEMENT
				break;
		}
		
	}while(choice != 'q');

	return 0;
}


// FUNCTION THAT PRINTS THE MENU
void printMenu()
{
	cout << "'A' Finds if the sum of the two numbers entered by the user is even" << endl;
	cout << "'B' Finds if the number entered is prime" << endl; 
	cout << "'C' Finds the sum between two integers" << endl;
	cout << "'D' Finds the gcd" << endl;
	cout << "'E' Displays the menu" << endl;
	cout << "'Q' Quits the program" << endl;
} // END IF printMenu


// FUNCTION THAT CHECKS IF THE SUM OF 2 INTEGERS IS EVEN
bool isEven(int first, int second)
{
	// SUM IS THE SUM OF THE 2 INTEGERS PASSED TO FUNCTION
	int sum = first + second;
	
	// CALCULATES IF THE SUM IS EVEN
	if(sum % 2 == 0)
	{
		// RETURN true IF SUM IS EVEN
		return true;
	}
	else
	{
		// RETURN false IF SUM IS NOT EVEN
		return false;
	}
} // END OF isEven 


// isPrime RETURN A BOOLEAN ANDHAS ARGUMENT OF INTEGER
bool isPrime(int integerCheck)
{
	// CHECKS IF THE INPUT IS EITHER 0, 1, OR -1
	if(integerCheck == 0 || integerCheck == 1 || integerCheck == -1)
	{
		// IF 0 OR 1 THEN INTEGER ISNT PRIME
		return false;
	}
	
	// LOOP THAT IS USED TO CHECK IF THE NUMBER IS A PRIME
	for(int i = 2; i < integerCheck / 2; i++)
	{
		// INTEGER INPUT IS DIVIDED BY i
		if(integerCheck % i == 0)
		{
			// IF THE REMAINDER IS 0 THEN THE NUMBER IS NOT PRIME
			return false;
		}
	}
	// RETURNS TRUE IF THE NUMBER IS PRIME
	return true;
} // END OF isPrime


// sum RETURNS THE SUM BETWEEN TWO INTEGERS
int sum(int first, int second)
{
	int sum = 0, temp;
	
	// CHECKS WHICH INTEGER IS GREATER
	if(first > second)
	{
		// SWAPS THE INTEGERS IF THE FIRST IS GREATER THAN THE SECOND
		temp = second;
		second = first;
		first = temp; 
	} 
	
	temp = second - first;
	for(int i = 0; i <= temp / 2; i++)
	{
		// IF THE FIRST AND SECOND INTEGERS ARE TEH SAME THEN ADD FIRST TO SUM
		if(first == second)
		{
			sum = sum + first;
		}
		else
		{
			// CALCULATES THE SUM, INCREMENTS THE FIRST INTEGER, AND DECREMENTS THE SECOND INTEGER
			sum = sum + first + second;  
			first++; 
			second--; 
		}
	}

	// RETURNS THE SUM
	return sum;

} // END OF sum


// gcd RETURNS THE GCD OF TWO NUMBERS
int gcd(int x, int y)
{
	// USED TO STORE THE ARGUMENTS
	int largest, smallest, gcd;

	// CHECK WHICH INTEGER IS GREATER
	if(x > y)
	{
		// IF INTEGER X IS GREATER THEN THE INTEGERS ARE STORED IN THE FOLLOWING WAY
		largest = x;
		smallest = y;
	}
	// CHECKS IF THE SECOND INTEGER IS GREATER
	else if(x < y)
	{
		// IF INTEGER Y IS GREATER THEN STORE INTEGERS IN THE FOLLOWING WAY
		largest = y;
		smallest = x;
	}
	// IF THE PREVIOUS STATEMENTS ARENT TRUE THEN THE NUMBERS MUST BE THE SAME
	else
	{
		gcd = x;
	}

	// LOOP THAT RUNS UNTIL THE TWO INTEGERS ARE THE SAME
	while(largest != smallest)
	{
		if(largest > smallest)
		{
			largest = largest - smallest;
			gcd = largest;
		}
		else
		{
			smallest = smallest - largest;
		}
	}
	
	// RETURNS THE GCD OF THE TWO INTEGERS
	return gcd;
}












