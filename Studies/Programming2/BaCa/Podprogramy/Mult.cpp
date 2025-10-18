//Karol Dziekan
#include <cstdarg>
#include <string>

using namespace std;

string IntToString_Mult(int num){
    string number;

    if(num<0){
        number = "-";
        num *= -1;
    }

    if(num>9){
        number += IntToString_Mult(num/10);

    }

    number += (char)(num%10 + '0');
    return number;
}
string ReverseString(int index, int length1, int length2, int result[], string result_reversed){
    if((index < length1 + length2)){
        result_reversed += IntToString_Mult(result[index]);
        index += 1;
        return ReverseString(index, length1, length2, result, result_reversed);
    }else{
        return result_reversed;
    }
}


string SkipSign_Mult(string num){
    if(num[0]=='-' || num[0]=='+'){
        num.erase(0,1);
        return num;
    }
    else{
        return num;
    }
}
int SkipZeros(int i, int length1, int length2, int result[]){
    if((i < length1 + length2) && result[i] == 0){
        i += 1;
        return SkipZeros(i, length1, length2, result);
    }else{
        return i;
    }
}
void DeleteZeros_Mult(string& num){
    if(num.empty()){
        num = "0";
    }else{
        if (num[0] == '0') {
            num.erase(0, 1);
            DeleteZeros_Mult(num);
        }
    }
}
void ClearArray(int* tab, int size, int index = 0){
    if(index < size){
        tab[index] = 0;
        ClearArray(tab, size, index + 1);
    }

    return;
}



void GetArguments_Mult(string* numbers, va_list arguments, int index, int count){
    if(index < count){
        numbers[index] = va_arg(arguments, const char*);
        GetArguments_Mult(numbers, arguments, index + 1, count);
        return;
    }
}



void MultiplyDigits(int index1, int index2, int carry, string digits1, string digits2, int result[]){
    if(index2 >= 0){
        int digit1 = digits1[index1] - '0';
        int digit2 = digits2[index2] - '0';

        int sum = digit1 * digit2 + result[index1 + index2 + 1] + carry;

        carry = sum / 10;
        result[index1 + index2 + 1] = sum % 10;

        MultiplyDigits(index1, index2 - 1, carry, digits1, digits2, result);
    }else{
        if(carry > 0){
            result[index1] += carry;
        }
    }

    return;
}
void MultiplyNumbers(int index, int length, string number1, string number2, int result[]){
    if (index < 0){
        return;
    }

    MultiplyDigits(index, length - 1, 0, number1, number2, result);
    MultiplyNumbers(index - 1, length, number1, number2, result);
    return;
}



string MultiplyNS(string& number1, string& number2){
    int length1 = number1.length();
    int length2 = number2.length();

    int sizeTab = length1 + length2;
    int* result = new int[sizeTab];

    ClearArray(result, sizeTab);

    int index = length1 - 1;
    MultiplyNumbers(index, length2, number1, number2, result);

    int i = SkipZeros(0,length1,length2,result);

    if (i == length1 + length2)
        return "0";

    string result_reversed="";
    result_reversed = ReverseString(i, length1, length2, result, result_reversed);

    delete[] result;
    return result_reversed;
}



string MultiplyS(string number1, string number2){
    string result = "";

    string number1_ns;
    string number2_ns;

    number1_ns = SkipSign_Mult(number1);
    DeleteZeros_Mult(number1_ns);

    number2_ns = SkipSign_Mult(number2);
    DeleteZeros_Mult(number2_ns);

    if(number1_ns[0] == '0' || number2_ns[0] == '0'){
        return "0";
    }

    if((number1[0] == '-' && number2[0] == '-') || (number1[0] != '-' && number2[0] != '-')){
        result = MultiplyNS(number1_ns,number2_ns);
    }

    if((number1[0] == '-' && number2[0] != '-') || (number2[0] == '-' && number1[0] != '-')){
        string sign = "-";
        result = sign + MultiplyNS(number1_ns,number2_ns);

    }

    return result;
}
string MultiplyArray(int count, int index, const string* number, string result = ""){
    if(index < count){
        if(index == 0){
            result = number[0];
            return MultiplyArray(count, index + 1, number, result);
        }else{
            result = MultiplyS(result,number[index]);
            index++;

            if(index < count){
                return MultiplyArray(count, index, number, result);
            }
        }
    }

    return result;
}



string Mult(int count, const string* numbers){
    string result ="";
    
    result = MultiplyArray(count, 0, numbers);
    return result;
}
void Mult(string* result, int count, const string*numbers){
    *result = "";

    *result = MultiplyArray(count, 0, numbers);
    return;
}
void Mult(string& result, int count, const string*numbers){
    result = MultiplyArray(count, 0, numbers);
    return;
}



string Mult(int count, ...){
    string result = "";

    string* numbers = new string[count];
    va_list arguments;

    va_start(arguments, count);
    GetArguments_Mult(numbers, arguments, 0, count);
    va_end(arguments);

    result = MultiplyArray(count, 0, numbers);

    delete[] numbers;
    return result;
}

void Mult(string* result, int count, ...){
    *result = "";
    string* numbers = new string[count];

    va_list arguments;
    va_start(arguments,count);
    GetArguments_Mult(numbers, arguments, 0, count);
    va_end(arguments);

    *result = MultiplyArray(count, 0, numbers);

    delete[] numbers;
    return;
}

void Mult(string& result, int count, ...){
    result = "";
    string* numbers = new string[count];

    va_list arguments;
    va_start(arguments, count);
    GetArguments_Mult(numbers, arguments, 0, count);
    va_end(arguments);

    result = MultiplyArray(count, 0, numbers);

    delete[] numbers;
    return;
}