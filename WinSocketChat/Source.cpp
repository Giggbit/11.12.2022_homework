//Main.cpp
#include <iostream>
#include "Socket.h"

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");

	int nChoice;
	int port = 24242;  //�������� ����
	string ipAddress = "127.0.0.1"; //����� �������
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
		//��������� ������
		server.StartHosting(port);
		while (true)
		{
			cout << "\tWaiting..." << endl;
			//�������� ������ �� �������
			//� ��������� � ���������� receiveMessage
			server.ReceiveData(receiveMessage, MAXSTRLEN);
			
			if (receiveMessage[0] == '1') {
				cout << "�������" << endl;
				cout << "���-��: " << receiveMessage[2] << endl;
			}
			else if (receiveMessage[0] == '2') {
				cout << "�������" << endl;
				cout << "���-��: " << receiveMessage[2] << endl;
			}
			else if(receiveMessage[0] == '3'){
				cout << "�������" << endl;
				cout << "���-��: " << receiveMessage[2] << endl;
			}
			//���������� ������ �������
			server.SendDataMessageToClient(receiveMessage);
			//���� ���� ��������� "end", ��������� ������
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
	}
	else if (nChoice == 2)
	{
		cout << "1) ������� - 7800 ���" << endl;
		cout << "2) ������� - 26000 ���" << endl;
		cout << "3) ������� - 9000 ���" << endl;

		//cout << "Enter an IP address: " << endl;
		//����������� IP �������
		//cin >> ipAddress;
		ClientSocket client;
		//������������ � �������
		client.ConnectToServer(ipAddress.c_str(), port);
		while (true)
		{
			//���������� ���������
			client.SendDataMessage();
			cout << "\tWaiting" << endl;
			//�������� �����
			client.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "Received: " << receiveMessage << endl;
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
		//��������� ����������
		client.CloseConnection();
	}
	else if (nChoice == 3)
		return 0;
}










