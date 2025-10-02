#include <string>

class User
{
private:
    std::string name;
    long cashBalance;
    long stockBalance;

public:
    const long id;
    User(long id, std::string name);
    User(long id, std::string name, long cashBalance, long stockBalance);
    // getters
    std::string getName();
    long getCashBalance();
    long getStockBalance();
    // setters
    bool updateBalance(long deltaCash, long deltaStock);
};
