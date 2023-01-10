			/******************************************************************************
      					                    Shopping Cart Backend 
			*******************************************************************************/
#include<iostream>
#include<string>
#include<vector> 
#include"class.h"
using namespace std;

//Driver's Code

vector<Product>PumaX1Der = {                      //global array of products
    Product(1, "Popcat Slides", 1139),
    Product(2, "Miragemox Slides", 2799),
    Product(3, "No Relaxed Tshirt", 1199),
    Product(4, "Jack V2 Sneakers", 2799),
    Product(5, "Supertec Shoes", 5039),
    Product(6, "Brook Sneakers", 2559),
    Product(7, "The Servepro lite shoes", 5499),
};

Product* chooseProducts(){                // if item not there we return NULL only using *
    string productList;
    cout << "Available Products:-" << endl;
    for(auto product : PumaX1Der){
        productList.append(product.getProductName());
    }
    
    cout << productList << endl;
    
    cout << "----------------" << endl;
    string choice;
    cin >> choice;
    
    for(int i=0; i<PumaX1Der.size(); i++){
        if(PumaX1Der[i].getShortName() == choice){
            return &PumaX1Der[i];                 //address of that particular object so we can find object there.
        }
    }
    cout << "Product Not FOUND!" << endl;
    return NULL;
}

bool checkOut(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    
    int total = cart.getTotal();
    cout << "Pay by cash (in Rs.):";
    
    int paid;
    cin >> paid;
    
    if(paid >= total){
        cout << "Return Amount: " << paid - total << "/-" << endl;
        cout << "Thank you for Shopping 🤞";
        return true;
    }
    
    else{
        cout << "Not enough cash ⚠" ;
        return false;
    }
}
    
int main(){
    
    char action;
    Cart cart;
    
    while(true){
        cout << "Select an action - (A)dd item, (V)iew cart, (C)heckout" << endl;
        cin >> action;
        
        if(action == 'A'){
            Product * product = chooseProducts();
            if(product != NULL){
                cout << "Added to cart --> " << product->getProductName() << endl;
                cart.addProduct(*product);
            }
        }
        
        else if(action == 'V'){
            cout << "---------------" << endl;
            cout << cart.viewCart();
            cout << "---------------" << endl;
        }
        
        else{
            cart.viewCart();
            if(checkOut(cart)){
                break;
            }
        }
    }
    return 0;
}