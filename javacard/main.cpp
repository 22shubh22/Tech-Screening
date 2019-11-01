#include "Applet.h"
#include <iostream>
#include <climits>
#include <assert.h>

using namespace std;

//check if power is on
const int TOTAL_TEST = 3;
bool power_on = 1;
int main()
{
    int test_passed=0;

    while(power_on){
        Applet *app = new Applet();
        // app is initallised
        int temp = app->case2();
        // test2 : power_on, !stored, retrived
        assert(temp == INT_MAX);
        //store
        app->case3(2);
        temp = app->case2();
        // test1 : power_on, store, retrived
        assert(temp == 2);

        temp = app->case2();
        // test3 : power_on, !stored, retrived
        assert(temp == INT_MAX);
        power_on = false;  

        if(!power_on){
            //flush app. restart at power on.
            delete app;
            assert(app);
        }
    }
    cout << "The applet service can be released";
}