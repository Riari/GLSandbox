#pragma once

#include <utility>

#include "Exception/Exception.hpp"

namespace OGL::Input::Exception
{
    class PrimaryKeyMissingException : public ::OGL::Exception::Exception
    {
    public:
        explicit PrimaryKeyMissingException() : ::OGL::Exception::Exception("Primary key is required.")
        {}
    };
}