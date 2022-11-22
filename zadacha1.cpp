#include<iostream>
#include<fstream>
#include<math.h>
#include<locale.h>

//игра угадай число

void output(int numberUser);
bool logic( int numberGame, int numberUser);
int inputUser();
int inputStartgame();

int main() {
	bool winGame = false;
	int  numberUser, i = 0;
	while (!winGame) {
		numberUser = inputUser();
		winGame = logic(inputStartgame(), numberUser);
		output(numberUser);
		i++;
	}
	output(i);
	return 1;
}
bool logic( int numberGame,int numberUser)
{
	using namespace std;
	
	if (numberUser < numberGame)
		cout << "you number < :" << endl;
	if (numberUser > numberGame)
		cout << "you number > :" << endl;
	if (numberUser == numberGame)
	{
		cout << "you win";
		return true;
	}
	return false;
}
int inputUser()
{
	int numberUser;
	std::cin >> numberUser;
	return numberUser;
}

void output(int numberUser)
{
	std::ofstream f_output;// для записи
	f_output.open("endgame.txt", std::ios::app);
	f_output << numberUser << std::endl;
	f_output.close();
	std::cout << "sss";
	return;
}

int inputStartgame()
{
	int numberGame;
	std::ifstream f_input; // для чтения 
	f_input.open("startgame.txt");
	if (f_input.fail())//проверка на открытие
	{
		std::cout << "???";
		return 0;
	}
	f_input >> numberGame;//запись в переменную
	f_input.close();
	return (numberGame);
}
