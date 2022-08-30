
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli i,j;

#define pii  pair<lli, lli>
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define yes cout << "YES" << "\n";
#define no cout << "NO" << "\n";
#define SORT(v) sort(v.begin(),v.end());
#define R_SORT(v) sort(v.begin(),v.end(),greater<lli>());
#define en "\n"

struct available
{

    lli a=0;
    lli b=0;
    lli c=0;
    lli d=0;
    lli fg =0;
};

void solve()
{

    lli n;
    cout << "Total Number process" << endl;
    cin >> n;
    vector<available> allc;
    vector<available> mx_nd;
    vector<available> remain_nd;
    available res;   //given resourse
    cout<<"Total resourse "<<endl;
    cin>>res.a>>res.b>>res.c>>res.d;


    available tl_sm; //sum of total
    available avail; //available


    cout<<"Enter the allocation : "<<endl;
    for(i=0; i<n; i++)
    {
        available gm;
        lli a,b,c,d;
        cin>>a>>b>>c>>d;
        gm.a =a;
        gm.b =b;
        gm.c =c;
        gm.d =d;
        allc.pb(gm);
        tl_sm.a+=a;
        tl_sm.b+=b;
        tl_sm.c+=c;
        tl_sm.d+=d;

    }

 cout<<"Enter the Max need : "<<endl;
    for(i=0; i<n; i++)
    {
        available gm;
        lli a,b,c,d;
        cin>>a>>b>>c>>d;
        gm.a =a;
        gm.b =b;
        gm.c =c;
        gm.d =d;
        mx_nd.pb(gm);
    }

    //remain resource
    for(i=0; i<n; i++)cout << "Total Number process" << endl;
    {
        available gm;
        gm.a = mx_nd[i].a-allc[i].a;
        gm.b = mx_nd[i].b-allc[i].b;
        gm.c = mx_nd[i].c-allc[i].c;
        gm.d = mx_nd[i].d-allc[i].d;
        remain_nd.pb(gm);
    }

    //available resourse
  avail.a = res.a - tl_sm.a;
   avail.b = res.b - tl_sm.b;
   avail.c = res.c - tl_sm.c;

    avail.a = res.a;
    avail.b = res.b ;
    avail.c = res.c ;
    avail.d = res.d ;


    lli pr_sum=0;
    lli ls_fg=0;


    while(1)
    {
        cout<<"Nice life"<<endl;
        for(i=0; i<n; i++)
        {
            if(remain_nd[i].a<=avail.a && remain_nd[i].b<=avail.b && remain_nd[i].c<=avail.c&&remain_nd[i].d<=avail.d && remain_nd[i].fg==0)
            {
                remain_nd[i].fg=1;


                avail.a+=allc[i].a;
                avail.b+=allc[i].b;
                avail.c+=allc[i].c;
                avail.d+=allc[i].d;
                pr_sum++;
                cout<<"p"<<i<<"->"<<endl;

            }
        }

        if(pr_sum==n)
        {
            break;
        }
        else if(pr_sum==0)
        {
            cout<<"Is not safe"<<endl;
            break;
        }

    }

    for(i=0; i<n; i++)
    {
        cout<<remain_nd[i].a<<" "<<remain_nd[i].b<<" "<<remain_nd[i].c<<" "<<remain_nd[i].d<<endl;
    }






}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t, l = 0;
    cin >> t;
    while (t--)
    {
        l++;

         cout<<"Case "<<l<<": ";
        solve();
    }

    return 0;
}
