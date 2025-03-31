/*
 * IPC144 N1F Assignment 4
 * Submitted by: Joseph Oladunmoye
 * Due date: 2023-12-4
 *
 * In continuation to Assignment 2, the goal is to create a C program that would
 * issue 10 passports by prompting the passport applicant for their
 * first name, last name, and their age. You need to check the
 * validity of the name and age of the applicant (e.g., names should be
 * greater than one character in length and only contains English ASCII letters
 * from A-Z or a-z. Age of the applicant should be greater than 16 years old).
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_NAME_LEN 200
#define INVALID_ENTRY_COUNT 3
#define VALID_AGE 16
#define DOB_LEN 12

int number_of_passports=0; // global variable for number of passports

// Passport structure definition
typedef struct {
	char firstName[MAX_NAME_LEN]; // define character for char array for first name
	char lastName[MAX_NAME_LEN]; // define pointer for char array for last name
//	char *firstName; // define character for char array for first name
//	char *lastName; // define pointer for char array for last name
	unsigned int age;
	long unsigned int passport_id;
} Passport;

// function prototypes for prompts
int getPassportCount();
void getFirstNameFromApplicant(Passport *record);
void getLastNameFromApplicant(Passport *record);
void getAgeFromApplicant(int currentYear, int currentMonth, char date_of_birth[],  size_t size,  int *year_of_birth,
		int *month_of_birth,  int *day_of_birth, Passport *record);
void getPassportID(Passport *record);

// function prototypes for data validation
int checkName(Passport *record);
int checkAge(int currentYear, int currentMonth, int year_of_birth, int month_of_birth, Passport *record);

// function prototype to display data
void displaySingleRecord(Passport *record);
void displayRecord(Passport *passportGroup,Passport *record );

// file scope functions and variables for formatting output
void line(int length, char c); // create lines with different characters
char *space = ""; // add space as required in output

// function prototype for writing data to file
void writeData( Passport *passportGroup, Passport *applicantRecordPtr );
//Passport *readData(char *filename);

// Function main begins program execution
int main(void){
	setbuf(stdout, NULL);

	//	current time to collect date
	time_t t = time(&t);

	struct tm date = *localtime(&t);
	int currentYear = date.tm_year + 1900;
	int currentMonth = date.tm_mon + 1;
	int currentDay = date.tm_mday;

	// Welcome Message and instructions to user
	char welcomeMessage[] = "WELCOME TO THE PASSPORT APPLICATION PAGE";
	char instructions[] =
					"   All names should be greater than one character in length. \n"
					"   Enter only English letters from A-Z or a-z. \n"
					"   Age of the applicant should be greater than 16 years old.";
	puts("");
	printf("   %s\n\n", welcomeMessage);
	printf("%s\n\n", instructions);
	printf("   Date: %d-%02d-%02d ", currentYear, currentMonth, currentDay); // display current date
	puts("");
	puts("");
	line(90, '+');
	puts("");

	number_of_passports=getPassportCount(); // get input from user for number of passports

	Passport applicantRecord; // variable applicantRecord for structure
	Passport *applicantRecordPtr = &applicantRecord; // assign address of applicantRecord to applicantRecordPtr

	applicantRecordPtr = malloc(sizeof(Passport));

	Passport passportGroup[number_of_passports]; // define an array of 10 Passports

	unsigned int inputCounter = 0; // counter variable for number of user inputs


	// Loop through passportGroup
	for (size_t i = 0;i < number_of_passports; i++ ){

		printf("\n   Please enter Details for applicant #%d: \n", i+1);

		// do while loop to get applicant first name,
		// check valid entry and allow for user
		// re-entry of data in case of errors
		do {
		getFirstNameFromApplicant(applicantRecordPtr);

		// determines if user input is valid
		if (checkName(applicantRecordPtr) == 1){
			strcpy(passportGroup[i].firstName, applicantRecordPtr->firstName);
			break; }// endif

		else{
		inputCounter++;

		// switch statement to track number entries for user input errors
		switch (inputCounter) {

			case 1:
				inputCounter = INVALID_ENTRY_COUNT - 2;
				puts("\n      ERROR! You have entered an invalid character. ");
				puts("      You have 2 more attempts. Please reenter your first name.");
				break;

			case 2:
				inputCounter = INVALID_ENTRY_COUNT - 1;
				puts("\n      ERROR! You have entered an invalid character. ");
				puts("      You have 1 more attempt. Please reenter your first name.");
				break;

			default:
				inputCounter = INVALID_ENTRY_COUNT;
				puts("");
				puts("      ERROR! You have entered an invalid character. ");
				puts("      No more entries allowed. Please start over!");
				line(90, '-');
				puts("");
				line(90, '*');
				return (0);

			} // End Switch

			} // end else
			} while (checkName(applicantRecordPtr) != 1 && inputCounter < INVALID_ENTRY_COUNT );
		// end do while

		// do while loop to get applicant last name,
		// check valid entries and allow for user re-entry of
		// input in case of errors
		do {
			getLastNameFromApplicant(applicantRecordPtr);

			// determines if user input is valid
			if (checkName(applicantRecordPtr) == 1){
				strcpy(passportGroup[i].lastName, applicantRecordPtr->lastName);
				break;}

			else{
			inputCounter++;

			// switch statement to track number entries for user input errors

			switch (inputCounter) {

				case 1:
					inputCounter = INVALID_ENTRY_COUNT - 2;
					puts("\n      ERROR! You have entered an invalid character. ");
					puts("      You have 2 more attemptsPlease reenter your last name.\n");
					break;

				case 2:
					inputCounter = INVALID_ENTRY_COUNT - 1;
					puts("\n      ERROR! You have entered an invalid character. ");
					puts("      You have 1 more attempt. Please reenter your last name.\n");
					break;

				default:
					inputCounter = INVALID_ENTRY_COUNT;
					puts("\n      ERROR! You have entered an invalid character. ");
					puts("      No more entries allowed. Please start over!");
					line(90, '-');
					puts("");
					line(90, '*');
					return (0);

				} // End Switch

				} // end else
				} while (checkName(applicantRecordPtr) != 1 && inputCounter < INVALID_ENTRY_COUNT );
		// end do while

		char date_of_birth[DOB_LEN]; // variable for date of birth

		int year_of_birth,  month_of_birth, day_of_birth ; // variable for age information


		// while loop to get applicant age,
		// check valid entries and allow for user re-entry of
		// input in case of errors
		while (inputCounter <= INVALID_ENTRY_COUNT) {

			getAgeFromApplicant(currentYear, currentMonth, date_of_birth, DOB_LEN, &year_of_birth, &month_of_birth, &day_of_birth, applicantRecordPtr);

			unsigned int checkedAge = checkAge(currentYear, currentMonth, year_of_birth, month_of_birth, applicantRecordPtr);

			// determines if user input is valid
			if (checkedAge == 1) {
				passportGroup[i].age = applicantRecordPtr->age;
					break;}

			else if (checkedAge == 0 || applicantRecordPtr->age<=0)

			{
				inputCounter++;
				// switch statement to track number entries for user input errors
				switch(inputCounter){

				case 1:
					inputCounter = INVALID_ENTRY_COUNT - 2;
					puts("\n      You have entered an invalid age. Please reenter age.");
					puts("      You have 2 more attempts");
					puts("");
					break;

				case 2:
					inputCounter = INVALID_ENTRY_COUNT - 1;
					puts("\n      You have entered an invalid age. Please reenter age.");
					puts("      You have 1 more attempt");
					puts("");
					break;

				default:
					inputCounter = INVALID_ENTRY_COUNT;
					puts("\n      You have entered an invalid age.");
					puts("      No more entries allowed. Please start over!");
					puts("");
					line(90, '*');
					return (0);

				} // End Switch
			}  // end else
		} // end while loop

		// get passport id and assign to structure array
		for (size_t i = 0;i < number_of_passports; i++ ){
			getPassportID(applicantRecordPtr);
			passportGroup[i].passport_id = applicantRecordPtr->passport_id;
		}

		printf("\n   Successful Entry for applicant #%d! \n", i+1);
		printf("      %s%lu\n", "Your temporary passport number is:", applicantRecordPtr->passport_id);

		line(70, '-');

		// display record of input to user
		displaySingleRecord(applicantRecordPtr);
	}

	// display summary of all inputs to user
	displayRecord(passportGroup, applicantRecordPtr);

	// write data to file passport.dat
	writeData(passportGroup, applicantRecordPtr);
}


// Function Definitions


// write data to file
void writeData( Passport *passportGroup, Passport *applicantRecordPtr ){
	FILE *pfPtr; // passports.dat file pointer

		// fopen opens file and exits program if unable to create file
		if ((pfPtr = fopen("passport.dat", "wb"))== NULL){
			puts("File could not be opened");
		}
		else {
			for (unsigned int i =0; i <= number_of_passports; i++){

				fwrite(&passportGroup[i], sizeof(Passport), 1, pfPtr );
			}
		}
		if (fclose(pfPtr) == EOF)
			puts("File could not be closed");
		else
			puts("\n Thank you. Your data has been saved.");
}

// get number of passports from User
int getPassportCount(){
	int number_of_passports;
	printf("Please enter the number of passports: ");
	scanf("%d", &number_of_passports);

	return number_of_passports;
}

// display summary of inputs to user
void displayRecord(Passport *passportGroup, Passport *record) {
	puts("\nSummary for all applicants below:");
	line(90, '-');
	printf("\n\t%s\t%s\t%s\t%s\n", "First Name", " Last Name", "Age", "Passport ID");
	for(size_t i = 0; i < number_of_passports; i++){
		printf("%d\t%-10s\t\%5s\t%10d\t%10lu \n", i + 1,
				passportGroup[i].firstName,
				passportGroup[i].lastName,
				passportGroup[i].age,
				passportGroup[i].passport_id
				);
	}
}

// display single record to user
void displaySingleRecord(Passport *record) {
	puts("   Applicant details:");
	printf("\t%s\t%s\t%s\t%s\n", "First Name", " Last Name", "Age", "Passport ID");

	printf("\t%-10s\t\%5s\t%10d\t%10lu \n",
			record->firstName,
			record->lastName,
			record->age,
			record->passport_id);
	line(70, '-');
}

/*
 * getFirstNameFromApplicant prompts and gets user first name
 * It copies the input by reference to the array in main
 */
