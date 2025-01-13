
#include "Phonebook.hpp"
#include "Helpers.hpp"


Phonebook::Phonebook(void)
{
	this->_index = 0;

	std::cout << "              ******  Choose a Command : ADD | SEARCH | EXIT  ******" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "MCHA" << std::endl;
}

Contact	Phonebook::get_contact(int index)
{
	return (this->_contacts[index % 8]);
}

void Phonebook::add(void) 
{
    std::string str;

    if (_index > 7) {
        std::cout << "Warning: you will lose " << _contacts[_index % 8].get_first_name() << std::endl;
    }

    std::cout << "Enter the first name: ";
    while (1) {
    if (std::getline(std::cin, str)) { 
        if (is_valid_input(str, 0)) {
            _contacts[_index % 8].set_first_name(str);
            break;
        } else {
            std::cout << "Invalid input, Please enter a valid first name: ";
        }
    } else { 
        std::cout << "\nInput terminated. Exiting 'add' function.";
        return;
    }
    }


    std::cout << "Enter last name: ";
    while (1) {
    if (std::getline(std::cin, str)) { 
        if (is_valid_input(str, 0)) {
            _contacts[_index % 8].set_last_name(str);
            break;
        } else {
            std::cout << "Invalid input, Please enter a valid last name: ";
        }
    } else { 
        std::cout << "\nInput terminated. Exiting 'add' function.";
        return;
    }
    }

    std::cout << "Enter nickname: ";
    while (1) {
    if (std::getline(std::cin, str)) { 
        if (is_valid_input(str, 0)) {
            _contacts[_index % 8].set_nickname(str);
            break;
        } else {
            std::cout << "Invalid input, Please enter a valid nickname: ";
        }
    } else { 
        std::cout << "\nInput terminated. Exiting 'add' function.";
        return;
    }
    }

    std::cout << "Enter phone number: ";
    while (1) {
    if (std::getline(std::cin, str)) { 
        if (is_valid_input(str, 1)) {
            _contacts[_index % 8].set_phone_number(str);
            break;
        } else {
            std::cout << "Invalid input, Please enter a valid Phone number: ";
        }
    } else { 
        std::cout << "\nInput terminated. Exiting 'add' function.";
        return;
    }
    }

    std::cout << "Enter darkest secret: ";
    while (1) {
    if (std::getline(std::cin, str)) { 
        if (is_valid_input(str, 0)) {
            _contacts[_index % 8].set_darkest_secret(str);
            break;
        } else {
            std::cout << "Invalid input, Please enter a valid darkest secret: ";
        }
    } else { 
        std::cout << "\nInput terminated. Exiting 'add' function.";
        return;
    }
    }

    std::cout <<"successfully added to your phonebook" << std::endl;

    _index++;
}

void	Phonebook::infos(Contact contact)
{
	std::cout << std::endl << "Contact infos :" << std::endl;
	std::cout << std::endl << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl<< std::endl;
}

void Phonebook::search(void)
{
    int c;
    std::string str;

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (c = 0; c < 8; ++c)
    {
        if (this->_contacts[c].get_first_name().size() > 0)
        {
            std::cout << "|" << std::setw(10) << c + 1; 
            std::cout << "|" << std::setw(10) << (_contacts[c].get_first_name().length() <= 10 
                                                    ? _contacts[c].get_first_name() 
                                                    : _contacts[c].get_first_name().substr(0, 9) + ".");
            std::cout << "|" << std::setw(10) << (_contacts[c].get_last_name().length() <= 10 
                                                    ? _contacts[c].get_last_name() 
                                                    : _contacts[c].get_last_name().substr(0, 9) + ".");
            std::cout << "|" << std::setw(10) << (_contacts[c].get_nickname().length() <= 10 
                                                    ? _contacts[c].get_nickname() 
                                                    : _contacts[c].get_nickname().substr(0, 9) + ".");
            std::cout << "|" << std::endl;
        }
    }
    std::cout << " ------------------------------------------- " << std::endl;

    if (_index == 0)
    {
        std::cout << std::endl << "Phonebook is empty!" << std::endl;
        return;
    }

    while (!std::cin.eof())
    {
        std::cout << "Choose an index for more info: ";
        if (std::getline(std::cin, str) && str != "")
        {
            std::stringstream ss(str);
            int chosenIndex;
            if (ss >> chosenIndex && chosenIndex >= 1 && chosenIndex <= 8 && _contacts[chosenIndex - 1].get_first_name().size())
            {
                this->infos(_contacts[chosenIndex - 1]);
                break;
            }
        }

        if (str != "")
            std::cout << "Invalid index!" << std::endl;
    }
}
