#include "FileHandler.cpp"
class SearchProduct
{
private:
    string filename = "data/products.json";

public:
    string searchText;
    FileHandler fHandler;

    string to_lowercase(const string& text) {
        string lowercase_text;
        for (char c : text) {
            lowercase_text += tolower(c);
        }
        return lowercase_text;
    }

    vector<Product> searchByName(string name){
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cout << "Failed to open file for reading: " << filename << endl;
            // Return an empty list if file couldn't be opened
        }
        else{
            //fHandler.readJsonFile();
          //  if(std::find(name.begin(),name.end(),name) != name.end()) {
            //}

            //}
            std::vector<Product> allProducts = fHandler.readJsonFile();
            std::vector<Product> foundProducts;
            for (const auto& product : allProducts) {
                if (product.name == name) {
                    foundProducts.push_back(product);
                }
            }

            return foundProducts;
        }



        // TODO
        //Add code to search by name. Searching is not case sensitive it means
        //for input like: "name" products with names like "Name 1", "Product name" needs to included in the found results.

    };

    vector<Product> searchByCategory(string categ){

        // TODO
        //Add code to search by category. Searching is not case sensitive it means
        //for input like: "categ" products with category like "category 1", "Product category" needs to included in the found results.
    };

    vector<Product> searchByBrand(string brand){
        // TODO
        //Add code to search by brand. Searching is not case sensitive it means
        //for input like: "br" products with names like "Brand 1", "brand name" needs to included in the found results.
        ;
    };

    void showSearchResult(vector<Product> plist, string sTxt)
    {
        // TODO
        //Add code to display Search results

    }
};