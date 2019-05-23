#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
class Node{
    public:
    int ymax;
    float xmin,inverseslope;
    Node* next;
};
// Node* getNode(int data) 
// { 
//     // allocating space 
//     Node* newNode = new Node(); 
  
//     // inserting the required data 
//     newNode->data = data; 
//     newNode->next = NULL; 
//     return newNode; 
// } 
int n;
bool cmp( pair<int,pair<double,double> > &p1, pair<int,pair<double,double> > &p2){
    return p1.second.second<=p2.second.second;
}
class mp{
    public:
    int i,l,r;
};
int main(){
 cout<<"Enter no. of points ";
 cin>>n;
 pair<int,pair<double,double> >poly[n];
// vector<Node> poly;
double ymin = 1000.0, ymax = 0.0;
for(int i = 0;i<n; ++i){
    double x,y;
    cin>>x>>y;
    poly[i].first = i;
    poly[i].second={x,y};
    ymin = min(ymin,y);
    ymax = max(ymax,y);
}
sort(poly,poly+n,cmp);

vector<Node> arr;

double yymin = ymin;
pair<int,pair<double,double> > p1=poly[0],p2=poly[1],p3=poly[2];
double m1 = (p2.y.x-p1.y.x)/(p2.y.y-p1.y.y), m2 = (p3.y.x-p1.y.x)/(p3.y.y-p1.y.y);
cout<<ymin<<"  "<<"( "<<p2.y.y<<","<<p2.y.x<<","<<m1<<" ) -> "<<"( "<<p3.y.y<<","<<p3.y.x<<","<<m2<<" )\n";
// for(int i = 0; i<n; ++i){
// int xi = poly[i].first,l,r;
// if(xi==0){
// l=n-1;
// r=1;
// }
// else if(xi==n-1){
// l=n-2;
// r=0;
// }
// else{
//     l=xi-1;
//     r=xi+1;
// }
//  pair<int,pair<double,double> > p1,p2;
//  for(int j = 0;j<)
// }
return 0;
}