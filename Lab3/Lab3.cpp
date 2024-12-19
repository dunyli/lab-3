﻿// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <malloc.h>
#include <Windows.h>

// Определение контруктора с параметрами класса Client
Client::Client(char* name, char* phone, char* address)
{
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
}

// Определение контруктора с параметрами класса Supplier
Supplier::Supplier(char* name, char* phone, char* address)
{
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
    num_products = 0;
}

// Определение контруктора с параметрами класса Category
Category::Category(char* name)
{
    strncpy(this->name, name, sizeof(this->name));
    num_products = 0;
}

// Определение контруктора  класса Product
Product::Product()
{
    price = 0;
    count = 0;
    category_id = 0;
    supplier_id = 0;
}

// Определение контруктора класса Order
Order::Order()
{
    client_id = 0;
    num_products = 0;
    total_price = 0;
}

// Определение контруктора класса Storehouse
Storehouse::Storehouse()
{
    num_products = 0;
}

// Определение контруктора класса OrderHistory
OrderHistory::OrderHistory()
{
    orderCount = 0;
}

// Определение контруктора класса Store
Store::Store()
{
    num_clients = 0;
    num_categories = 0;
    num_suppliers = 0;
}

//Получение значений переменных-членов класса и данных класса Client
void Client::get(char* name, char* phone, char* address) {
    strncpy(name, this->name, sizeof(this->name));
    strncpy(phone, this->phone, sizeof(this->phone));
    strncpy(address, this->address, sizeof(this->address));
}

void Client::set(char* name, char* phone, char* address) {
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
}

//Получение значений переменных-членов класса и данных класса Suppplier
void Supplier::get(char* name, char* phone, char* address) {
    strncpy(name, this->name, sizeof(this->name));
    strncpy(phone, this->phone, sizeof(this->phone));
    strncpy(address, this->address, sizeof(this->address));
}

void Supplier::set(char* name, char* phone, char* address) {
    strncpy(this->name, name, sizeof(this->name));
    strncpy(this->phone, phone, sizeof(this->phone));
    strncpy(this->address, address, sizeof(this->address));
}

//Получение значений переменных-членов класса и данных класса Category
void Category::get(char* name) {
    strncpy(name, this->name, sizeof(this->name));
}

void Category::set(char* name) {
    strncpy(this->name, name, sizeof(this->name));
}

//Получение значений переменных-членов класса и данных класса Product
void Product::get(std::string& name, int* price, int* count, int* category_id, int* supplier_id) {
    name = this->name;
    *price = this->price;
    *count = this->count;
    *category_id = this->category_id;
    *supplier_id = this->supplier_id;
}

void Product::set(std::string name, int price, int count, int category_id, int supplier_id) {
    this->name = name;
    this->price = price;
    this->count = count;
    this->category_id = category_id;
    this->supplier_id = supplier_id;
}

//Получение значений переменных-членов класса и данных класса Product
void Order::get(int* client_id, int* num_products, int* total_price) {
    *client_id = this->client_id;
    *num_products = this->num_products;
    *total_price = this->total_price;
}

void Order::set(int client_id, int num_products, int total_price) {
    this->client_id = client_id;
    this->num_products = num_products;
    this->total_price = total_price;
}

//Определение функции-члена класса Order для вывода истории заказов
void Order::listProducts(Product* product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

//Определение функции-члена класса OrderHistory для вывода истории заказов
void OrderHistory::listOrders(Order* order, int count) {
    for (int i = 0; i < orderCount; i++) {
        if (i == count) *order = orders[i];
    }
}

//Определение функции-члена класса Storehouse для вывода списка товаров
void Storehouse::listStorehouse(Product* product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

//Определение функции-члена класса Store для вывода списка клиентов
void Store::listClients(Client* client, int count) {
    for (int i = 0; i < num_clients; i++) {
        if (i == count) *client = clients[i];
    }
}

//Определение функции-члена класса Store для вывода списка категорий
void Store::listCategories(Category* category, int count) {
    for (int i = 0; i < num_categories; i++) {
        if (i == count) *category = categories[i];
    }
}

//Определение функции-члена класса Store для вывода списка поставщиков
void Store::listSuppliers(Supplier* supplier, int count) {
    for (int i = 0; i < num_suppliers; i++) {
        if (i == count) *supplier = suppliers[i];
    }
}



// Определение функции - члена класса Storehouse - функции addProduct()
void Storehouse::addProduct(Product& newProduct) {
    // Создаем новый массив с размером на 1 больше
    std::unique_ptr<Product[]> newProducts = std::make_unique<Product[]>(num_products + 1);

    // Копируем старые продукты в новый массив
    for (int i = 0; i < num_products; ++i) {
        newProducts[i] = products[i]; // Используем оператор копирования
    }

    // Добавляем новый продукт
    newProducts[num_products] = newProduct; // Копируем новый продукт
    num_products++;

    // Перенаправляем указатель
    products = std::move(newProducts); // Умный указатель автоматически освободит старую память
}



// Определение функции - члена класса OrderHistory - функции addOrder()
void OrderHistory::addOrder(Order* order) {
    orders = (Order*)realloc(orders, (orderCount + 1) * sizeof(Order));
    orders[orderCount] = *order;
    orderCount++;
}

// Определение функции - члена класса Store - функции addClient()
void Store::addClient(Client* client) {
    clients = (Client*)realloc(clients, (num_clients + 1) * sizeof(Client));
    clients[num_clients] = *client;
    num_clients++;
}

// Определение функции - члена класса Store - функции addCategory()
void Store::addCategory(Category* category) {
    categories = (Category*)realloc(categories, (num_categories + 1) * sizeof(Category));
    categories[num_categories] = *category;
    num_categories++;
}

// Определение функции - члена класса Store - функции addSupplier()
void Store::addSupplier(Supplier* supplier) {
    suppliers = (Supplier*)realloc(suppliers, (num_suppliers + 1) * sizeof(Supplier));
    suppliers[num_suppliers] = *supplier;
    num_suppliers++;
}

void Storehouse::editProduct(int product_id, char* name, int price, int volume, int category_id, int supplier_id) {
    products[product_id].set(name, price, volume, category_id, supplier_id);
}

// Функция для вывода меню
void outmenu() {
    printf("\nЗоомагазин Собачий Патруль\n");
    printf("1. Добавить клиента\n");
    printf("2. Добавить категорию\n");
    printf("3. Добавить поставщика\n");
    printf("4. Добавить товар\n");
    printf("5. Создать заказ\n");
    printf("6. Вывести список клиентов\n");
    printf("7. Вывести список категорий\n");
    printf("8. Вывести список поставщиков\n");
    printf("9. Вывести список товаров\n");
    printf("10. Вывести список заказов\n");
    printf("0. Выход\n");
    printf("Выберите действие: ");
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
