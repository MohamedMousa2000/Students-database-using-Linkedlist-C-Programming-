#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

int main()
{
    u32 Option = 0;
    while(1)
    {
        printf("\nPlease Choose an option:\n1. Add Entry\n2. Delete Entry\n3. Read Entry\n4. Get all IDs\n5. Check the existence of an ID\n6. Number of IDs\n7. Is database full?\n(Press -1 to exit)\n");
        scanf("%d", &Option);
        
        if(Option == -1)
        {
            printf("\nThank You :)\n");
            break;
        }
        switch(Option)
        {
            case 1 : SDB_ADD_ENTRY()    ; break;
            case 2 : SDB_DELETE_ENTRY() ; break;
            case 3 : SDB_READ_ENTRY()   ; break;
            case 4 : SDB_GET_ID_LIST()  ; break;
            case 5 : SDB_IS_ID_EXIST()  ; break;
            case 6 : SDB_GET_USED_SIZE(); break;
            case 7 : SDB_IS_FULL()      ; break;
            default: printf("\nPlease Enter a valid option :(\n");
        }
    
    }
    
}