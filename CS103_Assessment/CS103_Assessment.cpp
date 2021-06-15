#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Policy
{
	int policyNumber;
	string first_name;
	string last_name;
	string dob;
	string gender;
	string contact_no;
	string email;
	string address;
	string vehicleRegNumber;
	string vehicle_name;
	string model;
};

void policyRegistration(int);

int main()
{
    

}

void policyRegistration(int policy_num) {

	Policy p;
	fstream policies;
	int temp_num = 100 + policy_num;
	bool check = true;

	policies.open("policies.dat", ios::in | ios::binary);

	while (check == true)
	{
		check = false;
		while (policies.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			if (p.policyNumber = temp_num)
			{
				cout << temp_num;
				temp_num += 100;
				check = true;
			}
		}
	}

	p.policyNumber = temp_num;

	policies.close();

	cout << "\nEnter your first name : ";
	cin >> p.first_name;
	cout << "\nEnter your last name : ";
	cin >> p.last_name;
	cout << "\nEnter your date of birth (dd/mm/yyyy) : ";
	cin >> p.dob;
	cout << "\nEnter your gender : ";
	cin >> p.gender;
	cout << "\nEnter your phone number : ";
	cin >> p.contact_no;
	cout << "\nEnter your email address : ";
	cin >> p.email;
	cout << "\nEnter your home address : ";
	cin >> p.address;
	cout << "\nEnter your vehicle registration number : ";
	cin >> p.vehicleRegNumber;
	cout << "\nEnter your vehicle name : ";
	cin >> p.vehicle_name;
	cout << "\nEnter your vehicle model : ";
	cin >> p.model;

	policies.open("policies.dat", ios::out | ios::app | ios::binary);

	policies.write(reinterpret_cast<char*>(&p), sizeof(p));

	policies.close();
}
