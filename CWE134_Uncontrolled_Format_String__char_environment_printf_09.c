/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_printf_09.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_environment_printf_09_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(GLOBAL_CONST_TRUE)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);//SLIVER_SOURCE
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                strncat(data+dataLen, environment, 100-dataLen-1);
            }
        }
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);//SLIVER_SINK
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodB2G1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(GLOBAL_CONST_TRUE)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);//SLIVER_SOURCE
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                strncat(data+dataLen, environment, 100-dataLen-1);
            }
        }
    }
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);//SLIVER_SINK
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(GLOBAL_CONST_TRUE)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);//SLIVER_SOURCE
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                strncat(data+dataLen, environment, 100-dataLen-1);
            }
        }
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);//SLIVER_SINK
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodG2B1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);//SLIVER_SINK
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);//SLIVER_SINK
    }
}

void CWE134_Uncontrolled_Format_String__char_environment_printf_09_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE134_Uncontrolled_Format_String__char_environment_printf_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_environment_printf_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
//SLIVER_SOURCE:44--->SLIVER_SINK:56 YES
//SLIVER_SOURCE:44--->SLIVER_SINK:92 NO
//SLIVER_SOURCE:44--->SLIVER_SINK:119 NO
//SLIVER_SOURCE:44--->SLIVER_SINK:142 NO
//SLIVER_SOURCE:44--->SLIVER_SINK:160 NO
//SLIVER_SOURCE:75--->SLIVER_SINK:56 NO
//SLIVER_SOURCE:75--->SLIVER_SINK:92 YES
//SLIVER_SOURCE:75--->SLIVER_SINK:119 NO
//SLIVER_SOURCE:75--->SLIVER_SINK:142 NO
//SLIVER_SOURCE:75--->SLIVER_SINK:160 NO
//SLIVER_SOURCE:107--->SLIVER_SINK:56 NO
//SLIVER_SOURCE:107--->SLIVER_SINK:92 NO
//SLIVER_SOURCE:107--->SLIVER_SINK:119 YES
//SLIVER_SOURCE:107--->SLIVER_SINK:142 NO
//SLIVER_SOURCE:107--->SLIVER_SINK:160 NO