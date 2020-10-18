// Title: project-01.cpp
// Abstract: This program will serve as an automat. This program can essentially take in food and drink orders while displaying calories, ounces, and prices.  It can also allow for orders to be canceled as well.
// Author: Daniel Figueroa
// Email: dafigueroa@csumb.edu
// Estimate: 6 days
// Date: 09/30/2020

#include <iostream>
using namespace std;

const int AUTOMAT_MAX = 10;
const int ORDER_MAX = 5;
// Automat can only contain 9 Food items and 9 Drink items at a time
// Error message if limit is reached

//First class beginning
class Food {
  public:
    Food();
    Food(string name, int calories, double price);

    string getName();
    int getCalories();
    double getPrice();

    void setName(string name);
    void setCalories(int calories);
    void setPrice(double price);
    void display();

  private:
    string myName;
    int myCalories;
    double myPrice;
};

//  Default constructor for Food
Food::Food() {
  myName = "Snorlax";
  myCalories = 0;
  myPrice = 0;
}
// Will assign values to attributes
Food::Food(string name, int calories, double price) {
  myName = name;
  myCalories = calories;
  myPrice = price;
}

// retrieves name
string Food::getName() {
  return myName;
}

// retrieves calories
int Food::getCalories() {
  return myCalories;
}

// retrieves price
double Food::getPrice() {
  return myPrice;
}

// assigns name a definition
void Food::setName(string name) {
  myName = name;
}

// assigns food a definition
void Food::setCalories(int calories) {
  myCalories = calories;
}

// assigns price a definition
void Food::setPrice(double price) {
  myPrice = price;
}

// will display food information
void Food::display()  {
  cout << myName << ": " << myCalories << " calories, $" << myPrice;
}
// First Class end----------

// 2nd Class Beginning
class Drink {
  public:
    Drink();
    Drink(string name, int ounces, double price);

    string getName();
    int getOunces();
    double getPrice();

    void setName(string name);
    void setOunces(int ounces);
    void setPrice(double price);
    void display();
  private:
    string myName;
    int myOunces;
    double myPrice;
};

// Default constructor for drink
Drink::Drink() {
  myName = "blastoise";
  myOunces = 0;
  myPrice = 0;
}

Drink::Drink(string name, int ounces, double price) {
  myName = name;
  myOunces = ounces;
  myPrice = price;
}

string Drink::getName() {
  return myName;
}

int Drink::getOunces() {
  return myOunces;
}
double Drink::getPrice() {
  return myPrice;
}

void Drink::setName(string name){
  myName = name;
}

void Drink::setOunces(int ounces) {
  myOunces = ounces;
}

void Drink::setPrice(double price) {
  myPrice = price;
}

void Drink::display() {
  cout << myName << ": " << myOunces << " ounces, $" << myPrice;
}
// 2nd Class end----------

// 3rd Class Beginning
class Automat {
  public:
  Automat();
  bool emptyFood();
  bool emptyDrink();
  void enqueue(Food f); //
  void enqueue(Drink d); //
  void dequeueFood();
  void dequeueDrink();

  Food frontFood();
  Drink frontDrink();
  int foodCount();
  int drinkCount();
  int getTotalCalories();
  int getTotalOunces();
  double getTotalPrice();
  void display();

  private:
  int myFoodFront;
  int myFoodBack;
  int myDrinkFront;
  int myDrinkBack;
  Food myFood[AUTOMAT_MAX];  //array of Food objects
  Drink myDrink[AUTOMAT_MAX];  //array of Drink objects
};

Automat::Automat(): myFoodFront(0), myFoodBack(0), myDrinkFront(0), myDrinkBack(0) {
}

// Return true if there are no Food items, false otherwise
bool Automat::emptyFood() {
  return (myFoodFront == myFoodBack);
}

// Return true if there are no Drink items, false otherwise
bool Automat::emptyDrink() {
  return (myDrinkFront == myDrinkBack);
}

//enqueue: Modifies a queue by adding a value at the back
void Automat::enqueue(Food f) {
  int newBack = (myFoodBack + 1) % AUTOMAT_MAX;
  if (newBack != myFoodFront) {
    myFood[myFoodBack] = f;
    myFoodBack = newBack;
  }
  else {
    cerr << "Automat food full; new food not added" << endl;
  }
}

