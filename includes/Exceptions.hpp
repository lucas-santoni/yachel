#pragma once

#include <exception>
#include <string>

#include "Chip8.hpp"

// Errors associated to Yachel
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
            const Yachel::Chip8& running);
        virtual const char *what(void) const throw();
        uint32_t offset(void) const;

      private:
        const std::string _errorMessage;
        uint32_t _offset;
    };
  }
}
