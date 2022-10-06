#include "datastore.h"
#include "util.h"

class MyDataStore : public DataStore{
	public:
		~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
		void displayCart(std::string username);
		void buyCart(std::string username);
		void addToCart (std::string username, Product* p);
	private:
		std::map<std::string, std::set<Product*>> productMap_;
		std::map<std::string, std::vector<Product*>> cartMap_;
		std::map<std::string, User*> userMap_;
		std::vector<Product*> productVec_;
		std::vector<User*> userVec_;
};