void Automat::enqueue(Drink d) {
  int newBack = (myDrinkBack + 1) % AUTOMAT_MAX;
  if (newBack != myDrinkFront) {
    myDrink[myDrinkBack] = d;
    myDrinkBack = newBack;
  }
  else {
    cerr << "Automat drink full; new drink not added" << endl;
  }
}
//dequeue: Modifies a queue by removing the value at the front
void Automat::dequeueFood() {
  if (!emptyFood()) {
    myFoodFront = (myFoodFront + 1) % AUTOMAT_MAX;
  }
  // else {
  //   cerr << "Automat food empty; new drink can not be removed" << endl;
  // }
}

void Automat::dequeueDrink() {
  if (!emptyDrink()) {
    myDrinkFront = (myDrinkFront + 1) % AUTOMAT_MAX;
  }
  // else {
  //   cerr << "Automat drink empty; new drink can not be removed";
  // }
}

//Accesses the front queue value for food
Food Automat::frontFood() {
  // if (!emptyFood()) {
    return (myFood[myFoodFront]);
  // }
  // else {
  //   cerr << "Automat food empty" << endl; 
  //   Food nothing;
  //   return nothing;
  // }
}
//Accesses the front queue value for Drink
Drink Automat::frontDrink() {
  // if(!emptyDrink()) {
    return (myDrink[myDrinkFront]);
  // }
  // else {
  //   cerr << "Automat drink empty" << endl;
  //   Drink nothing;
  //   return nothing;
  // }
}

// Counts food items in Automat
int Automat::foodCount() {
  int food_count = 0;
  for (int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX) {
    food_count++;
  }
  return food_count;
}

// Couknts drink items in Automat
int Automat::drinkCount() {
  int drink_count = 0;
  for (int k = myDrinkFront; k != myDrinkBack; k = (k + 1) % AUTOMAT_MAX) {
    drink_count++;
  }
  return drink_count;
}

// Gets total calories of Food
int Automat::getTotalCalories() {
  int total_calories = 0;

  for (int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX) {
    total_calories += myFood[i].getCalories();
  }
  return total_calories;
};

// Gets total ounces of Drinks
int Automat::getTotalOunces() {
  int total_ounces = 0;
  
  for (int k = myDrinkFront; k != myDrinkBack; k = (k + 1) % AUTOMAT_MAX) {
    total_ounces += myDrink[k].getOunces();
  }
  return total_ounces;
}

// Combined price for both food and drinks
double Automat::getTotalPrice() {
  double food_price = 0;
  double drink_price = 0;
  double total_price;
  for (int f = myFoodFront; f != myFoodBack; f = (f + 1) % AUTOMAT_MAX) {
    food_price += myFood[f].getPrice();
  }
  for (int d = myDrinkFront; d != myDrinkBack; d = (d + 1) % AUTOMAT_MAX) {
    drink_price += myDrink[d].getPrice();
  }
  total_price = food_price + drink_price;
  return total_price;
}

// Displays Automat information
void Automat::display() {
  cout << "Automat: " << endl;
  cout << "\t Food:" << endl;

  for (int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX) {
    cout << "\t\t";
    myFood[i].display();
    cout << endl;
  }
  
  cout << "\t\t" << foodCount() << " food items - Total Calories: " << getTotalCalories() << endl;

  cout << "\t Drinks:" << endl;

  for (int k = myFoodFront; k != myDrinkBack; k = (k + 1) % AUTOMAT_MAX) {
    cout << "\t\t";
    myDrink[k].display();
    cout << endl;
  }

  cout << "\t\t" << drinkCount() << " drinks - Total Ounces: " << getTotalOunces() << endl << endl;
}
// 3rd Class end----------

class Order {
  public:
    Order(); // should also increment myTotalOrders by 1
    
    bool emptyFood();
    bool emptyDrink();
    void push(Food f);
    void push(Drink d);
    void popFood();
    void popDrink();
    Food topFood();
    Drink topDrink();
    int foodCount();
    int drinkCount();
    double getTotalPrice();
    void display();

    void cancel(Automat &); // Automat must be passed by reference
    void purchase(); // will reset each stack
    static int getTotalOrders(); //A STATIC method to return myTotalOrders
  private:
    int myFoodTop;
    int myDrinkTop;
    Food myFood[ORDER_MAX]; // array of Food objests
    Drink myDrink[ORDER_MAX]; // array of Drink objects
    static int myTotalOrders; // 0
};

int Order::myTotalOrders = 0;
// Default constructor
Order::Order():myFoodTop(-1), myDrinkTop(-1) {
  myTotalOrders += 1;
}

