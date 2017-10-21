#pragma once

#include <exception>
#include <string>

#include "Status.hpp"

// Runtime error
namespace Yachel {
  namespace Exceptions {
    // Something happened when the emulator was loading
    class LoaderError : public std::exception {
      public:
        explicit LoaderError(const std::string& error,
            const std::string& romPath);
        virtual const char *what(void) const throw();
        const std::string& romPath(void) const;

      private:
        const std::string _errorMessage;
        const std::string _romPath;
    };

    // Something happened when the emulator was running
    class RuntimeError : public std::exception {
      public:
        explicit RuntimeError(const std::string& error,
            int32_t offset = Yachel::Status::FAILURE);
        virtual const char *what(void) const throw();
        int32_t offset(void) const;

      private:
        const std::string _errorMessage;
        int32_t _offset;
    };
  }
}
