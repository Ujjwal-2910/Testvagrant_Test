#include "bits/stdc++.h"
using namespace std;

// Shopping Cart Class
class ShoppingCart
{
    public:

    string product;
    int unitPrice;
    int GST;
    int Quantity;

    ShoppingCart(string product, int unitPrice, int GST, int Quantity)
    {
        this->product = product;
        this->unitPrice = unitPrice;
        this->GST = GST;
        this->Quantity = Quantity;
    }
};

void fivePercentDiscount(vector<ShoppingCart> &Basket, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(Basket[i].unitPrice >= 500)
        {
            int prevPrice = Basket[i].unitPrice;
            int updatedPrice = prevPrice - (prevPrice / 20); // reduced 5%
            Basket[i].unitPrice = updatedPrice;
        }
    }
}

ShoppingCart maximumGST(vector<ShoppingCart> Basket, int size)
{
    int ind;
    float value = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        float gstAmount = ((float) Basket[i].unitPrice * Basket[i].GST * Basket[i].Quantity) / 100;
        if(gstAmount > value)
        {
            value = gstAmount;
            ind = i;
        }
    }
    return Basket[ind];
}

float totalAmount(vector<ShoppingCart> Basket, int size)
{
    float ans = 0;
    for(int i = 0; i < size; i++)
    {
        float price = Basket[i].unitPrice;
        float gst = price * Basket[i].GST / 100;
        float finalPrice = (price + gst) * (float) Basket[i].Quantity;
        ans += finalPrice;
    }
    return ans;
}

// Main Function
int main()
{
    // Creating the product
    ShoppingCart product1("Leather wallet", 1100, 18, 1);
    ShoppingCart product2("Umbrella", 900, 12, 4);
    ShoppingCart product3("Cigarette", 200, 28, 3);
    ShoppingCart product4("Honey", 100, 0, 2);

    // Inserting to Basket
    vector<ShoppingCart> Basket;
    Basket.push_back(product1);
    Basket.push_back(product2);
    Basket.push_back(product3);
    Basket.push_back(product4);

    // Discount
    fivePercentDiscount(Basket, Basket.size());

    // 1. Identify the product for which we paid maximum GST amount
    ShoppingCart ans = maximumGST(Basket, Basket.size());
    cout << endl << "The product for which we paid maximum GST amount is: " << ans.product << endl;

    // 2. Calculate the total amount to be paid
    float total = totalAmount(Basket, Basket.size());
    cout << endl << "The total amount to be paid to the shop-keeper is: " << total << endl << endl;
    
    return 0;
}