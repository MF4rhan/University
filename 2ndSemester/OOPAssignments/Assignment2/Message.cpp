#include "Message.h"
#include <iostream>
using namespace std;

//static variable declaration
int Message::totalMessages = 0;

//constructors
Message::Message()
:messageID(totalMessages++), senderID(0), receiverID(0),content("N/A"), timestamp("N/A"), isRead(false)    {}

Message::Message(int sender, int receiver, string text, string time)
:messageID(totalMessages++), senderID(sender), receiverID(receiver),content(text), timestamp(time), isRead(false)  {}

//getters
int Message::getMessageID() const   {return messageID;}
int Message::getSenderID() const    {return senderID;}
int Message::getReceiverID() const  {return receiverID;}
string Message::getContent() const  {return content;}
string Message::getTimestamp() const    {return timestamp;}
bool Message::getIsRead() const {return isRead;}
int Message::getTotalMessages() {return totalMessages;}

//setters
void Message::setContent(string text)   {content = text;}

//methods
void Message::markAsRead()
{
    isRead = true;
}

string Message::getPreview() 
{
    if (content.length() <= 20)
        return content;
    return content.substr(0, 20) + "...";
}

void Message::calculateTimeSinceSent(string currentTime) 
{
    if (timestamp == "Now" || timestamp == "N/A") 
    {
        cout << "Just now." << endl;
        return;
    }
    int sentHour    = stoi(timestamp.substr(0, 2));
    int sentMinute  = stoi(timestamp.substr(3, 2));
    int curHour     = stoi(currentTime.substr(0, 2));
    int curMinute   = stoi(currentTime.substr(3, 2));

    int sentTotal   = sentHour * 60 + sentMinute;
    int curTotal    = curHour  * 60 + curMinute;
    int diff        = curTotal - sentTotal;

    if (diff < 0)
        cout << "Invalid time." << endl;
    else if (diff < 60)
        cout << diff << " minute(s) ago." << endl;
    else
        cout << diff / 60 << " hour(s) and " << diff % 60 << " minute(s) ago." << endl;
}

void Message::formatMessageThread() 
{
    cout << "--------------------------" <<endl;
    cout << "From    : " << senderID<<endl;
    cout << "To      : " << receiverID<<endl;
    cout << "Time    : " << timestamp <<endl;
    cout << "Status  : " << (isRead ? "Read" : "Unread") << endl;
    cout << "Message : " <<content<< endl;
    cout << "--------------------------" <<endl;
}
