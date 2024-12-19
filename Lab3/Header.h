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

//Класс для хранения информации о товаре
class Product {
private:
    std::string name;
    int price;
    int count;
    int category_id;
    int supplier_id;
public:
    Product(); //конструктор
    Product(Product& p) {
        name = p.name;
        price = p.price;
        count = p.count;
        category_id = p.category_id;
        supplier_id = p.supplier_id;
    }
    void get(std::string& name, int* price, int* count, int* category_id, int* supplier_id); //Получение данных класса
    void set(std::string name, int price, int count, int category_id, int supplier_id); //Получение значений переменных-членов класса
    int getPrice() {
        return price;
    };
    int getCount() {
        return count;
    };
};

//Класс для хранения данных о поставщике
class Supplier {
private:
    char name[50];
    char phone[20];
    char address[100];
    Product* products;
    int num_products;
public:
    Supplier(char* name, char* phone, char* address); //конструктор с параметрами
    ~Supplier() {
        delete[] products; //деструктор для очищения памяти
    };
    //void addProduct(Product* product); //Выделение места под Products
    void get(char* name, char* phone, char* address); //Получение данных класса
    void set(char* name, char* phone, char* address); //Получение значений переменных-членов класса
};

//Класс для хранения данных о категории товара
class Category {
private:
    char name[50];   // Название категории ("Корм", "Игрушки", "Аксессуары")
    Product* products;
    int num_products;
public:
    Category(char* name); //конструктор с параметрами
    ~Category() {
        delete[] products; //деструктор для очищения памяти
    }
    //void addProduct(Product* product); //Выделение места под Products
    void get(char* name); //Получение данных класса
    void set(char* name); //Получение значений переменных-членов класса
};
