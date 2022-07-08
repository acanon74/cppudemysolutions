#include <vector>
#include "classes/Account.h"
#include "classes/Checking.h"
#include "classes/Saving.h"
#include "classes/Trust.h"
#include "Account_Util.h"


using namespace std;

int main() {

    Checking frank {"Frank", 5000};
    cout << frank << endl;

    Account *trust = new Trust("James");
    cout << *trust << endl;

    Account *p1 = new Checking("Larry", 10000);
    Account *p2 = new Saving("Moe", 1000);
    Account *p3 = new Trust("Curly");

    std::vector<Account *> accounts {p1,p2,p3};

    display(accounts);
    deposit(accounts, 1000);

    display(accounts);

    withdraw(accounts, 2000);

    display(accounts);

    delete p1;
    delete p2;
    delete p3;
    return 0;
}