#include <iostream>
#include <stack>
 
using namespace std;
 
void showstack(stack <int> st)
{
    stack <int> g = st;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
 
int main ()
{
    stack <int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);
 
    cout << "The stack s is : ";
    showstack(s);
 
    cout << "\ns.size() : " << s.size();
    cout << "\ngquiz.top() : " << s.top();
 
 
    cout << "\ns.pop() : ";
    s.pop();
    showstack(s);
 
    return 0;
}