#include<string>
#include<unordered_map>
using namespace std;

//Product, Items, Cart

/**
 * @brief 
 * this actually point to the current object property. 
 * So since we are using 2 same variable so this is used to distinguish between the 2 variable so compiler can understand it.
 * 
 */
//Forward Declarations
class Items;
class Cart;

class Product{
    int id;
    string name;
    int price;
    public:
    //Assignments List
    Product(){}
    Product(int u_id,string name,int price){
        id=u_id;
        this->name=name;
        this->price=price;
    }
    string DisplayProduct(){
        return name+" : "+to_string(price)+"\n";
    }
    string getShortName(){
        return name.substr(0,1);
    }
    friend class Items;
    friend class Cart;
};

class Items{

    Product product; //const value is fixed and cannot be changed
    int quantity;
    public:
    //constructor using init list 
    Items(){}
    Items(Product p,int q):product(p),quantity(q){}

    int getItemPrice(){
        return product.price * quantity; // price is private and so in order to access we will use friend class
    }

    string getItemInfo(){
        return product.name + " x " + to_string(quantity) + " : Rs. " + to_string(quantity*product.price)+"\n";
    }
    friend class Cart;
};

class Cart{
    unordered_map<int,Items> items;
    public :
    void addProduct(Product product)
    {
        if(items.count(product.id) == 0)
        {
            Items newItems(product,1);
            items[product.id] = newItems;
        }else{
            items[product.id].quantity+=1;
        }
    }
    int getTotal(){
        int total=0;
        for(auto itemPair : items)
        {
            auto item=itemPair.second;
            total+=(item.product.price*item.quantity);
        }
        return total;
    }
    string viewCart(){
        if(items.empty())
        {
            return "Cart is empty";
        }
        string itemList;
        int cart_total=getTotal();

        for(auto itemPair : items){
            auto item=itemPair.second;
            itemList.append(item.getItemInfo());
        }

        return itemList+"\nTotal Amount : Rs. "+to_string(cart_total)+"\n";
    }

    bool isEmpty(){
        return items.empty();
    }
};