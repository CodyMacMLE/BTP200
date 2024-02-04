#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "fridge.h"
#include "fridge.h" // intentional
#include "food.h"
#include "food.h" // intentional

int cout = 0; // prevents compilation if headers don't follow convention

int main()
{
	// a bunch of things to eat
	seneca::Food foods[]{
					  seneca::Food("Apples", 4),
					  seneca::Food("Milk", 2),
					  seneca::Food("Carrots", 3),
					  seneca::Food("Onions", 3),
					  seneca::Food("Bell Pepper", 5),
					  seneca::Food("Sheppard Pepper", 2),
					  seneca::Food("Potatoes", 10),
					  seneca::Food("Orange Juice", 3),
					  seneca::Food("Pizza Leftovers", 3),
					  seneca::Food("Veggie Soup", 8),
					  seneca::Food("Mozzarella Cheese", 2),
					  seneca::Food("Beets", 1),
	};


	// TEST: create an empty fridge
	std::cout << "T1: Create an empty fridge\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	seneca::Fridge kitchenFridge;
	kitchenFridge.display();
	std::cout << "Contains any food? [" << (kitchenFridge.hasFood() ? "yes" : "no") << "]\n";
	std::cout << "----------:----------:----------:----------:----------\n\n";



	std::cout << "T2: Add some foods to the kitchen fridge\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	kitchenFridge.setModel("Frigero", 20);
	kitchenFridge.addFood(foods[0]);
	kitchenFridge.addFood(foods[1]);
	kitchenFridge.addFood(foods[2]);
	kitchenFridge.addFood(foods[4]);
	kitchenFridge.display();
	std::cout << "----------:----------:----------:----------:----------\n\n";



	std::cout << "T3: Add over capacity\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	kitchenFridge.addFood(foods[6]);
	kitchenFridge.display();
	std::cout << "----------:----------:----------:----------:----------\n\n";



	std::cout << "T4: Fill to >=90%\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	std::cout << "Is full? [" << (kitchenFridge.isFull() ? "yes" : "no") << "]\n";
	kitchenFridge.addFood(foods[10]);
	kitchenFridge.addFood(foods[11]);
	kitchenFridge.addFood(foods[5]);
	kitchenFridge.display();
	std::cout << "Is full? [" << (kitchenFridge.isFull() ? "yes" : "no") << "]\n";
	std::cout << "----------:----------:----------:----------:----------\n\n";



	std::cout << "T5: Looking for food in a full fridge\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	std::cout << "Contains any food? [" << (kitchenFridge.hasFood() ? "yes" : "no") << "]\n";
	std::cout << "Contains milk? [" << (kitchenFridge.hasFood("Milk") ? "yes" : "no") << "]\n";
	std::cout << "Contains eggs? [" << (kitchenFridge.hasFood("Eggs") ? "yes" : "no") << "]\n";
	std::cout << "Contains beets? [" << (kitchenFridge.hasFood("Beets") ? "yes" : "no") << "]\n";
	std::cout << "----------:----------:----------:----------:----------\n\n";



	std::cout << "T6: The basement fridge\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	seneca::Fridge basementFridge(foods, 10, "So Cold", 50);
	basementFridge.display();
	std::cout << "----------:----------:----------:----------:----------\n";

	return cout;
}
