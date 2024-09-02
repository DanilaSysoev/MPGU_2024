#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    vector<string> pizzaList {};

    vector<string> orderAddresses {};
    vector<string> orderTimes {};
    vector<vector<string>> orderPizza {};
    vector<bool> orderDelivered {};

    bool is_over = false;

    while(!is_over)
    {
        cout << "Select oeration:" << endl;
        cout << "1. Add order" << endl;
        cout << "2. Delivery order" << endl;
        cout << "3. Cancel order" << endl;
        cout << "4. Add pizza" << endl;
        cout << "5. Remove pizza" << endl;
        cout << "6. List of pizza" << endl;
        cout << "7. List of orders (all)" << endl;
        cout << "8. List of orders (not delivered)" << endl;
        cout << "9. Quit" << endl;

        int command = 0;
        cin >> command;
        if(!cin) {
            command = 0;
            cin.ignore(numeric_limits<int>::max(), '\n');
            cin.clear();
        }

        switch(command)
        {
            case 1:
            {
                cout << "Enter order date:\n";
                string date;
                getchar();
                getline(cin, date);
                cout << "Enter order address:\n";
                string address;
                getline(cin, address);
                cout << "How many pizza?\n";
                int numberOfPizza = 0;
                cin >> numberOfPizza;
                if(!cin) {
                    numberOfPizza = 0;
                    cin.ignore(numeric_limits<int>::max(), '\n');
                    cin.clear();
                }
                vector<string> orderP {};
                if(numberOfPizza > 0)
                {
                    for(int i = 0; i < numberOfPizza; ++i)
                    {
                        cout << "Select pizza number " << i + 1 << ":\n";
                        for(int j = 0; j < pizzaList.size(); ++j)
                        {
                            cout << j + 1 << ". " << pizzaList[j] << '\n';
                        }
                    
                        int p = 0;
                        cin >> p;
                        if(!cin) {
                            p = 0;
                            cin.ignore(numeric_limits<int>::max(), '\n');
                            cin.clear();
                        }
                        if(p > 0 && p <= pizzaList.size())
                            orderP.push_back(pizzaList[p - 1]);
                        else
                            --i;
                    }

                    orderAddresses.push_back(address);
                    orderDelivered.push_back(false);
                    orderTimes.push_back(date);
                    orderPizza.push_back(orderP);
                }
            }
            break;
            case 2:
            {
                cout << "Select order:\n";
                int j = 1;
                for(int i = 0; i < orderAddresses.size(); ++i)
                {
                    if(!orderDelivered[i])
                        cout << j++ << ". " << orderTimes[i] << " # " << orderAddresses[i] << endl;
                }

                int o = 0;
                cin >> o;
                if(!cin) {
                    o = 0;
                    cin.ignore(numeric_limits<int>::max(), '\n');
                    cin.clear();
                }
                if(o > 0 && o <= j)
                {                
                    for(int i = 0, k = 1; i < orderAddresses.size(); ++i)
                    {
                        if(!orderDelivered[i])
                        {
                            if(k == o)
                                orderDelivered[i] = true;
                            ++k;
                        }
                    }
                }
            }
            break;
            case 3:
            {
                cout << "Select order:\n";
                for(int i = 0; i < orderAddresses.size(); ++i)
                {
                    cout << i + 1 << ". " << orderTimes[i] << " # " << orderAddresses[i] << endl;
                }

                int o = 0;
                cin >> o;
                if(!cin) {
                    o = 0;
                    cin.ignore(numeric_limits<int>::max(), '\n');
                    cin.clear();
                }
                if(o > 0 && o <= orderAddresses.size())
                {
                    if(orderDelivered[o])
                        cout << "Order delivered\n";
                    else
                    {
                        orderAddresses.erase(orderAddresses.begin() + o);
                        orderDelivered.erase(orderDelivered.begin() + o);
                        orderTimes.erase(orderTimes.begin() + o);
                        orderPizza.erase(orderPizza.begin() + o);
                    }
                }
            }
            break;
            case 4:
            {
                cout << "Enter pizza name:\n";
                string name;
                getchar();
                getline(cin, name);
                pizzaList.push_back(name);
            }
            break;
            case 5:
            {
                cout << "Select pizza:\n";
                for(int i = 0; i < pizzaList.size(); ++i)
                {
                    cout << i + 1 << ". " << pizzaList[i] << endl;
                }

                int o = 0;
                cin >> o;
                if(!cin) {
                    o = 0;
                    cin.ignore(numeric_limits<int>::max(), '\n');
                    cin.clear();
                }
                if(o > 0 && o <= pizzaList.size())
                {
                    pizzaList.erase(pizzaList.begin() + o);
                }
            }
            break;
            case 6:
            cout << "List of pizza:\n";
            for(int i = 0; i < pizzaList.size(); ++i)
            {
                cout << i + 1 << ". " << pizzaList[i] << endl;
            }
            break;
            case 7:
            cout << "List of orders (all):\n";
            for(int i = 0; i < orderAddresses.size(); ++i)
            {
                cout << i + 1 << ". " << orderTimes[i] << " # " << orderAddresses[i] << endl;
            }
            break;
            case 8:
            cout << "List of orders (not delivered):\n";
            for(int i = 0, j = 1; i < orderAddresses.size(); ++i)
            {
                if(!orderDelivered[i])
                    cout << j++ << ". " << orderTimes[i] << " # " << orderAddresses[i] << endl;
            }
            break;
            case 9:
            is_over = true;
            break;
            default:
            cout << "Unknown command. Try again\n";
            break;
        }
        
    }

    return 0;
}