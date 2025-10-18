// Karol Dziekan
#include <string>
#include <cstdarg>

using namespace std;

void ReverseString(string &str, int left = 0, int right = -1){
    if (right == -1){
        right = str.length() - 1;
    }

    if (left >= right){
        return;
    }

    swap(str[left], str[right]);
    ReverseString(str, left + 1, right - 1);

    return;
}
string RemoveSign(const string &number, int index = 0){
    if (index >= number.length()){
        return "";
    }
    if (index == 0 && (number[index] == '+' || number[index] == '-')){
        return RemoveSign(number, index + 1);
    }
    return number[index] + RemoveSign(number, index + 1);
}
bool IsGreaterOrEqual(const string &number1, const string &number2){
    if (number1.length() != number2.length()){
        return number1.length() > number2.length();
    }
    return number1 >= number2;
}
string RemoveLeadingZerosRec(const string &number, int index = 0, int flag = 0){
    if (index >= number.length()){
        return "";
    }
    if (number[index] != '0' || flag == 1){
        return number[index] + RemoveLeadingZerosRec(number, index + 1, 1);
    }
    return RemoveLeadingZerosRec(number, index + 1, 0);
}
string RemoveLeadingZeros(const string &number, int index = 0){
    string result = RemoveLeadingZerosRec(number, index);
    if (result.empty()){
        result = "0";
    }

    return result;
}
void GetArguments_Sum(string* numbers, va_list arguments, int count, int index = 0) {
    if (index < count) {
        numbers[index] = va_arg(arguments, const char*);
        GetArguments_Sum(numbers, arguments, count, index + 1);
    }
    return;
}

string AddPositiveStrings(const string &number1, const string &number2, int carry = 0, int index1 = -2, int index2 = -2, string result = ""){
    if (index1 == -2)
        index1 = number1.length() - 1;
    if (index2 == -2)
        index2 = number2.length() - 1;

    if (index1 < 0 && index2 < 0 && carry == 0){

        ReverseString(result);
        return result;
    }

    int digit1 = 0;
    int digit2 = 0;

    if (index1 >= 0){
        digit1 = number1[index1] - '0';
    }else{
        digit1 = 0;
        index1 = 0;
    }
    if (index2 >= 0){
        digit2 = number2[index2] - '0';
    }else{
        digit2 = 0;
        index2 = 0;
    }

    int sum = digit1 + digit2 + carry;
    result += (char)((sum % 10) + '0');
    carry = sum / 10;

    return AddPositiveStrings(number1, number2, carry, index1 - 1, index2 - 1, result);
}
string SubtractPositiveStrings(const string &number1, const string &number2, int borrow = 0, int index1 = -2, int index2 = -2, string result = ""){
    if (index1 == -2)
        index1 = number1.length() - 1;
    if (index2 == -2)
        index2 = number2.length() - 1;

    if (index1 < 0 && index2 < 0){
        return RemoveLeadingZeros(result);
    }

    int digit1 = 0;
    int digit2 = 0;

    if (index1 >= 0){
        digit1 = number1[index1] - '0';
    }else{
        digit1 = 0;
        index1 = 0;
    }
    if (index2 >= 0){
        digit2 = number2[index2] - '0';
    }else{
        digit2 = 0;
        index2 = 0;
    }

    int diff = digit1 - digit2 - borrow;
    if (diff < 0){
        diff += 10;
        borrow = 1;
    }else{
        borrow = 0;
    }

    result = (char)(diff + '0') + result;
    return SubtractPositiveStrings(number1, number2, borrow, index1 - 1, index2 - 1, result);
}
string AddStrings(const string &number1, const string &number2){
    string num1 = RemoveLeadingZeros(RemoveSign(number1));
    string num2 = RemoveLeadingZeros(RemoveSign(number2));

    bool isNegative1 = (number1[0] == '-');
    bool isNegative2 = (number2[0] == '-');

    if (!isNegative1 && !isNegative2){
        return AddPositiveStrings(num1, num2);
    }
    if (isNegative1 && isNegative2){
        return "-" + AddPositiveStrings(num1, num2);
    }
    if (IsGreaterOrEqual(num1, num2) && IsGreaterOrEqual(num2,num1)){
        return "0";
    }
    if (IsGreaterOrEqual(num1, num2)){
        string result = SubtractPositiveStrings(num1, num2);
        return isNegative1 ? "-" + result : result;
    }else{
        string result = SubtractPositiveStrings(num2, num1);
        return isNegative2 ? "-" + result : result;
    }
}
string SumArrayRecursive(const string *numbers, int count, int index = 0, string result = ""){
    if (index >= count)
{
        return result;
    }

    result = AddStrings(result, RemoveLeadingZeros(numbers[index]));
    return SumArrayRecursive(numbers, count, index + 1, result);
}

string Sum(int count, const string *numbers){
    return SumArrayRecursive(numbers, count);
}

void Sum(string *result, int count, const string *numbers){
    *result = SumArrayRecursive(numbers, count);
    return;
}

void Sum(string &result, int count, const string *numbers){
    result = SumArrayRecursive(numbers, count);
    return;
}

string Sum(int count, ...){
    string *numbers = new string[count];
    va_list arguments;
    va_start(arguments, count);

    GetArguments_Sum(numbers, arguments, count);

    va_end(arguments);
    string result = SumArrayRecursive(numbers, count);
    delete[] numbers;
    return result;
}

void Sum(string *result, int count, ...){
    string *numbers = new string[count];
    va_list arguments;

    va_start(arguments, count);
    GetArguments_Sum(numbers, arguments, count);
    va_end(arguments);

    *result = SumArrayRecursive(numbers, count);

    delete[] numbers;
    return;
}

void Sum(string &result, int count, ...){
    string *numbers = new string[count];
    va_list arguments;

    va_start(arguments, count);
    GetArguments_Sum(numbers, arguments, count);
    va_end(arguments);

    result = SumArrayRecursive(numbers, count);

    delete[] numbers;
    return;
}
