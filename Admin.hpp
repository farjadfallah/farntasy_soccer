#include <string>

class Admin{
    public:
        Admin(std::string _username, std::string _password);
        bool has_certain_username(std::string _username);
        bool has_certain_password(std::string _password);
    private:
        std::string username;
        std::string password;
};