#include "Calculations.h"
#include "../definations.h"
#include "../Util/Util.h"

/**
 * @brief THis Function Will return Which Type of variable user wants
 * @param data 
 * @return Vartype 
 */
static Vartype WhichTypeOfVar(String data){
    if (*data == '"')   return Var_Type_String;
    else if ((*data == '-') || (*data > 47 && *data < 58)){
        int i = 0;
        while ( data[i] )
        {
            if (data[i] == '.') return Var_Type_Float;
            i++;
        }
        
        return Var_Type_Int;
    }

    return 0;
}


void* Do_Calculation(String data){
    String Instruction = (String)malloc(sizeof(char)*100);

    if (*data != '(')
        return;

    int i = 1;  
    while (*(data+i) != ')')
    {
        *(Instruction+i-1) = *(data+i);
        i++;
    }
    *(Instruction+i) = '\0';
    Instruction = RemoveSpaces(Instruction);
    i = stringLenth(Instruction);
    for (int j = 0; j < i ; j++){
    
    }


}