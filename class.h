			/******************************************************************************
                          					Shopping Cart Backend 
			*******************************************************************************/
#include<iostream>
#include<string>
#include<vector> 
#include<unordered_map>

using namespace std;

//Advance declaration
class Item;  
class Cart;

//Product Class
class Product{
private:
    int id;
    string name;
    int price;

public:
    Product(){}
    
    Product(int userId, string name, int price){
        id = userId;
        this->name = name;       //using this will tell the compiler to get the current object that we are referring to.
        this->price = price;
    }
    
    string getProductName(){   //method to return the description of the item.
        return name + ": Rs." + to_string(price) + "/-" + "\n";
    }
    
    string getShortName(){
        return name.substr(0,1);
    }
    
    friend class Item;  
    friend class Cart; // Item has access to private of Product.
};

//Item Class
class Item{
    Product product;  //not reassignable
    int quantity;
    
public:
    Item(){}
    
    Item(Product p, int q) : product(p), quantity(q){}      //constructor with initialisation list 
    
    int DisplayItemPrice(){
        return quantity * product.price;
    }
    
    string getItemInfo(){
        return to_string(quantity) + " x " + product.name + ": Rs." + to_string(quantity * product.price) + "/-" + "\n";
    }
    
    friend class Cart;
};

//Cart Class
class Cart{
    unordered_map<int, Item> items;
    
 public:
    void addProduct(Product product){
        if(items.count(product.id) == 0){
            Item newItem(product,1);
            items[product.id] = newItem;
        }
        else{
            items[product.id].quantity += 1;
        }
    }
    
    int getTotal(){
        int total = 0;
        for(auto itemPair : items){
            auto item = itemPair.second;
            total += item.DisplayItemPrice();
        }
        return total;
        
    }
    
    string viewCart(){
        if(items.empty()){
            return "Cart is empty." ;
        }
        
        string itemizedList;
        int cartTotal = getTotal();
        
        for(auto itemPair : items){
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }
        return itemizedList + "\n Total amount : Rs. "  + to_string(cartTotal) + "/-" + "\n";
    }
    
    bool isEmpty(){
        return items.empty();
    }
 
    
};