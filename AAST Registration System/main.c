#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



struct StudentInfo
{
    char ID[20];
    int password;
    char Name[20];
    double GPA;
    int EnglishLevel, Phy, Comp;
    int CalculusLevel;
    int NumberOfCourse;
    int Term;

};
struct FirstTermSub
{

};

struct CourseInfo
{
    char StudentID[10];
    char Code[10];
    char Name[50];
    int Credit;
    int Seventh;
    int Twelfth;
    int Final;
    int TotalScore;
    int Attendance;//14 99 3
    int State;
    int Withdraw;
    int Failed;
    int TermCourses;
    char Grade[2];
};

struct StudentInfo Students[100];
struct CourseInfo Courses[500];

// some global variables
int i,j, hour;
int TotalStudents = 0;
int TotalCourse = 0;
char StudentID[10];
/*FILE *AllStudents;
FILE *AllCourses;
FILE *ExistingAllStudents;
FILE *TempAllStudents;
FILE *ExistingAllCourses;
FILE *TempAllCourses;*/
// end
char BackOption;
char instructor_user[4] = "inst";
char instructor_pass[4] = "1234";
bool IsRunning = true;
void Menu();
void AddStudent();
void ShowAllStudents();
int  SearchStudent(char StudentID[10]);
void EditStudent(int StudentFoundIndex);
void DeleteStudent(int StudentIndex);
int  IsAlreadyExists(char GivenLine[30],char InfoType, char StudentID[300]);
void DeleteCourseByIndex(int CourseIndex);
void DeleteStudentByIndex(int CourseIndex);
void GoBackOrExit();
void ExitProject();
void Sample();
void Instructor();
void Registeration();
void FirstTerm();
void SecondTerm();
void SecTermQuestion();
void AddCourse();
void Doctor();
void InputDegree(int DegreeOption, int StudentIndex);
void DocOptions(int StudentIndex);
void saveStudents(struct StudentInfo Students[], int TotalStudents);
int loadStudents(struct StudentInfo Students[]);
void delete_FILE_students(struct StudentInfo Students[],int StudentIndex);
void savecources(struct CourseInfo Courses[], int TotalCourse,struct StudentInfo Students[],int StudentIndex) ;
int loadcources(struct CourseInfo Courses[]);
int Completed(int StudentIndex);
void gpa();
void GPA_table();
void Student_Transcript();
void Student_Results(int StudentIndex);
void Student();
float Previous_GPA;
float Cumulative_GPA;
float points;
float total_points = 0;
float GPA;
float subject_points;
int Total_hour = 18;
int Load ;
float epsilon = 0.000001;
int semester=1;
float SubGPA(int hour,int StudentIndex);
float RealGPA(int StudentIndex);
float StudentGPA(int,float*,int);


int main()
{
    //Sample(); // you can comment this line if not want dummy data
    TotalStudents=loadStudents(Students);
    TotalCourse=loadcources(Courses);
    printf("\n                  *-----------------------------------------------------------------*");
    printf("\n        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n        =                                                                               =");
    printf("\n        =             Welcome\t\tTo\t\tStudent\t\tPortal          =");
    printf("\n        =                                                                               =");
    printf("\n        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n                  *----------------------------------------------------------------*\n");
    printf("\n\n\nEnter any key to continue.....");
    getch();
    system("cls");

    while(IsRunning)
    {
        ka:Menu();
        int Option;
        scanf("%d",&Option);
        switch(Option)
        {
        case 0:
            IsRunning = false;
            ExitProject();
            break;
        case 1:
            system("cls");
            Registeration();
            GoBackOrExit();
            break;

        case 2:
            system("cls");
            Instructor();
            GoBackOrExit();
            break;

        case 3:
        {
            system("cls");
            Doctor();
            GoBackOrExit();
            break;
        }
        case 4:
            ko:system("cls");
            Student();
            /*printf("\n\t\t **** Edit a Student ****\n\n");
            printf(" Enter The Student ID: ");
            scanf("%s",StudentID);
            int StudentFoundIndex = SearchStudent(StudentID);

            if(StudentFoundIndex>=0)
            {
                EditStudent(StudentFoundIndex);
            }
            else
            {
                printf(" No Student Found\n\n");
            }*/
            GoBackOrExit();
            break;
        default:
            system("cls");
            printf("\033[0;31mWrong Input Please Try Again With Choose From 0 To 4 !\033[0m");
            goto ka;
            break;
        }
    }

    return 0;
} // end main function

void Menu()
{
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          [1] Registration.                                  =\n");
    printf("          =                          [2] Instructor.                                    =\n");
    printf("          =                          [3] Doctor.                                        =\n");
    printf("          =                          [4] Student.                                       =\n");
    printf("          =                          [0] Exit the Program.                              =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nPlease Enter The Choice : ");
} // end menu

