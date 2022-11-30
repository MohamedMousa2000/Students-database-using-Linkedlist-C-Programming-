#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

SDB_Node* Head = NULL;

static u8 Counter = 0;

/**
 * @brief: Check if the database is Full
 * 
 * @return true : The database is Full
 * @return false: Otherwise
 */
void SDB_IS_FULL(void)
{
    if(Counter == 10)
    {
        printf("\nDatabase is full\n");
    }
    else
    {
        printf("\nThere are %d spaces available :)\n", (10 - Counter));
    }
}

/**
 * @brief: Get the number of the entries in the database
 * 
 * @return u8: Number of entries
 */
void SDB_GET_USED_SIZE(void)
{
    printf("\nThere are %d entry in the database\n", Counter);
}

/**
 * @brief: Add new entry to database
 * 
 * @param[in] ID      : Student ID
 * @param[in] Year    : Student Year
 * @param[in] Subjects: Pointer to 3 subject IDs 
 * @param[in] Grades  : Pointer to 3 Grades
 * @return true       : If the new entry is successfully added
 * @return false      : Otherwise
 */
void SDB_ADD_ENTRY(void)
{
    if(Head == NULL)
    {
        Head = (SDB_Node*)malloc(sizeof(SDB_Node));
        printf("\nPlease Enter the ID for the first student: \n");
        scanf("%d", &Head->ID);
        printf("\nPlease Enter the Year of the student: \n");
        scanf("%d", &Head->Year);
        u8 i;
        for(i = 0; i < 3; i++)
        {
            printf("\nPlease Enter the %d Course ID: \n", i+1);
            scanf("%d", &Head->Courses_IDs[i]);

            printf("\nPlease Enter the %d Course Grade: \nNote: Please Enter a number between 0 -> 100\n", i+1);
            scanf("%d", &Head->Courses_Grades[i]);
        }
        Head->Next_Student_Ptr = NULL;
        Counter++;
    }
    else
    {
        if(Counter < 10)
        {
            SDB_Node* New_Node; 
            New_Node = (SDB_Node*)malloc(sizeof(SDB_Node));
            
            printf("\nPlease Enter the ID for a student: \n");
            scanf("%d", &New_Node->ID);
            printf("\nPlease Enter the Year of the student: \n");
            scanf("%d", &New_Node->Year);
            u8 i;
            for(i = 0; i < 3; i++)
            {
                printf("\nPlease Enter the %d Course ID: \n", i+1);
                scanf("%d", &(New_Node->Courses_IDs[i]));

                printf("\nPlease Enter the %d Course Grade: \nNote: Please Enter a number between 0 -> 100\n", i+1);
                scanf("%d", &(New_Node->Courses_Grades[i]));
            }
            
            SDB_Node* Last_Node = Head;
            
            while(Last_Node->Next_Student_Ptr != NULL)
            {
                Last_Node = Last_Node->Next_Student_Ptr;
            }
            
            Last_Node->Next_Student_Ptr = New_Node;
            
            New_Node->Next_Student_Ptr = NULL;
            
            Counter++;
        }
        else
        {
            printf("\nThe database is full :(\n");
        }
    }
    
}

/**
 * @brief: Delete the entry with the given ID
 * 
 * @param[in] ID: ID of the entry to be deleted 
 */
