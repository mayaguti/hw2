#include "book.h"
#include "util.h"
using namespace std;

Book :: Book(const std::string category, const std::string name, double price, int qty, const std::string author, const std::string isbn) :
		Product(category, name, price, qty),
		author_(author),
		isbn_(isbn)
{
}

Book :: ~Book(){

}

std::set <std::string> Book :: keywords() const
{
	std::set<std::string> keywords_ = parseStringToWords(name_ + " " + author_);
	keywords_.insert(isbn_);
	return keywords_;
}

std::string Book :: displayString() const
{
	std::string display_ = "Title: " + name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n$" + to_string(price_) + " " + to_string(qty_) + "left";
	return display_;
}

void Book :: database(std::ostream& os) const
{
	os << category_ << std::endl << name_ << price_ << std::endl << qty_ << std::endl << author_ << std::endl << isbn_ << std::endl;
}