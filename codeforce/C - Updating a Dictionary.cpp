#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<string,string> ma,mb;
set<pair<string,string> > c1,c2,c3;
int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		c1.clear(),c2.clear(),c3.clear();
		ma.clear(),mb.clear();
		string a,b;
		cin >> a >> b;
		int lena = a.length();
		int lenb = b.length();
		string value,key;
		key = value = "";
		for (int i = 0; i < lena; ++i)
		{
			
			if ( isdigit(a[i]) )
                value += a[i];
            else if ( isalpha(a[i]) )
                key += a[i];
            else if ( a[i] == ',' )
            {
                ma.insert( make_pair<string, string>(key, value) );
                key = value = "";
            }
            else if ( a[i] == '}' )
            {
                if ( key != "" )
                    ma.insert( make_pair<string, string>(key, value) );
                key = value = "";
            }
		}
		key = value = "";
		map<string,string>::iterator it;
		for (int i = 0; i < lenb; ++i)
		{
			
			if ( isdigit(b[i]) )
                value += b[i];
            else if ( isalpha(b[i]) )
                key += b[i];
            else if ( b[i] == ',' )
            {
                mb.insert( make_pair<string, string>(key, value) );
                it = ma.find(key);
                if (it == ma.end()) c1.insert(make_pair<string, string>(key, value) );
                else if (it -> second.compare(value) != 0) c3.insert(make_pair<string, string>(key, value) );
                key = value = "";
            }
            else if ( b[i] == '}' )
            {
                if ( key != "" )
                    mb.insert( make_pair<string, string>(key, value) );
                it = ma.find(key);
                if (it == ma.end()) c1.insert(make_pair<string, string>(key, value) );
                else if (it -> second.compare(value) != 0) c3.insert(make_pair<string, string>(key, value) );
				key = value = "";
            }
		}
		
		map<string,string> ::iterator temp;
		for(map<string,string>::iterator it = ma.begin();it != ma.end(); ++it)
		{
			temp = mb.find(it->first);
			if (temp == mb.end()) c2.insert (make_pair<string, string>(it -> first, it -> second) );
		}
		
		if(c1.empty() && c2.empty() && c3.empty()) cout << "No changes\n";
		else
		{	
			if(!c1.empty())
			{
				cout<<"+";
				for(set<pair<string,string> >:: iterator it = c1.begin(),rhs; ; it++)
				{
					rhs=it;
					rhs++;
					if (rhs != c1.end())
						cout <<it->first <<",";
					else
					{
						cout<<it->first<<"\n";
						break;
					}
						
				}
			}
		
			if(!c2.empty())
			{
				cout<<"-";
				for(set<pair<string,string> >:: iterator it = c2.begin(),rhs; ; it++)
				{
					rhs=it;
					rhs++;
					if (rhs != c2.end())
						cout <<it->first <<",";
					else
					{
						cout<<it->first<<"\n";
						break;
					}
				}
			}
			if(!c3.empty())
			{
				cout<<"+";
				for(set<pair<string,string> >:: iterator it = c3.begin(),rhs; ; it++)
				{
					rhs=it;
					rhs++;
					if (rhs != c3.end())
						cout <<it->first <<",";
					else
					{
						cout<<it->first<<"\n";
						break;
					}
				}
			}
		}
	}
	
	
	return 0;
}
