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

//����� ��� �������� ���������� � ������
class Product {
private:
    std::string name;
    int price;
    int count;
    int category_id;
    int supplier_id;
public:
    Product(); //�����������
    Product(Product& p) {
        name = p.name;
        price = p.price;
        count = p.count;
        category_id = p.category_id;
        supplier_id = p.supplier_id;
    }
    void get(std::string& name, int* price, int* count, int* category_id, int* supplier_id); //��������� ������ ������
    void set(std::string name, int price, int count, int category_id, int supplier_id); //��������� �������� ����������-������ ������
    int getPrice() {
        return price;
    };
    int getCount() {
        return count;
    };
};
