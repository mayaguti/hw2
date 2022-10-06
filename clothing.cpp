#include "clothing.h"
#include "util.h"
using namespace std;

Clothing :: Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand) :
		Product(category, name, price, qty),
		brand_(brand)
{
}

Clothing :: ~Clothing(){

}

std::set <std::string> Clothing :: keywords() const
{
	std::set<std::string> keywords_ = parseStringToWords(name_ + " " + brand_);
	return keywords_;
}

std::string Clothing :: displayString() const
{
	std::string display_ = "Title: " + name_ + "\nBrand: " + brand_ + "\n$" + to_string(price_) + " " + to_string(qty_) + "left";
	return display_;
}

void Clothing :: database(std::ostream& os) const
{
	os << category_ << std::endl << name_ << price_ << std::endl << qty_ << std::endl << brand_ << std::endl;
}