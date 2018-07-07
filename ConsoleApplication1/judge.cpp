#include "stdafx.h"

string fileName = "judges.csv";

void Copy2(Judges* J)
{
	int i;
	ofstream file(fileName, ios::out);
	if (!file)
	{
		cout << "\t  �ļ���ʧ�ܣ�" << endl;
	}
	else
	{
		for (i = 0; i < J->last; i++)
		{
			file << J->elem[i].name << ","<< J->elem[i].sex << ","<< J->elem[i].phone << "\n";
		}
	}
}




void Load2(Judges* J)
{
	string str;
	int i = 1, j = 0, s = 0;
	ifstream file(fileName, ios::in);
	while (getline(file, str)) {
		istringstream sin(str);
		vector<string>fields;
		string field;
		while (getline(sin, field, ',')) {
			fields.push_back(field);
		}
		J->elem[s].name = Trim(fields[0]);
		J->elem[s].sex = Trim(fields[1]);
		J->elem[s].phone = Trim(fields[2]);
		s++;
	}
	J->last = s;
}

void UI2()
{
	printf("\t\t\t|-----------------�˵�-----------------|\n");
	printf("\t\t\t|------------1.�����ί��Ϣ------------|\n");
	printf("\t\t\t|------------2.��ʾȫ����ί��Ϣ--------|\n");
	printf("\t\t\t|------------3.��ί��Ϣ��ѯ------------|\n");
	printf("\t\t\t|------------0.�˳���ί��Ϣϵͳ--------|\n");
}

void menu2(Judges* J)
{
	UI2();
	//	load2(J);//�����ļ�����ί����
	int i, have = 1;
	printf("ѡ��Ҫ���еĹ��ܣ�");
	while (cin>>i)
	{
		have = 1;
		switch (i)
		{
		case 1: add(J); break;
		case 2: Show(J); break;
		case 3: Query2(J); break;
		case 0: have = 0; break;
		}
		Copy2(J);
		if (have == 0) {
			cout << "\t  ������Ϣ����ɹ���" << endl;
			break;
			
		}	
		printf("ѡ��Ҫ���еĹ��ܣ�");
	}
}

void add(Judges* J)
{
	int i;
	i = J->last;
	printf("\t  ������ί���ϵͳ��\n");
	printf("\t  ������ί���֣�");
	cin>>J->elem[i].name;
	printf("\t  ������ί�Ա�");
	cin>>J->elem[i].sex;
	printf("\t  ������ί�绰��");
	cin>>J->elem[i].phone;
	J->last++;
	cout << "\t  �����ί��Ϣ�ɹ���" << endl;
}

void Show(Judges* J)
{
	printf("������ʾȫ����ί��Ϣϵͳ��\n");
	int i;
	printf("\t\t|      ����      | �Ա� |        �绰����        |\n");
	for (i = 0; i < J->last; i++)
	{
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
		//cout<<"\t\t|     "<<J->elem[i].name<<"     |  "<<J->elem[i].sex<<"  |       "<<J->elem[i].phone<<"       |\n";
	}
		
}

int Find2(Judges* J)//���Һ������ҵ������±꣬�Ҳ�������-1
{
	string Name;
	cout << "\t  ������Ҫ���ҵ���ί���֣�";
	cin >> Name;
	int i = 0;
	while ((i < J->last) && !(J->elem[i].name == Name)) {
		i++;
	}
	if (i < J->last)
		return i;
	else
		return -1;
}

void Query2(Judges* J)
{
	cout << "\t  �ѽ�����ί��Ϣ����ϵͳ"<<endl;
	int i;
	i = Find2(J);
	if (i != -1) {
		cout << "�ҵ���" << J->elem[i].name << "��ί����Ϣ��" << endl;
		printf("\t\t|      ����      | �Ա� |        �绰����        |\n");
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
	}
	else
		cout << "\t  ��Ǹ��û�д�����Ϣ��" << endl;
		
}