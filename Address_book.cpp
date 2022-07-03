#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//step 2:struct
struct person
{
	string m_name;
	int m_gender;
	int m_age;
	string m_phone;
};

struct addressbook
{
	person parray[MAX];
	int p_size;
};

//step 1: user interface
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4,查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}

//step 3: add person
void addperson(addressbook* ab)
{
	if (ab->p_size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		string name;
		cout << "name : ";
		cin >> name;
		ab->parray[ab->p_size].m_name = name;

		int gender = 0;
		cout << "gender(1 represent man, 2 represent woman) : ";
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				ab->parray[ab->p_size].m_gender = gender;
				break;
			}
			cout << "invalid value! try it again!" << endl;
		}
		

		int age;
		cout << "age : ";
		cin >> age;
		ab->parray[ab->p_size].m_age = age;

		string number;
		cout << "phone number : ";
		cin >> number;
		ab->parray[ab->p_size].m_phone = number;

		ab->p_size++;

		cout << "addition successful!" << endl;
		system("pause"); //任意键继续
		system("cls"); // clears
	}
	
}

//step 4: show the addressbook
void showperson(const addressbook * ab)
{
	if (ab->p_size == 0)
	{
		cout << "the addressbook is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < ab->p_size; i++)
		{
			cout << "name: " << ab->parray[i].m_name << "\t";
			cout << "gender: " << (ab->parray[i].m_gender == 1 ? "man" : "woman") << "\t";
			cout << "age: " << ab->parray[i].m_age << "\t";
			cout << "phone: " << ab->parray[i].m_phone << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}

//step 5: check whether the person exist?
int checkperson(addressbook *ab, string name)
{
		for (int i = 0; i < ab->p_size; i++)
		{
			if (name == ab->parray[i].m_name)
				return i;
		}
		return -1;
}

//step 6: delete the person
void deleteperson(addressbook* ab)
{
	string name;
	cout << "name: ";
	cin >> name;
	int res = checkperson(ab, name);
	if (res != -1)
	{
		for (int i = res; i < ab->p_size; i++)
		{
			//replace the data at x with the data at x+1
			ab->parray[i] = ab->parray[i + 1];
		}
		ab->p_size--;
		cout << "delete successfully!" << endl;
	}
	else
		cout << "not such person exist!" << endl;
	system("pause");
	system("cls");
}

void searchperson(addressbook* ab)
{
	string name;
	cout << "name: ";
	cin >> name;
	int res = checkperson(ab, name);
	if (res != -1)
	{
		cout << "name: " << ab->parray[res].m_name << "\t";
		cout << "gender: " << (ab->parray[res].m_gender == 1 ? "man" : "woman") << "\t";
		cout << "age: " << ab->parray[res].m_age << "\t";
		cout << "phone: " << ab->parray[res].m_phone << endl;
	}
	else
		cout << "not such person exist!" << endl;
	system("pause");
	system("cls");
}

void rewrite(addressbook* ab)
{
	string name;
	cout << "name: ";
	cin >> name;
	int res = checkperson(ab, name);
	if (res != -1)
	{
		cout << ab->parray[res].m_name << endl;

		string name;
		cout << "new name : ";
		cin >> name;
		ab->parray[res].m_name = name;

		int age;
		cout << "age: ";
		cin >> age;
		ab->parray[res].m_age = age;

		int gender = 0;
		cout << "gender(1 represent man, 2 represent woman) : ";
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				ab->parray[res].m_gender = gender;
				break;
			}
			cout << "invalid value! try it again!" << endl;
		}

		string number;
		cout << "phone number : ";
		cin >> number;
		ab->parray[res].m_phone = number;

		cout << "modify successfully!";
	}
	else
		cout << "not such person exist!" << endl;
	system("pause");
	system("cls");
}

void clear(addressbook* ab)
{
	char ch;
	cout << "are u sure? (y or n)" << endl;
	cin >> ch;
	if (ch == 'y')
	{
		ab->p_size = 0;
		cout << "clear completion!" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	addressbook ab;
	ab.p_size = 0;

	int select = 0;

	while (true)
	{
		//step 1: calling user interface
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			addperson(&ab); //step 3: pass by pointer
			break;
		case 2:
			showperson(&ab); //step 4
			break;
		case 3:
			deleteperson(&ab);//step 6
			break;
		case 4:
			searchperson(&ab); //step 7
			break;
		case 5:
			rewrite(&ab); //step 8
			break;
		case 6:
			clear(&ab); //step 9
			break;
		case 0:
			cout << "已退出" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}
