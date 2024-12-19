#pragma once
//Класс для хранения данных о клиенте
class Client {
private:
    char name[50];
    char phone[20];
    char address[100];
public:
    Client(char* name, char* phone, char* address); //конструктор с параметрами
    void set(char* name, char* phone, char* address); //Получение значений переменных-членов класса
    void get(char* name, char* phone, char* address); //Получение данных класса
};