void getFirstNameFromApplicant(Passport *record) {
	printf("\n      Enter First Name of applicant: ");
	scanf("%199s", record->firstName);
} // End getFirstNameFromApplicant

/*
 * getLastNameFromApplicant prompts and gets user last name
 * It copies the input by reference to the array in main
 */
void getLastNameFromApplicant(Passport *record) {
	printf("      Enter Last Name of applicant: ");
	scanf("%199s", record->lastName);
}// End getFirstNameFromApplicant

/*
 * getAgeFromApplicant prompts and gets user birth year and birth month
 * It copies the inputs by reference to the year_of_birth and month_of_birth parameters
 */
void getAgeFromApplicant(int currentYear, int currentMonth, char date_of_birth[], size_t size, int *year_of_birth,
		int *month_of_birth, int *day_of_birth, Passport *record) {

	 //	for (size_t i = 0; i < number_of_passports; i++) {
		int year_of_birthInput; // local variable
		int month_of_birthInput; // local variable
		int day_of_birthInput=0; // local variable
		char dob[12];

		// Prompt for input and read date of birth
		printf("      Please enter date of birth (dd/mm/yyyy): ");

		fgetc(stdin);
		fgets(dob, DOB_LEN, stdin);

		sscanf(dob, "%d%*c%d%*c%d", &day_of_birthInput, &month_of_birthInput, &year_of_birthInput);

		// update local variables of caller in the parameter list
		*year_of_birth = year_of_birthInput;
		*month_of_birth = month_of_birthInput;
		*day_of_birth = day_of_birthInput;

		int age = 0; // local variable to calculate age of user
		age = currentYear - year_of_birthInput;

		record->age = age;

}  // End getAgeFromApplicant


