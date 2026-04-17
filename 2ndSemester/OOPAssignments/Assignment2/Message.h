#pragma once
#include <string>
using namespace std;

class Message 
{
private:
    int messageID;
    int senderID;
    int receiverID;
    string content;
    string timestamp;
    bool isRead;
    static int totalMessages;   //static

public:
    //constructors
    Message();
    Message(int senderID, int receiverID, string content, string timestamp);

    //getters
    int getMessageID() const;
    int getSenderID() const;
    int getReceiverID() const;
    string getContent() const;
    string getTimestamp() const;
    bool getIsRead() const;
    static int getTotalMessages();

    //setters
    void setContent(string content);

    //methods
    void markAsRead();
    string getPreview();
    void calculateTimeSinceSent(string currentTime);
    void formatMessageThread();
};