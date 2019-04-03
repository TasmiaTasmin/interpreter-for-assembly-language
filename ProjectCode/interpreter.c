#include <stdio.h>

//int operand_1 = 2, operand_2 = 4;
int x = 2, y = 3, z;

void ArithmaticOption();
void LogicalOption();
void clear (void);

int sum (int val_1, int val_2);
int sub (int val_1, int val_2);
int mul (int val_1, int val_2);
int div (int val_1, int val_2);

int andFunction(int x, int y);
int orFunction(int x, int y);
int notFunction(int x, int y);
int xorFunction(int x, int y);
int shiftFunction(int x, int y);

int logical(int x, int y);

int main()
{
    while(1)
    {
        int option;
        char dic;

        printf("Options:\n");
        printf("    1.: Arithmatic Operation\n");
        printf("    2.: Logical Operation\n");
        printf("Your Choice: ");

        scanf("%d", &option);

        if(option == 1)
        {
            ArithmaticOption();
        }
        else if(option == 2)
        {
            LogicalOption();
        }
        else
        {
            printf("Invalid Input. Try Again!\n\n");
            continue;
        }
        printf("Execute? (yes/no): ");

        clear ();
        scanf("%c", &dic);
        if(dic == 'n')
        {
            break;
        }
    }
    return 0;
}

void clear (void)
{
    while ( getchar() != '\n' );
}

void ArithmaticOption()
{
    int choice;
    char val;

    printf("Options:\n");
    printf("    1.: Addition\n");
    printf("    2.: Subtraction\n");
    printf("    3.: Multiplication\n");
    printf("    4.: Division\n");

    printf("Your Choice: ");
    scanf("%d", &choice);

    int operand_1, operand_2;
    printf("Input: \n");
    printf("    operand_1:");
    scanf("%d", &operand_1);
    printf("    operand_2:");
    scanf("%d", &operand_2);
    if(choice == 1)
    {
        printf("%d+%d = %d\n\n", operand_1, operand_2, sum(operand_1, operand_2));
    }
    else if(choice == 2)
    {
        printf("%d-%d = %d\n\n", operand_1, operand_2, sub(operand_1, operand_2));
    }
    else if(choice == 3)
    {
        printf("%d*%d = %d\n\n", operand_1, operand_2, mul(operand_1, operand_2));
    }
    else if(choice == 4)
    {
        printf("%d/%d = %d\n\n", operand_1, operand_2, div(operand_1, operand_2));
    }
    else
    {
        printf("Invalid Input. Try Again!\n\n");
        ArithmaticOption();
    }

    printf("Continue? (yes/no): ");
    clear ();
    scanf("%c", &val);
    if(val == 'y')
    {
        ArithmaticOption();
    }
}

void LogicalOption()
{
    int choice;
    char val;

    printf("Options:\n");
    printf("    1.: AND\n");
    printf("    2.: OR\n");
    printf("    3.: NOT\n");
    printf("    4.: XOR\n");
    printf("    5.: SHIFT\n");
    printf("    6.: LogicFunction\n");

    printf("Your Choice: ");
    //fflush(stdin);
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("andFunction(x, y)\n\n");
        printf("%d\n\n\n", andFunction(x, y));
    }
    else if(choice == 2)
    {
        printf("orFunction(x, y)\n\n");
        printf("%d\n\n\n", orFunction(x, y));
    }
    else if(choice == 3)
    {
        printf("notFunction(x, y)\n\n");
        printf("%d\n\n\n", notFunction(x, y));
    }
    else if(choice == 4)
    {
        printf("xorFunction(x, y)\n\n");
        printf("%d\n\n\n", xorFunction(x, y));
    }
    else if(choice == 5)
    {
        printf("shiftFunction(x, y)\n\n");
        printf("%d\n\n\n", shiftFunction(x, y));
    }
    else if(choice == 6)
    {
        printf("logical(x, y)\n\n");
        printf("%d\n\n\n", logical(x, y));
    }
    else
    {
        printf("Invalid Input. Try Again!\n\n");
        LogicalOption();
    }
    printf("Continue? (yes/no): ");
    clear ();
    scanf("%c", &val);
    if(val == 'y')
    {
        LogicalOption();
    }
}

asm(
    " _sum:;"
    "   pushl %ebp;"
    "   movl %esp, %ebp;"
    "   movl 8(%ebp), %eax;"
    "   addl 12(%ebp), %eax;"
    "   movl %ebp, %esp;"
    "   popl %ebp;"
    "   ret"
);

asm(
    " _sub:;"
    "   pushl %ebp;"
    "   movl %esp, %ebp;"
    "   movl 8(%ebp), %eax;"
    "   subl 12(%ebp), %eax;"
    "   movl %ebp, %esp;"
    "   popl %ebp;"
    "   ret"
);

asm(
    " _mul:;"
    "   pushl %ebp;"
    "   movl %esp, %ebp;"
    "   movl 8(%ebp), %eax;"
    "   mull 12(%ebp);"
    "   movl %ebp, %esp;"
    "   popl %ebp;"
    "   ret"
);

asm(
    " _div:;"
    "   pushl %ebp;"
    "   movl %esp, %ebp;"
    "   movl 8(%ebp), %eax;"
    "   cltd;"
    "   divl 12(%ebp);"
    "   movl %ebp, %esp;"
    "   popl %ebp;"
    "   ret"
);

/*int logical(int x, int y)
{
    int t1 = x^y;
    int t2 = t1 >> 17;
    int mask = (1<<13) - 7;
    int rval = t2 & mask;
    return rval;
}*/

asm(
    "_logical:;"
    "   pushl %ebp;"
    "   movl %esp,%ebp;"
    "   movl 8(%ebp),%eax;"
    "   xorl 12(%ebp),%eax;"
    "   sarl $17,%eax;"
    "   andl $8185,%eax;"
    "   movl %ebp,%esp;"
    "   popl %ebp;"
    "   ret;"
);

asm(
    "_andFunction:;"
    "   pushl %ebp;"
    "   movl %esp,%ebp;"
    "   movl 8(%ebp), %eax;"
    "   andl 12(%ebp), %eax;"
    "   movl %ebp,%esp;"
    "   popl %ebp;"
    "   ret;"
);

asm(
    "_orFunction:;"
    "   pushl %ebp;"
    "   movl %esp,%ebp;"
    "   movl 8(%ebp), %eax;"
    "   orl 12(%ebp), %eax;"
    "   movl %ebp,%esp;"
    "   popl %ebp;"
    "   ret;"
);

asm(
    "_notFunction:;"
    "   pushl %ebp;"
    "   movl %esp,%ebp;"
    "   movl 8(%ebp), %eax;"
    "   notl %eax;"
    "   movl %ebp,%esp;"
    "   popl %ebp;"
    "   ret;"
);

asm(
    "_xorFunction:;"
    "   pushl %ebp;"
    "   movl %esp,%ebp;"
    "   movl 8(%ebp),%eax;"
    "   xorl 12(%ebp),%eax;"
    "   movl %ebp,%esp;"
    "   popl %ebp;"
    "   ret;"
);

asm(
    "_shiftFunction:;"
    "   pushl %ebp;"
    "   movl %esp,%ebp;"
    "   movl 8(%ebp),%eax;"
    "   sarl $17,%eax;"
    "   movl %ebp,%esp;"
    "   popl %ebp;"
    "   ret;"
);
