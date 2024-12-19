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

//Класс для хранения информации о заказе
class Order {
private:
    int client_id;
    Product* products;
    int num_products;
    int total_price;
public:
    Order(); //конструктор
    ~Order() {
        delete[] products; //деструктор для очищения памяти
    };
    void addProduct(Product* product); //Выделение места под Products
    void get(int* client_id, int* num_products, int* total_price); //Получение данных класса
    void set(int client_id, int num_products, int total_price); //Получение значений переменных-членов класса
    void listProducts(Product* product, int count);
};

// Структура для хранения информации о количестве товара
class Storehouse {
private:
    std::unique_ptr<Product[]> products;
    int num_products;
public:
    Storehouse(); //конструктор
    //~Storehouse() {
    //    delete[] products; //деструктор для очищения памяти
    //};
    void addProduct(Product& newProduct);
    void editProduct(int product_id, char* name, int price, int volume, int category_id, int supplier_id);
    void listStorehouse(Product* product, int count);
    void get(int num_products); //Получение данных класса
    int listnum_products() {
        return num_products;
    };
};

//Класс для хранения истории заказов
class OrderHistory {
private:
    Order* orders; // Массив заказов
    int orderCount;
public:
    OrderHistory();
    ~OrderHistory() {
        delete[] orders; //деструктор для очищения памяти
    };
    void addOrder(Order* order);
    void listOrders(Order* order, int count);
    int listorder_count() {
        return orderCount;
    };
};


//Класс для хранения информации о магазине
class Store {
private:
    Client* clients;
    int num_clients;
    Category* categories;
    int num_categories;
    Supplier* suppliers;
    int num_suppliers;
public:
    Store(); //конструктор
    ~Store() {
        delete[] clients;
        delete[] categories;
        delete[] suppliers;
    };
    void addClient(Client* client);
    void addCategory(Category* category);
    void addSupplier(Supplier* supplier);
    void listClients(Client* client, int count);
    void listCategories(Category* category, int count);
    void listSuppliers(Supplier* supplier, int count);
    int listnum_categories() {
        return num_categories;
    };
    int listnum_suppliers() {
        return num_suppliers;
    };
    int listnum_clients() {
        return num_clients;
    };
};
