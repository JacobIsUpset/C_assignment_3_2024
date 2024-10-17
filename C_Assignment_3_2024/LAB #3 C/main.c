#include <stdio.h>
#include <string.h>


#define MaxNumOfStudents 100
// welcome to jacobs kino coding tutorial


int main(){


    // arrays
    int idArray[MaxNumOfStudents] = {0};
    char nameArray[MaxNumOfStudents];
    int ageArray[MaxNumOfStudents] = {0};
    double gradeArray[MaxNumOfStudents] = {0};

    // size of
    int numOfStudents = sizeof(idArray);



    // The program should start by welcoming the user 
    // and then continuously display the menu after each operation, until the user chooses to exit.
    printf("welcome!\n");

    while (1)
    {
        // value for selecting the menu
        int menuValue = 0;

        //menu
        printf("----- menu -----\n");
        printf("print all students - 1\n");
        printf("add new student - 2\n");
        printf("remove student by id - 3\n");
        printf("grade statistics - 4\n");
        printf("quit - 5\n");
        scanf("%d", &menuValue);

        
        if (menuValue == 1)
        {
            // Display the details (ID, Name, Age, and Grade) of all the students currently in the system.
            for (int i = 0; i <= numOfStudents; i++)
            {
                printf("ID: %d\n", idArray[i]);
                printf("Name: %s\n", nameArray[i]);
                printf("Age: %d\n", ageArray[i]);
                printf("Grade: %.2f\n", gradeArray[i]); // note to self: %.2f is the amount of decimal spaces you want it to print
            }
        } else if (menuValue == 2){
            // Allow the user to enter details for a new student, making sure the ID is unique. 
            // Ensure that the student’s name is no longer than 40 characters 
            // and the age and grade are within reasonable ranges. If the list is full (100 students), 
            // the program should inform the user that no more students can be added.

            // im putting this int outside to use it as a ref for the next valadation
            int idInput = 0;

            // id input and validation
            char overwriteInput;
            while (1)
            {
                printf("do you want to overwrite a Student? Y/N\n");
                scanf(" %c", &overwriteInput);
                if (overwriteInput == 'y' || overwriteInput == 'n'){break;}
                printf("invalid answer!, Please try again");
            }
            
            if (overwriteInput == 'y')
            {
                while (1)
            {
                idInput = 0;
                printf("please enter the id of the student");
                scanf("%d", &idInput);
                for (int i = 0; i <= numOfStudents; i++){
                    if (idInput != idArray[i])
                    {
                        idArray[i] = idInput;
                        break;
                    }
                    
                }
                printf("error, please try again");
            }

            } else {
                // this should help better index the ids
                while (1)
                {
                    int idNumFlag = numOfStudents + 1;

                    if (numOfStudents == MaxNumOfStudents) {
                        idArray[numOfStudents] = idNumFlag;
                        printf("Student has been assigned ID %d\n", idNumFlag);
                        idInput = idNumFlag; // this "syncs" the id for the next parts
                        numOfStudents = numOfStudents + 1;
                        break;
                    } else {
                        printf("ERROR! Max number of students reached!\n");
                        break;
                    }
                }

            }
            
            //name input and "validation" // DONE
            while (1)
            {
                char nameInput[41];
                printf("enter the name of the student!");
                fgets(nameInput, sizeof(nameInput), stdin);
                strcpy(nameArray[idInput], nameInput);
                break;
            }

            //age input and validation // DONE
            while (1)
            {
                int ageInput = 0;
                printf("enter the age of the student!\n");
                scanf("%d", &ageInput);
                if (ageInput >= 0 && ageInput <= 100)
                {
                    ageArray[idInput] = ageInput;
                    break;
                }
                printf("Error!, please try again");
            }

            // Grade input and validation // DONE
            while (1)
            {
                int gradeInput = 0;
                printf("Enter the grade of the student!\n");
                scanf("%lf", &gradeInput);
    
                if (gradeInput >= 0 && gradeInput <= 100)
                {
                    gradeArray[idInput] = gradeInput;
                    break;
                }
                printf("Error! Please enter a valid grade between 0 and 100.\n");
            }

            
        } else if (menuValue == 3){
            // The user should be able to remove a student by entering their ID. If the ID does not exist, prompt the user to try again.
            int idInput = 0;

            while (1)
            {
                printf("please enter the id of the student you would like to remove!");
                scanf("%d", &idInput);
                if (ageArray[idInput] != 0)
                {
                    strcpy(nameArray[idInput], "");
                    ageArray[idInput] = 0;
                    gradeArray[idInput] = 0.0;
                    break;
                }
                printf("ERROR!, no student is assined to this id");

            }
            

            

        } else if (menuValue == 4){   // DONE
            // Calculate and display the average, minimum, and maximum grades of all students.
            int valueOfGrade = 0;
            // vars for grade calculation
            int highistGrade = 0;
            int lowestGrade = 0;
            int averageGrade = 0;
            int sumOfGrades = 0;

            for (int i = 0; numOfStudents ;i++)
            {
                gradeArray[i] = valueOfGrade;
                sumOfGrades += valueOfGrade;
                if (valueOfGrade > highistGrade){highistGrade = valueOfGrade;}
                if (valueOfGrade < lowestGrade){lowestGrade = valueOfGrade;}
                sumOfGrades += valueOfGrade;
            }

            averageGrade = sumOfGrades / numOfStudents;
            printf("\nHighest Grade: %d" ,highistGrade);
            printf("\nLowest Grade: %d" ,lowestGrade);
            printf("\nAverage Grade: %d" ,averageGrade);

        } else if (menuValue == 5){   // DONE
            // End the program when this option is selected.
            printf("goodbye!");
            break;
        }
    }
}