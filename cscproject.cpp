#include <iostream>
#include <cstdio>
using namespace std;

void receipt(string custName, int catChoice, int prodChoice, int prodQty, double totPrice, double deliveryDistance)
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
    cout << "\nDelivery distance: " << deliveryDistance <<"KM";
    cout << "\nTotal price: RM" << totPrice;
    cout << "\n\n";
}

int askCatInfo()
{
    //ask category code
    string catChoice;
    int returnCatValue;
    cout << "Please enter the category code (NP456 for New Product or BS123 for Best Seller): ";
    cin >> catChoice;

    if (catChoice.compare("NP456") == 0 || catChoice.compare("np456") == 0)
    {
        return 0;
    }
    else if (catChoice.compare("BS123") == 0 || catChoice.compare("bs123") == 0)
    {
        return 1;
    }
    else
    {
        cout << "ERROR: INVALID CATEGORY CODE.\n\n";
        returnCatValue = askCatInfo();
        return returnCatValue;
    }
}

int askProdInfo(int catChoice)
{
    //ask product code
    char prodChoice;
    int returnProdValue;
    if (catChoice == 0) //New Product
    {
        cout << "Please enter the product code (P for Promising Love, E for Endless Love): ";
        cin >> prodChoice;

        if (prodChoice == 'P' || prodChoice == 'p')
        {
            return 0;
        }
        else if (prodChoice == 'E' || prodChoice == 'e')
        {
            return 1;
        }
        else
        {
            cout << "ERROR: INVALID PRODUCT CODE.\n\n";
            returnProdValue = askProdInfo(catChoice);
            return returnProdValue;
        }
    }
    else if (catChoice == 1) //Best Seller
    {
        cout << "Please enter the product code (F for Ferrero Chocolate Foil Balloon, B for Birthday Cake Mania): ";
        cin >> prodChoice;

        if (prodChoice == 'F' || prodChoice == 'f')
        {
            return 2;
        }
        else if (prodChoice == 'B' || prodChoice == 'b')
        {
            return 3;
        }
        else
        {
            cout << "ERROR: INVALID PRODUCT CODE.\n\n";
            returnProdValue = askProdInfo(catChoice);
            return returnProdValue;
        }
    }
    else
    {
        cout << "For some reason, the program fails to detect your category code earlier. Please re-enter the category code." << endl;
        int catChoiceNew = askCatInfo();
        returnProdValue = askProdInfo(catChoiceNew);
        return returnProdValue;
    }
    
}

double priceCalc(int prodChoiceArr, int prodQty, double deliveryDistance)
{
    double prodPrice[4] = { 158.5, 198.5, 58.5, 188.5 };
    double finalPrice = 0;
    double deliveryCost = 0, deliveryDistanceFinal;

    if (deliveryDistance > 100)
    {
        deliveryDistanceFinal = deliveryDistance - 80;
        deliveryCost = 110 + (deliveryDistanceFinal * 2);
    }
    else if (deliveryDistance > 20 && deliveryDistance <= 80)
    {
        deliveryDistanceFinal = deliveryDistance - 20;
        deliveryCost = 20 + (deliveryDistanceFinal * 1.5);
    }
    else
    {
        deliveryCost = deliveryDistance * 1;
    }

    finalPrice = deliveryCost + (prodPrice[prodChoiceArr] * prodQty);
    return finalPrice;
}

int main()
{
    int prodQty, catChoiceArr, prodChoiceArr, userLoopController = 0;
    double totPrice, deliveryDistance;
    string custName;

    cout << "\tWELCOME TO HARMONY GIFT SHOP!\n\tPlease follow the instructions below." << endl;
    cout << "\nPlease enter your name: ";
    cin >> custName;

    while (userLoopController == 0)
    {
        catChoiceArr = askCatInfo();
        prodChoiceArr = askProdInfo(catChoiceArr);

        cout << "Please enter the quantity of the product: ";
        cin >> prodQty;
        if (prodQty <= 0)
        {
            while (prodQty <= 0)
            {
                cout << "ERROR: INVALID PRODUCT QUANTITY.\n" << endl;
                cout << "Please enter the quantity of the product: ";
                cin >> prodQty;
            }
        }

        cout << "Please enter the distance for delivery purposes in kilometers: ";
        cin >> deliveryDistance;
        if (deliveryDistance <= 0)
        {
            while (deliveryDistance <= 0)
            {
                cout << "ERROR: INVALID DISTANCE.\n" << endl;
                cout << "Please enter the distance for delivery purposes in kilometers: ";
                cin >> deliveryDistance;
            }
        }

        totPrice = priceCalc(prodChoiceArr, prodQty, deliveryDistance);

        //print receipt
        receipt(custName, catChoiceArr, prodChoiceArr, prodQty, totPrice, deliveryDistance);

        //ask user if want to order more
        cout << "\n\tThank you for ordering! Your order will be processed, completed, and delivered soon." << endl;
        cout << "\nDo you want to order more? Press 0 to continue, 1 to exit. ";
        cin >> userLoopController;
    }

    return 0;
}