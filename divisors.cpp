#include <iostream>
#include<stdlib.h>
#include<string.h>
#include <vector>

using namespace std;

int contains_3 (int value)
{
    while (value && (value % 10) != 3)
        value /= 10;
    return value;
}

int main (int argc, char **argv)
{
    int number, found_flag, last_div3, adjust, adjust_digit;
    vector<int> div3;
    vector<int>::reverse_iterator find3;
    vector<int>::iterator it;

    
    div3.push_back(3);
    div3.push_back(13);
    div3.push_back(23);

    if (argc != 2)
        return -1;

    number = atoi (argv[1]);
    found_flag = 0;

    
    last_div3 = div3.back();

    while (last_div3 * 2 < number)
    {
    
        if ((last_div3 % 10) != 9 && contains_3(last_div3/10))
        {
            last_div3++;
        } else
        {
           
            last_div3 /= 10;
            last_div3++;
            last_div3 *= 10;
            if (!contains_3(last_div3))
                last_div3 += 3;
        }
    
        for (it = div3.begin() ; it != div3.end() && (last_div3 % *it); ++it) ;
        if (it == div3.end())
        {
            div3.push_back(last_div3);
        }
    }

    cout << "list is now: ";
    for (it = div3.begin() ; it != div3.end(); ++it)
        cout << ' ' << *it;
    cout << endl;

    for (find3 = div3.rbegin(); !found_flag && find3 != div3.rend(); find3++)
    {
        if (!(number % *find3))
        {
            cout << "candidate: " << *find3 << ", remaining to sieve: " << number/(*find3) << endl;

            found_flag++;
        }
    }

    if (!found_flag)
        cout << "None found" << endl;

    return 0;
}
