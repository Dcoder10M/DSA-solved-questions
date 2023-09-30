class Solution {
public:
int racecar(int target) {
queue<pair<int,pair<int,int>>>q;
q.push({0,{0,1}});
set<pair<int,int>>vis;
// vis.insert({0,0});
while(!q.empty())
{
int mov=q.front().first;
int pos=q.front().second.first;
long long int speed=q.front().second.second;
q.pop();
if(pos==target)
return mov;
if(vis.find({pos,speed})!=vis.end())
continue;
else{
vis.insert({pos,speed});
q.push({mov+1,{pos+speed,speed*2}});

        if( pos+speed>target && speed>0 || pos+speed<target && speed<0)
        {
            if(speed>0)
            speed=-1;
            else speed=1;
             q.push({mov+1,{pos,speed}});
        }
        }
    }
    return -1;
}
};