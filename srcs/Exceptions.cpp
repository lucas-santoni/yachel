#include "Yachel.hpp"

// LoaderError
namespace Yachel {
  namespace Exceptions {
    // Takes an error message and the current offset
    LoaderError::LoaderError(const std::string& error,
        const std::string& romPath) :
      _errorMessage(error),
      _romPath(romPath) {}

    // Return error message
    const char *LoaderError::what(void) const throw() {
      return _errorMessage.data();
    }

    // Return the path of the ROm which was being loaded
    const std::string& LoaderError::romPath(void) const {
      return _romPath;
    }
  }
}

// RuntimeError
namespace Yachel {
  namespace Exceptions {
    // Takes an error message and the current offset
    RuntimeError::RuntimeError(const std::string& error, int32_t offset) :
      _errorMessage(error) {
        _offset = offset;
      }

    // Return error message
    const char *RuntimeError::what(void) const throw() {
      return _errorMessage.data();
    }

    // Get the offset on which that happened
    int32_t RuntimeError::offset(void) const {
      return _offset;
    }
  }
}
