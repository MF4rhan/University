#include <iostream>
#include <string>
using namespace std;

class Message
{
protected:
    string sender, reciever, content;
public:
    Message(string s, string r, string c): sender(s), reciever(r), content(c)   {}

    void setSender(string s)    {sender = s;}
    void setReciever(string r)  {reciever = r;}
    virtual void setContent(string c)   {content = c;}

    string getSender() const    {return sender;}
    string getReciever() const  {return reciever;}
    string getContent() const   {return content;}
};

class textMessage:virtual public Message
{
protected:
    string textContent;
public:
    textMessage(string s, string r, string c, string tc): Message(s,r,c), textContent(tc)   {}

    void setTextContent(string tc)  {textContent=tc;}
    void setContent(string c) override
    {
        cout<<"===========Message Preview==========="<<endl;
        cout<<c<<endl<<endl;
        while(1)
        {
            cout<<"Press 1 to send, press 0 to cancel."<<endl;
            int choice;
            cin>>choice;
            if(choice==1)
            {content=c;    return;}
            else if(choice==0)
                return;
            else
                cout<<"Invalid option, please try again."<<endl<<endl;
        }

    }

    string getTextContent() const   {return textContent;}
};

class voiceMessage: virtual public Message
{
protected:
    int duration;
    string format;
public:
    voiceMessage(string s , string r, string c, int d, string f): Message(s, r ,c), duration(d), format(f)  {}

    void setDuration(int d) {duration=d;}
    void setFormat(string f){format=f;}

    int getDuration() const {return duration;}
    string getFormat() const{return format;}
};

class videoMessage: public Message
{
private:
    int duration, resolution;
    string format;
public:
    videoMessage(string s , string r, string c, int d, string f, int re=0)
    : Message(s, r ,c), duration(d), format(f), resolution(re) {}

    void setDuration(int d)         {duration=d;}
    void setFormat(string f)        {format=f;}
    void setResolution(int r)    {resolution=r;}
    void setContent(string c) override
    {
        if(resolution>3840) //resolution for 4K UHD is 3840x2160 and 8K UHD is 7680x4320
        {
            cout<<"Warning: Resolution is too high, may cause issues for some users."<<endl;
            content=c;
        }
        else if (resolution==0)
            {cout<<"ERROR: Resolution not set."<<endl;  return;}
        else
        {
            content=c;
            cout<<"Video successfully sent."<<endl;
        }

    }


    int getDuration() const         {return duration;}
    string getFormat() const        {return format;}
    int getResolution() const    {return resolution;}
};

class GroupChat: public textMessage, public voiceMessage
{
    int counter;
    string members[10];
public:
    GroupChat(string s, string r, string c, string tc, int d, string f)
    :Message(s,r,c), textMessage(s,r,c,tc), voiceMessage(s,r,c,d,f), counter(0) {}

    void addMember(string name) {members[counter++]=name;}

    void displayMembers() const
    {
        if(counter==0)
            {cout<<"No Members Added."<<endl<<endl; return;}
        cout<<"==========Members List=========="<<endl;
        for(int i=0;i<counter;++i)
            cout<<"Member #"<<i+1<<" "<<members[i]<<endl;
        cout<<endl;
    }
};
