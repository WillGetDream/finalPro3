#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Clerk{
    bool w;//working
    int b;
    int e;
    int served;
    int speed;
};
struct Client{
    int b;
    int e;
    int time;
};
void f(vector<Clerk>,queue<Client>,int);
int main() {
    queue<Client> qline;
    vector<Clerk> clerks;

    Clerk clerkT1;
    bool flag4,flag5;
    int arrivedTime=60*1/4.0f;

    clerkT1.w= false;
    clerkT1.speed=60;//60*1/1

    Clerk clerkT2;
    clerkT2.w= false;
    clerkT2.speed=120;// 60*1/0.5

    Clerk clerkT3;
    clerkT3.w= false;
    clerkT3.speed=80; // 60*1/0.75

    Clerk clerkT4;
    clerkT4.w= false;
    clerkT4.speed=60;

    Clerk clerkT5;
    clerkT5.w= false;
    clerkT5.speed=60;

    clerks.push_back(clerkT1);
    clerks.push_back(clerkT2);
    clerks.push_back(clerkT3);
    clerks.push_back(clerkT4);
    clerks.push_back(clerkT5);
    cout<<"result: ----------------------------------------------->"<<endl;
    f(clerks,qline,arrivedTime);

    cout<<endl;
    clerks.clear();
    cout<<endl;

    clerkT1.speed=60*0.5;
    clerkT2.speed=120*0.5;
    clerkT3.speed=80*0.5;
    clerkT4.speed=60*0.5;
    clerkT5.speed=60*0.5;
    clerks.push_back(clerkT1);
    clerks.push_back(clerkT2);
    clerks.push_back(clerkT3);
    clerks.push_back(clerkT4);
    clerks.push_back(clerkT5);
    arrivedTime=30*0.5;
    cout<<"randomize servicing and arrival times by -50% result: --------------------------------------->"<<endl;
    f(clerks,qline,arrivedTime);

    cout<<endl;
    clerks.clear();
    cout<<endl;

    clerkT1.speed=60*1.5;
    clerkT2.speed=120*1.5;
    clerkT3.speed=80*1.5;
    clerkT4.speed=60*1.5;
    clerkT5.speed=60*1.5;
    clerks.push_back(clerkT1);
    clerks.push_back(clerkT2);
    clerks.push_back(clerkT3);
    clerks.push_back(clerkT4);
    clerks.push_back(clerkT5);
    arrivedTime=30*1.5;
    cout<<"randomize servicing and arrival times by +50% result: ---------------------------------------->"<<endl;
    f(clerks,qline,arrivedTime);


    cout<<"Professor: please look all the output result. thanks";
    return 0;
}
void f(vector<Clerk> clerks,queue<Client> qline,int arrivedTime){
    Clerk clerk1=clerks.at(0);
    Clerk clerk2=clerks.at(1);
    Clerk clerk3=clerks.at(2);
    Clerk clerk4=clerks.at(3);
    Clerk clerk5=clerks.at(4);

    int flag4,flag5;
    int sec=0;
    int maxLine=0;
    int totalClients=0;
    int totalClientsTimes=0;
    while(sec<1000){
        if(sec%arrivedTime==0){
            Client client;
            client.b=sec;
            qline.push(client);
            cout<<"total in line updated: "<<qline.size()<<endl;
            totalClients++;
            if(maxLine<qline.size())maxLine=qline.size();
        }
        //push to clerk
        if(qline.size()>0){
            //clerk1
            if(clerk1.w == false){
                clerk1.b=sec;
                clerk1.w=true;
                //   cout<<"clerk1 start:"<<clerk1.b<<endl;
            }

            if(clerk1.b==sec-clerk1.speed && clerk1.w ==true){
                clerk1.e=sec;
                clerk1.w= false;
                clerk1.served+=1;
                cout<<"clerk1 b-e: "<<clerk1.b<<"-->"<<clerk1.e<<endl;

                totalClientsTimes=totalClientsTimes+(sec-qline.front().b);
                qline.pop();

                cout<<"clerk1 finish p:"<<clerk1.served<<endl;
            }

            //clerk2
            if(clerk2.w == false){
                clerk2.b=sec;
                clerk2.w=true;
                //  cout<<"clerk2 start:"<<clerk2.b<<endl;
            }

            if(clerk2.b==sec-clerk2.speed && clerk2.w ==true){
                clerk2.e=sec;
                clerk2.w= false;
                clerk2.served+=1;
                cout<<" clerk2 b-e: "<<clerk2.b<<"-->"<<clerk2.e<<endl;

                totalClientsTimes=totalClientsTimes+(sec-qline.front().b);
                qline.pop();

                cout<<"clerk2 finish p:"<<clerk2.served<<endl;
            }


            //clerk3
            if(clerk3.w == false){
                clerk3.b=sec;
                clerk3.w=true;
                // cout<<"clerk3 start:"<<clerk3.b<<endl;
            }

            if(clerk3.b==sec-clerk3.speed && clerk3.w ==true){
                clerk3.e=sec;
                clerk3.w= false;
                clerk3.served+=1;
                cout<<" clerk3 b-e: "<<clerk3.b<<"-->"<<clerk3.e<<endl;

                totalClientsTimes=totalClientsTimes+(sec-qline.front().b);
                qline.pop();

                cout<<"clerk3 finish p:"<<clerk3.served<<endl;
            }

            //clerk 4 if qline.size>5
            if(qline.size()>5)flag4=true;

            if(qline.size()>5&&flag4==true){
                //clerk3
                if(clerk4.w == false){
                    clerk4.b=sec;
                    clerk4.w=true;
                    // cout<<"clerk3 start:"<<clerk3.b<<endl;
                }

                if(clerk4.b==sec-clerk4.speed && clerk4.w ==true){
                    clerk4.e=sec;
                    clerk4.w= false;
                    clerk4.served+=1;
                    cout<<" clerk4 b-e: "<<clerk4.b<<"-->"<<clerk4.e<<endl;

                    totalClientsTimes=totalClientsTimes+(sec-qline.front().b);
                    qline.pop();
                    cout<<"clerk4 finish p:"<<clerk4.served<<endl;

                    if(qline.size()==0){flag4=false;}
                }
            }

            //clerk 5 if qline.size>10
            if(qline.size()>10)flag5=true;

            if(qline.size()>10&&flag5==true){
                //clerk3
                if(clerk5.w == false){
                    clerk5.b=sec;
                    clerk5.w=true;
                    // cout<<"clerk3 start:"<<clerk3.b<<endl;
                }

                if(clerk5.b==sec-clerk5.speed && clerk5.w ==true){
                    clerk5.e=sec;
                    clerk5.w= false;
                    clerk5.served+=1;
                    cout<<" clerk5 b-e: "<<clerk5.b<<"-->"<<clerk5.e<<endl;

                    totalClientsTimes=totalClientsTimes+(sec-qline.front().b);
                    qline.pop();
                    cout<<"clerk5 finish p:"<<clerk5.served<<endl;

                    if(qline.size()==0){flag5=false;}
                }
            }
        }
        sec++;
    }
    cout<<endl;
    cout<<"Max number of customers in the line: "<<maxLine<<endl;
    cout<<"average customer wait time: "<<totalClientsTimes/totalClients<<" second."<<endl;


}
