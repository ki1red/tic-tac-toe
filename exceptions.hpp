#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <iostream>

class Exception
{
    // Methods
    public:
    virtual void what();
};

class InvalidValueException : public Exception
{
    // Variables
    private:
    std::string message_error;
    int code_error;

    // Constructors
    public:
    InvalidValueException();
    InvalidValueException(std::string message, int code_error);
    InvalidValueException(std::string message);
    InvalidValueException(int code_error);
    virtual void what();
};

class BeyondException : public Exception
{
    // Variables
    private:
    std::string message_error;

    // Constructors
    public:
    BeyondException();
    BeyondException(std::string message);
    virtual void what();
};

class InvalidNumbersException : public Exception
{
    // Variables
    private:
    std::string message_error;

    // Constructors
    public:
    InvalidNumbersException();
    InvalidNumbersException(std::string message);
    virtual void what();
};

#endif // EXCEPTIONS_HPP_