// generates random numbers for passports
void getPassportID(Passport *record){
	 int lower = 12000000, upper = 99999999;
	int num = (rand() % (upper - lower + 1)) + lower;
	record->passport_id = num;
} // End getPassportID

/*
 * Function to check name validity of name entry
 * names should be greater than one character in length
 * and only contains English ASCII letters from A-Z or a-z
 */
int checkName(Passport *record) {
		size_t nameLength_firstName = strlen(record->firstName);
		size_t nameLength_lastName = strlen(record->lastName);

		// tests name length and digits
		if ( isalpha(*record->firstName) || isdigit(*record->lastName) ){
						return 1;
					}
		if (nameLength_firstName == 1 || nameLength_lastName == 1 ){
			return 0;
		}
		if ( isdigit(*record->firstName) || isdigit(*record->lastName) ){
				return 0;
			}
		return 1;
} // End checkName

/*
 * Age of the applicant should be greater than 16 years old
 */
int checkAge(int currentYear, int currentMonth, int year_of_birth, int month_of_birth, Passport *record) {

	// Tests for valid age i.e various scenarios that check against age 16
	if (year_of_birth > currentYear)
		return 0;

	if (record->age > VALID_AGE)
		return 1;

	if (record->age < VALID_AGE)
		return 0;

	if (currentMonth < 0 || currentMonth > 12)
		return 0;

	if (record->age > VALID_AGE && month_of_birth < currentMonth)
		return 0;

	if (record->age > VALID_AGE && currentMonth >= month_of_birth)
		return 1;

	return 0;
}

/*
 * line function to add formatting to output
 * length and char parameters allows for more control by the caller
 */
void line(int length, char c) {
	int a; // local counter variable
	for (a = 0; a < length; ++a)
		putchar(c);
	puts("");
}
