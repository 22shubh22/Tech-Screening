#include<bits/stdc++.h>

using namespace std;

/* Defining Next */
int next(int i, vector<string> current_connected)
{
    if(i < current_connected.size() - 1)
        i++;
    else
        i=0;
    return i;
}

struct ReverseProxy{
    string domain_name;
    int m; //no of connected machines;
    string machine[100];

    //requirement;
    vector <string> current_connected;
    int turn=0;
};

int main()
{
    // total machines
    int n;
    cin >> n;
    string machine[n];
    for(int i=0; i<n; i++)
        cin >> machine[i];

    /*for(int i=0;i<n;i++)
    {
        cout << machine[i] << " ";
    }*/

    //total reverse proxies
    int r;
    cin >> r;
    ReverseProxy reverseProxy[r];
    for(int i=0;i<r;i++)
    {
        cin >> reverseProxy[i].domain_name;
        cin >> reverseProxy[i].m;
        for(int j=0;j<reverseProxy[i].m; j++)
        {
            cin >> reverseProxy[i].machine[j];
            reverseProxy[i].current_connected.push_back(reverseProxy[i].machine[j]);
        }
    }

    // query
    int q;
    cin >> q;

    // request logs of each machine
    string request_logs[n];
    for(int i=0;i<n;i++)
    {
        request_logs[i] = machine[i] + '\n';
        //cout << request_logs[i] << endl;
    }

    /*for(int i=0;i<n;i++)
    {
        cout << request_logs[i];
    }*/

    while(q--)
    {
        string query_string;
        cin >> query_string;

        std::size_t pos = query_string.find("/");
        string temp = query_string.substr(0,pos);

        //cout << "Debug temp: " << temp << '\n';

        // Do update HERE ? find the reverseProxy from the query. Linear Search Here ?
        int reverseProxyIndex = -1;
        for(int i=0; i<r; i++)
        {
            if(temp == reverseProxy[i].domain_name)
            {
                reverseProxyIndex = i;
                break;
            }
        }
        if(reverseProxyIndex == -1)
            cout << "why index -1, problem in searching";

        string temp2 = query_string.substr(pos+1, 7);
        if(temp2 == "machine")
        {
            std::size_t pos = query_string.find("_");
            string temp3 = query_string.substr(pos+1, 1);

            std::size_t pos2 = query_string.find("=");
            string machineToChangeConnection = query_string.substr(pos2+1);
            if(temp3 == "u")
            {
                reverseProxy[reverseProxyIndex].current_connected.push_back(machineToChangeConnection);
                reverseProxy[reverseProxyIndex].turn = next(reverseProxy[reverseProxyIndex].turn, reverseProxy[reverseProxyIndex].current_connected);
            }
            else
            {
                // machine down

                //remove from list - https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
                reverseProxy[reverseProxyIndex].current_connected.erase(std::remove(reverseProxy[reverseProxyIndex].current_connected.begin(), reverseProxy[reverseProxyIndex].current_connected.end(), machineToChangeConnection ), reverseProxy[reverseProxyIndex].current_connected.end());
                reverseProxy[reverseProxyIndex].turn = next(reverseProxy[reverseProxyIndex].turn, reverseProxy[reverseProxyIndex].current_connected);
            }
        }

        else
        {
            int index_for_logs=-1;      // 0 <= index_of_logs < n
            int temp_turn = reverseProxy[reverseProxyIndex].turn;
            string string_for_logs = reverseProxy[reverseProxyIndex].current_connected[temp_turn];
            //Search in machine index kya hai string ka.
            for(int i=0;i<n ;i++)
            {
                if(string_for_logs == machine[i])
                {
                    index_for_logs = i;
                    break;
                }
            }
            if(index_for_logs == -1)
            {
                cout << "Error in Linear Search ? -2 " << '\n';
            }

            //cout << "index_for_logs: " << index_for_logs << '\n';

            request_logs[index_for_logs] += query_string + '\n';
            reverseProxy[reverseProxyIndex].turn = next(reverseProxy[reverseProxyIndex].turn, reverseProxy[reverseProxyIndex].current_connected);
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << request_logs[i];
    }
}