void AddStudent()
{
    char StudentID[20];
    char Name[20];
    int NumberOfCourses;
    char CourseCode[20];
    char CourseName[20];
    char CourseCredit[20];
    int Eng=0, Calc=0;

    int flag1 = 0;
    while(!flag1)
    {
        printf("Enter The ID: ");
        scanf("%s",&StudentID);  //add id
        if(IsAlreadyExists(StudentID,'i',StudentID) > 0) //checking if the id is taken or not
        {
            printf("\033[0;31mError: This ID is already exists.\033[0m\n\n");
            flag1 = 0;
        }
        else if(strlen(StudentID) > 10)
        {
            printf("\033[0;31mError: ID can not be more than 10 characters.\033[0m\n\n");
            flag1 = 0;
        }
        else if(strlen(StudentID) <= 0)
        {
            printf("\033[0;31mError: ID can not be empty.\033[0m\n\n");
            flag1 = 0;
        }
        else
        {
            flag1 = 1;
        }
    }

    int flag2 = 0;
    while(!flag2)
    {
        lol: printf("Enter The Name: ");
        scanf(" %[^\n]s",&Name); //%[^\n]s---> to print spaces. :)
        if(strlen(Name) > 20)
        {
            system("cls");
            printf("\033[0;31mError: Name can not be more than 20 characters.\033[0m\n");
            flag2 = 0;
            goto lol;
        }
        if(strlen(Name) <= 0)
        {
            system("cls");
            printf("\033[0;31mError: Name can not be empty.\033[0m\n");
            flag2 = 0;
            goto lol;
        }
        else
        {
            flag2 = 1;
        }
    }
       aa:printf("Payment Completed? [Y / N]: ");
         char Sure = 'Y';
                getchar();
                scanf("%c",&Sure);
                if(Sure == 'N' || Sure == 'n')
                {
                    system("cls");
                    printf("\033[0;31mPayment Must Be Completed first in order to Continue.\033[0m\n");
                    flag2 = 1;
                    goto aa;
                }
    int flag4 = 0;
    while(!flag4)
    {
        ab:printf("Enter Your Department: \n");
        printf("[1] Math.\n[2] Science.\n[3] Literary.\n");
        scanf("%d",&Calc);
        if(Calc == 1)
        {
            Calc = 1;
            flag4 = 1;
        }
        else if(Calc == 2)
        {
            Calc = 0;
            flag4 = 1;
        }
        else if(Calc == 3){
            system("cls");
            printf("\033[0;31mYou Must be either from Math or Science Department.\033[0m\n\n");
            flag4 = 1;
            goto ab;
        }
        else{
            system("cls");
            printf("\033[0;31mError: Input from (1-3)\033[0m\n\n");
            flag4 = 0;
            goto ab;
        }
    }
    int flag3 = 0;
    while(!flag3)
    {
        ac:printf("Enter The English Exam Level (out of 50): ");
        scanf("%d",&Eng);
        if(Eng > 50 || Eng < 0)
        {
            system("cls");
            printf("\033[0;31mError: English Exam Test Cant be More than 50 or Less than 50.\033[0m\n\n");
            flag3 = 0;
            goto ac;
        }
        else if(Eng > 0 && Eng <=20){
            Eng = 0;
            flag3 = 1;
        }
        else if(Eng > 20 && Eng <=50)
        {
            Eng = 1;
            flag3=1;
        }
    }


    /*int IsValidNumberOfCourse = 0;
    while(!IsValidNumberOfCourse)
    {
        printf("Number of courses: ");
        scanf("%d",&NumberOfCourses);
        if(NumberOfCourses <= 0 || NumberOfCourses > 7)
        {
            printf("Error: Number of courses can not be more than 7 and lees than 1.\n\n");
            IsValidNumberOfCourse = 0;
        }
        else
        {
            IsValidNumberOfCourse = 1;
        }
    }*/

    strcpy(Students[TotalStudents].ID,StudentID);
    strcpy(Students[TotalStudents].Name,Name);
    Students[TotalStudents].NumberOfCourse = NumberOfCourses;
    Students[TotalStudents].EnglishLevel = Eng;
    Students[TotalStudents].CalculusLevel = Calc;

    /*for(i=0; i<NumberOfCourses; i++)
    {
        printf("Enter Course %d Code: ",i+1);
        scanf("%s",&CourseCode);

        printf("Enter Course %d Name: ",i+1);
        scanf(" %[^\n]s",&CourseName);

        printf("Enter Course %d Credit Hours: ",i+1);
        scanf("%d",&CourseCredit);

        strcpy(Courses[TotalCourse].StudentID,StudentID);
        strcpy(Courses[TotalCourse].Code,CourseCode);
        strcpy(Courses[TotalCourse].Name,CourseName);
        strcpy(Courses[TotalCourse].Credit,CourseCredit);
        TotalCourse++;
    }*/
     saveStudents(Students,TotalStudents++);
    printf("\n\033[0;32mStudent Added Successfully.\033[0m\n\n");
}

