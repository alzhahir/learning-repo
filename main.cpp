#include <iostream>
using namespace std;

void receipt(string custName, int catChoice, int prodChoice, int prodQty, double totPrice)
{
    string catCode[2] = { "NP456", "BS123" };
    string catName[2] = { "New Product", "Best Seller" };
    char prodCode[4] = { 'P', 'E', 'F', 'B' };
    string prodName[4] = { "Promising Love", "Endless Love", "Ferrero Chocolate Foil Balloon", "Birthday Cake Mania" };
    double prodPriceReceipt[4] = { 158.5, 198.5, 58.5, 188.5 };
    cout << "\n\n\tWELCOME TO HARMONY GIFT SHOP, " << custName << "!" << endl;
    cout << "\nYou purchased: " << prodName[prodChoice];
    cout << "\nCategory: " << catName[catChoice];
    cout << "\nQuantity: " << prodQty << "pcs";
    cout << "\nPrice per unit: RM" << prodPriceReceipt[prodChoice];
    cout << "\nTotal price: RM" << totPrice;
    cout << "\n\n";
}

int askCatInfo()
{
    //ask category code
    int catChoice;
    cout << "Please enter the category code (1 for New Product, NP456 or 2 for Best Seller, BS123): ";
    cin >> catChoice;

    if (catChoice < 1 || catChoice > 2)
    {
        while (catChoice < 1 || catChoice > 2)
        {
            cout << "ERROR: INVALID CATEGORY CODE.\nPlease enter the category code (1 for New Product, NP456 or 2 for Best Seller, BS123): ";
            cin >> catChoice;
        }
    }

    if (catChoice == 1)
    {
        return 0;
    }
    else if (catChoice == 2)
    {
        return 1;
    }
}

int askProdInfo(int catChoice)
{
    //ask product code
    char prodChoice;
    if (catChoice == 0) //New Product
    {
        cout << "Next, please enter the product code (P for Promising Love, E for Endless Love): ";
        cin >> prodChoice;

        if (prodChoice == 'P')
        {
            return 0;
        }
        else if (prodChoice == 'E')
        {
            return 1;
        }
        else
        {
            cout << "ERROR: INVALID PRODUCT CODE.\n";
            int returnValue = askProdInfo(catChoice);
            return returnValue;
        }
    }
    else if (catChoice == 1) //Best Seller
    {
        cout << "Please enter the product code (F for Ferrero Chocolate Foil Balloon, B for Birthday Cake Mania): ";
        cin >> prodChoice;

        if (prodChoice == 'F')
        {
            return 2;
        }
        else if (prodChoice == 'B')
        {
            return 3;
        }
        else
        {
            cout << "ERROR: INVALID PRODUCT CODE.\n";
            int returnValue = askProdInfo(catChoice);
            return returnValue;
        }
    }
    
}

double priceCalc(int prodChoiceArr, int prodQty)
{
    double prodPrice[4] = { 158.5, 198.5, 58.5, 188.5 };
    double finalPrice = 0;

    finalPrice = prodPrice[prodChoiceArr] * prodQty;
    return finalPrice;
}

int main()
{
    int prodQty, catChoiceArr, prodChoiceArr;
    double totPrice;
    string custName;

    cout << "\tWELCOME TO HARMONY GIFT SHOP!\n\tPlease follow the instructions below." << endl;
    cout << "\nPlease enter your name: ";
    cin >> custName;

    catChoiceArr = askCatInfo();
    prodChoiceArr = askProdInfo(catChoiceArr);
    cout << "Please enter the quantity of the product: ";
    cin >> prodQty;
    totPrice = priceCalc(prodChoiceArr, prodQty);

    //print receipt
    receipt(custName, catChoiceArr, prodChoiceArr, prodQty, totPrice);
}
