#include <iostream>
#include <string>
using namespace std;

class Content
{
protected:
	static int counter;
	const int contentID;
	string title;
public:
	Content(string t): title(t), contentID(counter++)	{}

	void virtual displayContent()
	{
		cout<<"Content ID:\t"<<contentID<<endl;
		cout<<"Title: \t\t"<<title<<endl;
	}
};

class VideoLesson: public Content
{
protected:
	int videoLength;
public:
	VideoLesson(string t, int len): Content(t), videoLength(len)	{}

	void displayContent()
	{
		cout<<"Content ID:\t"<<contentID<<endl;
		cout<<"Title: \t\t"<<title<<endl;
		cout <<"Video Length: \t"<<videoLength<<endl<<endl;
	}
};

class AudioLecture: public Content
{
protected:
	int audioLength;
public:
	AudioLecture(string t, int len): Content(t), audioLength(len)	{}

	void displayContent()
	{
		cout<<"Content ID:\t"<<contentID<<endl;
		cout<<"Title: \t\t"<<title<<endl;
		cout <<"Audio Length: \t"<<audioLength<<endl<<endl;
	}
};

class TextTutorial: public Content
{
protected:
	int numOfPages;
public:
	TextTutorial(string t, int num): Content(t), numOfPages(num)	{}

	void displayContent()
	{
		cout<<"Content ID:\t"<<contentID<<endl;
		cout<<"Title: \t\t"<<title<<endl;
		cout <<"Audio Length: \t"<<numOfPages<<endl<<endl;
	}
};

int Content::counter=0;

int main()
{
	Content* Array[3];
	VideoLesson video1("OOP Lab 7", 20);
	AudioLecture audio1("EW Lab 6", 10);
	TextTutorial text1("EW Lab 7", 10);

	Array[0] = &video1;
	Array[1] = &audio1;
	Array[2] = &text1;

	for (int i = 0; i < 3; ++i)
	{
		Array[i]->displayContent();
	}

	return 0;
}
