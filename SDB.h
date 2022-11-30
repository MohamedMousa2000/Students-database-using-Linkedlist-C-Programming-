#ifndef SDB_H_
#define SDB_H_
#include "DATA_TYPES.h"

#define NULL 0

typedef struct SDB_Node
{
    u32 ID;
    u32 Year;
    u32 Courses_IDs[3];
    u32 Courses_Grades[3];
    struct SDB_Node* Next_Student_Ptr;
}SDB_Node;

/**
 * @brief: Check if the database is Full
 *
 * @return true : The database is Full
 * @return false: Otherwise
 */
void SDB_IS_FULL(void);

/**
 * @brief: Get the number of the entries in the database
 *
 * @return u8: Number of entries
 */
void SDB_GET_USED_SIZE(void);

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
void SDB_ADD_ENTRY(void);

/**
 * @brief: Delete the entry with the given ID
 *
 * @param[in] ID: ID of the entry to be deleted
 */
void SDB_DELETE_ENTRY(void);

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
void SDB_READ_ENTRY(void);

/**
 * @brief: Get the List of the IDs of the students
 *
 * @param[out] Count: Pointer to the number of entries that currently exists in the data base
 * @param[out] List : Pointer to the list of IDs
 */
void SDB_GET_ID_LIST(void);

/**
 * @brief: Check if the given student ID exists
 *
 * @param[in] ID: Given ID
 * @return true : ID exists
 * @return false: Otherwise
 */
void SDB_IS_ID_EXIST(void);







#endif /*SDB_H_*/
