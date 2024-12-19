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

//����� ��� �������� ������ � ����������
class Supplier {
private:
    char name[50];
    char phone[20];
    char address[100];
    Product* products;
    int num_products;
public:
    Supplier(char* name, char* phone, char* address); //����������� � �����������
    ~Supplier() {
        delete[] products; //���������� ��� �������� ������
    };
    //void addProduct(Product* product); //��������� ����� ��� Products
    void get(char* name, char* phone, char* address); //��������� ������ ������
    void set(char* name, char* phone, char* address); //��������� �������� ����������-������ ������
};

//����� ��� �������� ������ � ��������� ������
class Category {
private:
    char name[50];   // �������� ��������� ("����", "�������", "����������")
    Product* products;
    int num_products;
public:
    Category(char* name); //����������� � �����������
    ~Category() {
        delete[] products; //���������� ��� �������� ������
    }
    //void addProduct(Product* product); //��������� ����� ��� Products
    void get(char* name); //��������� ������ ������
    void set(char* name); //��������� �������� ����������-������ ������
};
