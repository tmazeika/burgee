#ifndef BURGEE_GLFW_EXCEPTION_H
#define BURGEE_GLFW_EXCEPTION_H

#include <exception>

class GlfwException : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Error creating GLFW window";
    }
};

#endif
