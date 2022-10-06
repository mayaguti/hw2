#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include "datastore.h"

class Clothing : public Product{
	public:
		Clothing(const std::string category, const std::string name, double price, int qty, std::string brand);
		~Clothing();
		std::set <std::string> keywords() const;
		std::string displayString() const;
		void database(std::ostream& os) const;
	protected:
		std::string brand_;
};

#endif