#include "exceptions.hpp"

// Exceptions

// Methods
void Exception::what()
    {}

// InvalidValueException

// Constructors
InvalidValueException::InvalidValueException()
    : message_error("INVALID VALUE"), code_error(13)
    {}
InvalidValueException::InvalidValueException(std::string message, int code_error)
    : message_error(message), code_error(code_error)
    {}
InvalidValueException::InvalidValueException(std::string message)
    : message_error(message), code_error(13)
    {}
InvalidValueException::InvalidValueException(int code_error)
    : message_error("INVALID VALUE"), code_error(code_error)
    {}

// Methods
void InvalidValueException::what()
    {
        std::cout << this->code_error<< " " << this->message_error;
    }

// BeyondException

// Constructors
BeyondException::BeyondException()
    : message_error("POSITION UNAVAILABLE")
    {}

BeyondException::BeyondException(std::string message)
    : message_error(message)
    {}

// Methods
void BeyondException::what()
    {
        std::cout << this->message_error;
    }

// InvalidNumbersException

// Constructors
InvalidNumbersException::InvalidNumbersException()
    : message_error("INVALID NUMBERS")
    {}

InvalidNumbersException::InvalidNumbersException(std::string message)
    : message_error(message)
    {}

// Methods
void InvalidNumbersException::what()
    {
        std::cout << this->message_error;
    }
