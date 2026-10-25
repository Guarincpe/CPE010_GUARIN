#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>

using namespace std;

class Job
{
private:
    int jobID;
    string username;
    int pages;

public:
    Job(int id, string user, int page)
    {
        jobID = id;
        username = user;
        pages = page;
    }

    void display()
    {
        cout << "Job ID: " << jobID << endl;
        cout << "Username: " << username << endl;
        cout << "Pages: " << pages << endl;
    }
};

#endif