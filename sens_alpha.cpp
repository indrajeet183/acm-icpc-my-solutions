/* ACM-ICPC 2014 Problem:Sensor Network IGL vAlpha*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> v1,row;
vector<vector<int> > vec;
/* Class for sensor co-ordinate which take x and y co-ordinate*/

class sens {
	public:

	int x,y;

	sens() {
		x=y=0;
	}

	void set() {		

		cin>>x;
		cin>>y;
	}

	void disp() {

		cout<<"\nX"<<x<<"\nY"<<y;
		cout<<endl;
	}

};

/* Function for calculating the distances from sensors within the given x and y co-ordinates*/

double dist(sens ob1,sens ob2) {

	return sqrt((ob2.x-ob1.x)*(ob2.x-ob1.x)+(ob2.y-ob1.y)*(ob2.y-ob1.y));

}

int getLastPos() {
	int size=v1.size();
	return v1[v1.size()-1];
}

/* Printing the final result */

void finalResult(int n) {
	
	int max,i,j,resIndex;
	max=0;
	/*for(i=0;i<vec.size();i++) {
		cout<<"\nI"<<i+1<<endl;
		cout<<"___________________\n";
		for(j=0;j<vec[i].size();j++) {
			cout<<endl<<vec.at(i).at(j);
		}
		cout<<endl<<"__________________\n";
	}*/
	/* Here we find out the maximums sensor subset from 2D vecotr */
	for(i=0;i<vec.size();i++) {
		//cout<<"\ni"<<i<<"  size"<<vec[i].size();
		if(vec[i].size() > max) {
			max=vec[i].size();
			resIndex=i;
		}
	}
	cout<<"\nSensors in subset :"<<vec[resIndex].size()+1<<endl;
	cout<<"\nSensor index";
	cout<<"\n"<<resIndex+1;
	for(j=0;j<vec[resIndex].size();j++) {
		cout<<"    "<<vec.at(resIndex).at(j);
	}
	cout<<endl<<endl;
}
/* Calculating the distances from every sensor to every sensor */

void calcX(sens o[],int l,int dc) {

	int i,j;
	double dist_fi[l][l];
	int avl[l],tx,count,t;

	/* Calculating the distances from every sensor to every sensor*/

	for(i=0;i<l;i++) {
		for(j=0;j<l;j++) {
			dist_fi[i][j]=dist(o[i],o[j]);
		}
	}

	/*for(i=0;i<l;i++) {
		for(j=0;j<l;j++) {
			cout<<"\n"<<i<<"to "<<j<<" = ";
			cout<<dist_fi[i][j];
			cout<<endl;
		}
	}*/

	/* Loop for checking the distances from one sensor to another and storing the result in 2D vecotr*/
	for(i=0;i<l;i++) {
		count=1;
		for(j=0;j<l;j++) {
			if(dist_fi[i][j]<=dc && i!=j) {
				v1.push_back(j);
				if(count==1) {
					count++;
					avl[i]=count;	
					row.push_back(j+1);
				}
				else if(count>0) {
					tx=v1[v1.size()-2];
					if(dist_fi[tx][j]<=dc) {
						count++;
						avl[i]=count;
						row.push_back(j+1);
					}
				}
				if(j+1<l) {
					vec.push_back(row);
					row.clear();
				}		
			}			
		}
	}
	/*for(i=0;i<l;i++) {

		cout<<"\n"<<i<<" = ";
		cout<<avl[i];
		cout<<endl;
	}*/
		
}

/* The main starts here*/

int main() 
{
	int n,d;

	cout<<"\nEnter number of sensors\n";
	cin>>n;
	cout<<"\nEnter maximum distance\n";	
	cin>>d;

	sens ob[n];	

	for(int i=0;i<n;i++) {
		ob[i].set();
	}

	calcX(ob,n,d);
	
	finalResult(n);
	return 0;
}
