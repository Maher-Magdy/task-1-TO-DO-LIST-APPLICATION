#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	cout << "add your tasks by writing : \"add\" then the task name " << endl;
	cout << "write : \"view\" to see your list" << endl;
	cout << "write : \"complete task (number)\"" << endl;
	vector< pair < string, string>> task_list;
	while (true)
	{
		//get user input
		string input_line;
		getline(cin,input_line);	
		//case : if the user inputs add new task
		if (input_line.length() > 3 && input_line.substr(0, 3) == "add")
		{
			pair < string, string> input_line_and_status;
			input_line_and_status.first = input_line.substr(4, input_line.length() - 4);
			input_line_and_status.second = "uncompleted";
			task_list.push_back(input_line_and_status);
		}
		//case : if the user inputs view tasks
		else if (input_line == "view")
		{
			for (int i = 0; i < task_list.size(); i++)
			{
				cout << "task:"<<i+1<<" "<<task_list[i].first << "\t" << ", status : " << task_list[i].second << endl;
			}
		}
		//case : if the user wants to mark tasks as completed
		else if (input_line.length() > 13 && input_line.substr(0, 13) == "complete task")
		{
			int index =stoi(input_line.substr(15, input_line.length() - 15))-1;
			task_list[index].second = "completed";
		
		}		
		//case : if the user inputs exit end the program
		else if (input_line == "exit") break;
		//case : any other input is recognized
		else cout<<"unrecognized command "<<endl;
	}


	return 0;
}