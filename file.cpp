#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>


void    sort(std::vector<std::pair<int ,int> > &arr)
{
    if(arr.size() < 1)
    {
        std::vector<std::pair<int , int> > left(arr.begin(), arr.begin() + arr.size() / 2);
        std::vector<std::pair<int , int> > right(arr.begin() + arr.size() / 2, arr.end());

        sort(left);
        sort(right);

        int leftindex = 0;
        int rightindex = 0; 
        int arrindex = 0;

        while (leftindex < arr.size() / 2 && rightindex < arr.size() / 2 + arr.size() % 2)
        {
            if(left[leftindex] < right[rightindex])
            {
                arr[arrindex] = left[leftindex];
                leftindex++; 
            }
            else
            {
                arr[arrindex] = right[rightindex];
                rightindex++;
            }
            arrindex++;
        }
        while (leftindex < arr.size() / 2)
        {
            arr[arrindex] = left[leftindex];
            leftindex++; 
        }
        while(rightindex < arr.size() / 2 + arr.size() % 2)
        {
            arr[arrindex] = right[rightindex];
            rightindex++;   
        }

    }
}

void ford_johnson_vector(std::vector<int> &arr) 
{
    std::vector<std::pair<int, int> > ArrPair;
    int size = arr.size();
    bool odd = 0;
    int x;
    if (arr.size() % 2 != 0)
    {
        size--;
        x = arr[arr.size() - 1];
        odd =1;
    }

    for (int i = 0; i < size; i += 2)
        ArrPair.push_back(std::make_pair(arr[i], arr[i + 1]));
    for (std::vector<std::pair<int, int> >::iterator it = ArrPair.begin(); it != ArrPair.end(); ++it) 
    {
        if (it->first < it->second) 
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
    sort(ArrPair.begin(), ArrPair.end());
    std::vector<int> main;
    std::vector<int> pend;
    for(std::vector<std::pair<int, int> >::iterator it = ArrPair.begin() ; it != ArrPair.end(); it++)
    {
        main.push_back(it->first);
        pend.push_back(it->second);
    }
    for(std::vector<int>::iterator it = pend.begin(); it != pend.end(); it++)
    {
        main.insert(lower_bound(main.begin(),main.end(), *it), *it);
    }
    if(odd == true)
        main.insert(lower_bound(main.begin(), main.end(), x) , x);
    arr = main;

}
/******************************************deque*************************************************/

void    sort(std::deque<std::pair<int ,int> > &arr)
{
    if(arr.size() < 1)
    {
        std::deque<std::pair<int , int> > left(arr.begin(), arr.begin() + arr.size() / 2);
        std::deque<std::pair<int , int> > right(arr.begin() + arr.size() / 2, arr.end());

        sort(left);
        sort(right);

        int leftindex = 0;
        int rightindex = 0; 
        int arrindex = 0;

        while (leftindex < arr.size() / 2 && rightindex < arr.size() / 2 + arr.size() % 2)
        {
            if(left[leftindex] < right[rightindex])
            {
                arr[arrindex] = left[leftindex];
                leftindex++; 
            }
            else
            {
                arr[arrindex] = right[rightindex];
                rightindex++;
            }
            arrindex++;
        }
        while (leftindex < arr.size() / 2)
        {
            arr[arrindex] = left[leftindex];
            leftindex++; 
        }
        while(rightindex < arr.size() / 2 + arr.size() % 2)
        {
            arr[arrindex] = right[rightindex];
            rightindex++;   
        }

    }
}

void    ford_johnson_deq(std::deque<int> &arr)
{
    std::deque<std::pair<int, int> > ArrPair;
    int size = arr.size();
    bool odd = 0;
    int x;
    if (arr.size() % 2 != 0)
    {
        size--;
        x = arr[arr.size() - 1];
        odd =1;
    }

    for (int i = 0; i < size; i += 2)
        ArrPair.push_back(std::make_pair(arr[i], arr[i + 1]));
    for (std::deque<std::pair<int, int> >::iterator it = ArrPair.begin(); it != ArrPair.end(); ++it) 
    {
        if (it->first < it->second) 
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
    sort(ArrPair.begin(), ArrPair.end());
    std::deque<int> main;
    std::deque<int> pend;
    for(std::deque<std::pair<int, int> >::iterator it = ArrPair.begin() ; it != ArrPair.end(); it++)
    {
        main.push_back(it->first);
        pend.push_back(it->second);
    }
    for(std::deque<int>::iterator it = pend.begin(); it != pend.end(); it++)
    {
        main.insert(lower_bound(main.begin(),main.end(), *it), *it);
    }
    if(odd == true)
        main.insert(lower_bound(main.begin(), main.end(), x) , x);
    arr = main;

}

int main() {
    std::vector<int> myVector;
    myVector.push_back(2);
    myVector.push_back(1);
    myVector.push_back(0);
    myVector.push_back(5);
    myVector.push_back(4);
    myVector.push_back(3);

    std::deque<int> myDeque;
    myDeque.push_back(2);
    myDeque.push_back(1);
    myDeque.push_back(0);
    myDeque.push_back(5);
    myDeque.push_back(4);
    myDeque.push_back(3);
    for(std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout << *it << " ";
    }
    ford_johnson_vector(myVector);
    std::cout <<"\n";
    for(std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n********************************************\n";
    
    for(std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++)
    {
        std::cout << *it << " ";
    }

    ford_johnson_deq(myDeque);
    std::cout <<"\n";
     for(std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++)
    {
        std::cout << *it << " ";
    }
    return 0;
}
