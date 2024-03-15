
#include <iostream>
using namespace std;
#define size 10

class Contact{
public:
	string name;
	string num;

	Contact(){
		name="";
		num="";
	}
};


class Hash{
public:
	Contact *people;

	Hash(){
		people=new Contact[size];
		for(int i=0;i<size;i++){
			people[i]=Contact();
		}
	}

	int gethash(string key){
		int hash=0;
		for(int i=0;i<key.length();i++){
			hash+=int(key[i]);
		}
		cout<<hash<<endl;
		return hash%size;
	}

	void insert_without_replacement(string name,string num){
		int hash=gethash(name);

		while(people[hash].name!="" || people[hash].name==name){
			hash=(hash+1)%size;
		}

		people[hash].name=name;
		people[hash].num=num;
		cout<<"inserted"<<endl;
	}

	void insert_with_replacement(string name,string num){
		int hash=gethash(name);
		while(people[hash].name!="" || people[hash].name==name){
		      int prev=gethash(people[hash].name);
		      if(prev!=hash){
                //swap

		    	string temp_name=people[hash].name;
		    	string temp_num=people[hash].num;

		    	people[hash].name=name;
		    	people[hash].num=num;

		    	name=temp_name;
		    	num=temp_num;

		      }
		      hash=(hash+1)%size;
		}
		people[hash].name=name;
		people[hash].num=num;
		cout<<"inserted"<<endl;
	}

	void display(){
		for(int i=0;i<size;i++){
			cout<<i<<"->"<<people[i].name<<"                  "<<people[i].num<<endl;
		}

	}
	 void search(string name)
	    {
	        int count = 0;

	        int hash = gethash(name);

	        for (int i = 0; i < size; i++)
	        {
	            count++;
	            if (people[hash].name == name)
	            {
	                cout << "Contact Found! Required Comparisions = " << count << endl;
	                cout << "Name: " << people[hash].name << endl;
	                cout << "Number: " << people[hash].num << endl;
	                return;
	            }
	            hash = (hash + 1) % size;
	        }
	        cout << "Data Not Found!!" << endl;
	    }


};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Hash h;
//	h.insert_without_replacement("prabhu","8421318464");
//	h.insert_without_replacement("renz","9869393457");
//	h.insert_without_replacement("manoj","8378973381");
//	h.insert_without_replacement("prabhu","73381");
//	h.insert_with_replacement("e","545");
//	h.insert_with_replacement("g","54");
//	h.insert_with_replacement("g","4");
//	h.insert_with_replacement("h","100");
//	h.display();
//	h.search("a");


	return 0;
}