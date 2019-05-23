#include <bits/stdc++.h>
#include <math.h>
#include <graphics.h>

using namespace std;
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define pb push_back

void ScanFill(vector<pair<double,double> >poly)
{
    double ymax=INT_MIN,ymin=INT_MAX;
    //Sorting Part
    vector<pair<pi,ll> > copy;
    for(ll i=0;i<poly.size();++i){
            copy.pb({{poly[i].y,poly[i].x},i});
            ymax=max(ymax,poly[i].y);
            ymin=min(ymin,poly[i].y);
    }
    sort(copy.begin(),copy.end());
    for(ll i=0;i<poly.size();++i){swap(copy[i].first.first,copy[i].first.second);}
    // Global Edge Table
    set<pi> sss;
    vector< pair<pair<double,double> ,double > > get[700];
    for(ll i=0;i<poly.size();++i)
    {
        ll idx=copy[i].second;
        ll idx1=(idx+1)%poly.size();
        if(sss.find(mp(min(idx,idx1),max(idx,idx1)))==sss.end())
        {
            sss.insert(mp(min(idx,idx1),max(idx,idx1)));
            ll y=copy[i].first.second;
            get[y].pb(mp(mp( poly[idx].x,poly[idx1].y ), (poly[idx1].x-poly[idx].x)*1.0/(poly[idx1].y-poly[idx].y) ));
        }
        idx1=(idx-1+poly.size())%poly.size();
        if(sss.find(mp(min(idx,idx1),max(idx,idx1)))==sss.end())
        {
            sss.insert(mp(min(idx,idx1),max(idx,idx1)));
            ll y=copy[i].first.second;
            get[y].pb(mp(mp( poly[idx].x,poly[idx1].y ), (poly[idx1].x-poly[idx].x)*1.0/(poly[idx1].y-poly[idx].y) ));
        }
    }

    // Active Edge Table
    vector< pair<pair<double,double> ,double > > aet;
    for(ll i=ymin;i<=ymax;++i)
    {
        vector< pair<pair<double,double> ,double > > ::iterator it;
        for(it=aet.begin();it!=aet.end();++it){
            if((*it).first.second==i){aet.erase(it);--it;}
            else{(*it).first.first+=(*it).second;}
        }
        for(ll j=0;j<get[i].size();++j){aet.pb(get[i][j]);}
        sort(aet.begin(),aet.end());
        for(ll j=0;j<aet.size();j+=2)
        {
            //cout<<aet[j].first.first<<","<<aet[j].first.second<<","<<aet[j].second<<"  "; make j+=1 above for showing
            line(aet[j].first.first,i,aet[j+1].first.first,i);
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    char drive[] = "";
    initgraph(&gd, &gm, drive);
    vector<pair<double, double> > poly;
    poly.pb({100,100});
    poly.pb({150,50});
    poly.pb({200,80});
    poly.pb({250,50});
    poly.pb({200,150});
    poly.pb({200,200});
    ScanFill(poly);
    int n; cin>>n;
    closegraph();
    return 0;
}