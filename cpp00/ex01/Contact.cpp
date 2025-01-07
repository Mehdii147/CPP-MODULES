#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::get_first_name(void) const
{
    return(this->_first_name);
}

std::string Contact::get_last_name(void) const
{
    return(this->_last_name);
}

std::string Contact::get_nickname(void) const
{
    return(this->_nickname);
}

std::string Contact::get_phone_number(void) const
{
    return(this->_phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
    return(this->_darkest_secret);
}

void Contact::set_first_name(std::string etwas)
{
    this->_first_name = etwas;
}

void Contact::set_last_name(std::string etwas)
{
    this->_last_name = etwas;
}

void Contact::set_nickname(std::string etwas)
{
    this->_nickname = etwas;
}

void Contact::set_phone_number(std::string etwas)
{
    this->_phone_number = etwas;
}

void Contact::set_darkest_secret(std::string etwas)
{
    this->_darkest_secret = etwas;
}
