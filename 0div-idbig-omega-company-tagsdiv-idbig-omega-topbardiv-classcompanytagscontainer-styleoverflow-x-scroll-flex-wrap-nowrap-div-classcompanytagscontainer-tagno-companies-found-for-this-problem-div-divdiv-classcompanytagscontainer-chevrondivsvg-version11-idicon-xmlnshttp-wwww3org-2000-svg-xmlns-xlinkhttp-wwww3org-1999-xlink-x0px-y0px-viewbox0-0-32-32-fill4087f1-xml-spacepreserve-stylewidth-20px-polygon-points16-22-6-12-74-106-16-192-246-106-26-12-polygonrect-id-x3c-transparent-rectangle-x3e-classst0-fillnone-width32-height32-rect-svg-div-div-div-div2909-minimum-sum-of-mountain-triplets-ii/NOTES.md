map<int,int> mp1;
mp1[2] = 2;
mp1[3] = 1;
mp1[1] = 1;
auto it = mp1.begin();
cout<<it->first<<" "<<it->second<<"    ";
--(it->second);
if(it->second == 0)
mp1.erase(it->first);
it = mp1.begin();
cout<<it->first<<" "<<it->second<<"    ";