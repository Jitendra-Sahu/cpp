#include<iostream>

using namespace std;


struct Workshop
{
	int start_time;
	int duration;
	int end_time;
};

struct Available_Workshops
{
	int number;
	Workshop *Workshop[];
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
	Available_Workshops* a = new Available_Workshops[n];
	for(int i=0; i < n; ++i)
	{
		a[i].number = i;
		a[i].Workshop[i]->start_time = start_time[i];
		a[i].Workshop[i]->duration = duration[i];
		a[i].Workshop[i]->end_time = start_time[i] + duration[i];
	}
	return a;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
	int n = ptr->number;
	Available_Workshops* a = new Available_Workshops();
	Available_Workshops* temp = new Available_Workshops();
	a = ptr;  

	int lowest_start_time = a[0].Workshop[0]->start_time;;
	int highest_end_time = a[0].Workshop[0]->end_time;

	//calculate lowest start time and highest end time 
	for(int i=0; i <= n; i++)
	{
		cout<<"\nFirst caught";
    		if(lowest_start_time > a[i].Workshop[i]->start_time)
        		lowest_start_time = a[i].Workshop[i]->start_time;

    		if(highest_end_time < a[i].Workshop[i]->end_time)
        		highest_end_time = a[i].Workshop[i]->end_time;
	}

	// change start_time and end_time so that it start from 0 . then it is easy to access using array
	for(int i=0; i <= n; i++)
	{
		cout<<"\n2nd caught";
    		a[i].Workshop[i]->start_time -= lowest_start_time;
    		a[i].Workshop[i]->end_time -= lowest_start_time;
	}

	// sort using bubble sort (sort patameter is duration)
	for(int i=0; i < n; i++)
	{
		for(int i=0; i < n; i++)
		{
			cout<<"\n3rd caught";
			if(a[i+1].Workshop[i+1]->duration < a[i].Workshop[i]->duration)
			{
				cout<<"\n4th caught";
        			temp->number = a[i].number;
        			temp->Workshop[i]->start_time = a[i].Workshop[i]->start_time;
        			temp->Workshop[i]->end_time = a[i].Workshop[i]->end_time;
        			temp->Workshop[i]->duration = a[i].Workshop[i]->duration;

        			a[i] = a[i+1];
        			a[i+1].number = temp->number;
        			a[i+1].Workshop[i+1]->start_time = temp->Workshop[i]->start_time;
        			a[i+1].Workshop[i+1]->end_time = temp->Workshop[i]->end_time;
        			a[i+1].Workshop[i+1]->duration = temp->Workshop[i]->duration;
    			}
		}
	}

	cout<<"\n high time: "<<highest_end_time;
	cout<<"\n low start time: "<<lowest_start_time;
	//int p = highest_end_time -(lowest_start_time+1);
	bool check[316] = { false};

	int workshop_amout = 0;

	for(int i=0; i <= n; i++)
	{
    		bool array_check = false;

    		for(int j = a[i].Workshop[i]->start_time; j < a[i].Workshop[i]->end_time; j++)
		{
        		if(check[j])
            		{
				array_check = true;
        		}

    		}

    		if(!array_check)
		{
        		workshop_amout++;

        		for(int k = a[i].Workshop[i]->start_time; k < a[i].Workshop[i]->end_time; k++)
            		{
				check[k] = true;
			}
    		}         
	}

	return workshop_amout;
}

int main() {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    cout<<"\nintialize success after start time";
    cout<<"\nintialize success after duration";
    /*for(int i = 0; i < n; i++){
        cin >> duration[i];
    }*/

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout<<"\nintialize success";
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
