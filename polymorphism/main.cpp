#include <vector>
#include "classes/Account.h"
#include "classes/Checking.h"
#include "classes/Saving.h"
#include "classes/Trust.h"
#include "Account_Util.h"


using namespace std;

int main() {


    vector<Account *> v;

    Account *q = new Checking{"checking", 100, 3};

    Account *w = new Saving{"saving", 200, 4};

    Account *e = new Trust {"trust", 300, 500};

    v.push_back(q);
    v.push_back(w);
    v.push_back(e);

    display(v);

    deposit(v, 100);

    display(v);

    withdraw(v, 100);

    display(v);

    return 0;
}