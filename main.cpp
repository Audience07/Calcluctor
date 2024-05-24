#include "head.h"
using namespace std;
void eatspace(char* str);
double number(char* str, size_t& index);
double calc(char* str, size_t& index);
int main() {
	double value{};
	char a[MAX]{};
	cout << "Please enter,if you want to exit, please enter the “ENTER” key\n" << endl;						//接收字符串
		while (1) {
		size_t index{};
		cin.getline(a, MAX);
		if (a[1] == '\0') {
			return 1;
		}
		eatspace(a);
		cout << a << "=";
		try {
			value = calc(a, index);
			cout << value << endl;
		}
		catch (char* a) {
			cout << a << endl;
		}
	}
	
}
void eatspace(char* str) {								//消除空格
	size_t i{}, j{};
	while ((*(str + i) = *(str + j++)) != '\0') 
		if (*(str + i) != ' ')
			i++;
		return;
}
		
double number(char*  str,size_t& index) {					//字符串递加，如果遇到数字（value*10进位，并且加上）
	double value{};										
	while (isdigit(*(str + index))) {
		value *= 10;
		value += (*(str + index++) - '0');
	}
	if (*(str + index) != '.')
		return value;

	double factor{ 1 };
	while (isdigit(*(str + ++index))) {					//如果遇到小数点（value*0.1下位）
		factor *= 0.1;
		value = value + (*(str + index) - '0')*factor;
	}
	return value;
}

double  term(char* str, size_t& index) {			//查看下一项是否为乘除，如果为乘除，就执行乘除操作
	double value{number(str,index)};
	while (1) {
		if (*(str + index) == '*') {
			value *= number(str, ++index);
		}
		else if (*(str + index) == '/') {
			value /= number(str, ++index);
		}
		else {
			break;
		}
	}
	return value;
}

double calc(char* str, size_t& index) {				//判断下一个字符是否为加或者减号，以及是不是到达了字符串的终点'\0'
	double value{ term(str,index) };
	while (1) {
		switch (*(str + index)) {
		case '+':
			value += term(str, ++index);
			break;
		case '-':
			value -= term(str, ++index);
			break;
		case '\0':
			return value;
			break;
		default:
			char Message[]{ "Error" };
			throw Message;
		}
	}
}




