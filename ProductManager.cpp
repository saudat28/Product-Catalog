#include "SearchProduct.cpp"

class ProductManager
{
private:
    Product prod;
public:
    int getMenu() {

        // TODO Add code to display Menu
        // Menu should have
        // Add Product
        //Search Product By Name
        //Search Product By Category
        //Search Product By Brand
        // Update Product
        // Delete Product

        bool isChoiceOk = false;
        int selectedChoice = -1;

        while (!isChoiceOk) {
            cout << " Product Catalog: " << endl;
            cout << " 1: Add Product: " << endl;
            cout << " 2: Search Product by Name: " << endl;
            cout << " 3: Search Product by Category " << endl;
            cout << " 4: Search Product by Brand " << endl;
            cout << " 5: Update Product " << endl;
            cout << " 6: Delete Product " << endl;
            cout << " 7: Exit" << endl;
            cin >> selectedChoice;

            if (cin.fail() || selectedChoice < 1 || selectedChoice >= 8) {
                cout << "Enter a valid choice" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                isChoiceOk = true;
            }
            return selectedChoice;

        }
    }
    void addProduct(){
        // TODO add code to add product and
        // store the product to products.json file by using Product class and FileHandler class
        prod.createProduct();
        cout<<"Product here:" <<endl << prod.toJson();
        FileHandler fHandler;
        fHandler.saveToJsonFile(prod);
    }

    // TODO Add code for Updating a product

    // TODO Add code for deleting a product

};

int main()
{

    // ADD Code for displaying a welcome Menu
    // and handle all required logic to add, search, update, and delete product

    Product prod;
    ProductManager prodManager;

    SearchProduct sProd;

    int choice = -1;

    // Write code handle selected choice.
    while (choice != 7)
    {
        choice = prodManager.getMenu();
        string name;
        string brand;
        string categ;
        string del;
        string update;
        switch (choice) {
            case 1:
                prodManager.addProduct();
                break;
            case 2:
                cout << "Enter the name of product to search: " << endl;
                cin.ignore();
                getline(cin, name);
                sProd.searchByName(name);
                break;
            case 3:
                cout << "Enter the category of product to search: " << endl;
                cin.ignore();
                getline(cin, categ);
                sProd.searchByCategory(categ);
                break;
            case 4:
                cout << "Enter the brand of product to search: " << endl;
                cin.ignore();
                getline(cin, brand);
                sProd.searchByBrand(brand);
                break;
            case 5:
                cout << "Enter the name of product to update: " << endl;
                cin.ignore();
                getline(cin, update);
                sProd.searchByCategory(update);
                break;
            case 6:
                cout << "Enter the name of product to delete: " << endl;
                cin.ignore();
                getline(cin, del);
                sProd.searchByCategory(del);
                break;
            case 7:
                cout <<  "....Exiting Product Catalog'....." << endl;
                break;
        }

    }
    return 0;
}