void ShowAllStudents()
{
    printf("|==========|====================|==========|\n");
    printf("|    ID    |        Name        |    GPA   |\n");
    printf("|==========|====================|==========|\n");
    TotalStudents=loadStudents(Students);
    for(i=0; i<TotalStudents; i++)
    {
        printf("|");
        printf("%s",Students[i].ID);
        for(j=0; j < (10-strlen(Students[i].ID)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",Students[i].Name);
        for(j=0; j < (20-strlen(Students[i].Name)); j++)
        {
            printf(" ");
        }
        printf("|");

        printf("%.2f     ",Students[i].GPA);
            printf(" ");
        printf("|\n");
        printf("|----------|--------------------|----------|\n");
    }
    printf("\n");
}

int SearchStudent(char StudentID[10]) //give him the id, and it  returns the student index id
{
    system("cls");
    int StudentFoundIndex = -1;

    int i;
    for(i=0; i<TotalStudents; i++)
    {
        if(strcmp(StudentID,Students[i].ID) == 0) //if studentid==student[i].id
        {
            StudentFoundIndex = i;                //take its index
            printf("\n One Student Found for ID: %s\n\n",StudentID);
            printf(" Student Informations\n");
            printf("=========================\n");

            printf(" ID:    %s\n",Students[i].ID);
            printf(" Name:  %s\n",Students[i].Name);
            printf("\n Total Number of Courses: %d\n",Students[i].NumberOfCourse);
        }
    }
    int CourseCount = 0;
    int j;
    for(j=0; j<TotalCourse; j++)
    {
        if(strcmp(StudentID,Courses[j].StudentID) == 0)
        {
            CourseCount++;
            printf(" Course %d Code: %s\n",CourseCount,Courses[j].Code);
            printf(" Course %d Name: %s\n",CourseCount,Courses[j].Name);
        }
    }

    return StudentFoundIndex; //return the index of the student to edit/delete
}

void EditStudent(int StudentFoundIndex)
{
    printf("\n\t\t **** Edit The Student ****\n\n");

    char NewName[300];
    int NewNumberOfCourses;
    char StudentID[300];
    strcpy(StudentID, Students[StudentFoundIndex].ID);
    int OldTotalNumberOfCourse = Students[StudentFoundIndex].NumberOfCourse;

    int flag = 0;
    while(!flag)
    {
        printf(" Enter The New Name(0 for skip): ");
        scanf(" %[^\n]s",&NewName);
        if(strlen(NewName) > 20)
        {
            printf("\033[0;31mError: Name can not be more than 20 characters.\033[0m\n\n");
            flag = 0;
        }
        else if(strlen(NewName) <= 0)
        {
            printf("\033[0;31mError: Name can not be empty.\033[0m\n\n");
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }
    int IsValidNumberOfCourse = 0;
    while(!IsValidNumberOfCourse)
    {
        printf(" Number of New courses(0 for skip): ");
        scanf("%d",&NewNumberOfCourses);

        if(NewNumberOfCourses > 4 || NewNumberOfCourses < 0)
        {
            printf("\033[0;31mError: A Student can have maximum 4 and Minimum 0 number of courses.\033[0m\n\n");
            IsValidNumberOfCourse = 0;
        }
        else
        {
            IsValidNumberOfCourse = 1;
        }
    }

    if(strcmp(NewName,"0") != 0)
    {
        strcpy(Students[StudentFoundIndex].Name,NewName);
    }

    if(NewNumberOfCourses != 0)
    {
        int OldTotalCourse = Students[StudentFoundIndex].NumberOfCourse;
        Students[StudentFoundIndex].NumberOfCourse = NewNumberOfCourses;


        int FirstCourseIndex;
        int dc;
        for(dc=0; dc<TotalCourse; dc++)
        {
            if(strcmp(StudentID,Courses[dc].StudentID) == 0)
            {
                FirstCourseIndex = dc; // store the index for delete
                break;
            }
        }
        // after every delete array index will update (decrease by one)
        // we store the courses sequential
        // so if we know the first course index and total number of course we can delete all
        for(dc=1; dc<=OldTotalCourse; dc++)
        {
            DeleteCourseByIndex(FirstCourseIndex);
        }

        char CourseCode[300];
        char CourseName[300];
        for(i=1; i<=NewNumberOfCourses; i++)
        {
            printf(" Enter New Course %d Code: ",i);
            scanf("%s",&CourseCode);

            printf(" Enter New Course %d Name: ",i);
            scanf(" %[^\n]s",&CourseName);

            strcpy(Courses[TotalCourse].StudentID,StudentID);
            strcpy(Courses[TotalCourse].Code,CourseCode);
            strcpy(Courses[TotalCourse].Name,CourseName);
            TotalCourse++;
        }
    }

    printf("\033[0;32mStudent Edited Successfully.\033[0m\n\n");

}

void DeleteStudent(int StudentIndex) //give him the index of the student from the structure so he can delete
{
    int d;
    int FirstCourseIndexs;
    struct StudentInfo ThisStudents; //accessing the studentinfo struct
    ThisStudents = Students[StudentIndex]; //giving the full student index structure for example student index number 1
    for(d=0; d<TotalCourse; d++)  //delete all the courses
    {
        if(strcmp(ThisStudents.ID,Courses[d].StudentID) == 0)
        {
            FirstCourseIndexs = d;
            break;
        }
    }
    for(d=1; d<=ThisStudents.NumberOfCourse; d++)
    {
        DeleteCourseByIndex(FirstCourseIndexs);
    }
    delete_FILE_students(Students,StudentIndex);
    DeleteStudentByIndex(StudentIndex);
    printf("\033[0;32mStudent Deleted Successfully.\033[0m\n\n");
    GoBackOrExit();
}


void DeleteCourseByIndex(int CourseIndex)
{
    int c;
    for(c=0; c<TotalCourse-1; c++)
    {
        if(c>=CourseIndex)
        {
            Courses[c] = Courses[c+1];
        }
    }
    TotalCourse--;

}

void DeleteStudentByIndex(int CourseIndex)
{
    int s;
    for(s=0; s<TotalStudents-1; s++)
    {
        if(s>=CourseIndex)
        {
            Students[s] = Students[s+1]; //after student[s] became 0,, swap the empty student with the next student
        }
    }
    TotalStudents--;

}


int IsAlreadyExists(char GivenLine[300],char InfoType, char StudentID[300])//to check if there is the same username or no
{
    int IDExists = 0;

    for(int i=0; i<TotalStudents; i++) //counter to check all the registered students
    {
        if(strcmp(GivenLine,Students[i].ID) == 0)//if exist return 1, which means there is the same user
        {
            IDExists++;
        }
    }

    if(InfoType == 'i')
    {
        return IDExists;
    }
    else
    {
        return 0;
    }
}
void GoBackOrExit()
{
    getchar();
    char Option;
    printf("Go back(b) or Exit(0)?: ");
    scanf("%c",&Option);
    if(Option == '0')
    {
        ExitProject();
    }
    else
    {
        system("cls");
    }
}

void ExitProject()
{
    system("cls");
    int i;
    char bye[100]     = " -----------------------------------{{ Thanks You For Using }}-----------------------------------\n";
    char bye2[100]   =  " --------------- {{ Arab Academy for Science, Technology & Maritime Transport Portal }} ---------------\n";
    for(i=0; i<strlen(bye); i++)
    {
        printf("%c",bye[i]);
        Sleep(40);
    }
    for(i=0; i<strlen(bye2); i++)
    {
        printf("%c",bye2[i]);
        Sleep(40);
    }
    exit(0);
}
void Registeration()
{
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          Registration Section                               =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    printf("\nChoose The Options Below.");
    printf("\n[1] Add New Student. \n[2] Delete Student. \n[3] View All Students.\n[4] Back To Home.\n");
    int option;
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            system("cls");
            printf("---------------------------------------------------------------\n");
            printf("=                      Add New Student                        =\n");
            printf("---------------------------------------------------------------\n\n");
            AddStudent();
            break;

        case 2:
            system("cls");
            printf("---------------------------------------------------------------\n");
            printf("=                      Delete a Student                       =\n");
            printf("---------------------------------------------------------------\n\n");
            printf("Enter The Student ID: ");
            scanf("%s",StudentID);


            int DeleteStudentFoundIndex = SearchStudent(StudentID);//searchstudent function returns the index of the student

            if(DeleteStudentFoundIndex>=0) //check if he wants to delete or no
            {
                char Sure = 'N';
                getchar();
                printf("\n\n");
                printf("Are you sure want to delete this student? (Y/N): ");
                scanf("%c",&Sure);

                if(Sure == 'Y' || Sure == 'y')
                {
                    DeleteStudent(DeleteStudentFoundIndex);
                }
                else
                {
                    printf("\033[0;32mYour Data is Safe.\033[0m\n\n");
                }

            }
            else
            {
                printf("\033[0;31mNo Student Found\033[0m\n\n");
            }
            break;

        case 3:
            system("cls");
            printf("---------------------------------------------------------------\n");
            printf("=                      All Students                           =\n");
            printf("---------------------------------------------------------------\n\n");
            ShowAllStudents();
            break;
        case 4:
            system("cls");
            main();
            break;

        default:
            system("cls");
            printf("\033[0;31mWrong Input Please Try Again With Choose From 1 To 3 !\033[0m");
            Registeration();
            break;
    }
}
void Sample()
{
    //-- store some dummy data
    //-- student 1
    strcpy(Students[0].ID,"221009381");
    strcpy(Students[0].Name,"Lionel Mody");
    Students[0].GPA = 3.5;
    Students[0].NumberOfCourse=1;

    strcpy(Courses[0].StudentID,"221009381");
    strcpy(Courses[0].Name,"Course - 1");

    //-- student 2
    strcpy(Students[1].ID,"221005400");
    strcpy(Students[1].Name,"Salahiano Ahraf");
    Students[1].NumberOfCourse=2;

    strcpy(Courses[1].StudentID,"221005400");
    Students[1].GPA = 2.75;
    strcpy(Courses[1].Name,"Course - 1");

    strcpy(Courses[2].StudentID,"221005400");
    strcpy(Courses[2].Code,"CSE-2");
    strcpy(Courses[2].Name,"Course - 2");


    //-- student 3
    strcpy(Students[2].ID,"221003213");
    strcpy(Students[2].Name,"Gafar EL-Omda");
    Students[2].NumberOfCourse=3;

    strcpy(Courses[3].StudentID,"221003213");
    strcpy(Courses[3].Code,"CSE-1");
    strcpy(Courses[3].Name,"Course - 1");

    strcpy(Courses[4].StudentID,"221003213");
    strcpy(Courses[4].Code,"CSE-2");
    strcpy(Courses[4].Name,"Course - 2");

    strcpy(Courses[5].StudentID,"221003213");
    strcpy(Courses[5].Code,"CSE-3");
    strcpy(Courses[5].Name,"Course - 3");

    TotalStudents = 3;
    TotalCourse = 6;
}
void Instructor(){

    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          Instructor Section                                 =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    //Instructor Registration--------------------------------------
    char inst_user[20];
    char inst_pass[20];
   a:printf("Enter your Username (inst): ");
   scanf("%s", inst_user);

   printf("Enter your password (1234): ");
   scanf("%s", inst_pass);

   if(strcmp(inst_user, "inst") == 0 && strcmp(inst_pass, "1234") == 0)
   {
      printf("\033[0;32mLogin successful!\033[0m\n\n");
   }
   else
   {
      printf("\033[0;31mInvalid username or password. Please try again.\033[0m\n");
      goto a;
   }


    qa:printf("Enter Student ID: ");
    scanf("%s",StudentID);
    int StudentIndex = SearchStudent(StudentID);
    system("cls");
    if(StudentIndex>1


       )
    {
        printf("\n One Student Found for ID: %s\n\n",StudentID);
        printf(" \n");
        printf("=========================\n");

        printf(" ID:    %s\n",Students[StudentIndex].ID);
        printf(" Name:  %s\n\n",Students[StudentIndex].Name);
    }
    else
    {
        printf("\033[0;31mThere is no student with this ID, Try Again!.\033[0m\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          Instructor Section                                 =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
        goto qa;
    }

    // Student ------------------------------------------------------

    printf("\nChoose The Options below\n");
    printf("[1] Add Courses. \n[2] Withdraw Courses.\n[3] Back To Home.");

    int option;
    scanf("%d",&option);

    switch(option){
    case 1:
        system("cls");
        printf("*** Add Courses ***\n\n");
        FirstTerm(StudentIndex);
        break;

    case 2:
        system("cls");
        printf("*** Withdraw Courses ***\n\n");
        break;
    case 3:
        system("cls");
        main();
        break;

    default:
        GoBackOrExit();
        break;
    }

}
void FirstTerm(int StudentIndex) //For new Students
{
    system("cls");
    printf("The First Term Courses:\n\n");
    //Calc -------------------------------------------------------------------
    if(Students[StudentIndex].CalculusLevel == 1){
        strcpy(Courses[TotalCourse].Name, "Calculus 1");
        Courses[TotalCourse].Credit = 3;
        printf("1. Calculus 1\n");
    }
    else
    {
        strcpy(Courses[TotalCourse].Name , "Calculus 0");
        Courses[TotalCourse].Credit = 3;
        printf("1. Calculus 0\n");
    }
    //ESP------------------------------------------------------------------------------
    if(Students[StudentIndex].EnglishLevel == 1){
        strcpy(Courses[TotalCourse+1].Name , "ESP 1");
        Courses[TotalCourse+1].Credit = 2;
        printf("2. ESP 1\n");
    }
    else
    {
        strcpy(Courses[TotalCourse+1].Name , "ESP 0");
        Courses[TotalCourse+1].Credit = 2;
        printf("2. ESP 0\n");
    }

    //else----------------------------------------------------------------------------
    printf("3. Physics. \n4. Introduction To Computing. \n5. Information System. \n6. Business. \n7. Creativity.\n\n\n");
    strcpy(Courses[TotalCourse+2].Name , "Physics");
    Courses[TotalCourse+2].Credit = 3;

    strcpy(Courses[TotalCourse+3].Name , "Introduction To Computing");
    Courses[TotalCourse+3].Credit = 3;

    strcpy(Courses[TotalCourse+4].Name , "Information System");
    Courses[TotalCourse+4].Credit = 3;

    strcpy(Courses[TotalCourse+5].Name , "Business");
    Courses[TotalCourse+5].Credit = 3;

    strcpy(Courses[TotalCourse+6].Name , "Creativity");
    Courses[TotalCourse+6].Credit = 3;
    savecources(Courses,TotalCourse,Students,StudentIndex);
    for(i=0; i<7; i++)
    {
        strcpy(Courses[TotalCourse].StudentID,StudentID);
        TotalCourse++;
    }
    //  0,calculus
    //  0,EsP
}
void SecondTerm(){
    int flag = 0;
    while(!flag)
    {
        printf("Enter your Previous GPA: \n");
        double grade;
        scanf("%f",&grade);
        double check = grade *1.0* 100;
        if(check > 200 && check <=400)
        {
            SecTermQuestion();
            flag = 1;
        }
        else if(check > 0 && check <= 200)
        {
            flag = 1;
        }
        else
        {
            printf("Error: Grade must be between (0 - 4.0).\n\n");
            flag=1;
        }
    }
    //Calculus ------------------------------------------------------------
    printf("The Courses:\n");
    if(Students[TotalStudents].CalculusLevel == 2){
        strcpy(Courses[TotalCourse].Name, "Calculus 2");
        Courses[TotalCourse].Credit = 3;
        printf("1. Calculus 1\n");
    }
    else if(Students[TotalStudents].CalculusLevel == 1){
        strcpy(Courses[TotalCourse].Name, "Calculus 1");
        Courses[TotalCourse].Credit = 3;
        printf("1. Calculus 1\n");
    }
    else
    {
        strcpy(Courses[TotalCourse].Name , "Calculus 0");
        Courses[TotalCourse].Credit = 3;
        printf("1. Calculus 0\n");
    }
    //ESP----------------------------------------------------------
    if(Students[TotalStudents].EnglishLevel == 2){
        strcpy(Courses[TotalCourse+1].Name , "ESP 2");
        Courses[TotalCourse+1].Credit = 2;
        printf("2. ESP 1\n");
    }
    else if(Students[TotalStudents].EnglishLevel == 1){
        strcpy(Courses[TotalCourse+1].Name , "ESP 1");
        Courses[TotalCourse+1].Credit = 2;
        printf("2. ESP 1\n");
    }
    else
    {
        strcpy(Courses[TotalCourse+1].Name , "ESP 0");
        Courses[TotalCourse+1].Credit = 2;
        printf("2. ESP 0\n");
    }
    //Another ----------------------------------------------------------

    //Physics-------------------------------------------------------------------
    if(Students[TotalCourse+2].Phy == 1)
    {
      printf("3. Advanced Physics\n");
      strcpy(Courses[TotalCourse+2].Name , "Advanced Physics");
      Courses[TotalCourse+2].Credit = 3;
    }
    else
    {
       printf("3. Physics\n");
       strcpy(Courses[TotalCourse+2].Name , "Physics");
       Courses[TotalCourse+2].Credit = 3;
    }

    //Computing--------------------------------------------------------------
    if(Students[TotalCourse+3].Comp == 1)
    {
       printf("4. Problem Solving\n");
       strcpy(Courses[TotalCourse+3].Name , "Problem Solving");
       Courses[TotalCourse+3].Credit = 3;
    }

    else
    {
        printf("4. Computing\n");
        strcpy(Courses[TotalCourse+3].Name , "Computing");
        Courses[TotalCourse+3].Credit = 3;
    }

    //Else --------------------------------------------------------------------

    printf("5. Discrete\n");
    strcpy(Courses[TotalCourse+4].Name , "Discrete");
    Courses[TotalCourse+4].Credit = 3;

    printf("6. Entrepreneurship\n");
    strcpy(Courses[TotalCourse+5].Name , "Entrepreneurship");
    Courses[TotalCourse+5].Credit = 2;

    printf("7. Communication\n");
    strcpy(Courses[TotalCourse+6].Name , "Communication");
    Courses[TotalCourse+6].Credit = 2;

    for(i=0; i<7; i++)
    {
        strcpy(Courses[TotalCourse].StudentID,StudentID);
        TotalCourse++;
    }
}
void SecTermQuestion()
{

}
void AddCourse()
{
}
void Doctor()
{
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          Doctor Section                                     =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
   //Login For Doctor-------------------------------------------------------------
   char doc_user[20];
   char doc_pass[20];
   int student_id;

   b:printf("Enter your Username (doc): ");
   scanf("%s", doc_user);

   printf("Enter your password (1234): ");
   scanf("%s", doc_pass);

   if(strcmp(doc_user, "doc") == 0 && strcmp(doc_pass, "1234") == 0)
   {
      printf("\033[0;32mLogin successful!\033[0m\n\n");
   }
   else
   {
      printf("\033[31mInvalid Username or Password. Please try again.\033[0m\n\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          Doctor Section                                     =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
      goto b;
   }

    //Enter Student ID------------------------------------------------------------------------------------

    qb:printf("Enter Student ID: ");
    scanf("%s",StudentID);
    int StudentIndex = SearchStudent(StudentID);
    system("cls");
    if(StudentIndex>0)
    {
        printf("\n One Student Found for ID: %s\n\n",StudentID);
        printf(" \n");
        printf("=========================\n");

        printf(" ID:    %s\n",Students[StudentIndex].ID);
        printf(" Name:  %s\n\n",Students[StudentIndex].Name);
    }

    else
    {
        printf("\033[0;31mThere is no student with this ID, Try Again!.\033[0m\n");
        goto qb;


    }
    DocOptions(StudentIndex);
}

    //------------------------------------------------------------------------------------------------
void DocOptions(int StudentIndex)
{
    int Com = Completed(StudentIndex);
    int DegreeOption;

    if(Com == 1)
    {
        printf("Congratulation!! You Have Completed The First Term. ");

    }
    else
    {
    printf("[1] Add Degrees. \n[2] Add Total Attendance\n[3] Students GPA.\n[4] Back To Home.\n\n");

    int option;
    scanf(" %d",&option);
        switch(option){

    //Show ALl Courses-----------------------------------------------------------------
      case 1:
        TotalCourse = TotalCourse - 7;
        system("cls");
        for(int i=0;i<7;i++)
        {
            printf("%d. %s  ",i+1,Courses[TotalCourse].Name);
            if(Courses[StudentIndex + i].Failed == 1){
                printf("--> Failed");
            }
            if(Courses[StudentIndex + i].Withdraw == 1){
                printf("--> Withdrawed");
            }

            printf("\n");
            TotalCourse++;
        }
        int DegreeOption;
        scanf("%d",&DegreeOption);
        switch(DegreeOption){
//---------------------------------------------------------------------------------------
         case 1://First Subject
         system("cls");
             InputDegree(DegreeOption, StudentIndex);
            break;
//---------------------------------------------------------------------------------------
        case 2://Seconed Subject/
         system("cls");
             InputDegree(DegreeOption, StudentIndex);
            break;
//---------------------------------------------------------------------------------------
         case 3://Third Subject/
         system("cls");
             InputDegree(DegreeOption, StudentIndex);
            break;
//---------------------------------------------------------------------------------------
         case 4://Fourth Subject/
            system("cls");
            InputDegree(DegreeOption, StudentIndex);
            break;
//---------------------------------------------------------------------------------------
         case 5://Fifth Subject/
         system("cls");
             InputDegree(DegreeOption, StudentIndex);
            break;

//---------------------------------------------------------------------------------------
         case 6://Sixth Subject/
         system("cls");
             InputDegree(DegreeOption, StudentIndex);
            break;

//---------------------------------------------------------------------------------------
         case 7://Seventh Subject/
            system("cls");
             InputDegree(DegreeOption, StudentIndex);
            break;
        }
        break;
    case 2:
        system("cls");
        TotalCourse = TotalCourse - 7;
        system("cls");
        for(int i=0;i<7;i++)
        {
            printf("%d. %s  ",i+1,Courses[TotalCourse].Name);
            if(Courses[StudentIndex + i].Failed == 1){
                printf("--> Failed");
            }
            if(Courses[StudentIndex + i].Withdraw == 1){
                printf("--> Withdrawed");
            }

            printf("\n");
            TotalCourse++;
        }
        int SubOption2;
        scanf("%d",&SubOption2);
        switch(SubOption2){
        case 1:
            InputAttend(SubOption2, StudentIndex);
            break;
        case 2:
            InputAttend(SubOption2, StudentIndex);
            break;
        case 3:
            InputAttend(SubOption2, StudentIndex);;
            break;
        case 4:
            InputAttend(SubOption2, StudentIndex);
            break;
        case 5:
            InputAttend(SubOption2, StudentIndex);
            break;
        case 6:
            InputAttend(SubOption2, StudentIndex);
            break;
        case 7:
            InputAttend(SubOption2, StudentIndex);
            break;
        default:
            GoBackOrExit();
            break;
                            }
        break;
        case 3:
            printf("Enter Student ID: ");
            scanf("%s",StudentID);
            int StudentIndex = SearchStudent(StudentID);
            int Com = Completed(StudentIndex);
            float Garr[Com*2];
            int oa=0;
            for(int as=0;as<Com*2;as++)
            {
                if(as%2==0)
                {
                    Garr[as]=Courses[StudentIndex + oa].TotalScore;
                    oa++;
                }
                else
                {
                    Garr[as]=Courses[StudentIndex + oa].Credit;
                }

            }
            Students[StudentIndex].GPA=StudentGPA(StudentIndex,Garr,Com);
            printf("The Student GPA Is : %0.2f",Students[StudentIndex].GPA);
            break;

            /*case 4:
            system("cls");
            main();
            break;

            default:
            system("cls");
            printf("\033[0;31mWrong Input Please Try Again With Choose From 1 To 4 !\033[0m");
            DocOptions();
            break;*/


        }
}
}
void InputDegree(int DegreeOption, int StudentIndex)
{
    int week1, week2, week3;
            system("cls");

//7th------------------------------------------------------------------------
            do {
            printf("Enter The 7th Degree between 0 and 30: ");
            scanf("%d",&week1);
            if (week1 < 0 || week1 > 30) {
                    system("cls");
            printf("Invalid input. Please try again.\n");
                    }
            }
            while (week1 < 0 || week1 > 30);

//12--------------------------------------------------------------------------------


       do {
            printf("Enter The 12th Degree between 0 and 30: ");
            scanf("%d",&week2);
            if (week2 < 0 || week2> 30) {
                    system("cls");
            printf("Invalid input. Please try again.\n");
            }
            }
            while (week2 < 0 || week2 > 30);

//Final------------------------------------------------------------------------------


        do {
            printf("Enter The Final Degree between 0 and 40: ");
            scanf("%d",&week3);
            if (week3 < 0 || week3 > 40) {
            system("cls");
            printf("Invalid input. Please try again.\n");
            }
            }
            while (week3 < 0 || week3 > 40);

//Saving the Grades----------------------------------------------------------------

         Courses[StudentIndex+DegreeOption - 1].Seventh = week1;
         Courses[StudentIndex+DegreeOption - 1].Twelfth = week2;
         Courses[StudentIndex+DegreeOption - 1].Final = week3;
         Courses[StudentIndex+DegreeOption - 1].TotalScore = week1+week2+week3;
         int sc = week1 + week2 + week3;
         if(sc < 50)
         {
             Courses[StudentIndex + DegreeOption - 1].Failed = 1;
         }
         else
         {
              Courses[StudentIndex + DegreeOption - 1].State = 1;
         }

            printf("\nTotal Score = { %d }\n",sc);
            printf("\n\nDegree Added Successfully\n\n");
            printf("Go Back (b) Exit(0) : ");
            scanf(" %c",&BackOption);

            if(BackOption =='b'||BackOption =='B')
            {
                DocOptions(StudentIndex);
            }
            else
            {
                ExitProject();
            }
}

void InputAttend(int SubOption2, int StudentIndex)
{
    int abs;
        system("cls");
        printf("\n\nEnter the number of times the student is Absent from the course : ");
        scanf("%d",&abs);

        if(abs>=5)
        {
            printf("The Course has been Withdrawn for Exceeding the allowed number of Absences.\n");
            Courses[SubOption2 + StudentIndex - 1].Withdraw = 1;
            Courses[StudentIndex + SubOption2 - 1].Attendance = abs;

            printf("\nGo Back (b) Exit(0) : ");
            scanf(" %c",&BackOption);

            if(BackOption =='b'||BackOption =='B')
            {
                DocOptions(StudentIndex);
            }
            else
            {
                ExitProject();
            }
        }
        else
        {
            printf("\nThe Number of Absence has been Entered Successfully!\n");
            printf("\nGo Back (b) Exit(0) : ");
            Courses[StudentIndex + SubOption2 - 1].Attendance = abs;

            scanf(" %c",&BackOption);
            if(BackOption =='b'||BackOption =='B')
            {
                DocOptions(StudentIndex);
            }
            else
            {
                ExitProject();
            }
        }
}
void saveStudents(struct StudentInfo Students[], int TotalStudents) {
    FILE* file = fopen("students.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s,%s,%d,%d\n",Students[TotalStudents].ID,Students[TotalStudents].Name,Students[TotalStudents].CalculusLevel, Students[TotalStudents].EnglishLevel);
    fclose(file);
}
int loadStudents(struct StudentInfo Students[]) {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("\033[0;31mIError opening file.\033[0m\n");
        return 0;
    }

    int TotalStudents = 0;
    while (fscanf(file, "%[^,],%[^,],%d,%d\n",Students[TotalStudents].ID,Students[TotalStudents].Name,&Students[TotalStudents].CalculusLevel,&Students[TotalStudents].EnglishLevel)!=EOF) {
        TotalStudents++;
    }

    fclose(file);
    return TotalStudents;
}

void delete_FILE_students(struct StudentInfo Students[],int StudentIndex)
 {
    FILE *f1,*f2;
    f1= fopen("students.txt", "r");
    f2= fopen("copy.txt", "a+");
    if(f1!=NULL)
    {
        int i=0;
         while ((fscanf(f1, "%[^,],%[^,],%d,%d\n",Students[i].ID,Students[i].Name, &Students[i].CalculusLevel, &Students[i].EnglishLevel)!=EOF))
         {
            if(i!=StudentIndex)
            {
              fprintf(f2, "%s,%s,%d,%d\n",Students[i].ID,Students[i].Name,Students[i].CalculusLevel, Students[i].EnglishLevel);
            }
            i++;
         }
    fclose(f1);
    fclose(f2);
    remove("students.txt");
    rename("copy.txt","students.txt");

    }

 }
void savecources(struct CourseInfo Courses[], int TotalCourse,struct StudentInfo Students[],int StudentIndex) {
    FILE* file = fopen("Courses.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    int i=0;
    while(i<7)
   {
        if(i==0)
        fprintf(file,"%s,",Students[StudentIndex].ID);

         fprintf(file, "%s,",Courses[TotalCourse+i].Name);
         i++;
   }
   fprintf(file,"\n");
    fclose(file);
}
int loadcources(struct CourseInfo Courses[]) {
    FILE* file = fopen("Courses.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    int TotalCourse= 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\n",Courses[TotalCourse].StudentID,Courses[TotalCourse].Name,Courses[TotalCourse+1].Name,Courses[TotalCourse+2].Name,Courses[TotalCourse+3].Name,Courses[TotalCourse+4].Name,Courses[TotalCourse+5].Name,Courses[TotalCourse+6].Name)!=EOF) {
            {
                        TotalCourse+=7;
            }
    }

    fclose(file);
    return TotalCourse;
}

int Completed(int StudentIndex)
{

    int sum=0;
    for(int i = 0 ; i < 7 ; i++){
        sum += Courses[StudentIndex + i - 1].Withdraw + Courses[StudentIndex + i - 1].State + Courses[StudentIndex + i - 1].Failed;
    }
    printf("Com = %d \n",sum);
    if(sum == 7)
    {
        Students[StudentIndex - 1].Term = 1;
        return 1;
    }
    else
    {
        Students[StudentIndex - 1].Term = 0;
        return 2;
    }
}

void gpa()
{
    int subject_grade;
    char grade[2];
    int hour;

    for(i=0; i<7; i++)
    {
        hour;
        if(i<=3)
        {
            hour=3;
        }
        else
        {
            hour=2;
        }
        printf("Enter subject %d grade :",i+1);
        scanf(" %d",&subject_grade);
        if(subject_grade>=96&&subject_grade<=100)
        {
            grade[0] = 'A';
            grade[1] = '+';
            points = 4.0;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=92&&subject_grade<96)
        {
            grade[0] = 'A';
            grade[1] = ' ';
            points = 3.7;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=88&&subject_grade<92)
        {
            grade[0] = 'A';
            grade[1] = '-';
            points = 3.4;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=84&&subject_grade<88)
        {
            grade[0] = 'B';
            grade[1] = '+';
            points = 3.2;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=80&&subject_grade<84)
        {
            grade[0] = 'B';
            grade[1] = ' ';
            points = 3;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=76&&subject_grade<80)
        {
            grade[0] = 'B';
            grade[1] = '-';
            points = 2.8;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=72&&subject_grade<76)
        {
            grade[0] = 'C';
            grade[1] = '+';
            points = 2.6;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=68&&subject_grade<72)
        {
            grade[0] = 'C';
            grade[1] = ' ';
            points = 2.4;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=64&&subject_grade<68)
        {
            grade[0] = 'C';
            grade[1] = '-';
            points = 2.2;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=60&&subject_grade<64)
        {
            grade[0] = 'D';
            grade[1] = '+';
            points = 2;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=55&&subject_grade<60)
        {
            grade[0] = 'D';
            grade[1] = ' ';
            points = 1.5;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade>=50&&subject_grade<55)
        {
            grade[0] = 'D';
            grade[1] = '-';
            points = 1;
            subject_points = (hour*points);
            total_points += subject_points;
        }
        else if(subject_grade<50)
        {
            grade[0] = 'F';
            grade[1] = ' ';
            points = 0;
            subject_points = (hour*points);
            total_points += subject_points;
        }
    }
    GPA = (total_points/18);

    //Comparing Previous GPA if equal to zero or not
    if (fabs(Previous_GPA) < epsilon)
        Cumulative_GPA = GPA;

    else
        Cumulative_GPA = ((GPA + Previous_GPA)/2.0);

    //Student grade view --------------------------------------------------------------------------
    printf("+---------------+----------+-----------+\n");
    printf("|  total hours  |    GPA   |   Points  |\n");
    printf("+---------------+----------+-----------+\n");
    for(i=0; i<3; i++)
    {
        printf("|");

        if(semester == 2 && i == 2)
            printf("%d             ",Total_hour*2);

        else  if(semester == 3 && i == 2)
            printf("%d             ",Total_hour*3);

        else  if(semester == 4 && i == 2)
            printf("%d             ",Total_hour*4);

        else  if(semester == 5 && i == 2)
            printf("%d             ",Total_hour*5);

        else  if(semester == 6 && i == 2)
            printf("%d             ",Total_hour*6);

        else  if(semester == 7 && i == 2)
            printf("%d             ",Total_hour*7);

        else  if(semester == 8 && i == 2)
            printf("%d             ",Total_hour*8);


        else
            printf("%d             ",Total_hour);

        printf("|");
        if(i == 0)
        {
            printf("%.2f      ",Previous_GPA);
        }
        else if(i == 1)
        {
           printf("%.2f      ",GPA);
        }
        else
        {
            printf("%.2f      ",Cumulative_GPA);
        }

        //sz = sizeof(Cumulative_GPA)/sizeof(*Cumulative_GPA);
        printf(" |");
        if(i == 0)
        {
             printf("%.1f     ",Previous_GPA*18);
        }
        else if(i == 1)
        {
            printf("%.1f     ",total_points);
        }
      else if(i == 2)
        {
            printf("%.1f     ",(total_points+Previous_GPA*18));
        }


        printf(" |\n");
        printf("+---------------+----------+-----------+\n");
    }
    printf("\n");

}//end

void Student_Transcript(int StudentIndex)
{
    for(int i = 1 ; i<= semester ; i++)
    {
    system("cls");

    if(semester == 1)
    {

   printf("+------------------------------------------+-----------------+------------------+---------------------+-------------+\n");
   printf("|                Course Name               |  credit Hours   |      grade       |        points       |    GPA      |\n");
   printf("+------------------------------------------+-----------------+------------------+---------------------+-------------+\n");


         for (int j = 0; j < 7; j++) {
                    printf("| %-40s | %-15d | %-16d | %-19f |  %-11f|\n",
            Courses[StudentIndex + j].Name,
            Courses[StudentIndex + j].Credit,
            Courses[StudentIndex + j].TotalScore,
            SubGPA(Courses[StudentIndex + j].Credit,StudentIndex),
            RealGPA(StudentIndex));


printf("+------------------------------------------+-----------------+------------------+---------------------+-------------+\n");
    }
    printf("%0.2f                   ",GPA);
printf("\n+------------------------------------------+-----------------+------------------+---------------------+-------------+\n");
    }
    else
    {
   printf("+------------------------------------------+-----------------+------------------+---------------------+-------------+\n");
   printf("|                Course Name               |  credit Hours   |      grade       |        points       |    GPA      |\n");
   printf("+------------------------------------------+-----------------+------------------+---------------------+-------------+\n");
        for (int j = 0; j < 7; j++) {
                    printf("| %-40s | %-15d | %-16s | %-19f |             |\n",
           Courses[StudentIndex + j].Name,Courses[StudentIndex + j].Credit,SubGPA(Courses[StudentIndex + j].Credit,StudentIndex),Courses[StudentIndex + j].TotalScore);

printf("+------------------------------------------+-----------------+------------------+---------------------+-------------+\n");
    }
    }
    }
}

void Student_Results(int StudentIndex)
{


    system("cls");
    printf("+------------------------------------------+-----------------+------------------+---------------------+\n");
    printf("|                Course Name               |  7th week (30%%) |  12th week (30%%) | Final Grade         |\n");
    printf("+------------------------------------------+-----------------+------------------+---------------------+\n");
    for (i = 0; i < 7; i++) {
        printf("| %-40s | %-15d | %-16d | %-19d |\n",
            Courses[StudentIndex+ i].Name,
            Courses[StudentIndex+ i].Seventh,
             Courses[StudentIndex+ i].Twelfth,
             Courses[StudentIndex+ i].Final);

    printf("+------------------------------------------+-----------------+------------------+---------------------+\n");

    }
    printf("|%.2f                                                                                                 |\n",GPA);
    printf("+------------------------------------------+-----------------+------------------+---------------------+\n");

}

void Student()
{
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          Student Section                                    =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    char newbie;
    //Login ----------------------------------------------
    qc:printf("Enter Student ID: ");
    scanf("%s",StudentID);
    int StudentIndex = SearchStudent(StudentID);
    system("cls");
    if(StudentIndex>0)
    {
        printf("\n One Student Found for ID: %s\n\n",StudentID);
        printf(" \n");
        printf("=========================\n");

        printf(" ID:    %s\n",Students[StudentIndex].ID);
        printf(" Name:  %s\n\n",Students[StudentIndex].Name);
    }

    else
    {
        printf("\033[0;31mThere is no student with this ID, Try Again!.\033[0m\n");
      printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("          =                                                                             =\n");
    printf("          =                          Student Section                                    =\n");
    printf("\n          -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
        goto qc;
    }
    //-----------------------------------------------------
    system("cls");
    printf("IS This Your First Year (Y/N):\n");
    scanf(" %c",&newbie);
    system("cls");
    if(newbie=='N'||newbie=='n')
    {
        printf("Please Enter Your Previous GPA And Your Current Semester: ");
        scanf("%f %d",&Previous_GPA,&semester);
    }
    else
    {
        printf("Welcome to your first year!\n");
    }

a:
    printf("Choose from the options below:\n");
    printf("[1] GPA Calculator\n");
    printf("[2] Student Transcript\n");
    printf("[3] Student Results\n");
    printf("[4] Back To Home\n");
    int option;
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        system("cls");
        printf("\n**** GPA Calculator ****\n\n");
        gpa();
        break;

    case 2:
        system("cls");
        printf("\n**** Student Transcript ****\n\n");
        Student_Transcript(StudentIndex);
        break;

    case 3:
        system("cls");
        printf("\n**** Student results ****\n\n");
        Student_Results(StudentIndex);
        break;

    case 4:
        main();
        break;

    default:
        system("cls");
        printf("Error: Choose from (1 - 4)\n");
        goto a;

    }
}

float RealGPA(int StudentIndex)
{
    float SubjectGrade;
    int hour;
    for(i=0; i<7; i++)
    {
        SubjectGrade = Courses[StudentIndex + i].TotalScore;
        hour = Courses[StudentIndex + i].Credit;

        if(SubjectGrade>=96&&SubjectGrade<=100)
        {
            Courses[StudentIndex + i].Grade[0] = 'A';
            Courses[StudentIndex + i].Grade[1] = '+';
            points = 4.0;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=92&&SubjectGrade<96)
        {
            Courses[StudentIndex + i].Grade[0] = 'A';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 3.7;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=88&&SubjectGrade<92)
        {
            Courses[StudentIndex + i].Grade[0] = 'A';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 3.4;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=84&&SubjectGrade<88)
        {
            Courses[StudentIndex + i].Grade[0] = 'B';
            Courses[StudentIndex + i].Grade[1] = '+';
            points = 3.2;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=80&&SubjectGrade<84)
        {
           Courses[StudentIndex + i].Grade[0] = 'B';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 3;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=76&&SubjectGrade<80)
        {
            Courses[StudentIndex + i].Grade[0] = 'B';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 2.8;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=72&&SubjectGrade<76)
        {
            Courses[StudentIndex + i].Grade[0] = 'C';
           Courses[StudentIndex + i].Grade[1] = '+';
            points = 2.6;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=68&&SubjectGrade<72)
        {
            Courses[StudentIndex + i].Grade[0] = 'C';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 2.4;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=64&&SubjectGrade<68)
        {
            Courses[StudentIndex + i].Grade[0] = 'C';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 2.2;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=60&&SubjectGrade<64)
        {
            Courses[StudentIndex + i].Grade[0] = 'D';
            Courses[StudentIndex + i].Grade[1] = '+';
            points = 2;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=55&&SubjectGrade<60)
        {
            Courses[StudentIndex + i].Grade[0] = 'D';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 1.5;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=50&&SubjectGrade<55)
        {
            Courses[StudentIndex + i].Grade[0] = 'D';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 1;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade<50)
        {
            Courses[StudentIndex + i].Grade[0] = 'F';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 0;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
    }
    GPA = (total_points/18);
    return GPA;
}

float SubGPA(int hour,int StudentIndex)
{i=0;
    float SubjectGrade;
        SubjectGrade = Courses[StudentIndex].TotalScore;
         hour = Courses[StudentIndex + i].Credit;

        if(SubjectGrade>=96&&SubjectGrade<=100)
        {
            Courses[StudentIndex + i].Grade[0] = 'A';
            Courses[StudentIndex + i].Grade[1] = '+';
            points = 4.0;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=92&&SubjectGrade<96)
        {
            Courses[StudentIndex + i].Grade[0] = 'A';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 3.7;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=88&&SubjectGrade<92)
        {
            Courses[StudentIndex + i].Grade[0] = 'A';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 3.4;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=84&&SubjectGrade<88)
        {
            Courses[StudentIndex + i].Grade[0] = 'B';
            Courses[StudentIndex + i].Grade[1] = '+';
            points = 3.2;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=80&&SubjectGrade<84)
        {
           Courses[StudentIndex + i].Grade[0] = 'B';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 3;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=76&&SubjectGrade<80)
        {
            Courses[StudentIndex + i].Grade[0] = 'B';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 2.8;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=72&&SubjectGrade<76)
        {
            Courses[StudentIndex + i].Grade[0] = 'C';
           Courses[StudentIndex + i].Grade[1] = '+';
            points = 2.6;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=68&&SubjectGrade<72)
        {
            Courses[StudentIndex + i].Grade[0] = 'C';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 2.4;
            SubjectGrade = (hour*points);
            total_points += SubjectGrade;
        }
        else if(SubjectGrade>=64&&SubjectGrade<68)
        {
            Courses[StudentIndex + i].Grade[0] = 'C';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 2.2;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=60&&SubjectGrade<64)
        {
            Courses[StudentIndex + i].Grade[0] = 'D';
            Courses[StudentIndex + i].Grade[1] = '+';
            points = 2;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=55&&SubjectGrade<60)
        {
            Courses[StudentIndex + i].Grade[0] = 'D';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 1.5;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade>=50&&SubjectGrade<55)
        {
            Courses[StudentIndex + i].Grade[0] = 'D';
            Courses[StudentIndex + i].Grade[1] = '-';
            points = 1;
            SubjectGrade = (hour*points);
        }
        else if(SubjectGrade<50)
        {
            Courses[StudentIndex + i].Grade[0] = 'F';
            Courses[StudentIndex + i].Grade[1] = ' ';
            points = 0;
            SubjectGrade = (hour*points);
        }
    return SubjectGrade;
}
float StudentGPA(int StudentIndex,float arr[],int Com)
{
    int o;
    float GPA=0;
    float points=0;
    float subject_points=0;
    float total_points=0;
    int TotalHours=0;

    for(o=0;o<Com*2;o+=2)
    {
        TotalHours+=arr[o+1];
        if(arr[o]>=96&&arr[o]<=100)
        {
            points = 4.0;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=92&&arr[o]<96)
        {
            points = 3.7;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=88&&arr[o]<92)
        {
            points = 3.4;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=84&&arr[o]<88)
        {
            points = 3.2;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=80&&arr[o]<84)
        {
            points = 3;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=76&&arr[o]<80)
        {
            points = 2.8;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=72&&arr[o]<76)
        {
            points = 2.6;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=68&&arr[o]<72)
        {
            points = 2.4;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=64&&arr[o]<68)
        {
            points = 2.2;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=60&&arr[o]<64)
        {
            points = 2;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=55&&arr[o]<60)
        {
            points = 1.5;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]>=50&&arr[o]<55)
        {
            points = 1;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
        else if(arr[o]<50)
        {
            points = 0;
            subject_points = (arr[o+1]*points);
            total_points += subject_points;
        }
    }
    GPA = (total_points/TotalHours);
    return GPA;
    }

