#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

using namespace std;

namespace exceptions {
class Exception {

private:
   string message;

public:
   Exception( string message ) {
       this->message = message;
   }

   string getMessage() { return message; }
};
}
#endif // EXCEPTION_H
