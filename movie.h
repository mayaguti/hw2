#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "datastore.h"

class Movie : public Product{
	public:
		Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
		~Movie();
		std::set <std::string> keywords() const;
		std::string displayString() const;
		void database(std::ostream& os) const;
	protected:
		std::string genre_;
		std::string rating_;
};

#endif