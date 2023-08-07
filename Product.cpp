#include <iostream>
#include <string.h>
#include <chrono>
#include <string>
#include <random>


using namespace std;

using namespace std::chrono;



class Product{

public:
    int quantity;
    string name;
    string brand;
    string description;
    string code;
    float price;
    string dosageInstruction;
    string category;
    bool requires_prescription;

public:

    string getName(){
        //TODO Add code that return the Product Name
        return  name;
    }

    string getBrand(){
        //TODO Add code that return the Product Brand
        return  brand;
    }

    string getDescrisption(){
        //TODO Add code that return the Product Description
        return description;
    }

    string getDosageInstruction(){
        //TODO Add code that return the Product Dosage Instruction
        return dosageInstruction;
    }

    string getCategory(){
        //TODO Add code that return the Product Category
        return category;
    }

    int getQuantity(){
        //TODO Add code that return the Product Quantity
        return quantity;
    }

    float getPrice(){
        //TODO Add code that return the Product Price
        return  price;
    }

    bool getRequiresPrescription(){
        //TODO Add code that return Product Requires Prescription status
        return  requires_prescription;
    }


    string generateUniqueCode()
    {
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        string uniqueCode = "";
        auto now = system_clock::now();
        auto millis = duration_cast<milliseconds>(now.time_since_epoch());
        mt19937 generator(millis.count());
        uniform_int_distribution<int> distribution(0, 100000);

        // generate 10 characters long unique string

        for (int i = 0; i <= 10; i++)
        {
            int random_index = distribution(generator) % characters.length();
            uniqueCode += characters[random_index];
        }

        return uniqueCode;
    };

    string promptTextField(string promptText){
        // TODO Add code to prompt user for input for any Product string field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        string  inputField;
        cout << promptText << endl;
        cin >> inputField;
        return  inputField;
    }

    float promptNumberField(string promptText){
        // TODO Add code to prompt user for input for any Product Numeric field
        // method takes text to display e.g: "Enter Product Name:"
        // it prompts a user and return user input in form of text. Text can be made by multiple words.
        float input;
        cout << promptText << endl;
        cin >> input;
        return input;
    }

    bool promptRequirePrescription()
    {
        // TODO Add code to prompt user for choosing if Product requires prescription.
        // User can type 1 or 0.
        // it prompts a user and return user input in form of boolean.
        bool require_prescription;
        cout << "Product requires prescription? (1 for yes, 0 for no):" << endl;

        string description;
        int selection;
        cin >> selection;
        if (selection == 1) {
            require_prescription = true;
        } else if (selection == 0){
            require_prescription = false;
        }else {
            cout << "Invalid selection. 'Assuming no Prescriptions'." << endl;
            require_prescription = false;
            return selection;
        }

        if (require_prescription){
            cout << "Enter Prescription:" << endl;
            cin.ignore();
            getline(cin, description);
        }
        return require_prescription;
    }

    void createProduct()
    {

        // TODO Add code that calls promptTextField() method and prompt user for entering product name and update the name field.
        name = promptTextField("Enter name for the product");
        // TODO Add code that calls promptTextField() method and prompt user for entering product brand and update the brand field.
        brand = promptTextField("Enter Brand for the product");
        // TODO Add code that calls promptTextField() method and prompt user for entering product description and update the decription field.
        description = promptTextField("Enter description for the product");
        // TODO Add code that calls promptTextField() method and prompt user for entering product category and update the category field.
        category = promptTextField("Enter category for the product");
        // TODO Add code that calls promptTextField() method and prompt user for entering product dosageInstruction and update the dosage instruction field.
        dosageInstruction = promptTextField("Enter Dosage Instruction for the product");
        // TODO Add code that calls promptNumberField() method and prompt user for entering product quantity and update the quantity field.
        quantity = promptNumberField("Enter quantity for the product");
        // TODO Add code that calls promptNumberField() method and prompt user for entering product price and update the price field.
        price = promptNumberField("Enter Price for the product");
        // TODO Add code that calls promptRequirePrescription() method and prompt user for entering product requires presc and update the requiresprescription field.
        requires_prescription = promptRequirePrescription();
        // Add code to generate Unique code for product using generateUniqueCode method
        code = generateUniqueCode();

    };

    string toJson()
    {
        // TODO Add code for converting a product to json form from the private declared attributes.
        string productInJson = "{"
        "\"code\":\"" + code +
       "\"," "\"name\":\"" + name +
        "\"," "\"brand\":\"" + brand +
        "\"," "\"description\":\"" + description +
        "\"," "\"dosage_instruction\":\"" + dosageInstruction +
        "\"," "\"price\":" + to_string(price) +
        "," "\"quantity\":" + to_string(quantity) +
        "," "\"category\":\"" + category +
        "\"," "\"requires_prescription\":" + to_string(requires_prescription) +  "}";
        // The Output should look like:
        //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}
        return productInJson;
    };


    void productFromJson(string txt)
    {
        //TODO Add code to convert a json string product to product object
        // string is in the form below
        //{"code":"tgtwdNbCnwx","name":"name 1","brand":"br 2","description":"df","dosage_instruction":"dfg","price":123.000000,"quantity":13,"category":"des","requires_prescription":1}
        // You need to extract value for each field and update private attributes declared above.

    };


    };

