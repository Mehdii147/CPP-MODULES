#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Helpers.hpp"
#include <iomanip>
#include <string>

class	Phonebook
{
	private:
		Contact	_contacts[8];
		int		_index;
	public:
		Phonebook();
		~Phonebook();
		Contact	get_contact(int index);
		
		void	add();
		void	search();
		void	infos(Contact contact);
};

#endif