/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡖⠁⠀⠀⠀⠀⠀⠀⠈⢲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⢀⣀⣤⣤⣤⣤⣀⡀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣔⢿⡿⠟⠛⠛⠻⢿⡿⣢⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⣷⣤⣀⡀⢀⣀⣤⣾⣿⣿⣿⣷⣶⣤⡀⠀⠀⠀⠀
⠀⠀⢠⣾⣿⡿⠿⠿⠿⣿⣿⣿⣿⡿⠏⠻⢿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣷⡀⠀⠀
⠀⢠⡿⠋⠁⠀⠀⢸⣿⡇⠉⠻⣿⠇⠀⠀⠸⣿⡿⠋⢰⣿⡇⠀⠀⠈⠙⢿⡄⠀
⠀⡿⠁⠀⠀⠀⠀⠘⣿⣷⡀⠀⠰⣿⣶⣶⣿⡎⠀⢀⣾⣿⠇⠀⠀⠀⠀⠈⢿⠀
⠀⡇⠀⠀⠀⠀⠀⠀⠹⣿⣷⣄⠀⣿⣿⣿⣿⠀⣠⣾⣿⠏⠀⠀⠀⠀⠀⠀⢸⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⢇⣿⣿⣿⣿⡸⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠈⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠐⢤⣀⣀⢀⣀⣠⣴⣿⣿⠿⠋⠙⠿⣿⣿⣦⣄⣀⠀⠀⣀⡠⠂⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠉⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠋⠁⠀⠀⠀
              ravireddy07⠀⠀
*/

/*
cout << "[";
	for (int i = 0; i < out.size(); i++)
	{
		if (i == out.size() - 1)
			cout << out[i];
		else
			cout << out[i] << ", ";
	}
cout << "]" << endl;
*/

/*
cout << "[";
    for (int i = 0; i < output.size(); i++)
    {
        cout << endl
             << " [";
        for (int j = 0; j < output[0].size(); j++)
        {
            if (j == output[0].size() - 1)
                cout << output[i][j];
            else
                cout << output[i][j] << ", ";
        }
        cout << "]";
    }
cout << endl
     << "]";*/

#include <bits/stdc++.h>
using namespace std;

void showq(queue<string> student)
{
    queue<string> s = student;
    while (!s.empty())
    {
        cout << '\t' << s.front();
        s.pop();
    }
    cout << '\n';
}

void showdq(deque<string> s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}

void showlist(list<string> s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

void showpq(priority_queue<string> student)
{
    priority_queue<string> s = student;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';
}

int main()
{
    int choice;
    cout << "1. Stack\n";
    cout << "2. Simple Queue\n";
    cout << "3. Double Ended Queue\n";
    cout << "4. Priority\n";
    cout << "5. List\n";
    cout << "\nEnter your Choice : ";
    cin >> choice;

    if (choice == 1)
    {
        stack<string> s;
        s.push("Harry");
        s.push("101");
        s.push("9.0");
        s.pop();
        s.push("9.5");
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    else if (choice == 2)
    {
        queue<string> student;
        student.push("Harry");
        student.push("101");
        student.push("9.0");

        cout << "The queue student is : ";
        showq(student);

        cout << "\nstudent.size() : " << student.size();
        cout << "\nstudent.front() : " << student.front();
        cout << "\nstudent.back() : " << student.back();

        cout << "\nstudent.pop() : ";
        student.pop();
        showq(student);
    }
    else if (choice == 3)
    {
        deque<string> student;
        student.push_back("101");
        student.push_front("Harry");
        student.push_back("9.0");
        cout << "The deque student is : ";
        showdq(student);
        cout << "\nstudent.at(2) : " << student.at(2);
        cout << "\nstudent.front() : " << student.front();
        cout << "\nstudent.back() : " << student.back();
        student.pop_front();
        showdq(student);
    }
    else if (choice == 4)
    {
        priority_queue<string> student;
        student.push("Harry");
        student.push("101");
        student.push("9.0");

        cout << "The priority queue student is : ";
        showpq(student);

        cout << "\nstudent.size() : " << student.size();
        cout << "\nstudent.top() : " << student.top();
        student.pop();
        showpq(student);
    }
    else if (choice == 5)
    {
        list<string> student;

        student.push_back("Harry");
        student.push_back("101");
        student.push_back("9.0");
        cout << "\nList 1 (student) is : ";
        showlist(student);

        cout << "\nstudent.front() : " << student.front();
        cout << "\nstudent.back() : " << student.back();

        cout << "\nstudent.pop_front() : ";
        student.pop_front();
        showlist(student);
    }
    else
        cout << "Invaild Input.";
    return 0;
}
