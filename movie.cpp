#include "movie.h"
#include "util.h"
using namespace std;

Movie :: Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
		Product(category, name, price, qty),
		genre_(genre),
		rating_(rating)
{
}

Movie :: ~Movie(){

}

std::set <std::string> Movie :: keywords() const
{
	std::set<std::string> keywords_ = parseStringToWords(name_ + " " + genre_);
	return keywords_;
}

std::string Movie :: displayString() const
{
	std::string display_ = "Title: " + name_ + "\nGenre: " + genre_ + "\n$" + to_string(price_) + " " + to_string(qty_) + "left";
	return display_;
}

void Movie :: database(std::ostream& os) const
{
	os << category_ << std::endl << name_ << price_ << std::endl << qty_ << std::endl << genre_ << std::endl << rating_ << std::endl;
}