void SDB_DELETE_ENTRY(void)
{
    if(Head != NULL)
    {
        s32 ID = -1;
        printf("\nPlease Enter the ID to be deleted: \n");
        scanf("%d", &ID);
        SDB_Node* Current_Node = Head;
        SDB_Node* Temp = Head;
        if(Temp->ID == ID)
        {
            Head = Head->Next_Student_Ptr;
            free(Temp);
            Temp = NULL;
            Counter--;
            printf("\nThe ID had been deleted Successfully !!!");
        }
        else
        {
        
            while(Current_Node->Next_Student_Ptr != NULL)
            {
                if(Current_Node->Next_Student_Ptr->ID == ID)
                {
                    Temp = Current_Node->Next_Student_Ptr;
                    break;
                }
                else
                {
                    Current_Node = Current_Node->Next_Student_Ptr;
                }
            }
            if(Current_Node->Next_Student_Ptr == NULL)
            {
                printf("\nThe ID is not in the database\n");
            }
            else
            {
                Current_Node->Next_Student_Ptr = Temp->Next_Student_Ptr;
                free(Temp);
                Counter--;
                printf("\nThe ID had been deleted Successfully !!!");
            }
        
        }
    }
    else
    {
        printf("\nNo Head for your database, please create one and try again :)\n");
    }
}

/**
 * @brief: Read the entry that matches the given ID
 * 
 * @param[in]  ID       : Student ID 
 * @param[out] Year     : Pointer to student year 
 * @param[out] Subjects : Pointer to subjects
 * @param[out] Grades   : Pointer to grades 
 * @return true         : If the entry exist
 * @return false        : Otherwise
 */
void SDB_READ_ENTRY(void)
{
    if(Head != NULL)
    {
        s32 ID = -1;
        u8 Flag = 0;
        printf("\nPlease Enter the ID you are looking for: \n");
        scanf("%d", &ID);
        SDB_Node* Search = Head;
        while(Search != NULL)
        {
            if(Search->ID == ID)
            {
                printf("\nWe found the %d of the student in year %d: \n", ID, Search->Year);
                u8 i;
                for(i = 0; i < 3; i++)
                {
                    printf("\nSubject %d with ID %d is graded by %d out of 100\n", i, Search->Courses_IDs[i], Search->Courses_Grades[i]);
                }
                Flag = 1;
                break;
            }
            else
            {
                Search = Search->Next_Student_Ptr;
            }
        }
        if(Flag != 1)
        {
            printf("\nWe Couldn't find the ID :(\n");
        }
    }
    else
    {
        printf("\nNo Head for your database, please create one and try again :)\n");
    }
}

/**
 * @brief: Get the List of the IDs of the students
 * 
 * @param[out] Count: Pointer to the number of entries that currently exists in the database
 * @param[out] List : Pointer to the list of IDs
 */
void SDB_GET_ID_LIST(void)
{
    if(Head != NULL)
    {
        SDB_Node* Print = Head;
        u8 Counter_Print = 0;
        while(Print != NULL)
        {
            printf("\n%d) ID = %d\nYear = %d\n", Counter_Print, Print->ID, Print->Year);

            for(u8 j = 0; j < 3; j++)
            {
                printf("Subject %d with ID %d is graded by %d out of 100\n", j, Print->Courses_IDs[j], Print->Courses_Grades[j]);
            }
            Print = Print->Next_Student_Ptr;
            Counter_Print++;
        }
        if(Counter_Print != Counter)
        {
            printf("\nThere is an error in the number of entries (Check the add and delete functions)\n");
        }
    }
    else
    {
        printf("\nNo Head for your database, please create one and try again :)\n");
    }
}

/**
 * @brief: Check if the given student ID exists
 * 
 * @param[in] ID: Given ID 
 * @return true : ID exists
 * @return false: Otherwise
 */
void SDB_IS_ID_EXIST(void)
{
    if(Head != NULL)
    {
        s32 ID = -1;
        u8 Flag = 0;
        printf("\nPlease Enter the ID you are looking for: \n");
        scanf("%d", &ID);
        SDB_Node* Find = Head;
        while(Find != NULL)
        {
            if(Find->ID == ID)
            {
                printf("\nThis ID exists !!\n");
                Flag = 1;
                break;
            }
            else
            {
                Find = Find->Next_Student_Ptr;
            }
        }
        if(Flag != 1)
        {
            printf("\nThis ID doesn't exist :(\n");
        }
    }
    else
    {
        printf("\nNo Head for your database, please create one and try again :)\n");
    }
}
