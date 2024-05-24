#include "head.h"
using namespace std;
void eatspace(char* str);
double number(char* str, size_t& index);
double calc(char* str, size_t& index);
int main() {
	double value{};
	char a[MAX]{};
	cout << "Please enter,if you want to exit, please enter the ��ENTER�� key\n" << endl;						//�����ַ���
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
void eatspace(char* str) {								//�����ո�
	size_t i{}, j{};
	while ((*(str + i) = *(str + j++)) != '\0') 
		if (*(str + i) != ' ')
			i++;
		return;
}
		
double number(char*  str,size_t& index) {					//�ַ����ݼӣ�����������֣�value*10��λ�����Ҽ��ϣ�
	double value{};										
	while (isdigit(*(str + index))) {
		value *= 10;
		value += (*(str + index++) - '0');
	}
	if (*(str + index) != '.')
		return value;

	double factor{ 1 };
	while (isdigit(*(str + ++index))) {					//�������С���㣨value*0.1��λ��
		factor *= 0.1;
		value = value + (*(str + index) - '0')*factor;
	}
	return value;
}

double  term(char* str, size_t& index) {			//�鿴��һ���Ƿ�Ϊ�˳������Ϊ�˳�����ִ�г˳�����
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

double calc(char* str, size_t& index) {				//�ж���һ���ַ��Ƿ�Ϊ�ӻ��߼��ţ��Լ��ǲ��ǵ������ַ������յ�'\0'
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




