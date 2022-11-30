#include<iostream>
#include<fstream>

//суммирует четные числа(пользователя) до определенного значения = (predel.txt)
//выводит в kolmax.txt максимальное введенное число и количество введенных чисел "GuntityNumber"

void output(int Maxnumber, int GuantityNumber) ;
int inputUser();
int inputNumberPredel();

int main() {
	int  NumberUser, GuantityNumber = 0, NumberPredel, MaxNumber = 0, sum = 0;
	NumberPredel = inputNumberPredel();
	do
	{
		NumberUser = inputUser();
		sum += NumberUser;
		if (MaxNumber < NumberUser)
			MaxNumber = NumberUser;
		GuantityNumber++;
	} while (sum < NumberPredel);

	output(MaxNumber, GuantityNumber);//вывод в ФАЙЛ 
	std::cout << "end" << std::endl;
	return 1;
}
int inputUser()
{
	int numberUser;
	std::cout << "enter number:";
	std::cin >> numberUser;
	if (numberUser % 2 == 0)
		return numberUser;
	return 0;
	
}


void output(int Maxnumber,int GuantityNumber)
{
	FILE *f_output;// для записи в файл
	f_output= fopen("kolmax.txt","w");
	fprintf(f_output, "Guantity Number: %d /n Max number: %d ", GuantityNumber ,Maxnumber);
	fclose(f_output);
}

int inputNumberPredel()
{
	int numberPredel;
	FILE *f_input; // для чтения из файла
	f_input = fopen("predel.txt","r");
	if (f_input== 0)//проверка на открытие
	{
		std::cout << "not file predel.txt";
		return 0;
	}
	fscanf(f_input, "%d", &numberPredel);//запись в переменную
	fclose(f_input);
	return (numberPredel);
}
