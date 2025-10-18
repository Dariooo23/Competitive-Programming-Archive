//Karol Dziekan
#include <cstdarg>
#include <string>

using namespace std;

void GetArgumentsOperation(std::string* arguments, va_list args, int i, int count){
    if (i < count){
        arguments[i] = va_arg(args, const char*);
        GetArgumentsOperation(arguments, args, i + 1, count);
    }
}



string Operation(string (*function)(int, const string*), int count, const string* numbers){
    return function(count, numbers);
}



string Operation(string (*function)(int, const string*), int count, ...){
    va_list args;
    va_start(args, count);
    string* arguments = new string[count];

    GetArgumentsOperation(arguments, args, 0, count);

    va_end(args);
    string result = function(count, arguments);

    delete[] arguments;

    return result;
}



void Operation(string* result, string (*function)(int, const string*), int count, ...){
    va_list args;
    va_start(args, count);
    string* arguments = new string[count];

    GetArgumentsOperation(arguments, args, 0, count);

    va_end(args);
    *result = function(count, arguments);

    delete[] arguments;
    return;
}



void Operation(string* result,string(*function)(int,const string*), int count, const string* num){
    *result = function(count,num);
    return;
}



void Operation(string& result, void(*function)(string*, int, const string*), int count, const string* num){
    function(&result,count,num);
    return;
}



void Operation(string& result, void (*function)(string*, int, const string*), int count, ...){
    va_list args;
    va_start(args, count);
    string* arguments = new string[count];

    GetArgumentsOperation(arguments, args, 0, count);

    va_end(args);
    function(&result,count, arguments);

    delete[] arguments;
    return;
}