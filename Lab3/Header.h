#pragma once
//����� ��� �������� ������ � �������
class Client {
private:
    char name[50];
    char phone[20];
    char address[100];
public:
    Client(char* name, char* phone, char* address); //����������� � �����������
    void set(char* name, char* phone, char* address); //��������� �������� ����������-������ ������
    void get(char* name, char* phone, char* address); //��������� ������ ������
};