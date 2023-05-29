#ifndef __MY__EXCEPTION__
#define __MY__EXCEPTION__
#include <string>

class Exceptions{
    public:
        virtual std::string error_message() = 0; 
};
class BAD_REQUEST : public Exceptions {
    public:
         std::string error_message(){
            return "Bad Request";
         } 
};

class PERMISSION_DENIED : public Exceptions {
     public:
         std::string error_message(){
            return "Permission Denied";
         } 
};

class NOT_FOUND : public Exceptions {
     public:
         std::string error_message(){
            return "Not Found";
         } 
};

class EMPTY : public Exceptions {
     public:
         std::string error_message(){
            return "Empty";
         } 
};
#endif