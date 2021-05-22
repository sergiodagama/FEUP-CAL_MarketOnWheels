#include <gtest/gtest.h>
#include "Headquarter.h"

/**
 *  THE FOLLOWING TESTS ARE ONLY USED TO FILL FILES WITH SPECIFIC DATA
 *  this dataset as valid positions for both penafiel_strong and porto_strong maps
 */

TEST(test, FILLER_PENAFIEL_OR_PORTO) {

    //---------------PRODUCTS---------------

    Headquarter headquarter("123");

    //total of 30 alimentary supermarket products
    headquarter.addProduct(new Product("snack", 1.5, 1));
    headquarter.addProduct(new Product("milk", 4.4, 4));
    headquarter.addProduct(new Product("butter", 2.1, 2));
    headquarter.addProduct(new Product("cheese ", 10, 3));
    headquarter.addProduct(new Product("beef ", 6, 5));
    headquarter.addProduct(new Product("chicken ", 2.5, 7));
    headquarter.addProduct(new Product("salmon", 15.3, 5));
    headquarter.addProduct(new Product("tuna ", 21.2, 4));
    headquarter.addProduct(new Product("crab ", 17.4, 4));
    headquarter.addProduct(new Product("potato ", 0.8, 2));
    headquarter.addProduct(new Product("onion", 0.9, 2));
    headquarter.addProduct(new Product("tomato ", 1, 3));
    headquarter.addProduct(new Product("broccoli", 0.7, 3));
    headquarter.addProduct(new Product("banana ", 0.9, 1));
    headquarter.addProduct(new Product("apple", 1.6, 1));
    headquarter.addProduct(new Product("grapes", 2.7, 3));
    headquarter.addProduct(new Product("bacon", 13, 2));
    headquarter.addProduct(new Product("ham ", 20, 5));
    headquarter.addProduct(new Product("pasta ", 1, 2));
    headquarter.addProduct(new Product("rice ", 0.6, 2));
    headquarter.addProduct(new Product("cookie ", 3.6, 3));
    headquarter.addProduct(new Product("chocolate ", 3.2, 2));
    headquarter.addProduct(new Product("cake", 14.4, 6));
    headquarter.addProduct(new Product("egg ", 1.3, 4));
    headquarter.addProduct(new Product("juice", 6.1, 3));
    headquarter.addProduct(new Product("water ", 2.1, 4));
    headquarter.addProduct(new Product("beer ", 1.1, 1));
    headquarter.addProduct(new Product("wine ", 7, 4));
    headquarter.addProduct(new Product("whiskey", 35, 5));
    headquarter.addProduct(new Product("oil ", 1.8, 2));

    headquarter.saveProductData("../src/Resources/products.txt");

    //---------------PROVIDERS---------------

    Provider *lidl = new Provider("lidl", "lidl", 26);
    Provider *continente = new Provider("continente", "continente", 200);
    Provider *pingo_doce = new Provider("pingo_doce", "pingo_doce", 201);

    lidl->addProduct(headquarter.getProductById(1), 200);
    lidl->addProduct(headquarter.getProductById(2), 120);
    lidl->addProduct(headquarter.getProductById(3), 130);
    lidl->addProduct(headquarter.getProductById(4), 103);
    lidl->addProduct(headquarter.getProductById(5), 96);
    lidl->addProduct(headquarter.getProductById(6), 220);
    lidl->addProduct(headquarter.getProductById(7), 176);
    lidl->addProduct(headquarter.getProductById(8), 34);
    lidl->addProduct(headquarter.getProductById(9), 45);
    lidl->addProduct(headquarter.getProductById(10), 110);

    continente->addProduct(headquarter.getProductById(11), 39);
    continente->addProduct(headquarter.getProductById(12), 138);
    continente->addProduct(headquarter.getProductById(13), 67);
    continente->addProduct(headquarter.getProductById(14), 206);
    continente->addProduct(headquarter.getProductById(15), 156);
    continente->addProduct(headquarter.getProductById(16), 76);
    continente->addProduct(headquarter.getProductById(17), 145);
    continente->addProduct(headquarter.getProductById(18), 203);
    continente->addProduct(headquarter.getProductById(19), 58);
    continente->addProduct(headquarter.getProductById(20), 88);

    pingo_doce->addProduct(headquarter.getProductById(21), 30);
    pingo_doce->addProduct(headquarter.getProductById(22), 212);
    pingo_doce->addProduct(headquarter.getProductById(23), 189);
    pingo_doce->addProduct(headquarter.getProductById(24), 132);
    pingo_doce->addProduct(headquarter.getProductById(25), 84);
    pingo_doce->addProduct(headquarter.getProductById(26), 53);
    pingo_doce->addProduct(headquarter.getProductById(27), 47);
    pingo_doce->addProduct(headquarter.getProductById(28), 125);
    pingo_doce->addProduct(headquarter.getProductById(29), 190);
    pingo_doce->addProduct(headquarter.getProductById(30), 12);

    headquarter.addProvider(lidl);
    headquarter.addProvider(continente);
    headquarter.addProvider(pingo_doce);

    headquarter.saveProviderData("../src/Resources/providers.txt");

    //---------------CLIENTS---------------

    headquarter.addClient(new Client("Mary", "mary", Date(17, 9, 2000), 9));
    headquarter.addClient(new Client("Lionel", "lio", Date(19, 7, 1975), 11));
    headquarter.addClient(new Client("Erica", "erica", Date(24, 1, 1947), 17));
    headquarter.addClient(new Client("Rebecca", "rebecca", Date(25, 4, 1985), 91));
    headquarter.addClient(new Client("Frances", "fran", Date(6, 4, 1956), 80));
    headquarter.addClient(new Client("Carmen", "carmen", Date(27, 6, 1993), 81));
    headquarter.addClient(new Client("John", "john", Date(16, 3, 1977), 98));
    headquarter.addClient(new Client("Christopher", "chris", Date(9, 2, 1991), 92));
    headquarter.addClient(new Client("Patricia", "patri", Date(13, 11, 1987), 101));
    headquarter.addClient(new Client("David", "davi", Date(21, 5, 1976), 106));

    //---------------ORDERS---------------

    Order *order1 = new Order(1);
    Order *order1_2 = new Order(1);
    Order *order1_3 = new Order(1);
    Order *order2 = new Order(2);
    Order *order2_2 = new Order(2);
    Order *order3 = new Order(3);
    Order *order3_2 = new Order(3);
    Order *order3_3 = new Order(3);
    Order *order3_4 = new Order(3);
    Order *order3_5 = new Order(3);
    Order *order4 = new Order(4);
    Order *order4_2 = new Order(4);
    Order *order5 = new Order(5);
    Order *order5_2 = new Order(5);
    Order *order5_3 = new Order(5);
    Order *order5_4 = new Order(5);
    Order *order6 = new Order(6);
    Order *order6_2 = new Order(6);
    Order *order6_3 = new Order(6);
    Order *order7 = new Order(7);
    Order *order7_2 = new Order(7);
    Order *order7_3 = new Order(7);
    Order *order7_4 = new Order(7);
    Order *order7_5 = new Order(7);
    Order *order7_6 = new Order(7);
    Order *order7_7 = new Order(7);
    Order *order8 = new Order(8);
    Order *order8_2 = new Order(8);
    Order *order9 = new Order(9);
    Order *order9_2 = new Order(9);
    Order *order9_3 = new Order(9);
    Order *order9_4 = new Order(9);
    Order *order10 = new Order(10);
    Order *order10_2 = new Order(10);
    Order *order10_3 = new Order(10);
    Order *order10_4 = new Order(10);
    Order *order10_5 = new Order(10);

    order1->addProduct(headquarter.getProductById(1), 20);
    order1->addProduct(headquarter.getProductById(2), 70);
    order1->addProduct(headquarter.getProductById(3), 10);
    order1_2->addProduct(headquarter.getProductById(3), 27);
    order1_2->addProduct(headquarter.getProductById(1), 60);
    order1_3->addProduct(headquarter.getProductById(3), 50);
    order2->addProduct(headquarter.getProductById(3), 10);
    order2->addProduct(headquarter.getProductById(4), 38);
    order2_2->addProduct(headquarter.getProductById(5), 40);
    order2_2->addProduct(headquarter.getProductById(6), 102);
    order2_2->addProduct(headquarter.getProductById(7), 70);
    order3->addProduct(headquarter.getProductById(7), 23);
    order3->addProduct(headquarter.getProductById(3), 10);
    order3->addProduct(headquarter.getProductById(4), 60);
    order3->addProduct(headquarter.getProductById(8), 14);
    order3_2->addProduct(headquarter.getProductById(1), 100);
    order3_2->addProduct(headquarter.getProductById(8), 10);
    order3_2->addProduct(headquarter.getProductById(9), 15);
    order3_2->addProduct(headquarter.getProductById(6), 12);
    order3_2->addProduct(headquarter.getProductById(10), 30);
    order3_3->addProduct(headquarter.getProductById(5), 36);
    order3_4->addProduct(headquarter.getProductById(9), 20);
    order3_5->addProduct(headquarter.getProductById(6), 59);
    order3_5->addProduct(headquarter.getProductById(10), 50);
    order3_5->addProduct(headquarter.getProductById(20), 47);
    order4->addProduct(headquarter.getProductById(19), 22);
    order4->addProduct(headquarter.getProductById(18), 110);
    order4_2->addProduct(headquarter.getProductById(20), 31);
    order4_2->addProduct(headquarter.getProductById(18), 78);
    order4_2->addProduct(headquarter.getProductById(19), 13);
    order5->addProduct(headquarter.getProductById(17), 49);
    order5->addProduct(headquarter.getProductById(15), 43);
    order5_2->addProduct(headquarter.getProductById(16), 60);
    order5_2->addProduct(headquarter.getProductById(14), 134);
    order5_2->addProduct(headquarter.getProductById(15), 64);
    order5_3->addProduct(headquarter.getProductById(17), 60);
    order5_3->addProduct(headquarter.getProductById(13), 23);
    order5_4->addProduct(headquarter.getProductById(12), 70);
    order6->addProduct(headquarter.getProductById(12), 38);
    order6->addProduct(headquarter.getProductById(11), 11);
    order6_2->addProduct(headquarter.getProductById(11), 12);
    order6_3->addProduct(headquarter.getProductById(13), 20);
    order7->addProduct(headquarter.getProductById(21), 5);
    order7_2->addProduct(headquarter.getProductById(11), 3);
    order7_2->addProduct(headquarter.getProductById(22), 17);
    order7_2->addProduct(headquarter.getProductById(29), 44);
    order7_3->addProduct(headquarter.getProductById(22), 16);
    order7_4->addProduct(headquarter.getProductById(22), 120);
    order7_5->addProduct(headquarter.getProductById(21), 7);
    order7_6->addProduct(headquarter.getProductById(24), 16);
    order7_7->addProduct(headquarter.getProductById(26), 3);
    order7_7->addProduct(headquarter.getProductById(25), 10);
    order8->addProduct(headquarter.getProductById(24), 31);
    order8->addProduct(headquarter.getProductById(26), 12);
    order8_2->addProduct(headquarter.getProductById(21), 6);
    order9->addProduct(headquarter.getProductById(29), 120);
    order9_2->addProduct(headquarter.getProductById(23), 8);
    order9_3->addProduct(headquarter.getProductById(30), 2);
    order9_3->addProduct(headquarter.getProductById(26), 7);
    order9_4->addProduct(headquarter.getProductById(23), 6);
    order9_4->addProduct(headquarter.getProductById(30), 5);
    order10->addProduct(headquarter.getProductById(24), 9);
    order10_2->addProduct(headquarter.getProductById(23), 29);
    order10_2->addProduct(headquarter.getProductById(28), 34);
    order10_3->addProduct(headquarter.getProductById(27), 23);
    order10_3->addProduct(headquarter.getProductById(23), 17);
    order10_3->addProduct(headquarter.getProductById(28), 28);
    order10_4->addProduct(headquarter.getProductById(24), 22);
    order10_5->addProduct(headquarter.getProductById(28), 57);
    order10_5->addProduct(headquarter.getProductById(23), 63);

    headquarter.addOrder(order1);
    headquarter.addOrder(order1_2);
    headquarter.addOrder(order1_3);
    headquarter.addOrder(order2);
    headquarter.addOrder(order2_2);
    headquarter.addOrder(order3);
    headquarter.addOrder(order3_2);
    headquarter.addOrder(order3_3);
    headquarter.addOrder(order3_4);
    headquarter.addOrder(order3_5);
    headquarter.addOrder(order4);
    headquarter.addOrder(order4_2);
    headquarter.addOrder(order5);
    headquarter.addOrder(order5_2);
    headquarter.addOrder(order5_3);
    headquarter.addOrder(order5_4);
    headquarter.addOrder(order6);
    headquarter.addOrder(order6_2);
    headquarter.addOrder(order6_3);
    headquarter.addOrder(order7);
    headquarter.addOrder(order7_2);
    headquarter.addOrder(order7_3);
    headquarter.addOrder(order7_4);
    headquarter.addOrder(order7_5);
    headquarter.addOrder(order7_6);
    headquarter.addOrder(order7_7);
    headquarter.addOrder(order7_2);
    headquarter.addOrder(order8);
    headquarter.addOrder(order8_2);
    headquarter.addOrder(order9);
    headquarter.addOrder(order9_2);
    headquarter.addOrder(order9_3);
    headquarter.addOrder(order9_4);
    headquarter.addOrder(order10);
    headquarter.addOrder(order10_2);
    headquarter.addOrder(order10_3);
    headquarter.addOrder(order10_4);
    headquarter.addOrder(order10_5);

    //---------------TRUCKS---------------

    headquarter.addTruck(new Truck(100));
    headquarter.addTruck(new Truck(500));
    headquarter.addTruck(new Truck(500));
    headquarter.addTruck(new Truck(1000));
    headquarter.addTruck(new Truck(3000));

    headquarter.saveAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                            "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                            "../src/Resources/products.txt");
}