// will return true if there are no food items, false otherwise
bool Order::emptyFood() {
  return (myFoodTop == -1);
}
// will return true if there are drinks, false otherwise
bool Order::emptyDrink() {
  return (myDrinkTop == -1);
}

// Adds food to the top of the stack
void Order::push(Food f) {
  if (myFoodTop < ORDER_MAX - 1) {
    ++myFoodTop;
    myFood[myFoodTop] = f;
  }
  else {
    cerr << "Food is full -- can't add new item";
    return;
  }
}

// Adds drink to the top of the stack 
void Order::push(Drink d) {
  if (myDrinkTop < ORDER_MAX - 1) {
    ++myDrinkTop;
    myDrink[myDrinkTop] = d;
  }

  else {
    cerr << "Drink is full -- can't add new item";
    return;
  }
}

// Will lower Top food 
void Order::popFood() {
  if (!emptyFood()) {
    myFoodTop--;
  }
  // else {
  //   cerr << "Food is empty -- can't remove item";
  // }
}

// Will lower Top drink
void Order::popDrink() {
  if (!emptyDrink()) {
    myDrinkTop--;
  }
  // else {
  //   cerr << "Drink is empty -- can't remove item";
  // }
}

// returns food item at the very top
Food Order::topFood() {
  // if (!emptyFood()) {
    return (myFood[myFoodTop]);
  // }
  // else {
  //   cerr << "Food is empty -- insignificant value" << endl;
  //   Food nothing;
  //   return nothing;
  // }
}

// returns drink item at the very top
Drink Order::topDrink() {
  // if (!emptyDrink()) {
    return (myDrink[myDrinkTop]);
  // }
  // else {
  //   cerr << "Drink is empty -- insignificant value" << endl;
  //   Drink nothing;
  //   return nothing;
  // }
}

// returns the number of food items
int Order::foodCount() {
  return (myFoodTop + 1);
}

// returns the number of drinks
int Order::drinkCount() {
  return (myDrinkTop + 1);
}

// gets total price of both food and drinks
double Order::getTotalPrice() {
  double food_price = 0;
 for (int i = myFoodTop; i > -1; i--) {
   food_price += myFood[i].getPrice();
 }
  
  double drink_price = 0;
  for (int k = myDrinkTop; k > -1; k--) {
    drink_price += myDrink[k].getPrice();
  }

  double total_price = food_price + drink_price;
  return total_price;
}

// Will display order information
void Order::display() {
  cout << "Order:" << endl;
  cout << "\t Food (" << foodCount() << " items): " << endl;
  
  for (int f = myFoodTop; f > -1; f--) {
    cout << "\t\t";
    myFood[f].display();
    cout << endl;
  }

  cout << "\t Drinks (" << drinkCount() << " items):" << endl;
  for (int d = myDrinkTop; d > -1; d--) {
    cout << "\t\t";
    myDrink[d].display();
    cout << endl;
  }
  cout << "\t Order Total: $" << getTotalPrice() << endl << endl;
}

// Will pop items from both stacks
void Order::cancel(Automat &a) {
  for (int f = myFoodTop; f > -1; f--) {
    a.enqueue(myFood[myFoodTop]);
    popFood();
  }
  for (int d = myDrinkTop; d > -1; d--) {
    a.enqueue(myDrink[myDrinkTop]);
    popDrink();
  }
}

// resets each stack
void Order::purchase() {
  myFoodTop = -1;
  myDrinkTop = -1;
}

// returns the number of orders recorded
int Order::getTotalOrders() {
  return myTotalOrders;
}

// Test case example
int main() {
  Automat a;
  a.enqueue(Food("Let's Potato Chips", 300, 1.50));
  a.enqueue(Food("Mini Donuts", 500, 1));
  a.enqueue(Drink("Coffee", 6, 5.50));
  a.enqueue(Drink("Nacho Drink", 22, 2.50));
  cout << "Starting Automat\n";
  a.display();
  
  Order o;
  o.push(a.frontFood());
  a.dequeueFood();
  o.push(a.frontDrink());
  a.dequeueDrink();
  cout << "Ordered one food, one drink\n";
  o.display();
  a.display();
  cout << "Canceled order\n";
  o.cancel(a);
  o.display();
  a.display();
  cout << "Ordered one food, one drink, purchased\n";
  o.push(a.frontFood());
  a.dequeueFood();
  o.push(a.frontDrink());
  a.dequeueDrink();
  o.purchase();
  o.display();
  a.display();
}