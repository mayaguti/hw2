#include "mydatastore.h"
using namespace std;

MyDataStore::~MyDataStore() {
	for(int i = 0; i < (int)productVec_.size(); i++){
		delete productVec_[i];
	}
	for(int i = 0; i < (int)userVec_.size(); i++){
		delete userVec_[i];
	}
}

void MyDataStore::addProduct(Product* p){
	productVec_.push_back(p);
	std::set<std::string> keywords_ = p->keywords();
	std::set<std::string>::iterator it;
	for(it = keywords_.begin(); it != keywords_.end(); ++it){
		if(productMap_.find(*it) == productMap_.end()){ //if keyword doesn't exist in map
			std::set<Product*> productSet;
			productSet.insert(p);
			productMap_[*it] = productSet;
		}
		else{ // if it does add product to set paired with existing keyword
			productMap_.find(*it)->second.insert(p);
		}
	}
}

void MyDataStore::addUser(User* u){
	userVec_.push_back(u);
	userMap_[u->getName()] = u;
	vector<Product*> cart;
	cartMap_[u->getName()] = cart;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	std::vector<Product*> prodKeys;
	std::set<Product*> compareSet = productMap_[terms[0]];
	if(type == 0){ //AND
		 for(int i = 1; i < (int)terms.size(); ++i){ // iterate # of terms amount of times
			 compareSet = setIntersection(compareSet, productMap_[terms[i]]);
		 }
		 std::vector<Product*> intersect(compareSet.begin(), compareSet.end());
		 return intersect;
	}
	else{ //OR
		for(int i = 1; i < (int)terms.size(); ++i){
			compareSet = setUnion(compareSet, productMap_[terms[i]]);
		}
		std::vector<Product*> onion(compareSet.begin(), compareSet.end());
		return onion;
	}
}

void MyDataStore::dump(std::ostream& ofile){
	ofile << "<products>" << endl;
	for(int i = 0; i < (int)productVec_.size(); ++i){
		productVec_[i] -> dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for(int i = 0; i < (int)userVec_.size(); ++i){
		userVec_[i] -> dump(ofile);
	}
	ofile << "</users>" << endl;
}

void MyDataStore::displayCart(std::string username){
	for(int i = 0; i < (int)cartMap_[username].size(); ++i){
		cout << "Item " << i+1 << ": " << cartMap_[username][i]->displayString() << endl;
	}
}

void MyDataStore::buyCart(std::string username){

}
		
void MyDataStore::addToCart (std::string username, Product* p){
	cartMap_[convToLower(username)].push_back(p);
}