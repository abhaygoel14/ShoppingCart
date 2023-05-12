#include<iostream>
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1,"apple",26),
    Product(2,"mango",46),
    Product(3,"guava",36),
    Product(4,"orange",86),
    Product(5,"kiwi",66),
};

Product* chooseProduct(){
    string productList;
    cout<<"Available products :"<<"\n";
    for(auto product : allProducts) {
      productList.append(product.DisplayProduct());
    }
    cout<<productList<<"\n";
    cout<<"----------------------"<<"\n";
    string choice;
    cin>>choice;
    for(int i=0;i<allProducts.size();i++) {
        if(allProducts[i].getShortName()==choice) {
            return &allProducts[i];
        }
    }
    cout<<"Product not found"<<endl;
    return NULL;
};
int main()
{
    char action;
    Cart cart;
    while(true)
    {
         cout<<"Select an action - (a)dd item , (v)iew cart, (c)heckout "<<"\n";
        cin >> action;
        if(action == 'a')
        {
            Product* p = chooseProduct();
            if(p!=NULL)
            {
                cout<<"Item added to cart: "<<endl;
                cart.addProduct(*p);
            }
        }
        else if(action == 'v')
        {
            cout<<"----------------"<<"\n";
            cout<<cart.viewCart()<<endl;
            cout<<"------------------"<<"\n";
        }
        else if(action == 'c')
        {
            break;
        }
    }
   
    return 0;
}