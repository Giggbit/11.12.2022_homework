//Main.cpp
#include <iostream>
#include "Socket.h"

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");

	int nChoice;
	int port = 24242;  //выбираем порт
	string ipAddress = "127.0.0.1"; //Адрес сервера
	//string ipAddress = "10.4.3.8";
	char receiveMessage[MAXSTRLEN];
	char sendMessage[MAXSTRLEN];

	cout << "1) Start server" << endl;
	cout << "2) Connect to server" << endl;
	cout << "3) Exit" << endl;
	cin >> nChoice;
	if (nChoice == 1)
	{
		ServerSocket server;
		cout << "Starting server..." << endl;
		//Запускаем сервер
		server.StartHosting(port);
		while (true)
		{
			cout << "\tWaiting..." << endl;
			//Получаем данные от клиента
			//и сохраняем в переменной receiveMessage
			server.ReceiveData(receiveMessage, MAXSTRLEN);
			
			if (receiveMessage[0] == '1') {
				cout << "Телефон" << endl;
				cout << "Кол-во: " << receiveMessage[2] << endl;
			}
			else if (receiveMessage[0] == '2') {
				cout << "Ноутбук" << endl;
				cout << "Кол-во: " << receiveMessage[2] << endl;
			}
			else if(receiveMessage[0] == '3'){
				cout << "Планшет" << endl;
				cout << "Кол-во: " << receiveMessage[2] << endl;
			}
			//Отправляем данные клиенту
			server.SendDataMessageToClient(receiveMessage);
			//Если есть сообщение "end", завершаем работу
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
	}
	else if (nChoice == 2)
	{
		cout << "1) Телефон - 7800 грн" << endl;
		cout << "2) Ноутбук - 26000 грн" << endl;
		cout << "3) Планшет - 9000 грн" << endl;

		//cout << "Enter an IP address: " << endl;
		//Запрашиваем IP сервера
		//cin >> ipAddress;
		ClientSocket client;
		//подключаемся к серверу
		client.ConnectToServer(ipAddress.c_str(), port);
		while (true)
		{
			//отправляем сообщение
			client.SendDataMessage();
			cout << "\tWaiting" << endl;
			//получаем ответ
			client.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "Received: " << receiveMessage << endl;
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
		//Закрываем соединение
		client.CloseConnection();
	}
	else if (nChoice == 3)
		return 0;
}










